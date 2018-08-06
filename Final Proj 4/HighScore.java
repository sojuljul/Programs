
/**
 * Juliano Nguyen
 * CSS161 A
 * 12/2/2015
 * 
 * HighScore Class - saves the user's name and score to a text file
 * This class will be called in the main java class of the game Tower
 */

import java.io.PrintWriter;
import java.io.FileOutputStream;
import java.io.IOException;

public class HighScore
{
    /*
     * Saves the name of the user and their end game score
     * Make sure the text file is not overwritten each time the game is played
     */
    public static void saveBoard(String name, int score) throws IOException
    {
        PrintWriter line = new PrintWriter(new FileOutputStream("data.txt", true));

        line.println(name + " " + score); //print user's name and score to text file
        line.close(); //close the stream
    }
}
