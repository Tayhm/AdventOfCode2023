
void shift_buffer_left(char* buffer, int size){

    int i;
    
    for (i = 0; i < (size-1); i++)
    {
        buffer[i] = buffer[i + 1];
    }
    
    buffer[i] = 0;

}

void clear_buffer(char* buffer, int size){

    int i;

    for(i = 0; i < size; i++){
        buffer[i] = 0;
    }

}