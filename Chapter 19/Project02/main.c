#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#include "stackADT2.h"

#define ADD_OPERATOR		(0)
#define SUBTRACT_OPERATOR	(1)
#define MULTIPLY_OPERATOR	(2)
#define DIVIDE_OPERATOR		(3)

int dtoi(char digit)
{
	switch (digit) {
	case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	}

	return -1;
}

int operation(int operand1, int operand2, int operator)
{
	switch (operator) {
	case ADD_OPERATOR: return operand1 + operand2;
	case SUBTRACT_OPERATOR: return operand1 - operand2;
	case MULTIPLY_OPERATOR: return operand1 * operand2;
	case DIVIDE_OPERATOR: return operand1 / operand2;
	}

	printf("Wrong operator \n");
	exit(EXIT_FAILURE);
}

int operation_code(int operator)
{
	switch (operator) {
	case '+': return ADD_OPERATOR;
	case '-': return SUBTRACT_OPERATOR;
	case '*': return MULTIPLY_OPERATOR;
	case '/': return DIVIDE_OPERATOR;
	}

	printf("Wrong operation code");
	exit(EXIT_FAILURE);
}

int main(void)
{
	Stack stack;
	int ch, number, digit;
	int operand1, operand2, operator;

	stack = create(10);

	for (;;) 
	{
		printf("Enter an RPN expression: ");
		for (digit = 0;digit != -1;) {
			ch = getchar();
			if (ch == 'q')
				exit(EXIT_SUCCESS);

			if ( isdigit(ch) ) {
				if ( digit == 0 ) {
					number = dtoi(ch);
				} else {
					number *= 10;
					number += dtoi(ch);
				}
				digit++;
			} else {
				switch (ch) {
				case '+': case '-': case '*': case '/':
					operator = operation_code(ch);
					operand2 = pop(stack);
					operand1 = pop(stack);
					
					number = operation(operand1, operand2, operator);
					digit = 1;

				case ' ':
					if (digit > 0) {
						push(stack, number);
						digit = 0;
					}
					break;

				case '=':
					number = pop(stack);
					digit = -1;
					break;
				}
			}
		}

		printf("Value of expression: %d \n", number);
	}

	return 0;
}
