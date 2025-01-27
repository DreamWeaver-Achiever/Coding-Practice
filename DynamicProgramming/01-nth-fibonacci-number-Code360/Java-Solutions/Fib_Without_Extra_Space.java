public class Fib_Without_Extra_Space {
    
    public static int fibonacci(int n ){
        int prev = 1;
        int secondPrev = 0;
        
        for (int i = 2; i <= n; i++){
            int curr = prev + secondPrev;
            secondPrev = prev;
            prev = curr;
        }
        return prev;
        
    }
    public static void main(String[] args) {
        int n = 10;
        System.out.println("The " + n + "th Fibonacci number is: " + fibonacci(n));
    }
}
