import java.io.Serializable;

/*
 * Author: 			Juliano Nguyen
 * 6/6/2016
 * CSS162			Bill Money Date
 * Date class
 * Description:		Represents the date as integers: month/day/year
 * Building getters/setters for month, day, year; restrict month to be 1-12, day to be 1-31, year to be 2014-2024
 * Build constructors, equals, toString()
 */
public class Date implements Comparable, Cloneable, Serializable {

	/*
	 * data items for Date class
	 * Month, Day, Year as int
	 */
	private int month;
	private int day;
	private int year;
	
	/*
	 * Default constructor that takes no arguments
	 * Initializes the month = 1, day = 1, and year = 2014 if not initialized by user
	 */
	public Date()
	{
		//cannot have date be null OR 0
		setMonth(1);
		setDay(1);
		setYear(2014);
	}
	
	/*
	 * Constructor that takes 3 ints as argument
	 * Initializes month, day, and year using setters
	 */
	public Date(int newMonth, int newDay, int newYear)
	{
		setMonth(newMonth);
		setDay(newDay);
		setYear(newYear);
	}
	
	/*
	 * Copy constructor that takes an Date object as argument
	 * Initializes month, day, and year of object using setters
	 */
	public Date(Date other)
	{
		if (other == null) //null check
		{
			throw new PizzaException("Object is null");
		}
		setMonth(other.getMonth());
		setDay(other.getDay());
		setYear(other.getYear());
	}
	
	/*
	 * Overrides the clone method, which is part of the Cloneable interface
	 * Returns a new Date object
	 */
	@Override
	public Object clone()
	{
		return new Date(this.month, this.day, this.year);
	}
	
	/*
	 * Overrides the compareTo method, which is part of the Comparable interface
	 * Subtract this and that date, then return the value as an int
	 * If 0, this == that; if +1, this > that; if -1, this < that
	 */
	@Override
	public int compareTo(Object other)
	{
		if (other == null || !(other instanceof Date)) //null check
		{
			throw new PizzaException("Object is null / not the same class type");
		}
		
		Date that = (Date) other;
		
		int thisDelta = this.day + 31*this.month + 12*31*this.year; //add up this in days
		int thatDelta = that.day + 31*that.month + 12*31*that.year; //add up that in days
		
		return thisDelta - thatDelta; //return the subtracted amount
	}
	
	/*
	 * Override the toString() method
	 * Return a string that prints out the month/day/year
	 */
	@Override
	public String toString()
	{
		return month + "/" + day + "/" + year;
	}
	
	/*
	 * Override the equals method
	 * Checks if object is null OR not an instance of the Date class
	 * Returns true if two dates are equal (month, day, and year are all equal)
	 */
	@Override
	public boolean equals(Object other)
	{
		if (other == null || !(other instanceof Date)) //null check
		{
			throw new PizzaException("Object is null / not the same class");
		}
		
		Date that = (Date) other;
		return (this.month == that.month && this.day == that.day && this.year == that.year);
	}
	
	/*
	 * Setter for year in Date class
	 * Takes in an int as argument and sets the year to it
	 * INVARIANT: Year should be between 2014-2024
	 */
	public void setYear(int newYear)
	{
		if (newYear >= 2014 && newYear <= 2024) //check if valid
		{
			this.year = newYear;
		}
		else
		{
			throw new PizzaException("Invalid input for year");
		}
	}
	
	/*
	 * Getter for year in Date class
	 * Returns the year as an int
	 */
	public int getYear()
	{
		return this.year;
	}
	
	/*
	 * Setter for day in Date class
	 * Takes in an int as argument and sets the day to it
	 * INVARIANT: Day should be between 1-31
	 */
	public void setDay(int newDay)
	{
		if (newDay >= 1 && newDay <= 31) //check if valid
		{
			this.day = newDay;
		}
		else
		{
			throw new PizzaException("Invalid input for day");
		}
	}
	
	/*
	 * Getter for day in Date class
	 * Returns the day as an int
	 */
	public int getDay()
	{
		return this.day;
	}
	
	/*
	 * Setter for month in Date class
	 * Takes in an int as argument and sets the month to it
	 * INVARIANT: Month should be between 1-12
	 */
	public void setMonth(int newMonth)
	{
		if (newMonth >= 1 && newMonth <= 12) //check if valid
		{
			this.month = newMonth;
		}
		else
		{
			throw new PizzaException("Invalid input for month");
		}
	}
	
	/*
	 * Getter for month in Date class
	 * Returns the month as an int
	 */
	public int getMonth()
	{
		return this.month;
	}
}
