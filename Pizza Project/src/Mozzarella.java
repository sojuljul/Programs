/*
 * Author:		Juliano Nguyen
 * CSS162		Pizza Manager
 * 5/29/2016
 * Mozzarella class
 * Description:
 * 				This represents the Mozzarella class, which extends Cheese, the superclass
 * 				Create a constructor to initialize the description, calories, cost
 */
public class Mozzarella extends Cheese {
	
	//data items
	public static final String description = "Mozzarella";
	public static final int calorie = 250;
	public static final Money cost = new Money(1,50);
	
	/*
	 * Constructor that takes no arguments
	 * Calls the super class to initialize the data items
	 */
	public Mozzarella()
	{
		super(description, cost, calorie);
	}

}
