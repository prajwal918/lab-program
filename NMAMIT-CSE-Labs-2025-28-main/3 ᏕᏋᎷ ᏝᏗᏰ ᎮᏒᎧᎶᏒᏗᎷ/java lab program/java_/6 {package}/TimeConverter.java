package converter;
import java.util.Scanner;

public class TimeConverter {
    public void convert() {
        Scanner read = new Scanner(System.in);
        System.out.println();
        System.out.println("Enter the time in hours: ");
        int hrs = read.nextInt();
        int min = hrs * 60; // Conversion from hours to minutes
        long sec = hrs * 60 * 60; // Conversion from hours to seconds
        System.out.println("Converted time: " + min + " minutes " + sec + " seconds");
        System.out.println("--------------------");

        System.out.println("Enter the time in minutes: ");
        int umin = read.nextInt();
        int chrs = umin / 60; // Conversion from minutes to hours
        long csec = umin * 60; // Conversion from minutes to seconds
        System.out.println("Converted time: " + chrs + " hours " + csec + " seconds");
    }
}