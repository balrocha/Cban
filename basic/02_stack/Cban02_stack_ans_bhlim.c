/*
 ============================================================================
 Name        : Cban02_stack.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define STR_YES "YES"
#define STR_NO "NO"

#define MAX_STR_LEN 50

#undef DEBUG_PRINT

char stack[50];
int top = 0;

void initStack() {
	top = 0;
}

int pushChar(char ch) {
	if (top >= MAX_STR_LEN) {
		return -1;
	}
	else {
		stack[top] = ch;
		top++;
	}

	return 1;
}

int isStackEmpty() {
	if (top <= 0) {
		return 1;
	}

	return 0;
}

char popChar() {
	char ch = stack[top];
	top--;

	return ch;
}


int checkParenthesisPair(char* str) {
	char ch;
	int len = strlen(str);

	initStack();

	for (int i = 0; i < len; i++) {
		ch = str[i];
		if (ch == '(') {
			if (pushChar(ch) == -1) {
				printf("Stack Overflow\n");
				return 0;
			}
		}
		else if (ch == ')') {
			if (isStackEmpty()) {
				return 0;
			}
			popChar(ch);
		}
	}

	if (isStackEmpty())
		return 1;

	return 0;
}

int main(void) {
	int inCnt;
	char** pptr = NULL;

	// Get user input for test count
	scanf ("%d\n", &inCnt);

	// Allocate memory for pointer array
	pptr = (char**) malloc (sizeof(char*) * inCnt);

	for (int i = 0; i < inCnt; i++) {
		pptr[i] = malloc (sizeof(char) * (MAX_STR_LEN+1));
		memset (pptr[i], 0x00, MAX_STR_LEN+1);
		gets(pptr[i]);
	}

#ifdef DEBUG_PRINT
	for (int i = 0; i < inCnt; i++) {
		printf("%-2d: %s\n", i, pptr[i]);
	}
#endif

	printf("\n");

	for (int i = 0; i < inCnt; i++) {

		if(checkParenthesisPair(pptr[i]) == 1) {
			printf("%s\n", STR_YES);
		}
		else {
			printf("%s\n", STR_NO);
		}
	}

	// Free Memory
	for (int i = 0; i < inCnt; i++) {
		free(pptr[i]);
	}
	free(pptr);

	return EXIT_SUCCESS;
}
