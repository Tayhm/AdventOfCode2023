#include "util.h"

void shift_buffer_left(char* buffer, int size, int distance){

    int i;
    
    for (i = 0; i < (size-distance); i++)
    {
        buffer[i] = buffer[i + distance];
    }
    
    clear_buffer(buffer+i, distance);

}

void clear_buffer(char* buffer, int size){

    int i;

    for(i = 0; i < size; i++){
        buffer[i] = 0;
    }

}