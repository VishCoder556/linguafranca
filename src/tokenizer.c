#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "tokenizer.h"

Tokenizer *tokenizer_init(char *input_file, char *buffer){
    Tokenizer *tokenizer = malloc(sizeof(Tokenizer));
    tokenizer->input_file = input_file;
    tokenizer->buffer = buffer;
    tokenizer->cur = 0;
    tokenizer->tokencap = 10; // For now
    tokenizer->tokenlen = 0;
    tokenizer->tokens = malloc(sizeof(Token) * tokenizer->tokencap);
}
