public class Fibonacci_Recursion {

    // Function to calculate the nth Fibonacci number
    public static int fibonacci(int n) {
        
        if (n <= 1) {
            return n;
        }
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
    public static void main(String[] args) {
        int n = 10;
        System.out.println("The " + n + "th Fibonacci number is: " + fibonacci(n));
    }
}