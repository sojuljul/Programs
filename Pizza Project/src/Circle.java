import java.awt.Color;
import java.awt.GradientPaint;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Ellipse2D;

/*
 * Author:		Juliano Nguyen
 * CSS162		Pizza Manager
 * 5/29/2016
 * Circle Class
 * Description:
 * 				This represents the circle class, which extends Shape, the super class
 * 				Circle has a radius, its area is pi*r*r
 * 				Has a final radius so that it cannot be changed
 */
public class Circle extends Shape implements Cloneable {
	
	//instance variables
	public static final int radius = 16;
	
	/*
	 * Constructor that takes no arguments
	 * Calls the super class to initialize the x,y coordinate to 0
	 */
	public Circle()
	{
		super(0,0);
	}
	
	/*
	 * Copy constructor that takes a Circle object
	 * Calls the super class to initialize the x,y coordinate of object
	 */
	public Circle(Circle other)
	{
		super(other.getX(), other.getY());
	}
	
	/*
	 * Constructor that takes 2 arguments
	 * Calls the super class to set x,y coordinates
	 */
	public Circle(int newX, int newY) 
	{
		super(newX, newY);
	}
	
	/*
	 * Overrides the clone method, which is the Cloneable interface
	 * Returns a new Circle object
	 */
	@Override
	public Shape clone()
	{
		return new Circle(this);
	}
	
	/*
	 * Overrides the toString method
	 * Returns a string value to print out the shape, which is circle
	 */
	@Override
	public String toString()
	{
		return "Circular";
	}
	
	/*
	 * Calculates the area of a circle: pi*r*r
	 * Returns the area as a double
	 */
	@Override
	public double getArea()
	{
		return radius*radius*Math.PI;
	}
	
	/*
	 * Draws a circle at a random location
	 * Color of circle is set to red
	 */
	@Override
	public void draw(Graphics graphic)
	{
		Graphics2D g2d = (Graphics2D) graphic;		
		
		final int xCoord = getX();
		final int yCoord = getY();
		
		g2d.setColor( Color.RED ); //color is set to red
		g2d.setPaint( new GradientPaint( xCoord, yCoord, Color.RED, xCoord + 10, yCoord + 10, Color.RED, true) ); //paint is set to red
		
		int xOffset = 0;
		int yOffset = 0;
		for( int i = 0; i < 10; i++) {
			xOffset = (int) (Math.random()*radius);
			yOffset = (int) (Math.random()*radius);
			g2d.drawOval(xCoord + xOffset, yCoord + yOffset, xCoord + xOffset+3, yCoord + yOffset+3); //drawOval draws a oval/circle to the screen
		}
		
	}
	
	/*
	 * Getter for radius of Circle class
	 * Returns radius as a double
	 */
	public double getRadius()
	{
		return radius;
	}

}
