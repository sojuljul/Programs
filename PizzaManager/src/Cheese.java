/*
 * Author:		Juliano Nguyen
 * CSS162		Pizza Manager
 * 5/29/2016
 * Cheese class
 * Description:
 * 				This represents the Cheese class, which extends Ingredient, the superclass
 * 				Create a constructor that takes in the description, calories, cost
 */
public class Cheese extends Ingredient {
	
	/*
	 * Constructor that takes 3 arguments
	 * Calls the super class to initialize the respective items
	 */
	public Cheese(String description, Money cost, int calorie)
	{
		super(description, cost, calorie);
	}
	
	/*
	 * main that tests the Cheese class
	 */
	public static void main(String[] args)
	{
		Money testCost = new Money(1, 50);
		Cheese testOne = new Cheese("Mozzarella", testCost, 50);
		
		System.out.println(testOne.toString());
	}

}
