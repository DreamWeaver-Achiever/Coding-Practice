#include<limits.h>

int maxSegments(int rodLength, int x, int y, int z) {

	//Base case - 1
	if(rodLength==0) {
		return 0;
	} 

	//Base case - 2; to handle the cases where subtraction will be negative integer.
	if(rodLength<0) {
		return INT_MAX;
	} 

	int startWithFirst = maxSegments((rodLength-x), x, y, z)+1;
	int startWithSecond = maxSegments((rodLength-y), x, y, z)+1;
	int startWithThird = maxSegments((rodLength-z), x, y, z)+1;

	int maximumCuts = max(startWithFirst, max(startWithSecond, startWithThird));
	return maximumCuts;
}

int cutSegments(int rodLenght, int x, int y, int z) {
	// Write your code here.
	int maximumCuts = maxSegments(rodLenght, x, y, z);

	if(maximumCuts<0) {
		return 0;
	} else {
		return maximumCuts;
	}
}