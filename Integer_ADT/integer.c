#include "integer.h"
#include <stdlib.h>
#include <stdio.h>

void initInteger(Integer *a) {
	a->head = (node *)malloc(sizeof(node));
	a->tail = a->head;
	a->head->p = NULL;
	a->head->q = NULL;
	a->head->ch = '0';
	a->count = 0;
}

void addDigit(Integer *a, char ch) {
	node *temp;
	temp = a->tail;
	if(a->count != 0) {
		temp->p = (node *)malloc(sizeof(node));
		temp->p->p = NULL;
		temp->p->q = temp;
		temp->p->ch = ch;
		a->tail = temp->p;
		a->count++;
	}
	else {
		temp->ch = ch;
		a->count++;
	}	
}

Integer createIntegerFromString(char *str) {
	Integer a;
	initInteger(&a);
	node *temp;
	temp = a.head;
	if(*str != '\0' && (*str >= '0' && *str <= '9')) {
		temp->ch = *str;
		str++;
		a.count++;
	}
	while(*str != '\0' && (*str >= '0' && *str <= '9')) {
		temp->p = (node *)malloc(sizeof(node));
		temp->p->p = NULL;
		temp->p->q = temp;
		temp->p->ch = *str;
		temp = temp->p;
		a.tail = temp;
		str++;
		a.count++;
	}
	return a;
}

