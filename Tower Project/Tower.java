/**
 * Juliano Nguyen
 * CSS 161 A
 * 12/2/2015
 * 
 * Game Project - Tower Game
 * The user enters XY coordinates to find the target on the grid
 * The user must start from the bottom row and work their way up the grid if they hit the target
 * If the user misses, they will lose a life
 * WIN if all the targets are hit; LOSE if all the user's lives are gone
 * 
 */

import java.util.Scanner;
import java.io.PrintWriter;
import java.io.FileOutputStream;
import java.io.IOException;

public class Tower
{    
    public static void main(String[] args) throws IOException
    {
        mainMenu(); //title and instructions of the game
        game(); //start the game

    }

    /*
     * Starts the game by having user enter their name and the difficulty they want to play at.
     * The game keeps track of their life, score, and the row number the user is at.
     * Have the user enter X Y coordinates on the grid to win the game
     * If XY hits an enemy, the user moves up one row and continues until user hits all enemies
     * If XY hits a health pack, increase their life by 1
     * If XY hits a coin, increase their score by a certain amount
     * WIN only if all enemies or hit and LOSE only if all life is gone
     */
    public static void game() throws IOException
    {
        Scanner keys = new Scanner(System.in);

        System.out.println("\nEnter name:");
        String name = keys.next();

        System.out.println("\nSelect difficulty: (1) Casual (2) Hard (3) Nightmare");
        final int SIZE = size(keys); //size of the grid

        char[][] board = new char[SIZE][SIZE]; //array in 2D

        int life = 3; //number of lives to start
        int score = 0; //score at the beginning of the game
        int rowNumber = board.length - 1; //start at the last row
        int retry = 0; //number of retrys for that level

        boolean stillPlaying = true; //check to make sure we are still playing the game
        HighScore save = new HighScore(); //define a new class HighScore

        setUp(board, SIZE); //sets up the board by initializing the char and drawing the board
        while (stillPlaying == true)
        {
            keepTrack(life, rowNumber, score); //displays the life, score, and what row the user is at

            System.out.println("Enter X and Y coordinates: "); //user enters XY coordinates
            int x = keys.nextInt();
            int y = keys.nextInt();

            if (y == rowNumber) //check if user entered the correct row
            {
                if (board[x][y] == '^') //check if user hit the enemy
                {
                    board[x][y] = 'X';
                    rowNumber--;
                    score = score + 100;
                    if (rowNumber >= 0)
                    {
                        System.out.println("\nMESSAGE: Bullseye! You are now at row: " + rowNumber);
                    }

                }
                else if (board[x][y] == 'h') //check if user hit a health pack
                {
                    board[x][y] = '+';
                    life++;
                    System.out.println("\nMESSAGE: Picked up health pack! +1 Life");
                }
                else if (board[x][y] == 'c') //check if user hit a coin
                {
                    board[x][y] = '$';
                    score = score + 250;
                    System.out.println("\nMESSAGE: Found rare coin! +300 Points");
                }
                else if (board[x][y] == '+' || board[x][y] == '$' || board[x][y] == ' ') //check if user hit a spot that has already been hit
                {
                    System.out.println("\nMESSAGE: This spot has been fired at already!");
                }
                else //otherwise, user missed
                {
                    board[x][y] = ' ';
                    System.out.println("\nMESSAGE: Missed! -1 Life");
                    life--;
                }
            }
            else //otherwise, wrong row
            {
                System.out.println("\nMESSAGE: Sorry, wrong row!");
            }

            System.out.println();
            drawBoard(board); //draw the board after each input

            stillPlaying = !didWeWin(board); //check if user won
            if (life == 0) //when life is 0, end the loop
            {
                System.out.println("\nContinue? (y) Yes (n) No"); //ask user if they want to continue where they left off
                String letter = keys.next();

                if (letter.indexOf('y') >= 0) //check if user entered anything with 'y'
                {
                    life = life + 3;
                    retry++;
                }
                else //otherwise, end the loop
                {
                    stillPlaying = false;
                }
            }
        }

        System.out.println("Score: " + score);
        score = score + (life * 50) - (retry * 150); //calculate new high score
        endScreen(life, score, retry); //display a message to see if the user won/lost
        save.saveBoard(name, score); //calls saveBoard method from the class HighScore
        playAgain(keys);

    }

