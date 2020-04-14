typedef struct node {
	double coeff;
	double power;
	struct node *next;
}node;

typedef struct poly {
	node *head;
	int len;
}poly;

void initPoly(poly *a);
void addEntry(poly *a, double coeff, double power);
poly addPoly(poly a, poly b);
poly multPoly(poly a, poly b);
double eval(poly a, double val);
double findOneRoot(poly a);
void printPoly(poly a);
