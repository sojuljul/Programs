import java.awt.Color;

/*
 * Author:		Juliano Nguyen
 * CSS162		Pizza Manager
 * 5/29/2016
 * Pepper class
 * Description:
 * 				This represents the Pepper class, which extends Vegetable, the superclass
 * 				Create a constructor to initialize the description, calories, cost, color
 */
public class Pepper extends Vegetable {

	//data items
	public static final String description = "Pepper";
	public static final int calorie = 50;
	public static final Money cost = new Money(0,75);
	
	/*
	 * Constructor that takes Color as argument
	 * Calls the super class to initialize the data items
	 */
	public Pepper(Color newColor)
	{
		super(description, cost, calorie, newColor);
	}
}
