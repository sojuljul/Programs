import java.awt.Color;

/*
 * Author:		Juliano Nguyen
 * CSS162		Pizza Manager
 * 5/29/2016
 * Olive class
 * Description:
 * 				This represents the Olive class, which extends Vegetable, the superclass
 * 				Create a constructor to initialize the description, calories, cost, color
 */
public class Olive extends Vegetable {
	
	//data items
	public static final String description = "Olive";
	public static final int calorie = 25;
	public static final Money cost = new Money(0, 50);
	
	/*
	 * Constructor that takes Color as argument
	 * Calls the super class to initialize the data items
	 */
	public Olive(Color newColor)
	{
		super(description, cost, calorie, newColor);
	}
}
