/** \file main.c
	\brief reading a string and computing some stats

	Details.
*/


#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "stringslib.h"


#define STR_SIZE 1000 


int main() {


	char str[STR_SIZE];
	char outstr[STR_SIZE];
	char mos;
	int occurrences;
	char tosearch;


	printf("Enter text: ");
	if (fgets(str, STR_SIZE, stdin) == NULL) {
		printf("ERROR in Main: cannot read input tetx\n");
		return -1;

	}

	str[strcspn(str, "\n")] = 0; // removes EOL from the string

	printf("\nstring: %s\n", str);

	MOSstring(str, STR_SIZE, &mos, &occurrences);
	printf("The most occurring symbol is '%c' = %d times\n", mos, occurrences);

	occurrences = AOstring(str, STR_SIZE);
	printf("The string includes %d alphabet characters\n", occurrences);

	occurrences = DOstring(str, STR_SIZE);
	printf("The string includes %d digits\n", occurrences);


	printf("Enter a symbol: ");
	tosearch = getchar();
	occurrences = SOstring(str, STR_SIZE, tosearch);

	printf("Symbol -%c- appears %d times.", tosearch, occurrences);


	return 0;
}