#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_OVERFLOW_MESSAGE ("Expression is too complex")
#define STACK_UNDERFLOW_MESSAGE ("Not enough operands in expression")

#define STACK_SIZE (10)
#define EXP_LEN (1024)

#define ADD_OPERATOR		(0)
#define SUBTRACT_OPERATOR	(1)
#define MULTIPLY_OPERATOR	(2)
#define DIVIDE_OPERATOR		(3)

typedef int stype;

stype contents[STACK_SIZE];
int top;

void stack_overflow(void)
{
	printf("%s \n", STACK_OVERFLOW_MESSAGE);
	exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
	printf("%s \n", STACK_UNDERFLOW_MESSAGE);
	exit(EXIT_FAILURE);
}

void make_empty(void)
{
	top = 0;
}

bool is_empty(void)
{
	return (top == 0);
}

bool is_full(void)
{
	return (top == STACK_SIZE);
}

void push(stype i)
{
	if ( is_full() )
		stack_overflow();

	contents[top++] = i;	
}

stype pop(void)
{
	if ( is_empty() )
		stack_underflow();
	
	return contents[--top];
}

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

int evaluate_RPN_expression(const char *exp)
{
	int ch, number, digit;
	int operand1, operand2, operator;

	for (digit = 0;digit != -1;) {
		ch = *exp++;
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
				operand2 = pop();
				operand1 = pop();
				
				number = operation(operand1, operand2, operator);
				digit = 1;

			case ' ':
				if (digit > 0) {
					push(number);
					digit = 0;
				}
				break;

			case '=':
				number = pop();
				digit = -1;
				break;
			}
		}
	}
	
	return number;
}

int main(void)
{
	char expression[EXP_LEN];

	fputs("Enter an RPN expression: ", stdout);
	fgets(expression, EXP_LEN, stdin);
	
	printf("Value of expression: %d \n", 
			evaluate_RPN_expression(expression));

	return 0;
}
