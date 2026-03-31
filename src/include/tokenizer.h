typedef enum {
    TOKEN_ID,
    TOKEN_EQ,
    TOKEN_INT,

    
    TOKEN_MAX, // Marker to know how many tokens we have
    // Keep adding on eventually
}TokenType;

typedef struct {
    TokenType type;
    char *value;
}Token;

typedef struct {
    char *input_file;
    char *buffer;


    Token *tokens;
    int tokencap;
    int tokenlen;


    int cur;

    int col;
    int row;
}Tokenizer;


Tokenizer *tokenizer_init(char *input_file, char *buffer);

char tokenizer_token(Tokenizer *tokenizer);
