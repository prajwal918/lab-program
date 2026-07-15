import java.util.*;

class GenerateException {
    private int[] myarray = new int[5];

    private void readElements() {
        Scanner read = new Scanner(System.in);
        System.out.println("Enter the array elements: ");
        for (int i = 0; i < myarray.length; i++) {
            myarray[i] = read.nextInt();
        }
    }

    private int getSmallestElement() {
        int small = myarray[0];
        for (int i = 0; i < myarray.length; i++) {
            if (myarray[i] < small) {
                small = myarray[i];
            }
        }
        return small;
    }

    private void divideElements() {
        int small = getSmallestElement();
        for (int i = 0; i < myarray.length; i++) {
            double result = myarray[i] / small;
        }
        System.out.println("Division is successful");
    }

    private void displayElement() {
        Scanner read = new Scanner(System.in);
        System.out.println("Enter the index you want to accers");
        int idx = read.nextInt();
        int val = myarray[idx];
        System.out.println("Value is: " + val);
    }

    void compute() {
        readElements();
        divideElements();
        displayElement();
    }
}

public class ExceptionDemo {
    public static void main(String[] args) {
        GenerateException objl = new GenerateException();
        try {
            objl.compute();
        } catch (InputMismatchException e) {
            System.out.println("Run time Input wis match error: " + e.getMessage());
        } catch (ArithmeticException e) {
            System.out.println("Run time Arithmetic Exception error: " + e.getMessage());
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Run time Array Index Out of Bounds Exception error: " + e.getMessage());
        }
    }
}