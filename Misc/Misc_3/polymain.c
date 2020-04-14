#include <stdio.h>
#include "poly.h"

int main() {
	poly a, b, c;
	initPoly(&a);
	initPoly(&b);
	double coeff, power;
	while((scanf("%lf%lf", &coeff, &power)) != -1)
		addEntry(&a, coeff, power);
	printPoly(a);
	printf("\n");
	printf("%.2lf", eval(a, 1));
	printf("\n");
	while((scanf("%lf%lf", &coeff, &power)) != -1)
		addEntry(&b, coeff, power);
	printPoly(b);	
	printf("\n");
	c = addPoly(a, b);
	printPoly(c);
	printf("\n");
	c = multPoly(a, b);
	printPoly(c);
	printf("\n");
	return 0;
}
