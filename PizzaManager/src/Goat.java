/*
 * Author:		Juliano Nguyen
 * CSS162		Pizza Manager
 * 5/29/2016
 * Goat class
 * Description:
 * 				This represents the Goat class, which extends Cheese, the superclass
 * 				Create a constructor to initialize the description, calories, cost			
 */
public class Goat extends Cheese {
	
	//data items
	public static final String description = "Goat";
	public static final int calorie = 300;
	public static final Money cost = new Money(2,25);
	
	/*
	 * Constructor that takes no arguments
	 * Calls the super class to initialize the data items
	 */
	public Goat()
	{
		super(description, cost, calorie);
	}

}