    //set up the board by initializing the board and drawing the board
    //additionally, set up the targets, health packs, coin
    public static void setUp(char[][] board, int size)
    {
        Items obj = new Items(); //define a new class Items

        initializeBoard(board); //initialize the board to be *'s
        drawBoard(board); //print out the board
        obj.hideTarget(board); //hide the target on the board
        obj.hideLife(board, size); //hide the health packs on the board

        if (size > 3)
        {
            obj.hideCoin(board); //hide a coin on the board IF size of the board >3
        }
    }

    //asks the user if they want to play the game again
    public static void playAgain(Scanner keys) throws IOException
    {
        System.out.println("Play again? (y) Yes (n) No");
        String letter = keys.next();
        if (letter.indexOf('y') >= 0) //check if user entered anything with 'y'
        {
            game(); //call the game method to execute again
        }
        else //otherwise, exit the program
        {
            System.out.println("\nGame Over");
            System.exit(0);
        }
    }

    //title of the game and instructions on how to play the game
    public static void mainMenu()
    {
        System.out.println("TOWER GAME \nFind the enemy on the map by entering the correct coordinates.");
        System.out.println("Start from the first floor and work your way up if you hit! \nIf you miss, the enemy will counter-attack and you will lose a life.");
        System.out.println("\nMAP LEGEND \n'*' Unknown Target \n'X' Enemy Killed \n' ' No Target Found \n'+' Health Pack \n'$' Coin ");
    }

    //display the amount of life left, score, and what row the user is at
    public static void keepTrack(int life, int row, int score)
    {
        System.out.println("Life: " + life);
        System.out.println("Score: " + score);
        System.out.println("Row #: " + row);       
    }

    //returns an integer size to determine what the array's size should be
    public static int size(Scanner keys) throws IOException
    {
        int diff = keys.nextInt(); //user input
        int arraySize = 0;

        switch(diff)
        {
            case 1: arraySize = 3; //if 1, then size of array is 3 by 3
            break;
            case 2: arraySize = 4; //if 2, then size of array is 5 by 5
            break;
            case 3: arraySize = 5;
            break;
            default: System.out.println("SECRET MAP: Impossible"); //anything else is 10 by 10
            arraySize = 10;
            break;

        }

        return arraySize;
    }

    /*
     * display a message to see if the user won or lost depending on the number of lives left
     * add to the user's score if they have extra life left
     * subtract the user's score if they continued
     */
    public static void endScreen(int life, int score, int retry)
    {                
        if (life > 0) //win if we have lives left
        {
            System.out.println("\nMESSAGE: You win! You have " + life + " life remaining.");
            System.out.println("By surviving, you earned extra points: +" + (life * 50));
            System.out.println("You continued " + retry + " times. Points loss: -" + (retry*150));
            System.out.println("\nFinal Score: " + score);
        }
        else //lose if 0 lives
        {
            System.out.println("\nMESSAGE: You lose! You have " + life + " life remaining.");
            System.out.println("You continued " + retry + " times. Points loss: -" + (retry*150));
            System.out.println("\nFinal Score: " + score);
        }  
    }  

    /*
     * check to see if the user won the game
     * return true ONLY IF all targets are hit
     * returns false if there are still targets on the board
     */
    public static boolean didWeWin(char[][] in)
    {
        boolean retVal = true;

        for (int y = 0; y < in.length; y++) //goes through the rows
        {
            for (int x = 0; x < in.length; x++) //goes through the columns
            {
                if (in[x][y] == '^') //checks to see if there are any targets
                {
                    retVal = false;
                }
            }
        }

        return retVal;
    }

    /*
     * Initializes the board with *'s using a nested loop for the row and column
     */
    public static void initializeBoard(char[][] in)
    {
        for (int y = 0; y < in.length; y++) //outer loop for row
        {
            for (int x = 0; x < in.length; x++) //inner loop for column
            {
                in[x][y] = '*'; //set * at x,y position on the grid
            }
        }
    }

    /*
     * Draws the board using a nested loop for the row and the column
     * Print ONLY the *'s for those targets, health, and coin
     */
    public static void drawBoard(char[][] in)
    {
        for (int y = 0; y < in.length; y++) //outer loop for row
        {
            for (int x = 0; x < in.length; x++) //inner loop for column
            {
                if (in[x][y] == '^' || in[x][y] == 'h' || in[x][y] == 'c') //checks if there is a target, health, or coin
                {
                    System.out.print("|" + '*' + "|"); //print *
                }
                else
                {
                    System.out.print("|" + in[x][y] + "|");
                }

            }
            System.out.println();
        }
    }
}
