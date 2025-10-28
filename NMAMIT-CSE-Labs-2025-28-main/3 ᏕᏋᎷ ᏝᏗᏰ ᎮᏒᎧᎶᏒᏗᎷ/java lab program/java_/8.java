import java.util.Scanner;

// The interface for creating a resume
interface Resume {
    public void biodata();
}

// The teacher class implementing the Resume interface
class teacher implements Resume {
    String personalinfo;
    String qual;
    String exp;
    String achievement;

    void readdata() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter teacher personal information, qualification, experience and achievements:");
        personalinfo = sc.nextLine();
        qual = sc.nextLine();
        exp = sc.nextLine();
        achievement = sc.nextLine();
    }

    public void biodata() {
        System.out.println("Personal information: " + personalinfo);
        System.out.println("Qualification: " + qual);
        System.out.println("Experience: " + exp);
        System.out.println("Achievements: " + achievement);
    }
}

// The Student class implementing the Resume interface
class Student implements Resume {
    String personalinfo;
    String result;
    String disc;

    void readdata() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Student personal information, result and discipline:");
        personalinfo = sc.nextLine();
        result = sc.nextLine();
        disc = sc.nextLine();
    }

    public void biodata() {
        System.out.println("Personal information: " + personalinfo);
        System.out.println("Result: " + result);
        System.out.println("Discipline: " + disc);
    }
}

// The main class to demonstrate the program
public class ResumeDemo {
    public static void main(String[] args) {
        teacher t = new teacher();
        t.readdata();
        t.biodata();

        Student s = new Student();
        s.readdata();
        s.biodata();
    }
}