#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    for (int i = 0; i < 10; i++) {
	printf("Child Process.\n");
    }

    exit(0);
}
