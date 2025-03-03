// Link to the problem: https://cses.fi/problemset/task/1083

import java.util.*;

public class MissingNo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long[] arr = new long[(int)n];
        for(int i = 0; i < n-1; i++){
            arr[i] = sc.nextInt();
        }
        long sum = n * (n+1) / 2;
        long arrSum = 0;
        for(long i : arr){
            arrSum += i;
        }
        System.out.println(sum - arrSum);
    }
}
