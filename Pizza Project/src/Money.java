import java.io.Serializable;

/*
 * Author:			Juliano Nguyen
 * 6/6/2016
 * CSS162			Bill, Money, Date
 * Money class
 * Description:		Represents the USD amount in dollars and cents.
 * Building getters/setters, adding to dollars/cents, equals, toString()
 */
public class Money implements Comparable, Cloneable, Serializable {
	
	/*
	 * instance variables for Money class
	 * dollars, cents as int
	 */
	private int dollars;
	private int cents;
	
	/*
	 * Default constructor that takes no arguments
	 * Initializes dollars = 0 and cents = 0
	 */
	public Money()
	{
		setDollars(0);
		setCents(0);
	}
	
	/*
	 * Constructor that takes an int as argument
	 * Initializes dollars using a setter
	 */
	public Money(int dol)
	{
		setDollars(dol);
	}
	
	/*
	 * Constructor that takes 2 ints as argument
	 * Initializes dollars and cents using setters
	 */
	public Money(int dol, int cent)
	{
		setMoney(dol, cent);
	}
	
	/*
	 * Constructor that takes a Money object as argument
	 * Initializes dollars and cents of object using setters
	 */
	public Money(Money other)
	{
		if (other == null) //null check
		{
			throw new PizzaException("Object is null");
		}
		setMoney(other.getDollars(), other.getCents());
	}
	
	/*
	 * Overrides the clone method, which is the Cloneable interface
	 * Returns a new Money object
	 */
	@Override
	public Object clone()
	{
		return new Money(this.dollars, this.cents);
	}
	
	/*
	 * Overrides the compareTo method, which is the Comparable interface
	 * Subtracts this and that money, then returns the value as an int
	 * If 0, this == that; if +1, this > that; if -1, this < that
	 */
	@Override
	public int compareTo(Object other)
	{
		if (other == null || !(other instanceof Money)) //null check
		{
			throw new PizzaException("Object is null / not the same class type");
		}
		
		Money that = (Money) other;
		double retVal = this.getMoney()*100 - that.getMoney()*100; //subtract this - that of their money
		
		if (retVal == 0) //if this - that == 0, return 0
		{
			return 0;
		}
		else if (retVal > 0) //if this - that > 0, return +1
		{
			return 1;
		}
		else //otherwise this - that < 0, return -1
		{
			return -1;
		}
	}
	
	/*
	 * Overrides the toString() method
	 * Returns a string that prints out the value of the money
	 */
	@Override
	public String toString()
	{
		if (cents < 10) //print a 0 before the cents, ie 0.01 where cents = 1
		{
			return "$" + this.dollars + ".0" + this.cents;
		}
		else
		{
			return "$" + this.dollars + "." + this.cents;
		}
	}
		
	/*
	 * Overrides the equals method
	 * Checks if object is null OR not an instance of the Money class
	 * Returns true if both money are equal (dollars and cents are equal)
	 */
	@Override
	public boolean equals(Object other)
	{
		if (other == null || !(other instanceof Money)) //null check
		{
			throw new PizzaException("Object is null / not same class type");
		}
		
		Money that = (Money) other;
		return (this.dollars == that.dollars && this.cents == that.cents);
	}
	
	/*
	 * Takes a Money object as argument
	 * Adds to dollars and cents from Money object
	 */
	public void add(Money other)
	{
		setDollars(dollars += other.getDollars());
		setCents(cents += other.getCents());
	}
	
	/*
	 * Takes 2 ints as argument
	 * Adds ints to dollars and cents respectively
	 */
	public void add(int newDol, int newCent)
	{
		setDollars(dollars += newDol);
		setCents(cents += newCent);
	}
	
	/*
	 * Takes an int as argument
	 * Adds that int to dollars
	 */
	public void add(int newDol)
	{
		setDollars(dollars += newDol);
	}
	
	/*
	 * Setter for money in Money class
	 * Takes in 2 ints as argument and initializes it to dollars and cents respectively
	 */
	public void setMoney(int newDol, int newCent)
	{
		setDollars(newDol);
		setCents(newCent);
	}
	
	/*
	 * Getter for money in Money class
	 * Returns the money as a double, ie 5.25
	 */
	public double getMoney()
	{
		double newCents = (double) cents / 100; //separate cents and divide by 100
		return (double) dollars + newCents; //add cents to dollars to get a Money value
	}
	
	/*
	 * Setter for cents in Money class
	 * Takes an int as argument and sets cents to it
	 * INVARIANT: Cents should be between 0 - 99 && never be < 0
	 */
	public void setCents(int newCent)
	{
		if (newCent >= 0 && newCent <= 99) //check if in between 0 and 99
		{
			this.cents = newCent;
		}
		else if (newCent > 99) //check if greater than 99
		{
			this.cents = newCent%100; //cents is the remainder after dividing by 100
			this.dollars += newCent/100; //add 1 to dollar
		}
		else
		{
			throw new PizzaException("Invalid input for cents");
		}
	}
	
	/*
	 * Getter for cents in Money class
	 * Returns the cents as an int
	 */
	public int getCents()
	{
		return this.cents;
	}
	
	/*
	 * Setter for dollars in Money class
	 * Takes in an int as argument and sets dollars to it
	 * INVARIANT: Dollars should never be < 0
	 */
	public void setDollars(int newDollars)
	{
		if (newDollars < 0) //check if valid
		{
			throw new PizzaException("Invalid input for dollars");
		}
		else
		{
			this.dollars = newDollars;
		}
	}
	
	/*
	 * Getter for dollars in Money class
	 * Returns the dollars as an int
	 */
	public int getDollars()
	{
		return this.dollars;
	}

}
