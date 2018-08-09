//package pizzaMainClasses;
import java.util.Scanner;

/*  PizzaManager Skeleton File
 *  CSS 161, Final Project
 * 
 * 	This class is a starting point for your final project and is incomplete.
 *  Start by reading the documentation(comments), and then the code.  Find the 
 *  empty stub methods you are to fill in using a Top-Down approach (see the
 *  assignment for more information on this and Stepwise Refinement)
 * 
 *  Author: Rob Nash
 */


/*
 * Author:		Juliano Nguyen
 * CSS162		Pizza Manager
 * 5/29/2016
 * PizzaManager class
 * Description:
 * 				Manages the pizza for the user to use and interact.
 * 				Allows user to add pizzas, eat some pizzas, sort it by price, size, or calories
 * 				Binary search a specific calorie in the list
 * 				Reverses the ordering of the pizza in the list
 * 				Displays all the information for each pizza
 * 
 */
public class PizzaManager {
	/*
	 *  TODO: Data definitions here.  
	 */
	private ArrayList<Pizza> pizzaData = new ArrayList<Pizza>(); //list of pizzas
	
	
	/* 
	 * The console interface is defined in the start method 
	 * You can exit or extend the code below to accomplish all of 
	 * the outcomes defined in the homework document
	 */
	public void start() {
		char selection='q'; //declare a char variable
		
		Scanner foo = new Scanner(System.in); //scanner to have user input something
		
		while(true) {
			displayAllPizzas(); //calls method to display all info of each pizza
			displayInstructions(); //calls methods to display instructions for user to do
			
			
			 //foo.nextChar() doesn't exist, so now what?
			selection = foo.next().charAt(0); //gets the first char of the user input
			
			switch(selection) {
				case	'A':    
				case	'a':	System.out.println("Adding a random pizza to the ArrayList<Pizza>.");
								//todo:
								addRandomPizza(); //add a random pizza
								break;
				case	'H':    
				case	'h':	System.out.println("Adding one hundred random pizzas to the ArrayList<Pizza>.");
								//todo:
								for (int i = 0; i < 100; i++) //add 100 random pizzas
								{
									addRandomPizza();
								}
								break;					
				case	'E':    
				case	'e':	System.out.println("Eating a fraction of a pizza. How much? (a/b)");
								//todo:pizza eating code here
								Scanner keyboard = new Scanner(System.in);
								eatSomePizza(keyboard); //call method to subtract amount from remaining pizza
								break;			
				case	'P':    
				case	'p': 	System.out.println("QuickSorting pizzas by (P)rice");
								//todo:
								quickSortByPrice(); //call method to sort the list by price
							  	break;	
				case	'S':    
				case	's': 	System.out.println("QuickSorting pizzas by (S)ize");
							 	//todo:
								quickSortBySize(); //call method to sort the list by size
							 	break;		  
				case	'C':    
				case	'c':  	System.out.println("QuickSorting pizzas by (C)alories");
							  	//todo
								quickSortByCalories(); //call method to sort the list by calories
							  	break;
				case	'B':
				case	'b':	System.out.println("(B)inary search over pizzas by calories(int).  QuickSorting first. What calorie count are you looking for?");
								//todo:
								quickSortByCalories(); //sort by calories first
								Scanner keyboardTwo = new Scanner(System.in);
								int number = keyboardTwo.nextInt(); //what calorie input to search for
								int numberIndex = binarySearchByCalories(number); //call method to binary search our target
								System.out.println("A pizza with the same calories is at index: " + numberIndex);
								break;
				case    'R':
				case 	'r':	System.out.println("(R)everse order of Pizzas with a Stack" );
								//todo:
								reverseData(pizzaData); //reverse the ordering of our pizza
								break;

				case    'Q':
				case 	'q':	System.out.println("(Q)uitting!" );
								//todo:
								System.exit(0); //exit the program
								break;
								
				default:	System.out.println("Unrecognized input - try again"); //if any other input, have user try again
			}
		}
	}

