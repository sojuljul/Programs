/*
 * Author:		Juliano Nguyen
 * CSS162		Pizza Manager
 * 5/29/2016
 * Sausage class
 * Description:
 * 				This represents the Sausage class, which extends Meat, the superclass
 * 				Create a constructor to initialize the description, calories, cost
 */
public class Sausage extends Meat {
	
	//data items
	public static final String description = "Sausage";
	public static final int calorie = 110;
	public static final Money cost = new Money(0, 85);
	
	/*
	 * Constructor that takes no arguments
	 * Calls the super class to initialize the data items
	 */
	public Sausage()
	{
		super(description, cost, calorie);
	}

}
