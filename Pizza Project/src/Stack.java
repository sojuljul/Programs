/*
 * Author:		Juliano Nguyen
 * 5/29/2016
 * CSS162		PizzaManager
 * Stack Class
 * Description:
 * 				This represents the Stack class. Create methods such as push(), pop(), size() toString(), isEmpty(), equals()
 * 				Resize the array if too small, check objects if they are null, if pop() an empty array
 * 				Last In First Out -> "Bat" then "taB"
 */
public class Stack<TBA> {
	
	//instance variables
	private int numElements = 0; //keeps track of number of elements in array
	private Object[] data = new Object[100];
	
	/*
	 * Empty constructor that takes no arguments
	 * Defaults numElements to 0, array size of 100
	 */
	public Stack()
	{
		
	}
	
	/*
	 * Constructor that takes an int size
	 * Creates a new object array with a given size
	 */
	public Stack(int size)
	{
		if (size <= 0)
		{
			throw new PizzaException("Invalid size number");
		}
		
		this.data = new Object[size];
	}
	
	/*
	 * Copy constructor that takes a Stack object
	 * Copies the values from given Stack object to the data array
	 * Sets numElements to the given object's numElements
	 */
	public Stack(Stack other)
	{
		if (other == null) //null check
		{
			throw new PizzaException("Cannot have null object");
		}
		
		for (int i = 0; i < other.numElements; i++)
		{
			this.data[i] = other.data[i]; //store values from object other to this.data
		}
		
		this.numElements = other.numElements;
	}
	
	/*
	 * Adds an object to the Object array
	 * Increases numElements by 1 after adding the object (size of array)
	 * Does null check of object, increases array size if too small
	 */
	public void push(Object next)
	{
		if (next == null) //null check
		{
			throw new PizzaException("Cannot push a null!");
		}
		
		if (numElements == data.length) //checks if we reach end of array
		{
			doubleInSize(); //calls method to double array size
		}
		
		data[numElements++] = next;
	}
	
	/*
	 * Removes the value of an object from the array
	 * Decreases numElements by 1 after removing (size of array)
	 */
	public Object pop()
	{
		if (data == null || isEmpty() == true) //null check
		{
			throw new PizzaException("Cannot pop in an empty array!");
		}
		
		return data[--numElements];
	}
	
	/*
	 * Returns the total number of elements in array as int
	 */
	public int size()
	{
		return numElements;
	}
	
	/*
	 * Overrides the toString() method
	 * Returns a string that concatenates all elements in array
	 */
	@Override
	public String toString()
	{
		String retVal = "";
		for (int index = 0; index < numElements; index++)
		{
			retVal += data[index] + ",";
		}
		return retVal;
	}
	
	/*
	 * Checks if an array is empty (has no values)
	 * Returns true if size of the array is empty
	 */
	public boolean isEmpty()
	{
		return numElements == 0;
	}
	
	/*
	 * Overrides the equals() method
	 * Returns false if object is null or not an instance of the Stack class
	 * Returns true only if both object arrays have the same length and
	 * the same value at each index
	 */
	@Override
	public boolean equals(Object other)
	{
		if (other == null || !(other instanceof Stack)) //null check and verify class types
		{
			return false;
		}
		
		Stack that = (Stack) other;		
		if (this.data.length != that.data.length) 		//checks if length of arrays are the same
		{
			return false;
		}
		
		for (int index = 0; index < numElements; index++) 			//checks if values in arrays are the same
		{
			if (!(this.data[index].equals(that.data[index])))
			{
				return false;
			}
		}
		
		return true;
	}
	
	/*
	 * Creates a new object array with double the size
	 * Stores all values from data array to the new array
	 * Sets data array to that new array
	 */
	public void doubleInSize()
	{
		Object[] temp = new Object[data.length * 2]; //temp array with double the size
		
		for(int index = 0; index < numElements; index++)
		{
			temp[index] = data[index]; 						//store values from previous array
		}
		
		data = temp; 								//new array with double the size
	}

}
