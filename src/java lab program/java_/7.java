import java.util.Scanner;
class Myarray {
    private int[] arr;
    private int oddno;
    private int evenno;
    public void readelements() {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter the size of the array");
        int size = sc.nextInt();
        arr = new int[size];
        System.out.println("enter the array elements");
        for (int i = 0; i < arr.length; i++) {
            arr[i] = sc.nextInt();
        }
    }
    public void compute() {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] % 2 == 0) {
                evenno++;
            } else {
                oddno++;
            }
        }
    }
    public int NoofEvenno() {
        return evenno;
    }
    public int NoofOddnos() {
        return oddno;
    }
}
class ArraySymmetry {
    public static void main(String[] args) {
        Myarray arr1 = new Myarray();
        System.out.println("Enter the first array elements");
        arr1.readelements();
        arr1.compute();
        Myarray arr2 = new Myarray();
        System.out.println("Enter the second array elements");
        arr2.readelements();
        arr2.compute();
        if ((arr1.NoofEvenno() == arr2.NoofEvenno()) && (arr1.NoofOddnos() == arr2.NoofOddnos())) {
            System.out.println("Arrays are Symmetrical");
        } else {
            System.out.println("Arrays are not Symmetrical");
        }
    }
}