#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "poly.h"

void initPoly(poly *a) {
	a->head = NULL;
	a->len = 0;
}

void printPoly(poly a) {
	node *p;
	int i = 0, x = a.len;
	p = a.head;
	while(i < x - 1) {
		printf("%.2lfx^%.2lf + ", p->coeff, p->power);
		i++;
		p = p->next;
	}
	printf("%.2lfx^%.2lf", p->coeff, p->power);
}

void addEntry(poly *a, double coeff, double power) {
	node *p, *q, *tmp;
	p = a->head, q = a->head;
	if(p == NULL) {
		tmp = (node *)malloc(sizeof(node));
		tmp->coeff = coeff;
		tmp->power = power;
		a->head = tmp;	
		tmp->next = a->head;
		(a->len)++;
		return;
	}
	p = p->next;
	while(p != a->head) {
		if(power == q->power) {
			q->coeff += coeff;
			return;
		}
		else if(power > q->power) {
			tmp = (node *)malloc(sizeof(node));
			tmp->coeff = coeff;
			tmp->power = power;
			tmp->next = q->next;
			a->head = tmp;
			(a->len)++;
			return;
		} 
		else if(power < q->power && power > p->power) {
			tmp = (node *)malloc(sizeof(node));
			tmp->coeff = coeff;
			tmp->power = power;
			tmp->next = q->next;
			q->next = tmp;
			(a->len)++;
			return;
		}
		else if(power < q->power && power <= p->power) {
			q = p;
			p = p->next;
		}
	}
	tmp = (node *)malloc(sizeof(node));
	tmp->coeff = coeff;
	tmp->power = power;
	tmp->next = a->head;
	q->next = tmp;
	(a->len)++;
	return;
}

double eval(poly a, double val) {
	double ans = 0;
	node *p;
	p = a.head;
	ans += p->coeff * pow(val, p->power);
	p = p->next;
	while(p != a.head) {
		ans += p->coeff * pow(val, p->power);
		p = p->next;
	}
	return ans;
}

poly addPoly(poly a, poly b) {
	node *qa, *qb;
	qa = a.head, qb = b.head;
	poly c;
	initPoly(&c);
	int x = a.len, y = b.len, i = 0, j = 0;
	if(qa && qb) {
		while(i < x && j < y) {
			if(qa->power > qb->power) {
				addEntry(&c, qa->coeff, qa->power);
				qa = qa->next;
				i++;
			}
			else if(qa->power == qb->power) {
				addEntry(&c, qa->coeff + qb->coeff, qa->power);
				qa = qa->next;
				i++;
				qb = qb->next;
				j++;
			}
			else {
				addEntry(&c, qb->coeff, qb->power);
				qb = qb->next;
				j++;
			}
		}
		while(i < x) {
			addEntry(&c, qa->coeff, qa->power);
			qa = qa->next;
			i++;
		}
		while(j < y) {
			addEntry(&c, qb->coeff, qb->power);
			qb = qb->next;
			j++;
		}
		return c;
	}					 
	else if(qa)
		addEntry(&c, qa->coeff, qa->power);
	else if(qb)
		addEntry(&c, qb->coeff, qb->power);
	return c;
}

poly multPoly(poly a, poly b) {
	poly c;
	initPoly(&c);
	node *qa, *qb;
	qa = a.head, qb = b.head;
	int x = a.len, y = b.len, i = 0, j = 0;
	while(i < x) {
		while(j < y) {
			addEntry(&c, (qa->coeff) * (qb->coeff), qa->power + qb->power);
			qb = qb->next;
			j++;
		}
		qb = b.head;
		j = 0;
		qa = qa->next;
		i++;
	}
	return c;
}
	
