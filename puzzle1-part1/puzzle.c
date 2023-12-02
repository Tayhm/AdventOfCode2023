#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "util.h"

#define TEMPSTR_SIZE 5  // The actual size -1 to keep in mind a trailing null-byte
#define NUM_COUNT 10

// The input file has to end with a newline in order to work properly
int main(){

    FILE *fp_in;
    char c, *test;
    char digits[3] = {0};
    char tempstr[6] = {0};
    char numbers[10][6] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char digits_temp_storage[2] = {0};
    int sum, strindex, i = 0;

    fp_in = fopen("input", "r");

    if(fp_in == NULL){
        return -1;
    }
    
    while ((c = fgetc(fp_in)) != EOF)
    {
        if(isdigit(c))
        {
            printf("Found Digit: %c\n",c);
            printf("Digits before: %s\n",digits);
            if (digits[0] == 0)
            {
                digits[0] = c;
            }
            // This assignment is not in an else statement because the first digit is also the last one at the time of reading it
            digits[1] = c;

            // Now reset the string buffer
            clear_buffer(tempstr, TEMPSTR_SIZE);
            strindex = 0;

            printf("Digits after: %s\n",digits);

        }
        else if (isalpha(c))
        {
            tempstr[strindex++] = c;
            for(i = 0; i < NUM_COUNT; i++){

                // Check if any number-string is in the current buffer
                if((test = strstr(tempstr, numbers[i])) != NULL){
                    printf("FOUND SUBSTING: %s\n", test);

                    printf("Digits before: %s\n",digits);
                    if (digits[0] == 0)
                    {   
                        printf("True\n");
                        snprintf(digits_temp_storage, 2, "%d", i);
                        strncpy(&(digits[0]), digits_temp_storage, 1);
                    }
                    // This assignment is not in an else statement because the first digit is also the last one at the time of reading it
                    snprintf(digits_temp_storage, 2, "%d", i);
                    strncpy(&(digits[1]), digits_temp_storage, 1);

                    // Now reset the buffer
                    clear_buffer(tempstr, TEMPSTR_SIZE);
                    strindex = 0;
                    printf("Digits after: %s\n",digits);
                    break;
                }

            }

            // If the index is too large, shift one to the left and decrement index to be able to keep writing
            if (strindex == 5){
                shift_buffer_left(tempstr, TEMPSTR_SIZE);
                strindex = 4;
            }


        }
        
        else if(c == 0xa)   // 0xa == \n
        {
            printf("Digits: %s\n", digits);
            sum += atoi(digits);
            digits[0] = 0;
            digits[1] = 0;

            // Now also reset the tempstr
            clear_buffer(tempstr, TEMPSTR_SIZE);
            strindex = 0;
        }
    }
    
    fclose(fp_in);

    printf("Sum = %d\n", sum);

    return 0;

}