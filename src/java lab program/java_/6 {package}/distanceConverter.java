package converter;
import java.util.Scanner;

public class distanceConverter {
    public void convert() {
        Scanner read = new Scanner(System.in);
        System.out.println("Enter the distance in miles: ");
        int miles = read.nextInt();
        double km = 1.609 * miles; // Conversion from miles to kilometers
        System.out.println("Converted value in km: " + km);
        System.out.println("--------------------");
        
        System.out.println("Enter distance in kilometer: ");
        int klm = read.nextInt();
        double cmiles = klm / 1.609; // Conversion from kilometers to miles
        long meter = klm * 1000; // Conversion from kilometers to meters [cite: 205]
        System.out.println("Converted value in miles: " + cmiles);
        System.out.println("Converted value in meters: " + meter);
        System.out.println("--------------------");
    }
}