Integer addIntegers(Integer a, Integer b) {
	int len1, len2;
	int num1, num2, num3;
	int rem, diff, car = 0;
	len1 = a.count;
	len2 = b.count;
	node *temp1, *temp2, *temp3;
	Integer c;
	initInteger(&c);
	temp1 = a.tail;
	temp2 = b.tail;
	temp3 = c.tail;
	if(len1 == len2) {
                while (temp1->q != NULL && temp2->q != NULL) {
			num1 = temp1->ch - '0';
			num2 = temp2->ch - '0';
			num3 = num1 + num2 + car;
			if(num3 > 9) {
				car = num3 / 10;
				rem = num3 % 10;
			}
			else {
				car = 0;
				rem = num3;
			} 
			temp3->q = (node *)malloc(sizeof(node));
			temp3->q->q = NULL;
			temp3->q->p = temp3;
			temp3->ch = (char)(rem + '0');
			temp3 = temp3->q;
			c.head = temp3;
			c.count++;
			temp1 = temp1->q;
			temp2 = temp2->q;
		}
		num1 = temp1->ch - '0';
		num2 = temp2->ch - '0';
		num3 = num1 + num2 + car;
		if(num3 > 9) {
			car = num3 / 10;
			rem = num3 % 10;
		}
		else {
			car = 0;
			rem = num3;
		}
		temp3->q = (node *)malloc(sizeof(node));
		temp3->q->q = NULL;
		temp3->q->p = temp3;
		temp3->ch = (char)(rem + '0');
		temp3 = temp3->q;
		c.head = temp3;
		c.count++;
		temp1 = temp1->q;
		temp2 = temp2->q;
		if(car > 0) {
                        temp3->q = (node *)malloc(sizeof(node));
                        temp3->q->q = NULL;
                        temp3->q->p = temp3;
                        temp3->ch = (char)(car + '0');
                        temp3 = temp3->q;
                        c.head = temp3;
                        c.count++;
                }
		return c;
	}
	else if(len1 > len2) {
                while(temp1->q != NULL && temp2->q != NULL) {
                        num1 = temp1->ch - '0';
                        num2 = temp2->ch - '0';
                        num3 = num1 + num2 + car;
                        if(num3 > 9) {
                                car = num3 / 10;
                                rem = num3 % 10;
                        }
                        else {
                                car = 0;
                                rem = num3;
                        }
                        temp3->q = (node *)malloc(sizeof(node));
                        temp3->q->q = NULL;
                        temp3->q->p = temp3;
                        temp3->ch = (char)(rem + '0');
                        temp3 = temp3->q;
                        c.head = temp3;
                        c.count++;
			temp1 = temp1->q;
			temp2 = temp2->q;
                }
		num1 = temp1->ch - '0';
		num2 = temp2->ch - '0';
		num3 = num1 + num2 + car;
		if(num3 > 9) {
			car = num3 / 10;
			rem = num3 % 10;
		}
		else {
			car = 0;
			rem = num3;
		}
		temp3->q = (node *)malloc(sizeof(node));
		temp3->q->q = NULL;
		temp3->q->p = temp3;
		temp3->ch = (char)(rem + '0');
		temp3 = temp3->q;
		c.head = temp3;
		c.count++;
		temp1 = temp1->q;
		temp2 = temp2->q;
                diff = len1 - len2;
		while(diff) {
			num1 = temp1->ch - '0';
			num3 = num1 + car;
			if(num3 > 9) {
				car = num3 / 10;
				rem = num3 % 10;
			}
			else {
				car = 0;
				rem = num3;
			}
                        temp3->q = (node *)malloc(sizeof(node));
                        temp3->q->q = NULL;
                        temp3->q->p = temp3;
                        temp3->ch = (char)(rem + '0');
                        temp3 = temp3->q;
			c.head = temp3;
			c.count++;
			diff--;
			temp1 = temp1->q;
		}
		if(car > 0) {
                        temp3->q = (node *)malloc(sizeof(node));
                        temp3->q->q = NULL;
                        temp3->q->p = temp3;
                        temp3->q->ch = (char)(car + '0');
                        temp3 = temp3->q;
                        c.head = temp3;
                        c.count++;
		}			
                return c;
	}
        else if(len1 < len2) {
                while(temp1->q != NULL && temp2->q != NULL) {
                        num1 = temp1->ch - '0';
                        num2 = temp2->ch - '0';
                        num3 = num1 + num2 + car;
                        if(num3 > 9) {
                                car = num3 / 10;
                                rem = num3 % 10;
                        }
                        else {
                                car = 0;
                                rem = num3;
                        }
                        temp3->q = (node *)malloc(sizeof(node));
                        temp3->q->q = NULL;
                        temp3->q->p = temp3;
                        temp3->ch = (char)(rem + '0');
                        temp3 = temp3->q;
                        c.head = temp3;
                        c.count++;
			temp1 = temp1->q;
			temp2 = temp2->q;
                }
		num1 = temp1->ch - '0';
		num2 = temp2->ch - '0';
		num3 = num1 + num2 + car;
		if(num3 > 9) {
			car = num3 / 10;
			rem = num3 % 10;
		}
		else {
			car = 0;
			rem = num3;
		}
		temp3->q = (node *)malloc(sizeof(node));
		temp3->q->q = NULL;
		temp3->q->p = temp3;
		temp3->ch = (char)(rem + '0');
		temp3 = temp3->q;
		c.head = temp3;
		c.count++;
		temp1 = temp1->q;
		temp2 = temp2->q;
                diff = len2 - len1;
                while(diff) {
                        num2 = temp2->ch - '0';
                        num3 = num2 + car;
                        if(num3 > 9) {
                                car = num3 / 10;
                                rem = num3 % 10;
                        }
                        else {
                                car = 0;
                                rem = num3;
                        }
                        temp3->q = (node *)malloc(sizeof(node));
                        temp3->q->q = NULL;
                        temp3->q->p = temp3;
                        temp3->ch = (char)(rem + '0');
                        temp3 = temp3->q;
                        c.head = temp3;
                        c.count++;
                        diff--;
			temp2 = temp2->q;
                }
                if(car > 0) {
                        temp3->q = (node *)malloc(sizeof(node));
                        temp3->q->q = NULL;
                        temp3->q->p = temp3;
                        temp3->ch = (char)(car + '0');
                        temp3 = temp3->q;
                        c.head = temp3;
                        c.count++;
                }
                return c;
	}
}

