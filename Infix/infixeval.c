#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "stack.h"
#include "cstack.h"
/* pre-condition:
 *    arr[] is an arry of characters, 
 *    n is the maximum possible length of the array 
 * post-condition: 
 *    arr[] contains a 'string', max 'n' in length
 * 	  arr[] may contain white-space
 *	  arr[] gets its contents from user
 *	  function returns no. of characters read
 */
int readline(char *arr, int n) {
	char ch;
	int i = 0;
	while((ch = getchar()) != '\n'  && i < n)
		arr[i++] = ch;
	arr[i] = '\0';
	return i;
}

#define OPERAND	100
#define OPERATOR 200
#define END		300
#define ERROR	400
typedef struct token {
	int type; // can be OPERAND, OPERATOR, END, ERROR
	union data {
		int num;
		char op;	
	}data;
}token;

enum state {START, DIG, OP, SPC, STOP, ERR};
token getnext(char *str, int *restart) {
	static int i = 0;
	static int currstate = START;
	int nextstate;
	char currchar;
	static char currop;
	static int sum = 0;
	token t;

	if(*restart == 1) {
		i = 0;
		currstate = START;
		*restart = 0;
	}
	while(1) {
		currchar = str[i];	
		switch(currstate) {
			case START:
				switch(currchar) {
					case '0': case '1': case '2':
					case '4': case '5': case '6':
					case '7': case '8': case '9':
					case '3': 
						nextstate = DIG;
						sum = currchar - '0';
						break;
					case '+': case '-': case '*':
					case '/': case '%': case '(':
					case ')':
						nextstate = OP;
						currop = currchar;
						break;
					case ' ': case '\t':
						nextstate = SPC;
						break;
					case '\0':
						nextstate = STOP;
						break;
					default:
						nextstate = ERR;
						break;
				}
				break;
			case DIG:
				switch(currchar) {
					case '0': case '1': case '2':
					case '4': case '5': case '6':
					case '7': case '8': case '9':
					case '3': 
						nextstate = DIG;
						sum = sum * 10 + currchar - '0';
						break;
					case '+': case '-': case '*':
					case '/': case '%': case '(':
					case ')':
						nextstate = OP;
						t.type = OPERAND;
						t.data.num = sum;
						sum = 0;
						i++;
						currstate = nextstate;
						currop = currchar;
						return t;	
						break;
					case ' ': case '\t':
						nextstate = SPC;
						t.type = OPERAND;
						t.data.num = sum;
						sum = 0;
						i++;
						currstate = nextstate;
						return t;	
						break;
					case '\0':
						nextstate = STOP;
						t.type = OPERAND;
						t.data.num = sum;
						sum = 0;
						i++;
						currstate = nextstate;
						return t;	
						break;
					default:
						nextstate = ERR;
						t.type = OPERAND;
						t.data.num = sum;
						sum = 0;
						i++;
						currstate = nextstate;
						return t;	
						break;
				}
				break;
			case OP:
				switch(currchar) {
					case '0': case '1': case '2':
					case '4': case '5': case '6':
					case '7': case '8': case '9':
					case '3': 
						nextstate = DIG;
						sum =  currchar - '0';
						t.type = OPERATOR;
						t.data.op = currop;
						i++;
						currstate = nextstate;
						return t;
						break;
					case '+': case '-': case '*':
					case '/': case '%': case '(':
					case ')':
						nextstate = OP;
						t.type = OPERATOR;
						t.data.op = currop;
						i++;
						currstate = nextstate;
						currop = currchar;
						return t;
						break;
					case ' ': case '\t':
						nextstate = SPC;
						t.type = OPERATOR;
						t.data.op = currop;
						i++;
						currstate = nextstate;
						return t;
						break;
					case '\0':
						nextstate = STOP;
						t.type = OPERATOR;
						t.data.op = currop;
						i++;
						currstate = nextstate;
						return t;
						break;
					default:
						nextstate = ERR;
						t.type = OPERATOR;
						t.data.op = currop;
						i++;
						currstate = nextstate;
						return t;
						break;
				}
				break;
			case SPC:
				switch(currchar) {
					case '0': case '1': case '2':
					case '4': case '5': case '6':
					case '7': case '8': case '9':
					case '3': 
						nextstate = DIG;
						sum = currchar - '0';
						break;
					case '+': case '-': case '*':
					case '/': case '%': case '(':
					case ')':
						nextstate = OP;
						currop = currchar;
						break;
					case ' ': case '\t':
						nextstate = SPC;
						break;
					case '\0':
						nextstate = STOP;
						break;
					default:
						nextstate = ERR;
						break;
				}
				break;
			case STOP:
				t.type = END;
				return t;
				break;
			case ERR:
				t.type = ERROR;
				return t;
				break;
			default:
				break;
		}
		currstate = nextstate;
		i++;
	}
}
int precedence(char op) {
	if(op == '%')
		return 40;
	if(op == '*' || op == '/')
		return 30;
	if(op ==  '+' || op == '-')
		return 20;
	if(op == '(')
		return 10;
	return 0;
}
char ctop(cstack *s) {
	char ch = cpop(s);
	cpush(s, ch);
	return ch;
}

