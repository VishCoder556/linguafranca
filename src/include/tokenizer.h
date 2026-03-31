typedef enum {
    TOKEN_ID,
    TOKEN_EQ,
    TOKEN_INT,
    // Keep adding on eventually
}TokenType;

typedef struct {
    char *value;
    TokenType type;
}Token;

typedef struct {
    char *input_file:
    char *buffer;


    Token *tokens;
    int tokencap;
    int tokenlen;


    int cur;
}Tokenizer;


Tokenizer *tokenizer_init(char *input_file, char *buffer);
