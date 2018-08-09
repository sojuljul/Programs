import java.awt.Color;

/*
 * Author:		Juliano Nguyen
 * CSS162		Pizza Manager
 * 5/29/2016
 * Vegetable class
 * Description:
 * 				This represents the Vegetable class, which extends Ingredient, the superclass
 * 				Create a constructor that takes in the description, calories, cost
 * 				Another constructor that is the same as above, but with color
 */
public class Vegetable extends Ingredient {

	//data items
	private Color myColor;
	
	/*
	 * main that tests the Vegetable class
	 */
	public static void main(String[] args)
	{
	    Money testCost = new Money(1,5);
	    Color testColor = new Color(255,0,0);
	    Vegetable testOne = new Vegetable("Pepper", testCost, 30, testColor);
	    Vegetable testTwo = new Vegetable("Pepper", testCost, 30, testColor);
	    
	    System.out.println(testOne.toString());
	    System.out.println(testOne.equals(testTwo));
	}
	
	/*
	 * Constructor that takes 3 arguments
	 * Calls the super class to initialize the variables in the super class
	 */
	public Vegetable(String newDescription, Money newCost, int newCalorie)
	{
		super(newDescription, newCost, newCalorie);
	}
	
	/*
	 * Constructor that takes 4 arguments
	 * Calls the super class to initialize the variables in the super class, and sets the color
	 */
	public Vegetable(String newDescription, Money newCost, int newCalorie, Color newColor)
	{
		super(newDescription, newCost, newCalorie);
		setColor(newColor);
	}
	
	/*
	 * Overrides the toString method
	 * Returns the value as a string to print the color and the super class toString
	 */
	@Override
	public String toString()
	{
		return "Color: " + myColor.toString() + ", " + super.toString();
	}
	
	/*
	 * Overrides the equals method
	 * Returns true if colors are equal and if the super class equals is true
	 * Otherwise, return false
	 */
	@Override
	public boolean equals(Object other)
	{
		if (other == null || !(other instanceof Vegetable)) //null check
		{
			throw new PizzaException("Object is null / not the same class");
		}
		
		Vegetable that = (Vegetable) other;
		
		return this.myColor == that.myColor && super.equals(other);
	}
	
	/*
	 * Getter for color
	 * Returns the value as a Color
	 */
	public Color getColor()
	{
		return this.myColor;
	}
	
	/*
	 * Setter for color
	 * Takes in a Color object and sets it to the color
	 */
	public void setColor(Color newColor)
	{
		if (newColor == null) //null check
		{
			throw new PizzaException("Color cannot be null");
		}
		this.myColor = newColor;
	}
}