	/*
	 * The user is asked how much pizza they want to eat in fraction form (a/b)
	 * Takes in a scanner as argument
	 * Calls the eatSomePizza method from the Pizza class to subtract the amount
	 */
	private void eatSomePizza(Scanner keys) {
		//todo:
		if (pizzaData.size() == 0) //check if list is empty
		{
			throw new PizzaException("List is empty");
		}
		
		String line = keys.nextLine(); //fraction as a string (a/b)

		String[] fractSplit = line.split("/"); //split the given string at "/"

		if (fractSplit.length == 1) //check if only 1 thing in the array; user did not input a/b
		{
			throw new PizzaException("Invalid input. Not in the form a/b");
		}
		
		int num = Integer.parseInt(fractSplit[0]); //numerator: a
		int denom = Integer.parseInt(fractSplit[1]); //denominator: b

		Fraction retVal = new Fraction(num, denom); //new reduced fraction

		System.out.println("Enter index of pizza to eat: ");
		int index = keys.nextInt(); //the index the user wants to eat the pizza
		
		if (index < 0 || index > pizzaData.size() - 1) //check if valid index
		{
			throw new PizzaException("Index is out of bounds");
		}

		try
		{
			pizzaData.get(index).eatSomePizza(retVal); //call eatSomePizza method to subtract the remaining fraction
		}
		catch(PizzaException message)
		{
			if(message.getMessage().equalsIgnoreCase("Pizza is all gone")) //check is message is equal to this, which means difference of fractions is 0
			{
				System.out.println(message.getMessage());
				pizzaData.remove(index); //remove from list if input is equal to the remaining
			}
			else
			{
				throw new PizzaException(message.getMessage()); //otherwise, throw the error message
			}
		}
	}
	
	/*
	 * Adds a random pizza to the list of pizzas
	 * Uses the array list add method to add a random pizza with random ingredients
	 */
	private void addRandomPizza() {
		//todo:
		pizzaData.add(new Pizza()); //adds a random pizza with random ingredients
	}

	/*
	 * Prints out the data of all the pizzas in the list
	 * Displays all the info, such as toppings, price, calories, fraction remains, shape
	 */
	private void displayAllPizzas() {
		//todo:
		for (int index = 0; index < pizzaData.size(); index++) //loop through the list of the pizzas
		{
			System.out.println(index + ") " + pizzaData.get(index)); //prints out the pizza info on each line
		}
	}

	/*
	 * Sort the list of pizzas by price in a quick sort algorithm
	 * Sorts the list from lowest to highest
	 */
	private void quickSortByPrice() {  
		//todo:
		if (pizzaData.size() == 0) //check if list is empty
		{
			throw new PizzaException("List is empty");
		}
		sortPrice(pizzaData, 0, pizzaData.size() - 1); //calls method to sort the list
	}
	
	/*
	 * Sort the list of pizzas by price
	 * Selects a pivot point and recursively calls itself to sort the list
	 * Check for null or bad index
	 */
	private void sortPrice(ArrayList<Pizza> data, int first, int last)
	{
		if (data == null) //null check
		{
			throw new PizzaException("List is null");
		}
		if (first < 0 || last < 0) //check if valid indices
		{
			throw new PizzaException("Invalid start/end index");
		}
		
		int pivot = pivotPrice(data, first, last); //select a pivot point
		
		if (first < pivot - 1) //if start index is less than our pivot
		{
			sortPrice(data, first, pivot - 1); //sort left side of the pivot point
		}
		if(last > pivot) //if end index is bigger than our pivot
		{
			sortPrice(data, pivot, last); //sort right side of the pivot point
		}
	}
	
