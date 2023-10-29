import java.io.*;
import java.util.*;

Class B1{
    static{
        System.loadLibrary("B1");
    }

    private native int add(int a, int b);
    public static void main(string[] args){
        Scanner sc = Scanner(System.in);
        int a, b , ch;
        System.out.println("Enter value of a: ");
        a = sc.nextInt();
        System.out.println("Enter value of b:");
        b = sc.nextInt();

        do{
            System.out.println("Enter you choice: ");
            ch = sc.nextInt();
            switch(ch){
                case 1: B1.add(a,b);
                    break;
                default: System.out.println("wrong choice");

            }
        }while(ch<2);
    }
}