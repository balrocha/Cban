/*
 ============================================================================
 Name        : Cban03_countword.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#undef DEBUG_PRINT

#define MAX_STR_IDX 1000000

char inputStr[MAX_STR_IDX + 1];

int isAlphabet(char ch) {
	if (ch >= 'a' && ch <= 'z') return 1;
	if (ch >= 'A' && ch <= 'Z') return 1;

	return 0;
}


int countWord(char *str) {
	int totalLen = strlen(str);
	int count = 0;
	int fWordEnd = 1;
	char ch;

#ifdef DEBUG_PRINT
	printf("input string length : %d\n", totalLen);
#endif

	for (int i = 0; i < totalLen; i++) {
		ch = str[i];
		if (ch == ' ') {
			fWordEnd = 1;
		}
		else if (isAlphabet(ch)){
			if (fWordEnd) {
				count++;
				fWordEnd = 0;
			}
		}
	}

	return count;
}

int main(void) {

	memset(inputStr, 0x00, MAX_STR_IDX+1);

	// 공백을 포함한 문자열을 입력 받는 2가지 방법
	gets(inputStr);
	//scanf("%[^\n]", inputStr);

	printf("Total words number: %d\n", countWord(inputStr));

	return EXIT_SUCCESS;
}
