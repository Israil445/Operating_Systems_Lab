#include <stdio.h>
#include <string.h>

void vulnerable_function(char input[]) {
    char buffer[8];  // Small buffer on the stack
    printf("Copying input to buffer...\n");
    strcpy(buffer, input);  // Unsafe copy; can overflow buffer
    printf("Buffer contents: %s\n", buffer);
}

int main() {
    char large_input[] = "This is a string that is way too long for the buffer";
    vulnerable_function(large_input);
    return 0;
}
