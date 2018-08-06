/*
 * Author:		Juliano Nguyen
 * CSS162		Pizza Manager
 * 5/29/2016
 * Meat class
 * Description:
 * 				This represents the Meat class, which extends Ingredient, the superclass
 * 				Create a constructor that takes in the description, calories, cost	
 */
public class Meat extends Ingredient {
	
	/*
	 * Constructor that takes 3 arguments
	 * Calls the super class to initialize the respective items
	 */
	public Meat(String description, Money cost, int calorie)
	{
		super(description, cost, calorie);
	}
	
	/*
	 * main that tests the Meat class
	 */
	public static void main(String[] args)
	{
		Money testCost = new Money(1, 50);
		Meat testOne = new Meat("Pepperoni", testCost, 50);
		
		System.out.println(testOne.toString());
	}

}
