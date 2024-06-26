import java.util.Scanner;

public class CountVowels {

   public static void main(String[] args) {
      // declare variables
      Scanner scan = null;
      String str = null;
      int countVowel = 0;

      // create Scanner class object
      scan = new Scanner(System.in);

      // read input
      System.out.print("Enter String:: ");
      str = scan.nextLine();

      // convert string to upperCase
      str = str.toUpperCase();

      // check each character
      for(int i=0; i < str.length(); i++) {
         if(isVowel(str.charAt(i)))
            countVowel++;
      }
      // display result
      System.out.println("Number of vowels:: "
                   + countVowel);

      // close Scanner object
      scan.close();
   }

   // method to check vowel (only uppercase)
   private static boolean isVowel(char ch) {
      if(ch == 'A' || ch == 'E' || ch == 'I'
                 || ch == 'O' || ch == 'U') {
         return true;
      }
      return false; // else return false;
   }

}