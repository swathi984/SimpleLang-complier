#include <stdio.h>
#include "lexer.h"
#include "parser.h"

void parse(FILE *file) {
    Token token;
    getNextToken(file, &token);

    while (token.type != TOKEN_EOF) {
        printf("Parsed token: %s\n", token.text);
        getNextToken(file, &token);
    }
}
