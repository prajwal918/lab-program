import java.util.*;

/**
 * Superclass Staff
 * Contains basic details for all staff members.
 */
class Staff {
    String StaffID;
    String name;
    String phone;
    double Salary;

    void readData() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Staff ID, Name, Phone No and Salary:");
        StaffID = sc.nextLine();
        name = sc.nextLine();
        phone = sc.nextLine();
        Salary = sc.nextDouble();
    }

    void displayData() {
        System.out.println("\n--- Staff Details ---");
        System.out.println("Staff ID: " + StaffID + "\nName: " + name + 
                           "\nPhone No: " + phone + "\nSalary: " + Salary);
    }
}

/**
 * Subclass Teaching
 * Extends Staff with domain and publication details.
 */
class Teaching extends Staff {
    String domain;
    String publication;

    void readData() {
        super.readData();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter domain and publications: ");
        domain = sc.nextLine();
        publication = sc.nextLine();
    }

    void displayData() {
        super.displayData();
        System.out.println("Domain: " + domain + "\nPublications: " + publication);
    }
}

/**
 * Subclass Technical
 * Extends Staff with skills details.
 */
class Technical extends Staff {
    String skills;

    void readData() {
        super.readData();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter skills: ");
        skills = sc.nextLine();
    }

    void displayData() {
        super.displayData();
        System.out.println("Skills: " + skills);
    }
}

/**
 * Subclass Contract
 * Extends Staff with contract period details.
 */
class Contract extends Staff {
    String period;

    void readData() {
        super.readData();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the contract period: ");
        period = sc.nextLine();
    }

    void displayData() {
        super.displayData();
        System.out.println("Contract Period: " + period);
    }
}

/**
 * Main class to drive the program.
 * Creates objects for each staff type and displays their details.
 */
public class StaffDemo {
    public static void main(String[] args) {
        System.out.println("--- Enter details for Technical Staff ---");
        Technical T1 = new Technical();
        T1.readData();
        
        System.out.println("\n--- Enter details for Teaching Staff ---");
        Teaching T2 = new Teaching();
        T2.readData();
        
        System.out.println("\n--- Enter details for Contract Staff ---");
        Contract C1 = new Contract();
        C1.readData();

        // Displaying all details at the end
        T1.displayData();
        T2.displayData();
        C1.displayData();
    }
}