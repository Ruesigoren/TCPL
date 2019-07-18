#include <stdio.h>

float FahrenheitToCelcius(float Fahrenheit);

main()
{
	float fahr, celsius;
	float lower, upper, step;

	lower = 0; /* lower limit of temperatuire scale */
	upper = 300; /* upper limit */
	step = 20; /* step size */
	printf("Fahrenheit Celsius\n");
	fahr = lower;
	while (fahr <= upper) {
		celsius = FahrenheitToCelcius(fahr);
		printf("%10.0f %7.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	return;
}

float FahrenheitToCelcius(float Fahrenheit)
{
	return (5.0 / 9.0) * (Fahrenheit - 32.0);
}