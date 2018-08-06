import java.io.Serializable;

/*
 * Author:			Juliano Nguyen
 * 6/6/2016
 * CSS162			Bill Money Date
 * Bill class
 * Description:		Calls on Money and Date classes to create a bill with amount, due date, paid date, and name
 * Building getters/setters from different classes, copy constructor, equals, toString(), if paid or not method
 */
public class Bill implements Comparable, Cloneable, Serializable {

	/*
	 * instance variables for Bill class
	 * Money object, 2 Date objects (due date and paid date), and a string
	 */
	private Money amount;
	private Date dueDate;
	private Date paidDate;
	private String originator;
	
	/*
	 * Constructor that takes no arguments
	 * Initializes the variables using the default constructors from other classes
	 */
	public Bill()
	{
		setAmount(new Money()); //dollars and cents are 0
		setDueDate(new Date()); //date will be 1/1/2014
		setOriginator(""); //empty string
		setUnpaid(); //paid date is null
	}
	
	/*
	 * Constructor that takes 3 different types of arguments; paidDate is null
	 * Initializes a new object to their respective types, ie new Money object for amount, new Date object for due date
	 */
	public Bill(Money newAmount, Date newDueDate, String newOriginator)
	{
		setAmount(new Money(newAmount));
		setDueDate(new Date(newDueDate));
		setOriginator(newOriginator);
		setUnpaid();
	}
	
	/*
	 * Copy constructor that takes a Bill object as argument, cannot copy paid date bc of null
	 * Initializes the amount, due date, originator of object using setters
	 */
	public Bill(Bill toCopy)
	{
		if (toCopy == null)
		{
			throw new PizzaException("Object is null");
		}
		setAmount(toCopy.getAmount());
		setDueDate(toCopy.getDueDate());
		setOriginator(toCopy.getOriginator());
		this.paidDate = toCopy.paidDate;
	}
	
	/*
	 * Overrides the clone method, which is the Cloneable interface
	 * Returns a new Bill object
	 */
	@Override
	public Object clone()
	{
		return new Bill((Money)this.amount.clone(), (Date)this.dueDate.clone(), this.originator);
	}
	
	/*
	 * Overrides the compareTo method, which is the Comparable interface
	 * Checks the amount, dueDate, and originator
	 * Using the compareTo methods from other classes for their respective variables
	 * If 0, this == that; if +1, this > that; if -1, this < that
	 */
	@Override
	public int compareTo(Object other)
	{
		if (other == null || !(other instanceof Bill))
		{
			throw new PizzaException("Object is null / not the same class type");
		}
		
		Bill that = (Bill) other;
		
		//compares the amount first: > 0, < 0, == 0
		if (this.amount.compareTo(that.amount) > 0) //return +1
		{
			return 1;
		}
		else if (this.amount.compareTo(that.amount) < 0) //return -1
		{
			return -1;
		}
		else if (this.amount.compareTo(that.amount) == 0)
		{
			//compares the dueDate if amount is equal: > 0, < 0, == 0
			if (this.dueDate.compareTo(that.dueDate) > 0) //return +1
			{
				return 1;
			}
			else if (this.dueDate.compareTo(that.dueDate) < 0) //return -1
			{
				return -1;
			}
			else if (this.dueDate.compareTo(that.dueDate) == 0)
			{
				//compares the string originator is dueDate equal: > 0, < 0, == 0
				if (this.originator.compareTo(that.originator) > 0) //return +1
				{
					return 1;
				}
				else if (this.originator.compareTo(that.originator) < 0) //return -1
				{
					return -1;
				}
				else if(this.originator.compareTo(that.originator) == 0) //return 0 since all equal
				{
					return 0;
				}
			}
		}
		
		return -1; //compiler happy
	}
	
