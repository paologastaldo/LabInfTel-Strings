/*! \file stringslib.h
	\brief Library of functions for extracting infos from a string

	Details.
*/


#ifndef STRINGSLIB_H 
#define STRINGSLIB_H

#define HIST_BINS 256 /* Number of bins in the char histogram */



void MOSstring(char* instr, int length, char* mos, int* occurrences);
int SOstring(char* instr, int length, char tosearch);
int DOstring(char* instr, int length);
int AOstring(char* instr, int length);

#endif