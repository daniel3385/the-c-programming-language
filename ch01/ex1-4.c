#include <stdio.h> 

/* printf Celsius to Fahrenheit table
	for celsius = 0, 10, .., 150; floating-point version */

int main () {
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 150;
	step = 10;

	celsius = lower;
	printf("Celsius\tFahrenheit\n\n");
	while (celsius <= upper) {
		fahr = ((9.0/5.0) * celsius) + 32.0;
		printf("%3.0f\t\t%6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
	return 0;
}
