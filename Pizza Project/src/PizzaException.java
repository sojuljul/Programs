/*
 * Author:		Juliano Nguyen
 * CSS162		Pizza Manager
 * 5/29/2016
 * PizzaException class
 * Description:
 * 				Throws an exception in place of RuntimeException for pizza manager
 * 				Create an empty constructor and a constructor that takes a String
 */
public class PizzaException extends RuntimeException {
	
	/*
	 * Constructor that takes no arguments
	 * Prints out a unique error message to the console
	 */
	public PizzaException()
	{
		super("An error occurred in Pizza");
	}
	
	/*
	 * Constructor that takes a String argument
	 * Prints out the given String message to the console
	 */
	public PizzaException(String message)
	{
		super(message);
	}

}
