#ifndef I_PARSER
#define I_PARSER
// TODO: Implement ASTs
#include "tokenizer.h"

typedef enum {
    I_AST_FUNCDEF,
}I_AST_BodyType;

typedef struct {
    char *name; // TODO: Implement more types
}I_AST_Body_Funcdef;

typedef struct {
    union {
        I_AST_Body_Funcdef funcdef;
    }data;
}I_AST_Body;

typedef struct {
    I_AST_Body *asthead; // First AST
    I_AST_Body *asttail; // Last AST
    int astlen; // Number of ASTs
}I_ASTs;
// Linked list implementation of ASTs

typedef struct {
    I_Token *tokens;
    int tokenlen;

    int cur;


    I_ASTs asts;
}I_Parser;




// TODO: implement types and type parsing (int, bool, etc.)


I_Parser *I_parser_init(I_Tokenizer *tokenizer);

#endif
