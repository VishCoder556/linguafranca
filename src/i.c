#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "include/i.h"

I_Runtime *I_runtime_from_code(char *input_file, char *buffer){
    I_Tokenizer *tokenizer = I_tokenizer_init(input_file, buffer);
    while (I_tokenizer_token(tokenizer) == 0){
    };
    free(tokenizer->buffer);

    I_Parser *parser = I_parser_init(tokenizer);

    while (I_parser_parse_body(parser) != 0){

    }
    free(tokenizer);
    free(parser->tokens);

    I_Runtime *runtime = I_runtime_init(parser);
    while (I_runtime_setup(runtime) != 0){

    };
    return runtime;
}

I_Runtime *I_runtime_from_file(char *input_file){
    FILE *file = fopen(input_file, "r");
    if (file == NULL){
        fprintf(stderr, "ERROR: Input File '%s' does not exist\n", input_file);
        exit(-1);
    };

    fseek(file, 0, SEEK_END);
    long count = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = malloc(count + 1);
    fread(buffer, 1, count, file);
    buffer[count] = '\0';
    fclose(file);

    return I_runtime_from_code(input_file, buffer);
}
