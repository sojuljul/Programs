//package pizzaMainClasses;
/* 
 * CSS 161, Pizza Manager Project
 * 
 * This interface can do everything the Comparable interface can and more
 * 
 * Author: Rob Nash
 */

/*
 * Author:		Juliano Nguyen
 * CSS162		Pizza Manager
 * 5/29/2016
 * PizzaComparable class
 * Description:
 * 				An interface that has specific methods to be created when impleted in another class
 * 				compareTo methods for the price, size, and calorie of the pizza
 */
public interface PizzaComparable extends Comparable {  //Example of interface inheritance
	
	@Override
	public int compareTo(Object other); 	 		//a.k.a compareToByPrice
	//non-overrides
	public int compareToBySize(Object o); 		//a.k.a. compareToByAreaLeft
	public int compareToByCalories(Object o);	
	
}