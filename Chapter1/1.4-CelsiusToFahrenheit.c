#include <stdio.h>
/* print Celsius-Fahrenheit table
for Celsius = 0, 20, ..., 300; floating-point version */
main()
{
	float fahr, celsius;
	float lower, upper, step;

	lower = 0; /* lower limit of temperatuire scale */
	upper = 300; /* upper limit */
	step = 20; /* step size */
	printf("Celsius Fahrenheit\n");
	celsius = lower;
	while (celsius <= upper) {
		fahr = (9.0 / 5.0) * (celsius + 32.0);
		printf("%7.0f %10.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}