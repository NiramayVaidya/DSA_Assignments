#include<stdio.h>

float convert(float);

int main() {
	float temp_celc, temp_fahr;
	for(temp_fahr = 0; temp_fahr < 300; temp_fahr = temp_fahr + 20) {
		temp_celc = convert(temp_fahr);
		printf("%3.0f %6.1f\n", temp_fahr, temp_celc);
	}
	return 0;
}
