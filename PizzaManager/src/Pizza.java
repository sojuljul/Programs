import java.awt.Color;
import java.text.DecimalFormat;

/*
 * Author:		Juliano Nguyen
 * CSS162		Pizza Manager
 * 5/29/2016
 * Pizza class
 * Description:
 * 				Creates a pizza with random shape and ingredients
 * 				Create methods such as getters for calorie and cost, getter/setter for shape,
 * 				Implements the PizzaComparable interface, create respective compareTo methods (override)
 * 				Create method for eatSomePizza, where you subtract the amount given to the remaining
 */
public class Pizza implements PizzaComparable {
	
	//data items
	private ArrayList<Ingredient> listOfIngred = new ArrayList<Ingredient>(); //list of ingredients
	private int calorie; //keeps track of calories
	private Money totalCost = new Money(0,0); //keeps track of the cost
	private Shape pizzaShape; //keeps track of the shape
	private Fraction pizzaFraction = new Fraction(); //keeps track of the fraction remaining
	
	/*
	 * Constructor that takes no arguments
	 * Generate a pizza with random shape and ingredients
	 */
	public Pizza()
	{
		//get a random shape: circle or square
		if(Math.random() > 0.5) 
		{
			Circle oneCircle = new Circle();
			pizzaShape = oneCircle; //sets the shape to be a circle
		}
		else 
		{
			Square oneSquare = new Square();
			pizzaShape = oneSquare; //otherwise set it to a square
		}
		
		//get a random base: marinara or alfredo
		if(Math.random() > 0.5)
		{
			addIngredient(new Marinara()); //add marinara to the list of ingredients
		}
		else
		{
			addIngredient(new Alfredo()); //add alfredo to the list of ingredients
		}
		
		//get a random cheese: goat or mozzarella
		if(Math.random() > 0.5)
		{
			addIngredient(new Goat()); //add goat to the list of ingredients
		}
		else
		{
			addIngredient(new Mozzarella()); //add mozzarella to the list of ingredients
		}
		
		//get a random meat: pepperoni or sausage
		if(Math.random() > 0.5)
		{
			addIngredient(new Pepperoni()); //add pepperoni to the list of ingredients
		}
		else
		{
			addIngredient(new Sausage()); //add sausage to the list of ingredients
		}
		
		//get a random veggie: pepper or olive
		if(Math.random() > 0.5)
		{
			if(Math.random() > 0.5)
			{
				addIngredient(new Pepper(Color.RED)); //add RED pepper to the list of ingredients
			}
			else
			{
				addIngredient(new Pepper(Color.GREEN)); //add GREEN pepper to the list of ingredients
			}
		}
		else
		{
			if(Math.random() > 0.5)
			{
				addIngredient(new Olive(Color.BLACK)); //add BLACK olive to the list of ingredients
			}
			else
			{
				addIngredient(new Olive(Color.GREEN)); //add GREEN olive to the list of ingredients
			}
		}
	}
	
	/*
	 * Getter for remaining
	 * Returns a new Fraction object of the pizza remaining
	 */
	public Fraction getRemaining()
	{
		return (Fraction) pizzaFraction.clone(); //uses the clone method from the Fraction class
	}
	
	/*
	 * Setter for remaining
	 * Takes in a Fraction object and sets it to the pizza remaining
	 */
	public void setRemaining(Fraction newFract)
	{
		pizzaFraction = (Fraction) newFract.clone(); //uses the clone method from the Fraction class
	}
	
	/*
	 * Getter for calorie
	 * Returns the value as an int
	 */
	public int getCalories()
	{
		return this.calorie;
	}
	
	/*
	 * Getter for cost
	 * Returns a new Money object of the pizza cost
	 */
	public Money getCost()
	{
		return (Money) totalCost.clone(); //uses the clone method from the Money class
	}
	
	/*
	 * Getter for the remaining area of pizza
	 * Calculates the area by getting the area of the shape scaled by the fraction of remaining pizza 
	 * Returns the value as a double
	 */
	public double getRemainingArea()
	{		
		return pizzaShape.getArea() * pizzaFraction.getDouble();
	}
	
	/*
	 * Setter for shape
	 * Takes in a shape object as argument and sets it to the pizza shape by making a clone
	 */
	public void setShape(Shape newShape)
	{
		pizzaShape = (Shape) newShape.clone(); //uses the clone method from the Shape class
	}
	
	/*
	 * Getter for shape
	 * Returns a new pizza object by making a clone
	 */
	public Shape getShape()
	{
		return (Shape) pizzaShape.clone(); //uses the clone method form the Shape class
	}
	
