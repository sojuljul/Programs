/*
 * Author:		Juliano Nguyen
 * 4/20/2016
 * CSS162		PizzaManager
 * ArrayList Class
 * Description:
 * 				This represents the ArrayList class. Create methods such as add(), remove(), size(), toString(), isEmpty(), indexOf(), equals()
 * 				Resize the array if too small, check objects if they are null, if remove() an empty array, shiftLeft and shiftRight method
 * 				X In X Out -> "Bat" then adding 'i' at index 2 will be "Bait"
 */
public class ArrayList<TBA> {

	//instance variables
	private int numElements = 0; //keeps track of number of elements in array
	private Object[] data = new Object[100];
	
	/*
	 * Empty constructor that takes no arguments
	 * Defaults numElements to 0, array size of 100
	 */
	public ArrayList()
	{
		
	}
	
	/*
	 * Constructor that takes an int size
	 * Creates a new object array with a given size
	 */
	public ArrayList(int size)
	{
		if (size <= 0)
		{
			throw new PizzaException("Invalid size number");
		}
		
		this.data = new Object[size];
	}
	
	/*
	 * Copy constructor that takes a ArrayList object
	 * Copies the values from the ArrayList object to the data array
	 * Sets numElements to the given object's numElements
	 */
	public ArrayList(ArrayList<TBA> other)
	{
		if (other == null) //null check
		{
			throw new PizzaException("Cannot have null object");
		}
		
		for (int index = 0; index < other.numElements; index++)
		{
			this.data[index] = other.data[index]; //store values from object other to this.data
		}
		
		this.numElements = other.numElements;
	}
	
	/*
	 * Returns the data value at a specific index
	 * Check if index is out of bounds / negative
	 */
	public TBA get(int index)
	{
		if (index < 0 || index > numElements) //check if valid index
		{
			throw new PizzaException("Invalid index value");
		}
		return (TBA) data[index];
	}
	
	/*
	 * Swaps 2 data values given their indexes
	 * Creates a temporary variable to store the object at index1
	 */
	public void swap(int index1, int index2)
	{
		Object temp = data[index1];
		data[index1] = data[index2];
		data[index2] = temp;
	}
	
	/*
	 * Adds an object to the array at a specific index
	 * Increases numElements by 1 after adding the object (size of array)
	 * Does null check of object, increases array size if too small
	 * If adding on index that already has a value, all elements after the index will shift to the right
	 */
	public void add(Object next, int index)
	{
		if (next == null) //null check
		{
			throw new PizzaException("Cannot add null");
		}
		else if (index > numElements || index < 0) //index check if valid
		{
			throw new PizzaException("Invalid index or index is out of bounds");
		}
		
		if (numElements == data.length) //check if size reaches its max
		{
			doubleInSize();
		}
		
		shiftRight(index); //shift elements to the right of the index
		data[index] = next; //store value at that index
		numElements++;
	}
	
	//add method that redirects to insert
	public void add(Object next)
	{
		add(next, numElements);
	}
	
	/*
	 * Removes an element from the list at a specific index
	 * All elements after the index will shift to the left
	 */
	public Object remove(int index)
	{
		if (data == null || isEmpty() == true) //null check
		{
			throw new PizzaException("Cannot remove in an empty array");
		}
		else if (index > numElements || index < 0) //index check if valid
		{
			throw new PizzaException("Invalid index or index is out of bounds");
		}
		
		Object retVal = data[index]; 		//value at index is 'removed'
		shiftLeft(index); 					//shift elements to the left
		numElements--;
		return retVal;
	}
	
	/*
	 * Shifts all elements to the right at a certain index
	 * Store values from the current index to the next
	 */
	public void shiftRight(int start)
	{
		for (int index = numElements - 1; index >= start; index--)
		{
			data[index+1] = data[index];
		}
	}
	
	/*
	 * Shifts all elements to the left starting at a certain index
	 * Store values from the next index to the current
	 */
	public void shiftLeft(int start)
	{
		for (int index = start; index < numElements - 1; index++)
		{
			data[index] = data[index+1];
		}
	}
	
	/*
	 * Returns the total number of elements in array as int
	 */
	public int size()
	{
		return this.numElements;
	}
	
	/*
	 * Overrides the toString() method
	 * Returns a string that concatenates all elements in list
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
	 * Returns the index of the given target
	 * If target is not found in array, return -1
	 */
	public int indexOf(Object target)
	{
		if (target == null) //null check
		{
			throw new PizzaException("Cannot give null as target");
		}
		
		for (int index = 0; index < numElements; index++)
		{
			if (this.data[index].equals(target)) //checks if values are the same
			{
				return index;
			}
		}
		
		return -1; //if target not found
	}
	
	/*
	 * Overrides the equals() method
	 * Returns false if object is null or not an instance of ArrayList
	 * Returns true only if both array objects have the same length
	 * and have the same values at each index
	 */
	@Override
	public boolean equals(Object other)
	{
		if (other == null || !(other instanceof ArrayList)) //null check and verify class types
		{
			return false;
		}
		
		ArrayList that = (ArrayList) other;
		if (this.data.length != that.data.length) 			//checks if lengths of arrays are the same
		{
			return false;
		}
		
		for (int index = 0; index < numElements; index++) 				//checks if values in arrays are the same
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
		Object temp[] = new Object[data.length * 2]; //temp array with double the size
		
		for (int index = 0; index < numElements; index++)
		{
			temp[index] = data[index]; 						//stores values from previous array
		}
		
		data = temp;
	}
}
