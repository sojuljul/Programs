/*
 * Author:		Juliano Nguyen
 * CSS162		Pizza Manager
 * 5/29/2016
 * Base class
 * Description:
 * 				This represents the Base class, which extends Ingredient, the super class
 * 				Create a constructor that takes in the description, calories, cost
 */
public class Base extends Ingredient {

	/*
	 * Constructor that takes 3 arguments
	 * Calls the super class to initialize the respective items
	 */
	public Base(String description, Money cost, int calorie)
	{
		super(description, cost, calorie);
	}
	
	/*
	 * main that tests the Base class
	 */
	public static void main(String[] args)
	{
		Money testCost = new Money(1, 50);
		Base testOne = new Base("Marinara", testCost, 50);
		
		System.out.println(testOne.toString());
	}
}
