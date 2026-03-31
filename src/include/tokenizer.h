typedef enum {
    TOKEN_ID,
    TOKEN_EQ,
    TOKEN_INT,
    TOKEN_LB,
    TOKEN_RB,
    TOKEN_LP,
    TOKEN_RP,
    
    TOKEN_MAX, // Marker to know how many tokens we have
    // Keep adding on eventually
}I_TokenType;

typedef struct {
    I_TokenType type;
    char *value;
}I_Token;

typedef struct {
    char *input_file;
    char *buffer;
    int bufferlen;


    I_Token *tokens;
    int tokencap;
    int tokenlen;


    int cur;

    int col;
    int row;
}I_Tokenizer;


I_Tokenizer *I_tokenizer_init(char *input_file, char *buffer);

char I_tokenizer_token(I_Tokenizer *tokenizer);
