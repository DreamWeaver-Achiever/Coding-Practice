//  Link: https://cses.fi/problemset/task/1068

import java.util.*;

public class WeirdAlgorithm {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); //159487

        long n = sc.nextLong();
        while(n != 1){
            System.out.print(n + " ");
            if(n % 2 != 0){
                n = n * 3 + 1;
            }else{
                n = n / 2;
            }
        }
        System.out.println(n + "");

    }
}

