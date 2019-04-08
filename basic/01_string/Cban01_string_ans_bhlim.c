/*
 ============================================================================
 Name        : cban01_string.c
 Author      : bhlim
 Version     :
 Copyright   :
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_STRING 20

#define DEBUG_PRINT

struct in_data {
	int repeat;
	char str[MAX_INPUT_STRING + 1];
};

int main(void) {
	int len;
	int cnt;
	int in_rep;
	char in_str[MAX_INPUT_STRING + 1];
	struct in_data* in;

	scanf("%d", &cnt);

	in = malloc(sizeof(struct in_data)*cnt);
	memset(in, 0x00, sizeof(struct in_data)*cnt);

	for (int i = 0; i < cnt; i++) {
		scanf("%d %s", &in_rep, in_str);
		in[i].repeat = in_rep;
		strncpy(in[i].str, in_str, strlen(in_str));
	}

#ifdef DEBUG_PRINT
	printf("------------\n");
	for (int i = 0; i < cnt; i++) {
		printf("Input data[%d] - Repeat:%d  String:%s\n", i, in[i].repeat, in[i].str);
	}
	printf("------------\n");
#endif

	printf("Output:\n");
	for (int i = 0; i < cnt; i++) {
		len = strlen(in[i].str);
		for (int j = 0; j < len; j++) {
			for (int k = 0; k < in[i].repeat; k++) {
				printf("%c", in[i].str[j]);
			}
		}
	}

	return EXIT_SUCCESS;
}
