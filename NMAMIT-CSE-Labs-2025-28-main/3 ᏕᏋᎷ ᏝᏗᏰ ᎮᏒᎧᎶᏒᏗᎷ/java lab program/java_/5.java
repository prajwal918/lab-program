package stackdemo;
import java.util.Scanner;

/**
 * The Stack class defines the stack data structure and its operations.
 */
class Stack {
    int top;
    int[] array = new int[10]; // Stack with a fixed size of 10

    // Constructor to initialize the top of the stack
    Stack() {
        top = -1;
    }

    // Method to add an element to the stack
    void push(int item) {
        if (top == 9) { // Max size is 10 (index 0-9)
            System.out.println("Stack is full");
        } else {
            top = top + 1;
            array[top] = item;
        }
    }

    // Method to remove an element from the stack
    void pop() {
        if (top == -1) {
            System.out.println("Stack is empty");
        } else {
            int item = array[top];
            top = top - 1;
            System.out.println("Element deleted is " + item);
        }
    }

    // Method to display all elements in the stack
    void display() {
        if (top == -1) {
            System.out.println("Stack is empty");
            return;
        }
        System.out.println("Elements in the array: ");
        for (int i = top; i > -1; i--) {
            System.out.println(array[i]);
        }
    }
}

/**
 * The main class to run the stack operations.
 */
public class stackdemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Stack S = new Stack();
        
        System.out.println("How many elements to insert?");
        int size = sc.nextInt();
        
        System.out.println("Enter the elements: ");
        for (int i = 0; i < size; i++) {
            int ele = sc.nextInt();
            S.push(ele);
        }
        
        System.out.println("\n--- Stack Operations ---");
        S.pop();
        S.display();
    }
}