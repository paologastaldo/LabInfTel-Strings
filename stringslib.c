/*! \file stringslib.c
    \brief Implementations of the functions declared in stringlib.h

    Details.
*/



#include "stringslib.h"

/*!	@brief finds most occurent ASCII symbol in a string
    @param instr input string
    @param length string length
    @param moc most occuring character (pointer to)
    @param occurrences frequency of the moc (pointer to)
*/
void MOSstring(char* instr, int length, char* mos, int* occurrences) {

    int freq[HIST_BINS]; /* Store frequency of each character */
    int i = 0;
    int max = 0;
    int ascii;

    /* Initializes frequency of all characters to 0 */
    for (i = 0; i < HIST_BINS; i++)
        freq[i] = 0;

    /* Finds frequency of each character */
    i = 0;
    while (instr[i] != '\0' && i < length)
    {
        ascii = (int)instr[i];
        freq[ascii] += 1;

        i++;
    }


    /* Finds maximum frequency */
    max = 0;
    for (i = 0; i < HIST_BINS; i++)
    {
        if (freq[i] > freq[max])
            max = i;
    }

    *mos = (char)max;
    *occurrences = freq[max];

    return;

}

/*! @brief finds in a string the occurrences of a given ASCII symbol
    @param instr string
    @param length of the string
    @param tosearch the character
    @return occurences of the character
*/
int SOstring(char* instr, int length, char tosearch) {

    int i = 0;
    int occurrences = 0;

    while (instr[i] != '\0' && i < length)
    {
        if (instr[i] == tosearch)
            occurrences++;

        i++;
    }

    return occurrences;
}

/*! @brief finds in a string the occurrences of digits
    @param instr string
    @param length of the string
    @return occurences of digits
*/
int DOstring(char* instr, int length) {

    int i = 0;
    int occurrences = 0;

    while (instr[i] != '\0' && i < length)
    {
        if (instr[i] > 47 && instr[i] < 58)
            occurrences++;

        i++;
    }

    return occurrences;
}

/*! @brief finds in a string the occurrences of alphabet characters
    @param instr string
    @param length of the string
    @return occurences of alphabet characters
*/
int AOstring(char* instr, int length) {

    int i = 0;
    int occurrences = 0;

    while (instr[i] != '\0' && i < length)
    {
        if ((instr[i] > 64 && instr[i] < 91) || (instr[i] > 96 && instr[i] < 123))
            occurrences++;

        i++;
    }

    return occurrences;
}
