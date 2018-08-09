/*
 * Author:		Juliano Nguyen
 * CSS162		Pizza Manager
 * 5/29/2016
 * Alfredo class
 * Description:
 * 				This represents the Alfredo class, which extends Base, the superclass
 * 				Create a constructor to initialize the description, calories, cost
 */
public class Alfredo extends Base {
	
	//data items
	public static final String description = "Alfredo";
	public static final int calorie = 125;
	public static final Money cost = new Money(1,50);
	
	/*
	 * Constructor that takes no arguments
	 * Calls the super class to initialize the data items
	 */
	public Alfredo()
	{
		super(description, cost, calorie);
	}

}
