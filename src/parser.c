#include <stdio.h>
#include <stdlib.h>
#include "include/parser.h"

I_Parser *I_parser_init(I_Tokenizer *tokenizer){
    I_Parser *parser = malloc(sizeof(I_Parser));
    parser->tokens = tokenizer->tokens;
    parser->tokenlen = tokenizer->tokenlen;

    parser->asts.asthead = NULL;
    parser->asts.asttail = NULL;
    parser->asts.astlen = 0;

    parser->cur = 0;
    return parser;
}

void I_parser_parse_body(I_Parser *parser){
    if (i > parser->tokenlen){
        assert(0 && "This should be unreachable code, how did we get here?");
    }
    I_Token token = parser->tokens[i];
    assert(I_TOKEN_MAX == 8 && "Exhaustive handling of tokens -- please implement how the token should be parsed here");
    switch (token.type){
    }
}
