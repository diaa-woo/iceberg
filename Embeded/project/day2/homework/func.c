#include <stdio.h>
#include "header.h"

void calc(int opd1, char op, int opd2) {
	int result = 0;
	double resultD = 0;
	printf("%d %c %d = ", opd1, op, opd2);
	switch(op) {
		case '+' :
			result = opd1 + opd2;
			break;
		case '-' :	
			result = opd1 - opd2;
			break;
		case '*' :
			result = opd1 * opd2;
			break;
		case '/' :
			resultD = opd1 / opd2;
			break;
		case '%' :
			result = opd1 % opd2;
			break;
		}
	(op == '/') ? printf("%lf\n", resultD) : printf("%d\n", result);
	return;

}
