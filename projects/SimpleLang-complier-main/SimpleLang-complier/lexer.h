#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>

typedef enum {
    TOKEN_INT, TOKEN_IDENTIFIER, TOKEN_NUMBER, TOKEN_ASSIGN, 
    TOKEN_PLUS, TOKEN_MINUS, TOKEN_LBRACE, TOKEN_RBRACE, TOKEN_SEMICOLON, 
    TOKEN_EOF, TOKEN_UNKNOWN
} TokenType;

typedef struct {
    TokenType type;
    char text[100];
} Token;

void getNextToken(FILE *file, Token *token);

#endif
