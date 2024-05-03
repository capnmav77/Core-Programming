//Java program to use interface in order to count the number of vowels in a string
import java.util.Scanner;

interface CountVowels {
    int countVowels(String str);
}


class VowelCount implements CountVowels {
    public int countVowels(String str) {
        int count = 0;
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I'
                    || ch == 'O' || ch == 'U') {
                count++;
            }
        }
        return count;
    }
}

public class vowel {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string: ");
        String str = sc.nextLine();
        CountVowels obj = new VowelCount();
        System.out.println("Number of vowels in the string: " + obj.countVowels(str));
        sc.close();
    }
}