package studentdemo1;

import java.util.*;

class student {
    String usn;
    String name;
    String branch;
    String phone;

    student() {
        usn = "";
        name = "";
        branch = "";
        phone = "";
    }

    student(String usn, String name, String branch, String phone) {
        this.usn = usn;
        this.name = name;
        this.branch = branch;
        this.phone = phone;
    }

    void display() {
        System.out.println("USN =" + usn + "");
        System.out.println("NAME=" + name + "");
        System.out.println("BRANCH=" + branch + "");
        System.out.println("PHONE=" + phone + "\n");
    }
}

public class studentdemo1 {
    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        System.out.println("How many Students");
        int size = read.nextInt();
        read.nextLine(); // Consume the newline character

        student objs[] = new student[size];

        for (int i = 0; i < size; i++) {
            System.out.println("Enter USn ,name , branch, Phone NO");
            String usn = read.nextLine();
            String name = read.nextLine();
            String branch = read.nextLine();
            String phone = read.nextLine();

            objs[i] = new student(usn, name, branch, phone);
        }

        System.out.println("\n enter the student details ");
        for (int i = 0; i < size; i++) {
            objs[i].display();
        }
    }
}