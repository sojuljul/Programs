/*
 * Author:		Juliano Nguyen
 * CSS162		Pizza Manager
 * 5/29/2016
 * Marinara class
 * Description:
 * 				This represents the Marinara class, which extends Base, the superclass
 * 				Create a constructor to initialize the description, calories, cost
 */
public class Marinara extends Base {

	//data items
	public static final String description = "Marinara";
	public static final int calorie = 100;
	public static final Money cost = new Money(1,0);
	
	/*
	 * Constructor that takes no arguments
	 * Calls the super class to initialize the data items
	 */
	public Marinara()
	{
		super(description, cost, calorie);
	}
}
