import java.io.Serializable;

/*
 * Author:			Juliano Nguyen
 * 5/29/2016
 * CSS162			Pizza Manager
 * Fraction class
 * Description:		
 * 					Represents the ratio of the two numbers, numerator and denominator, for the fraction.
 * 					Reduces the fraction using Greatest Common Divisor, and checks for cases such as denominator == 0, numerator == 0, etc.
 */

public class Fraction implements Comparable, Cloneable, Serializable {
	
	//data items
	private final int num; //numerator
	private final int denom; //denominator
	
	/*
	 * Constructor that takes no arguments
	 * Initializes the numerator, denominator to 1 as default
	 */
	public Fraction()
	{
		this.num = 1;
		this.denom = 1;
	}
	
	/*
	 * Constructor that takes 2 arguments
	 * Finds the GCD of the numerator/denominator and reduces the numerator/denominator
	 * CASES: if denom is 0, throw an exception
	 */
	public Fraction(int newNum, int newDenom)
	{	
		if (newDenom == 0) //check if denom is 0
		{
			throw new PizzaException("Cannot have denominator be 0");
		}
		if (newNum < 0 || newDenom < 0) //check if negative
		{
			throw new PizzaException("Cannot have negative values");
		}

		int divisor = gcd(newNum, newDenom);
		this.num = newNum / divisor;
		this.denom = newDenom / divisor;
	}
	
	/*
	 * Copy constructor that takes in an object of the same class
	 * Finds the the GCD of the numerator/denominator and reduces them
	 */
	public Fraction(Fraction other)
	{
		if (other == null) //null check
		{
			throw new PizzaException("Object is null");
		}
		
		int divisor = gcd(other.num, other.denom);
		this.num = other.getNumerator() / divisor;
		this.denom = other.getDenominator() / divisor;
	}
	
	/*
	 * Overrides the clone method, which is part of the Cloneable interface
	 * Returns a new Fraction object
	 */
	@Override
	public Object clone()
	{
		return new Fraction(this);
	}
	
	/*
	 * Overrides the compareTo method, which is part of the Comparable interface
	 * Subtract this and that fraction, then return the value as an int
	 * If 0, this == that; if +1, this > that; if -1, this < that
	 */
	@Override
	public int compareTo(Object other)
	{
		if (other == null || !(other instanceof Fraction)) //null check
		{
			throw new PizzaException("Object is null / not of the same class type");
		}
		
		Fraction that = (Fraction) other;
		double thisDelta = (double) this.num / this.denom;
		double thatDelta = (double) that.num / that.denom;
		
		return (int) (thisDelta*100 - thatDelta*100);
	}
	
	/*
	 * Subtracts two fractions
	 * Takes in a Fraction object as argument
	 * Find the common denominator, cross multiply to get the numerators, subtract the numerators, then get a new fraction
	 */
	public Fraction subtract(Fraction newFraction)
	{
		if (newFraction == null) //check if null
		{
			throw new PizzaException("Object is null");
		}
		
		Fraction retVal;
		
		if (this.getDenominator() == newFraction.getDenominator()) //if denoms are the same
		{
			int difference = this.getNumerator() - newFraction.getNumerator(); //subtract the numerators
			
			if (difference < 0) //check if difference is negative
			{
				throw new PizzaException("The remaining result will be negative");
			}
			
			retVal = new Fraction(difference, this.denom); //set to a new fraction of the num and denom
		}
		else
		{
			int tempDenom = this.getDenominator() * newFraction.getDenominator(); //multiply denoms to get a common denom
			int tempNum1 = this.getNumerator() * newFraction.getDenominator(); //first fract numerator
			int tempNum2 = newFraction.getNumerator() * this.getDenominator(); //second fract numerator
			
			int difference = tempNum1 - tempNum2; //subtract the numerators
			
			if (difference < 0) //check if difference is negative
			{
				throw new PizzaException("The remaining result will be negative");
			}
			
			retVal = new Fraction(difference, tempDenom); //set to a new fraction of the num and denom
		}
		
		return retVal;
	}
	
	/*
	 * Reduces a fraction by finding the Greatest Common Divisor
	 * If the numerator and denominator have the same divisor, then return that divisor
	 */
	public int gcd(int num, int denom)
	{
		int number = 1;
		if (denom > num) //checks if denom is bigger than num
		{
			number = denom;
		}
		else
		{
			number = num;
		}
		
		for (int divisor = number; divisor > 0; divisor--)
		{
			//if both num and denom are divisible by the divisor
			if (num % divisor == 0 && denom % divisor == 0)
			{
				return divisor;
			}
		}
		
		return 1; //returns 1 if cannot find GCD
	}
	
	/*
	 * Returns the value of the fraction as a double
	 * Numerator divided by the denominator to get the value
	 */
	public double getDouble()
	{
		double newNum = (double) this.num;
		double newDenom = (double) this.denom;
		return newNum / newDenom; //return the double value of num divided by denom
	}
	
	/*
	 * Returns true if both fractions are equal in numerator/denominator
	 * Otherwise, returns false
	 * If both fractions have same numerator and denominator, 1/2 = 1/2
	 * If 1/2 and 2/4, then cross multiply and see if equal: a/b = c/d  -> ad = bc
	 */
	@Override
	public boolean equals(Object other)
	{		
		boolean retVal = false;
		
		if(other == null || !(other instanceof Fraction)) //null check
		{
			throw new PizzaException("Object is null / not of the same class");
		}
		
		Fraction that = (Fraction) other;
		
		if (this.num * that.getDenominator() == that.getNumerator() * this.denom) //cross multiply and check if equal
		{
			retVal = true;
		}
		
		return retVal;
	}
	
	/*
	 * Override the toString method
	 * Returns a string value to print out the numerator / denominator
	 */
	@Override
	public String toString()
	{
		if (this.num == this.denom) //if num and denom are the same, print "1"
		{
			return "1";
		}
		return this.num + "/" + this.denom; //prints a/b
	}
	
	/*
	 * Getter for denominator
	 * Returns the value as an int
	 */
	public int getDenominator()
	{
		return this.denom;
	}
	
	/*
	 * Getter for numerator
	 * Returns the value as an int
	 */
	public int getNumerator()
	{
		return this.num;
	}
}