	/*
	 * Adds an ingredient to our list
	 * Takes in an Ingredient object as argument
	 * Add the calories and cost of that ingredient to the respective variables
	 */
	public void addIngredient(Ingredient topping)
	{
		listOfIngred.add(topping); //adds the topping to the list of ingredients
		calorie += topping.getCalorie(); //adds the calories from the ingredient to the total calorie
		calculateCost(); //calls method to calculate the cost of the remaining pizza
	}
	
	/*
	 * Subtracts an specific amount from our pizza
	 * If 0, throw an exception
	 * If < 0, throw an exception since this is an error case
	 */
	public void eatSomePizza(Fraction amount)
	{
		if (amount == null) //null check
		{
			throw new PizzaException("Cannot have null");
		}
		
		Fraction difference = pizzaFraction.subtract(amount); //get the difference of the Fraction and given amount

		if (difference.getNumerator() == 0) //check if 0
		{
			throw new PizzaException("Pizza is all gone");
		}

		pizzaFraction = new Fraction(difference); //make our pizzaFraction equal to our difference
		calculateCost(); //calls method to calculate the cost of the remaining pizza
	}
	
	/*
	 * Scales the cost of a given Money object by the percentage of the remaining pizza left
	 * Takes in a Money object as argument
	 * Returns the value as a new Money object
	 */
	public Money scaleCost(Money newMoney)
	{
		double percentage = (double) (pizzaFraction.getNumerator()) / pizzaFraction.getDenominator(); //gets the percentage from the fraction
		int totalCents = (newMoney.getDollars() * 100) + newMoney.getCents(); //gets the total amount in cents
		int scaledCents = (int) (percentage * totalCents); //scale the cents by the percentage
		
		return new Money(0, scaledCents); //return our new Money that is scaled by our current remaining pizza
	}
	
	/*
	 * Calculates the sum cost of the pizza ingredients
	 * Goes through a loop of all the ingredients in the list and adds up the cost
	 */
	public void calculateCost()
	{
		Money sum = new Money(0,0); //new money at 0.00
		
		for (int index = 0; index < listOfIngred.size(); index++) //keep looping through the list of ingredients
		{
			Money ingCost = listOfIngred.get(index).getCost(); //cost of the ingredient in the list
			sum.add(ingCost); //add the cost to the sum
		}
		
		this.totalCost = scaleCost(sum); //make total cost equal to the scale of our sum
	}
	
	/*
	 * Overrides the toString method
	 * Returns the value as a string to print out the cost, calorie, remaining, area, shape
	 */
	@Override
	public String toString()
	{
		DecimalFormat df = new DecimalFormat("#.00"); //make values have 2 decimal places in a string
		
		String retVal = "";
		for (int index = 0; index < listOfIngred.size(); index++) //loop through the list of ingredients
		{
			retVal += listOfIngred.get(index).getDescription() + ","; //add all ingredients to the string
		}
		
		return "Pizza toppings: " + retVal + " Pizza has a price: " + totalCost.toString() + " and calories: " + calorie + 
				", Fraction remaining: " + pizzaFraction.toString() + " and area left: " + df.format(getRemainingArea()) + 
				" and shape: " + pizzaShape.toString();
	}
	
	/*
	 * Overrides the compareTo method, which is the PizzaComparable interface
	 * Compares this and that for the cost of the pizza
	 * If 0, this == that; if +1, this > that; if -1, this < that
	 */
	@Override
	public int compareTo(Object other) //compareToByPrice
	{
		if (other == null || !(other instanceof Pizza)) //null check
		{
			throw new PizzaException("Object is null / not the same class");
		}
		
		Pizza that = (Pizza) other;
		return this.totalCost.compareTo(that.totalCost); //uses the compareTo method from Money class
	}
	
	/*
	 * Overrides the compareToBySize method, which is the PizzaComparable interface
	 * Compares this and that for the remaining area of the pizza
	 * If 0, this == that; if +1, this > that; if -1, this < that
	 */
	@Override
	public int compareToBySize(Object other) //compareToByAreaLeft
	{
		if (other == null || !(other instanceof Pizza)) //null check
		{
			throw new PizzaException("Object is null / not the same class");
		}
		
		Pizza that = (Pizza) other;
		return (int) (this.getRemainingArea() - that.getRemainingArea()); //+, 0, or -
	}
	
	/*
	 * Overrides the compareToByCalories method, which is the PizzaComparable interface
	 * Compares this and that for the calories of the pizza
	 * If 0, this == that; if +1, this > that; if -1, this < that
	 */
	@Override
	public int compareToByCalories(Object other)
	{
		if (other == null || !(other instanceof Pizza)) //null check
		{
			throw new PizzaException("Object is null / not the same class");
		}
		
		Pizza that = (Pizza) other;
		return this.calorie - that.calorie; // +, 0, or -
	}
}
