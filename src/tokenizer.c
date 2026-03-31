#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "include/tokenizer.h"

Tokenizer *tokenizer_init(char *input_file, char *buffer){
    Tokenizer *tokenizer = malloc(sizeof(Tokenizer));
    tokenizer->input_file = input_file;
    tokenizer->buffer = buffer;
    tokenizer->cur = 0;
    tokenizer->col = 0;
    tokenizer->row = 0;
    tokenizer->tokencap = 10; // For now
    tokenizer->tokenlen = 0;
    tokenizer->tokens = malloc(sizeof(Token) * tokenizer->tokencap);
    return tokenizer;
}

void tokenizer_append(Tokenizer *tokenizer, TokenType type, char *value){
    tokenizer->tokens[tokenizer->tokenlen++] = (Token){type, value};
}

char tokenizer_token(Tokenizer *tokenizer){
    char c = tokenizer->buffer[tokenizer->cur];

    assert(TOKEN_MAX == 3 && "Exhaustive handling of tokens -- please implement token here");
    // Assertion style copied from Tsoding Daily in his programming language Porth (P.S. you should check it out);

    switch (c){
        case '=': tokenizer_append(tokenizer, TOKEN_EQ, "="); break;
        case '\n': tokenizer->row++; tokenizer->col = 0; goto end;
        case ' ': goto increment;
        case '\t': goto increment;
        case '\0': return -1;
        default:
            if (isalpha(c)){
                int valuecap = 100;
                char *value = malloc(valuecap);
                int len = 0;
                while (isalpha(c)){
                    if (len >= valuecap){
                        valuecap += 5;
                        value = realloc(value, valuecap);
                    }
                    value[len++] = c;
                    tokenizer->cur++; tokenizer->col++;
                    c = tokenizer->buffer[tokenizer->cur];
                }
                tokenizer_append(tokenizer, TOKEN_ID, value);
                goto increment;
            }else if (isnumber(c)){
                int valuecap = 100;
                char *value = malloc(valuecap);
                int len = 0;
                while (isnumber(c)){
                    if (len >= valuecap){
                        valuecap += 5;
                        value = realloc(value, valuecap);
                    }
                    value[len++] = c;
                    tokenizer->cur++; tokenizer->col++;
                    c = tokenizer->buffer[tokenizer->cur];
                }
                tokenizer_append(tokenizer, TOKEN_INT, value);
                goto increment;
            }
    }
increment:
    tokenizer->cur++;
    tokenizer->col++;
end:
    return 0;
}
