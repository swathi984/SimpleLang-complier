#include <stdio.h>
#include <stdlib.h>  
#include "lexer.h"
#include "parser.h"

int main() {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        perror("Failed to open input.txt");
        exit(1);
    }

    printf("Starting parsing...\n");
    parse(file);
    fclose(file);
    
    return 0;
}
