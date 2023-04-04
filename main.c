/** \file main.c
	\brief reading a string and computing some stats

	Details.
*/


#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "stringslib.h" 
#include "fileIO.h"


#define PATH_SIZE 1000


int main() {


	char filePath[PATH_SIZE]; 
	char* str;
	int* hist;
	char mos;
	int occurrences;
	char tosearch;
	int rv;
	strtoken* listPtr;

	/* ******************************   */
	printf("Enter input file: ");
	if (fgets(filePath, PATH_SIZE, stdin) == NULL) {
		printf("ERROR in Main: cannot open input file %s\n",filePath);
		return -1;

	}

	filePath[strcspn(filePath, "\n")] = 0; // removes EOL from the string

	/* ******************************   */


	/* ******************************   */ 

	listPtr = ReadLinesFromFile(filePath);
	if (listPtr == NULL) {
		printf("ERROR in Main: cannot read input file %s\n", filePath);
		return -1;
	}

	str = listPtr->token;

	/* ******************************   */

	printf("\nstring: %s\n", str);

	hist = Shist(str, TOKENL);
	if ( hist == NULL ) {
		printf("ERROR in Main: cannot compute histogram\n");
		return -1;
		
	}

	rv = MOSstring(hist, &mos, &occurrences); 
	if (rv < 0) {
		printf("ERROR in Main: cannot compute most occurring symbol\n");
		return -1;

		
	}
		
	printf("The most occurring symbol is '%c' = %d times\n", mos, occurrences);

	occurrences = AOstring(hist);
	if (occurrences < 0) {
		printf("ERROR in Main: cannot compute the occurrences of alphabet symbols\n");
		return -1;
	}
	printf("The string includes %d alphabet characters\n", occurrences);

	occurrences = DOstring(hist);
	if (occurrences < 0) {
		printf("ERROR in Main: cannot compute the occurrences of digits\n");
		return -1;
	}
	printf("The string includes %d digits\n", occurrences);


	printf("Enter a symbol: ");
	tosearch = getchar();
	occurrences = SOstring(hist, tosearch);
	if (occurrences < 0) {
		printf("ERROR in Main: cannot compute the occurrences of the symbol\n");
		return -1;
		
	}

	printf("Symbol -%c- appears %d times.", tosearch, occurrences);

	/* ******************************   */
	ClearList(listPtr);
	if (hist != NULL)
		free(hist);

	/* ******************************   */

	return 0;
}