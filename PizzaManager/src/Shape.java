import java.awt.*;

/* Class Shape
 *
 * By Rob Nash
 * 
 * This is the superclass in a hierarchy of shapes that you have to construct
 */

/*
 * Author:		Juliano Nguyen
 * CSS162		Pizza Manager
 * 5/29/2016
 * Shape class
 * Description:
 * 				Shape is the superclass that will be used for our subclasses.
 * 				All shapes will have x,y coordinates.
 */

//the superclass in our inheritance hierarchy
//all "common" features, functions and data should go here
//for example, all shapes in Java2D have a x,y that declares their position
//and many of the shapes exposed have a width and a height (but not all, so we didn't put width and height here)
//note that this class is mostly empty, as there is no algorithm generic enough to guess an arbitrary shape's area (future subclasses must override getArea() to provide something reasonable)
//also, the draw method is empty too, as we don't know what shape to draw here! (again, our subclasses will need to replace this method with one that actually draws things)

public abstract class Shape extends Object {
	
	//instance variables
	private int xCoordinate = 0;
	private int yCoordinate = 0;
	
	/*
	 * Default no argument constructor
	 * x,y will default to 0
	 */
	public Shape()
	{
		setX(0);
		setY(0);
	}
	
	/*
	 * Constructor that takes 2 ints as argument
	 * Sets the values to x,y respectively
	 */
	public Shape(int newX, int newY) 
	{
		setX(newX);
		setY(newY);
	}
	
	/*
	 * Copy constructor that takes a Shape object
	 * Sets the x,y coordinates of the object
	 */
	public Shape(Shape other)
	{
		setX(other.getX());
		setY(other.getY());
	}
	
	/*
	 * Abstract clone method because they will be defined in our subclasses
	 * Circle and Square will have a clone method
	 */
	@Override
	public abstract Object clone();
	
	/*
	 * Returns the area of a 'Shape' as a double
	 * Shape is abstract, so -1 for now
	 */
	public double getArea() 
	{ 
		return -1;
	}
	
	/*
	 * Draw method that draws a 'Shape'
	 * Shape is abstract so empty for now
	 */
	public void draw(Graphics g)
	{
		
	}
	
	/*
	 * Getter for x of Shape class
	 * Returns x as an int
	 */
	public int getX()
	{ 
		return this.xCoordinate; 
	}
	
	/*
	 * Getter for y of Shape class
	 * Returns y as an int
	 */
	public int getY()
	{ 
		return this.yCoordinate; 
	}
	
	/*
	 * Setter for x of Shape class
	 * Takes an int as argument and sets it to x
	 */
	public void setX(int newX)
	{
		if (newX < 0) //check for valid x coordinate
		{
			throw new PizzaException("Invalid x value");
		}
		
		this.xCoordinate = newX;
	}
	
	/*
	 * Setter for y of Shape class
	 * Takes an int as argument and sets it to y
	 */
	public void setY(int newY)
	{
		if (newY < 0) //check for valid y coordinate
		{
			throw new PizzaException("Invalid y value");
		}
		
		this.yCoordinate = newY;
	}
}