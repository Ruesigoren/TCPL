#include <stdio.h>
/* print Celsius-Fahrenheit table
for Celsius = 0, 20, ..., 300; floating-point version */
main()
{
	float celsius;

	printf("Celsius Fahrenheit\n");
	for (celsius = 300; celsius >= 0; celsius = celsius - 20)
	{
		printf("%7.0f %10.1f\n", celsius, (9.0 / 5.0) * (celsius + 32));
	}
}