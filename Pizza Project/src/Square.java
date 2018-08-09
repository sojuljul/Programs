import java.awt.Color;
import java.awt.GradientPaint;
import java.awt.Graphics;
import java.awt.Graphics2D;

/*
 * Author:		Juliano Nguyen
 * CSS162		Pizza Manager
 * 5/30/2016
 * Square Class
 * Description:
 * 				This represents the Square class, which extends Shape, the super class
 * 				Square has a sidelength, its area is: side*side
 * 				Has a final length so that it cannot be changed
 */
public class Square extends Shape implements Cloneable {
	
	//instance variables
	public static final int sideLength = 24;
	
	/*
	 * Constructor that takes no arguments
	 * Calls the super class to set x,y coordinates to 0
	 */
	public Square()
	{
		super(0,0);
	}
	
	/*
	 * Constructor that takes 2 arguments
	 * Calls the super class to set x,y coordinates
	 */
	public Square(int newX, int newY)
	{
		super(newX,newY);
	}
	
	/*
	 * Copy constructor that takes a Square object
	 * Calls the super class to initializes the x,y coordinates of object
	 */
	public Square(Square other)
	{
		super(other.getX(), other.getY());
	}
	
	/*
	 * Overrides the clone method, which is the Cloneable interface
	 * Returns a new Square object
	 */
	@Override
	public Shape clone()
	{
		return new Square(this);
	}
	
	/*
	 * Overrides the toString method
	 * Returns a string value to print out the shape, which is square
	 */
	@Override
	public String toString()
	{
		return "Square";
	}
	
	/*
	 * Calculates the area of a Square: side*side
	 * Returns the area as a double
	 */
	@Override
	public double getArea()
	{
		return sideLength*sideLength;
	}
	
	/*
	 * Draws a square at a random location
	 * Color of square is set to blue
	 */
	@Override
	public void draw(Graphics graphic)
	{
		Graphics2D g2d = (Graphics2D) graphic;
		
		final int xCoord = getX();
		final int yCoord = getY();
		
		g2d.setColor( Color.BLUE ); //color is set to blue
		g2d.setPaint( new GradientPaint( xCoord, yCoord, Color.BLUE, xCoord + 5, yCoord + 5, Color.BLUE, true) ); //paint is set to blue
		
		int xOffset = 0;
		int yOffset = 0;
		for( int i = 0; i < 10; i++) {
			xOffset = (int) (Math.random()*sideLength);
			yOffset = (int) (Math.random()*sideLength);
			g2d.drawRect(xCoord + xOffset, yCoord + yOffset, xCoord + xOffset + 3, yCoord + yOffset + 3); //drawRect draws a rectangule/square to the screen
		}
	}
	
	/*
	 * Getter for sideLength of Square class
	 * Returns the sideLength as a double
	 */
	public double getSideLength()
	{
		return sideLength;
	}

}
