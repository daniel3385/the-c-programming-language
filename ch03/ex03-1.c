#include <stdio.h>

/*one opetion of binary search*/

int binsearch(int x, int v[], int n) {
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	while(low <= high) {
		mid = (low + high)/2;
		if(x < v[mid])
			high = mid - 1;
		else if(x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

void main() {

	int v[] = {1,3,5,7,9,11,13,15};
	int x = 11;
	printf("Result:%d ", binsearch(x, v, (sizeof(v)/sizeof(v[0]))));
}
