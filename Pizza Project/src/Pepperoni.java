/*
 * Author:		Juliano Nguyen
 * CSS162		Pizza Manager
 * 5/29/2016
 * Pepperoni class
 * Description:
 * 				This represents the Pepperoni class, which extends Meat, the superclass
 * 				Create a constructor to initialize the description, calories, cost
 */
public class Pepperoni extends Meat {
	
	//data items
	public static final String description = "Pepperoni";
	public static final int calorie = 120;
	public static final Money cost = new Money(0,85);
	
	/*
	 * Constructor that takes no arguments
	 * Calls the super class to initialize the data items
	 */
	public Pepperoni()
	{
		super(description, cost, calorie);
	}

}
