/*
 ============================================================================
 Name        : Cban04_sorting.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#undef DEBUG_PRINT

#define MAX_WORD_COUNT 20000
#define MAX_WORD_LEN 50

char** pptr;
char inputStr[MAX_WORD_LEN+1];

void swap(char** a, char** b) {
	char* temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void sortWord(char** input, int wordCnt) {

#ifdef DEBUG_PRINT
	for (int i = 0; i < wordCnt; i++) {
		printf("%-2d : %s\n", i, input[i]);
	}
#endif

	for (int i = 0; i < wordCnt; i++) {
		for (int j = i+1; j < wordCnt; j++) {
			int aLen = strlen(input[i]);
			int bLen = strlen(input[j]);

#ifdef DEBUG_PRINT
			printf("(%d:%d), (%d,%d)\n", i, aLen, j, bLen);
#endif

			if(aLen > bLen) {
#ifdef DEBUG_PRINT
				printf("length swap\n");
#endif
				swap(&input[i], &input[j]);
			}
			else if(aLen == bLen) {
				int cmpRslt;

				cmpRslt = strncmp(input[i], input[j], aLen);

				if (cmpRslt > 0) {
#ifdef DEBUG_PRINT
					printf("alphabet swap: %s - %s\n", input[i], input[j]);
#endif
					swap(&input[i], &input[j]);
				}
			}
		}
	}
}

void printResult(char** rslt, int rsltCnt) {
	char printStr[MAX_WORD_LEN+1] = {'\0', };

	for (int i = 0; i < rsltCnt; i++) {
		if (strcmp(printStr, rslt[i]) != 0) {
			strcpy(printStr, rslt[i]);
			printf("%s\n", printStr);
		}
	}
}

int main(void) {
	int lineNum = 0;

	scanf("%d", &lineNum);

	if (lineNum < 1 || lineNum > MAX_WORD_COUNT) {
		printf("Invalid input for word count!");
		return EXIT_FAILURE;
	}

	pptr = (char**)malloc(sizeof(char*) * lineNum);

	for (int i = 0; i < lineNum; i++) {
		int wordLen;

		scanf("%s", inputStr);

		wordLen = strlen(inputStr);
		pptr[i] = (char*)malloc(sizeof(char) * wordLen);

		strncpy(pptr[i], inputStr, wordLen+1);
	}

	sortWord(pptr, lineNum);

	printf("\n");

	printResult(pptr, lineNum);

	// Free allocated memory
	for (int i = 0; i < lineNum; i++) {
		free(pptr[i]);
	}
	free(pptr);

	return EXIT_SUCCESS;
}