	/*
	 * Chooses a pivot point in the array (middle element)
	 * Left of the pivot point (lower half) with new index for low/high (values < pivot)
	 * Right of the pivot point (upper half) with new index for low/high (values >= pivot)
	 */
	public int pivotPrice(ArrayList<Pizza> data, int first, int last)
	{
		if (data == null) //null check
		{
			throw new PizzaException("List is null");
		}
		
		int middle = (first + last) / 2; //middle index
		Pizza pivot = data.get(middle); //data at the middle index
		
		int low = first; //first index
		int high = last; //last index
		
		while (low <= high) //loop while low index <= high index
		{
			while (data.get(low).compareTo(pivot) > 0) //values left of the pivot point
			{
				low++;
			}
			
			while (data.get(high).compareTo(pivot) < 0) //values right of the pivot point
			{
				high--;
			}
			
			if (low <= high)
			{
				data.swap(low,  high); //swap the two data values if values at low <= high
				low++;
				high--;
			}
			
		}
		
		return low; //return the selected pivot
	}
	
	/*
	 * Sort the list of pizzas by size in a quick sort algorithm
	 * Sorts the list from lowest to highest
	 */
	private void quickSortBySize() {
		//todo:
		if (pizzaData.size() == 0) //check if list is empty
		{
			throw new PizzaException("List is empty");
		}
		sortSize(pizzaData, 0, pizzaData.size() - 1); //calls method to sort the list
	}
	
	/*
	 * Sort the list of pizzas by size
	 * Selects a pivot point and recursively calls itself to sort the list
	 * Check for null or bad index
	 */
	private void sortSize(ArrayList<Pizza> data, int first, int last)
	{
		if (data == null) //null check
		{
			throw new PizzaException("List is null");
		}
		if (first < 0 || last < 0) //check if valid indices
		{
			throw new PizzaException("Invalid start/end index");
		}
		
		int pivot = pivotSize(data, first, last); //select a pivot point
		
		if (first < pivot - 1) //if start index is less than our pivot
		{
			sortSize(data, first, pivot - 1); //sort left side of the pivot point
		}
		if(last > pivot) //if end index is bigger than our pivot
		{
			sortSize(data, pivot, last); //sort right side of the pivot point
		}
	}
	
	/*
	 * Chooses a pivot point in the array (middle element)
	 * Left of the pivot point (lower half) with new index for low/high (values < pivot)
	 * Right of the pivot point (upper half) with new index for low/high (values >= pivot)
	 */
	public int pivotSize(ArrayList<Pizza> data, int first, int last)
	{
		if (data == null) //null check
		{
			throw new PizzaException("List is null");
		}
		
		int middle = (first + last) / 2; //middle index
		Pizza pivot = data.get(middle); //data at the middle index
		
		int low = first; //first index
		int high = last; //last index
		
		while (low <= high) //loop while low index <= high index
		{
			while (data.get(low).compareToBySize(pivot) < 0) //values left of the pivot point
			{
				low++;
			}
			
			while (data.get(high).compareToBySize(pivot) > 0) //values right of the pivot point
			{
				high--;
			}
			
			if (low <= high)
			{
				data.swap(low,  high); //swap the two data values if values at low <= high
				low++;
				high--;
			}
			
		}
		
		return low; //return the selected pivot
	}
	
	
	/*
	 * Sort the list of pizzas by calories in a quick sort algorithm
	 * Sorts the list from lowest to highest
	 */
	private void quickSortByCalories() {
		//todo:
		if (pizzaData.size() == 0) //check if list is empty
		{
			throw new PizzaException("List is empty");
		}
		sortCalories(pizzaData, 0, pizzaData.size() - 1); //calls method to sort the list
	}
	
	/*
	 * Sort the list of pizzas by calories
	 * Selects a pivot point and recursively calls itself to sort the list
	 * Check for null or bad index
	 */
	private void sortCalories(ArrayList<Pizza> data, int first, int last)
	{
		if (data == null) //null check
		{
			throw new PizzaException("List is null");
		}
		if (first < 0 || last < 0) //check if valid indices
		{
			throw new PizzaException("Invalid start/end index");
		}
		
		int pivot = pivotCalories(data, first, last); //select a pivot point
		
		if (first < pivot - 1) //if start index is less than our pivot
		{
			sortCalories(data, first, pivot - 1); //sort left side of the pivot point
		}
		if(last > pivot) //if end index is bigger than our pivot
		{
			sortCalories(data, pivot, last); //sort right side of the pivot point
		}
	}
	
