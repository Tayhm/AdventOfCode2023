#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_SIZE 1024

int main(){
    
    FILE *input;
    char line[LINE_SIZE];
    char *current, *color_name;
    int is_possible;
    int max_red = 12;
    int max_green = 13;
    int max_blue = 14;
    int id, sum, red, green, blue, num_current = 0;

    input = fopen("input", "r");

    if (input == NULL)
    {
        return -1;
    }
    
    // Also check strlen to account for a trailing blank line
    while(fgets(line, LINE_SIZE, input) != NULL && strlen(line) > 4){
        
        id++;
        is_possible = 1;

        //First skip to the actual data, don't care about "game" etc:
        current = strstr(line, ":");
        current += 2;   //Also skip the space that comes after the colon

        while(current != (void*)0x1){ //Until current is (almost) null
            
            // Set the next space to 0 to use atoi next
            color_name = strstr(current, " ");
            *color_name++ = 0;

            num_current = atoi(current);

            switch(*color_name){

                case (int)'r':
                    if(num_current > max_red){
                        is_possible = 0;
                    }
                    break;
                case (int)'g':
                    if(num_current > max_green){
                        is_possible = 0;
                    }
                    break;
                case (int)'b':
                    if(num_current > max_blue){
                        is_possible = 0;
                    }
                    break;

            }

            // In case of end of line, this can become one
            current = strstr(color_name, " ") + 1;

        }

        if(is_possible){
            sum += id;
        }

    }

    printf("Result = %d\n", sum);

    return 0;

}