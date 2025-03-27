#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "lexer.h"

void getNextToken(FILE *file, Token *token) {
    int c;
    
    while ((c = fgetc(file)) != EOF) {
        if (isspace(c)) continue;

        if (isalpha(c)) {
            int len = 0;
            token->text[len++] = c;
            while (isalnum(c = fgetc(file))) {
                if (len < 99) token->text[len++] = c;
            }
            ungetc(c, file);
            token->text[len] = '\0';

            if (strcmp(token->text, "int") == 0) token->type = TOKEN_INT;
            else token->type = TOKEN_IDENTIFIER;
            return;
        }

        if (isdigit(c)) {
            int len = 0;
            token->text[len++] = c;
            while (isdigit(c = fgetc(file))) {
                if (len < 99) token->text[len++] = c;
            }
            ungetc(c, file);
            token->text[len] = '\0';
            token->type = TOKEN_NUMBER;
            return;
        }

        switch (c) {
            case '=': token->type = TOKEN_ASSIGN; strcpy(token->text, "="); return;
            case '+': token->type = TOKEN_PLUS; strcpy(token->text, "+"); return;
            case '-': token->type = TOKEN_MINUS; strcpy(token->text, "-"); return;
            case '{': token->type = TOKEN_LBRACE; strcpy(token->text, "{"); return;
            case '}': token->type = TOKEN_RBRACE; strcpy(token->text, "}"); return;
            case ';': token->type = TOKEN_SEMICOLON; strcpy(token->text, ";"); return;
            default: token->type = TOKEN_UNKNOWN; sprintf(token->text, "%c", c); return;
        }
    }

    token->type = TOKEN_EOF;
    token->text[0] = '\0';
}
