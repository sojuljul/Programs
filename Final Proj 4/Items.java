
/**
 * Juliano Nguyen
 * CSS161 A
 * 12/2/2015
 * 
 * Items Class - hides the target/enemy, health pack, and coin on the grid
 * This class will be called in the main java class of the game Tower
 */
public class Items
{
    /*
     * Hides a target in each row at a random location
     * Do NOT put more than 1 target
     */
    public static void hideTarget(char[][] in)
    {
        for (int row = 0; row < in.length; row++) //goes through each row
        {
            for (int i = 0; i < 1; i++) //puts only 1 target
            {
                int col = (int) (Math.random() * in.length); //random X location
                in[col][row] = '^'; //target is defined by '^'
            }
        }
    }

    /*
     * Hides a health pack at a random location on the map
     * The number of health packs is determined by the size of the 2D array
     */
    public static void hideLife(char[][] in, int size)
    {
        boolean isOpen = true;
        int count = 0;

        while(isOpen == true)
        {
            int col = (int) (Math.random() * in.length); //random X location
            int row = (int) (Math.random() * in.length); //random Y location

            if (in[col][row] != '^' && in[col][row] != 'h') //check to make sure spot is not a target or a health pack
            {
                in[col][row] = 'h'; //health pack is defined by 'h'
                count++;
            }

            if (count == size) //when the count is the size of the array, end the loop
            {
                isOpen = false;
            }            
        } 
    }

    /*
     * Hides a coin at a random location on the map
     * Make sure the spot is not taken by a target or a health pack
     */
    public static void hideCoin(char[][] in)
    {
        boolean isOpen = true;

        while(isOpen == true)
        {
            int col = (int) (Math.random() * in.length); //random X location
            int row = (int) (Math.random() * in.length); //random Y location

            if (in[col][row] != '^' && in[col][row] != 'h') //check to make sure spot is not taken
            {
                in[col][row] = 'c'; //coin is defined by 'c'
                isOpen = false;
            }        
        } 
    }
}
