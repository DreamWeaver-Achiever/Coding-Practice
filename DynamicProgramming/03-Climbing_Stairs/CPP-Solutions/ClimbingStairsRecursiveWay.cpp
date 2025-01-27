class Solution {
public:
    int climbStairs(int n) {
        return calculateStairs(n, 0);
        
    }
    int calculateStairs(int totalNumberOfStairs, int currentStair) {
    //Base case
    if(totalNumberOfStairs == currentStair) {
        return 1;
    }
    if(currentStair>totalNumberOfStairs) {
        return 0;
    }
    return(calculateStairs(totalNumberOfStairs, currentStair+1) + calculateStairs(totalNumberOfStairs, currentStair+2));
}
};