	/*
	 * Sort the calories from lowest to highest
	 * Chooses a pivot point in the array (middle element)
	 * Left of the pivot point (lower half) with new index for low/high (values < pivot)
	 * Right of the pivot point (upper half) with new index for low/high (values >= pivot)
	 */
	public int pivotCalories(ArrayList<Pizza> data, int first, int last)
	{
		if (data == null) //null check
		{
			throw new PizzaException("List is null");
		}
		
		int middle = (first + last) / 2; //middle index
		Pizza pivot = data.get(middle); //data at the middle index
		
		int low = first; //first index
		int high = last; //last index
		
		while (low <= high) //loop while low index <= high index
		{
			while (data.get(low).compareToByCalories(pivot) < 0) //values left of the pivot point
			{
				low++;
			}
			
			while (data.get(high).compareToByCalories(pivot) > 0) //values right of the pivot point
			{
				high--;
			}
			
			if (low <= high)
			{
				data.swap(low,  high); //swap the two data values if values at low <= high
				low++;
				high--;
			}
			
		}
		
		return low; //return the selected pivot
	}
	
	/*
	 * Searches for a specific calorie target in a binary search alogrithm
	 * Returns the index of where the target is located
	 * Otherwise, returns -1 if target was not found
	 */
	private int binarySearchByCalories(int cals) {
		//todo:
		int low = 0; //low index
		int high = pizzaData.size() - 1; //high index
		
		while (low <= high) //loop while low index is <= high index
		{
			int mid = (low + high) / 2; //mid index is the (low+high) / 2
			
			if (pizzaData.get(mid).getCalories() == cals) //if data at mid index is equal to our target
			{
				return mid; //return the mid index
			}
			else if (pizzaData.get(mid).getCalories() < cals) //if data at mid index is less than our target
			{
				low = mid + 1; //search in the upper half, low = mid + 1
			}
			else
			{
				high = mid - 1; //otherwise in the lower half, high = mid - 1
			}
		}
		
		return -1; //if not found
	}
	
	/*
	 * Returns the reverse data in an ArrayList
	 * Creates a temporary variable to add all of the data from the end
	 * Uses a stack to reverse the data by popping it from the end
	 */
	public void reverseData(ArrayList<Pizza> in)
	{
		Stack<Pizza> reverse = new Stack<Pizza>(); //new stack list
		
		if (in == null) //null check
		{
			throw new PizzaException("Cannot have null list");
		}
		
		if (pizzaData.size() == 0) //check if list is empty
		{
			throw new PizzaException("List is empty");
		}
		
		while(!pizzaData.isEmpty()) //while the list is not empty
		{
			Pizza pizzaItem = (Pizza) pizzaData.remove(0); //remove it from the beginning
			reverse.push(pizzaItem); //push it to the stack at the beginning
		} //pizzaData is now empty
		
		while(!reverse.isEmpty()) //while the reverse list is not empty
		{
			Pizza pizzaItem = (Pizza) reverse.pop(); //pop it from the end
			pizzaData.add(pizzaItem); //add it to the list
		} //pizzaData is now in reverse order
	}
	
	/*
	 * No need to edit functions below this line, unless extending the menu or
	 * changing the instructions
	 */
	private static final String instructions = "-----------------------\nWelcome to PizzaManager\n-----------------------\n(A)dd a random pizza\nAdd a (H)undred random pizzas\n(E)at a fraction of a pizza\nQuickSort pizzas by (P)rice\nQuickSort pizzas by (S)ize\nQuickSort pizzas by (C)alories\n(B)inary Search pizzas by calories\n(R)everse order of pizzas with a stack\n(Q)uit\n";
	private void displayInstructions() {
		System.out.println(instructions);	
	}
	/*
	 * Notice the one-line main function.
	 */
	public static void main(String[] args) {
		new PizzaManager().start();
	}
}