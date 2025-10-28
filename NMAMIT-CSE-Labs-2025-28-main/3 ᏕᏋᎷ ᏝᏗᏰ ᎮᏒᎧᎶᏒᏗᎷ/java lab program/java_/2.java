package guessMyNumber;

import java.util.*;

public class guessMyNumber {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Random rand = new Random();

        int number = rand.nextInt(10);

        while (true) {
            System.out.println("guess a number between 0 to 10 ");
            int myguess = sc.nextInt();
            if (myguess == number) {
                System.out.println("Your guess no: " + myguess + " is correct:");
                break;
            }
            if (myguess < number) {
                System.out.println("my guess is " + myguess + " is lower");
            } else {
                System.out.println("my guess is higher " + myguess + " is higher");
            }
        }
    }
}