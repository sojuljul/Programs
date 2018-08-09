/*
 * Author:		Juliano Nguyen
 * CSS162		Pizza Manager
 * 5/29/2016
 * Ingredient class
 * Description:
 * 				Keeps track of the description, cost, and calories
 * 				Create methods such as getter/setter for description, cost, calorie
 * 				Create a toString, compareTo for the cost, constructor that takes in a description, cost, calorie
 */
public class Ingredient implements Comparable {

	//data items
	private String description;
	private Money cost;
	private int calorie;
	
	/*
	 * Constructor that takes 3 arguments
	 * Initializes the respective data items in this class
	 */
	public Ingredient(String newDescription, Money newCost, int newCalorie)
	{
		setDescription(newDescription);
		setCost(newCost);
		setCalorie(newCalorie);
	}
	
	/*
	 * Overrides the toString method
	 * Returns a string that prints out the description, cost, and calorie
	 */
	@Override
	public String toString()
	{
		return description + ", Cost: " + cost + ", Calories: " + calorie;
	}
	
	/*
	 * Getter for cost
	 * Returns a new Money object of the cost
	 */
	public Money getCost()
	{
		return new Money(cost);
	}
	
	/*
	 * Setter for cost
	 * Takes in a Money object as argument and sets it to the cost
	 */
	public void setCost(Money newCost)
	{
		if (newCost == null) //null check
		{
			throw new PizzaException("Object is null");
		}
		this.cost = new Money(newCost);
	}
	
	/*
	 * Getter for description
	 * Returns the value as a String
	 */
	public String getDescription()
	{
		return this.description;
	}
	
	/*
	 * Setter for description
	 * Takes in a string as argument and sets it to description
	 */
	public void setDescription(String newDescription)
	{
		if (newDescription == null) //check if null
		{
			throw new PizzaException("Invalid string input");
		}
		this.description = newDescription;
	}
	
	/*
	 * Getter for calorie
	 * Returns the value as an int
	 */
	public int getCalorie()
	{
		return this.calorie;
	}
	
	/*
	 * Setter for calorie
	 * Takes in an int as argument and sets it to calorie
	 */
	public void setCalorie(int newCalorie)
	{
		if (newCalorie < 0) //check if valid
		{
			throw new PizzaException("Invalid calorie input");
		}
		calorie = newCalorie;
	}
	
	/*
	 * Overrides equals method
	 * Returns true if the description, cost, and calorie are all equal
	 * Otherwise, returns false
	 */
	@Override
	public boolean equals(Object other)
	{
		if (other == null || !(other instanceof Ingredient)) //null check
		{
			throw new PizzaException("Object is null / not the same class");
		}
		
		Ingredient that = (Ingredient) other;
		return this.description == that.description && this.calorie == that.calorie && this.cost.equals(that.cost); //check if equal to description, cost, calorie
	}
	
	/*
	 * Overrides compareTo method, which is the Comparable interface
	 * It will compare the cost, so use Money's compareTo method
	 * If 0, this == that; if +1, this > that; if -1, this < that
	 */
	@Override
	public int compareTo(Object other)
	{
		if (other == null || !(other instanceof Ingredient)) //null check
		{
			throw new PizzaException("Object is null / not the same class");
		}
		
		Ingredient that = (Ingredient) other;
		
		return this.cost.compareTo(that.cost); //calls the compareTo method from Money class
	}
}
