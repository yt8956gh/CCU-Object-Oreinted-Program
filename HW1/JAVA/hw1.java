import java.io.*;
import java.util.Scanner;


public class hw1
{
    public static void main(String args[])
    {
        String tmp;
        int i=0,j=0,len=0,isPal=1;;

        //scanner a line for System standard input
        Scanner scanner = new Scanner(System.in);


        //get a string including space and tab
        tmp = scanner.nextLine();
        len = tmp.length();

        while(len!=0)
        {
            i=0; j=len-1;
            isPal = 1;

            while(i<len || j>=0)
            {
                //If characters pointed are not alphabet, the pointers of comparison will move 
                while(!Character.isLetter(tmp.charAt(i))) i++;
                while(!Character.isLetter(tmp.charAt(j))) j--;

                if(tmp.charAt(i)!=tmp.charAt(j))
                {
                    isPal = 0;
                    break;
                }

                // move for next comparison
                i++; j--;
            }

            if(isPal == 1) System.out.println("Valid");
            else System.out.println("Invalid");

            tmp = scanner.nextLine();//read new line for next loop step
            len = tmp.length();
        }
    }
}