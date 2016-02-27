#include <stdio.h> 


#define LOWER   0       	/*Lowest limit of the table*/
#define UPPER   300       	/* upper limit */
#define STEP    20       	/* step size */

/* printf Fahrenheit_Celsius table
	for fahr = 0, 20, .., 300; floating-point version */

int main () {
	float fahr;

	printf("Fahrenheit\tCelsius\n\n");
	for (fahr=UPPER; fahr>=LOWER; fahr=(fahr-STEP)) {
		printf("%3.0f\t\t%6.1f\n", fahr, (5.0)/(9.0)*(fahr-32));
	}
	return 0;
}