Integer subtractIntegers(Integer a, Integer b) {
        int len1, len2;
        int num1, num2, num3;
	int diff = 0, len_diff;
	char bor;
        len1 = a.count;
        len2 = b.count;
        node *temp1, *temp2, *temp3;
        Integer c;
        initInteger(&c);
        temp1 = a.tail;
        temp2 = b.tail;
        temp3 = c.tail;
	if(len1 == len2) {
		bor = temp1->ch;
		while(temp1->q != NULL && temp2->q != NULL) {
			num1 = bor - '0';
			num2 = temp2->ch - '0';
			num3 = num1 - num2;
			diff = num3;
			if(num3 < 0) {
				num3 += 10;
				bor = temp1->q->ch;
				bor -= 1;
			}
			temp3->q = (node *)malloc(sizeof(node));
			temp3->q->q = NULL;
			temp3->q->p = temp3;
			temp3->ch = (char)(num3 + '0');
			temp3 = temp3->q;	
			c.head = temp3;
			c.count++;
			temp1 = temp1->q;
			temp2 = temp2->q;
		}
		if(diff < 0) {
			bor = bor;
		}
		else {
			bor = temp1->ch;
		}
		num1 = bor - '0';
		num2 = temp2->ch - '0';
		num3 = num1 - num2;
		diff = num3;
		if(num3 < 0) {
			num3 += 10;
			if(temp1->q == NULL && temp2->q == NULL) {
				destroyInteger(&c);
				initInteger(&c);
				return c;
			}
			else {
				bor = temp1->q->ch;
				bor -= 1;
			}
		}
		temp3->q = (node *)malloc(sizeof(node));
		temp3->q->q = NULL;
		temp3->q->p = temp3;
		temp3->ch = (char)(num3 + '0');
		temp3 = temp3->q;
		c.head = temp3;
		c.count++;
		temp1 = temp1->q;
		temp2 = temp2->q;
		if(diff < 0) {
			destroyInteger(&c);
			initInteger(&c);
			return c;
		}
		else {
			return c;
		}
	}
	if(len1 > len2) {
		while(temp1->q != NULL && temp2->q != NULL) {
			if(diff < 0) {
				bor = bor;
			}	
			else {
				bor = temp1->ch;
			}
                        num1 = bor - '0';
                        num2 = temp2->ch - '0';
                        num3 = num1 - num2; 
                        diff = num3; 
                        if(num3 < 0) {
                                num3 += 10;
                                bor = temp1->q->ch;
                                bor -= 1;
                        }
                        temp3->q = (node *)malloc(sizeof(node));
                        temp3->q->q = NULL; 
                        temp3->q->p = temp3;
                        temp3->ch = (char)(num3 + '0'); 
			temp3 = temp3->q;    
                        c.head = temp3;
                        c.count++;
			temp1 = temp1->q;
			temp2 = temp2->q;
                }
		if(diff < 0) {
			bor = bor;
		}
		else {
			bor = temp1->ch;
		}
	        num1 = bor - '0';
		num2 = temp2->ch - '0';
		num3 = num1 - num2;
		diff = num3;
		if(num3 < 0) {
			num3 += 10;
			bor = temp1->q->ch;
			bor -= 1;
		}
		temp3->q = (node *)malloc(sizeof(node));
		temp3->q->q = NULL;
		temp3->q->p = temp3;
		temp3->ch = (char)(num3 + '0');
		temp3 = temp3->q;
		c.head = temp3;
		c.count++;
		temp1 = temp1->q;
		temp2 = temp2->q;
		len_diff = len1 - len2;
		while(len_diff) {
			if(diff < 0) {
				bor = bor;
			}	
			else {
				bor = temp1->ch;
			}
			num1 = bor - '0';
			num3 = num1;
			if(num3 > 0) {
                        	temp3->q = (node *)malloc(sizeof(node));
	                        temp3->q->q = NULL;
        	                temp3->q->p = temp3;
                	        temp3->ch = (char)(num3 + '0');
				temp3 = temp3->q;
                        	c.head = temp3;
                        	c.count++;
				len_diff--;
				temp1 = temp1->q;
			}
			else if(num3 < 0) {
				num3 += 10;
				bor = temp1->q->ch;
				bor -= 1;
                                temp3->q = (node *)malloc(sizeof(node));
                                temp3->q->q = NULL;
                                temp3->q->p = temp3;
                                temp3->ch = (char)(num3 + '0');
				temp3 = temp3->q;
                                c.head = temp3;
                                c.count++;
                                len_diff--;
				temp1 = temp1->q;
			}
			else {
				break;
			}
		}
		return c;
	}
	else if(len1 < len2) {
		return c;
	}				
}

void printInteger(Integer a) {
	node *temp;
	temp = a.head;
	while(temp->p != NULL) {
		printf("%c", temp->ch);
		temp = temp->p;
	}
	printf("%c", temp->ch);
	printf("\n");
}

void destroyInteger(Integer *a)  {
	node *temp, *temp1;
	temp = a->tail;
	while(a->count) {
		temp1 = temp->q;
		free(temp);
		temp = temp1;
		a->count--;
	}
	initInteger(a);
}

