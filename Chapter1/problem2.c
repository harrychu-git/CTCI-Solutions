#include <stdio.h>
#include <string.h>

/*  Write code to reverse a C-Style String. (C-String means that “abcd” is represented as
    five characters, including the null character.) */
    
void reverseCString(char* s) {
    int length = strlen(s);
    char* start;
    char* end;
    start = s;
    end = start + length -1;
    while(start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}


int main() {
    char* c = "Harry";
    reverseCString(c);
    
    return 0;
}