int len(stack *s) {
        int num[32], length = 0, sub;
        while(!isempty(s)) {
                num[length++] = pop(s);
        }
        sub = length;
        while(length) {
                push(s, num[--length]);
        }
        return sub;
}

int infixeval(char *infix) {
	token t;
	stack a;
	cstack b;
	int restart = 1;
	int num1, num2, result;
	init(&a);
	cinit(&b);	
	while(1) {
		t = getnext(infix, &restart);
		if(t.type == OPERAND) {
			if(!isfull(&a)) {
				push(&a, t.data.num);
			}
			else {
				return INT_MIN;
			}
		}
		else if(t.type == OPERATOR) {
			if(t.data.op != ')') {
				if(!cisfull(&b)) {
					if(t.data.op == '(') {
						cpush(&b, t.data.op);
					}
					else {
						if(cisempty(&b)) {
							cpush(&b, t.data.op);
						}
						else if(precedence(t.data.op) <= precedence(ctop(&b))) {
							if(!isempty(&a)) {
								num2 = pop(&a);
							}
							else {
								return INT_MIN;
							}
							if(!isempty(&a)) {
								num1 = pop(&a);
							}
							else {
								return INT_MIN;
							}
							if(!cisempty(&b)) {
								switch(cpop(&b)) {
									case '+':
										result = num1 + num2;
										break;
									case '-':
										result = num1 - num2;
										break;
									case '*':
										result = num1 * num2;
										break;
									case '/':
										if(num2 != 0) {
											result = num2 / num1;
										}
										else {
											return INT_MIN;
										}
										break;
									case '%':
										result = num1 % num2;
										break;
									default:
									break;
								}
							}
							else {
								return INT_MIN;
							}
							if(!isfull(&a)) {
								push(&a, result);
							}
							else {
								INT_MIN;
							}
							cpush(&b, t.data.op);
						}
						else {
							cpush(&b, t.data.op);
						}
					}
				}
				else {
					return INT_MIN;
				}
			}
			else {
				while(!cisempty(&b) && ctop(&b) != '(') {
					if(len(&a) != 1) {
						if(!isempty(&a)) {
							num2 = pop(&a);
						}
						else {
							return INT_MIN;
						}
						if(!isempty(&a)) {
							num1 = pop(&a);
						}
						else {
							return INT_MIN;
						}
						if(!cisempty(&b)) {
							switch(cpop(&b)) {
								case '+':
									result = num1 + num2;
									break;
								case '-':
									result = num1 - num2;
									break;
								case '*':
									result = num1 * num2;
									break;
								case '/':
									if(num2 != 0) {
										result = num1 / num2;
									}
									else {
										return INT_MIN;
									}
									break;
								case '%':
									result = num1 % num2;
									break;
								default:
									break;
                                        		}
						}
						else {
							return INT_MIN;
						}
						if(!isfull(&a)) {
							push(&a, result);
						}
						else {
							return INT_MIN;
						}
					}
				}
				if(!cisempty(&b) && !cisfull(&b)) {
					if(ctop(&b) == '(') {
						cpop(&b);
					}
				}
			}
		}
		else if(t.type == END) {
			while(len(&a) != 1) {
				if(!isempty(&a)) {
					num2 = pop(&a);
				}
				else {
					return INT_MIN;
				}
				if(!isempty(&a)) {
					num1 = pop(&a);
				}
				else {
					return INT_MIN;
				}
				if(!cisempty(&b)) {
					switch(cpop(&b)) {
						case '+':
							result = num1 + num2;
							break;
						case '-':
							result = num1 - num2;
							break;
						case '*':
						result = num1 * num2;
						break;
						case '/':
							if(num2 != 0) {
								result = num1 / num2;
							}
							else {
								return INT_MIN;
							}
							break;
						case '%':
							result = num1 % num2;
							break;
						default:
							break;
					}
				}
				else {
					return INT_MIN;
				}
				if(!isfull(&a)) {
					push(&a, result);
				}
				else {
					return INT_MIN;
				}
			}
			break;
		}
		else if(t.type == ERROR) {
			return INT_MIN;
		}
	}
        if(!isempty(&a) && len(&a) == 1 && cisempty(&b)) {
                result = pop(&a);
	}
        else {
                return INT_MIN;
	}
        if(isempty(&a) && len(&a) == 0 && cisempty(&b)) {
                return result;
	}
        else {
                return INT_MIN;
	}
}

int main(int argc, char *argv[]) {
	char line[128], x;
	int result;
	while(x = readline(line, 128)) {
		result = infixeval(line);
		printf("%d\n", result);
	}
	return 0;
}