	/*
	 * Returns true if both bills are equal
	 * If amount, due date, originator are all equal
	 */
	public boolean equals(Bill toCompare)
	{
		if (toCompare == null ) //null check
		{
			throw new PizzaException("Object is null");
		}
		
		//check if amount, dueDate, and originator are equal
		if (this.amount.equals(toCompare.getAmount()) && this.dueDate.equals(toCompare.getDueDate()) && this.originator.equals(toCompare.getOriginator()))
		{
			if (this.paidDate == null && toCompare.paidDate == null) //if both are null, return true
			{
				return true;
			}
			else if (this.paidDate == null && toCompare.paidDate != null) //if one is not null, return false
			{
				return false;
			}
			else if (this.paidDate != null && toCompare.paidDate == null) //if other is not null, return false
			{
				return false;
			}
			else if (this.paidDate.equals(toCompare.paidDate)) //check using the Date equals method
			{
				return true;
			}
		}
		
		return false; //otherwise return false
	}
	
	/*
	 * Overrides toString() method
	 * Returns a string that prints out the amount, due date, originator
	 */
	@Override
	public String toString()
	{
		if (isPaid() == false) //if false, do not print the paid date
		{
			return "Paid? " + isPaid() + ", Amount: " + getAmount() + ", Due Date: " + getDueDate() + ", To: " + getOriginator();
		}
		
		//otherwise, prints the paid date
		return "Paid? " + isPaid() + ", Amount: " + getAmount() + ", Due Date is: " + getDueDate() + ", To: " + getOriginator() + ", Date Paid: " + paidDate;
	}

	/*
	 * Setter for originator in Bill class
	 * Takes in a string as argument and sets originator to it
	 */
	public void setOriginator(String newOriginator)
	{
		if (newOriginator == null) //null check
		{
			throw new PizzaException("Cannot have null for originator");
		}
		originator = newOriginator;
	}
	
	/*
	 * Getter for originator in Bill class
	 * Returns the originator as a string
	 */
	public String getOriginator()
	{
		return this.originator;
	}
	
	/*
	 * Returns true if paid date is not null (has been paid)
	 * Otherwise, returns false since it has not been paid
	 */
	public boolean isPaid()
	{
		boolean retVal = false;
		
		if(paidDate != null) //if not null, then set it to true
		{
			retVal = true;
		}
		
		return retVal;
	}
	
	/*
	 * Setter for unpaid in Bill class
	 * Set paid date to be null since bill has not been paid
	 */
	public void setUnpaid()
	{
		this.paidDate = null;
	}
	
	/*
	 * Setter for paid date in Bill class; bill has been paid
	 * Takes in a Date object and sets paid date to a new Date object to avoid privacy leaks
	 * INVARIANT: Paid date should be on or earlier than the due date
	 */
	public void setPaid(Date onDay)
	{
		//check if paid date is less than the due date
		if (onDay.getYear() <= dueDate.getYear() && onDay.getMonth() <= dueDate.getMonth() && onDay.getDay() <= dueDate.getDay())
		{
			paidDate = new Date(onDay);
		}
		else
		{
			throw new PizzaException("Paid date is after the due date!");
		}
	}
	
	/*
	 * Setter for due date in Bill class
	 * Takes in a Date object and sets due date to a new Date object to avoid privacy leaks
	 * INVARIANT: due date before the paid date will fail
	 */
	public void setDueDate(Date nextDate)
	{
		if (isPaid() == false) //check if paid date is null
		{
			dueDate = new Date(nextDate);
		}
		else if (nextDate.getYear() >= paidDate.getYear() && nextDate.getMonth() >= paidDate.getMonth() && nextDate.getDay() >= paidDate.getDay())
		{
			dueDate = new Date(nextDate);
		}
		else
		{
			throw new PizzaException("Due date is before the paid date!");
		}
		
	}
	
	/*
	 * Getter for due date in Bill class
	 * Returns a new Date object that takes due date as its argument to avoid privacy leaks
	 */
	public Date getDueDate()
	{
		return new Date(this.dueDate);
	}
	
	/*
	 * Setter for amount in Bill class
	 * Takes in a Money object as argument and sets amount to a new Money object to avoid privacy leaks
	 */
	public void setAmount(Money newAmount)
	{
		this.amount = new Money(newAmount);
	}
	
	/*
	 * Getter for amount in Bill class
	 * Returns a new Money object that takes amount as its argument to avoid privacy leaks
	 */
	public Money getAmount()
	{
		return new Money(this.amount);
	}
}
