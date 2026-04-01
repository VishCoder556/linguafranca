#ifndef I_EXEC
#define I_EXEC

#include "parser.h"

// Execution header file for I programming language


/*
 * I_function_create((I_Runtime *runtime) => {
 *      printf("%s", I_runtime_get_arg(runtime, I_RUNTIME_STRING));
 * });
 *
 *
 *
*/

typedef enum {
    I_RUNTIME_STRING,
    I_RUNTIME_INT,
    I_RUNTIME_MAX
}I_Runtime_ArgType;

typedef struct {
    I_Runtime_ArgType type;
    void *ptr;
}I_Runtime_Arg;


typedef struct {
    LinkedList(I_AST_Statement);
    struct I_Runtime_Function *next;
}I_Runtime_Function;

// Runtime struct for I, contains important metadata
typedef struct {
    LinkedList(I_AST_Body); // These are the old ASTs that will be converted soon
    I_AST_Body *cur;
    int idx;

    LinkedList(I_Runtime_Arg); // I features an argument stack for functions
    LinkedList(I_Runtime_Function); // List of functions defined
}I_Runtime;


I_Runtime *I_runtime_init(I_Parser *parser);

// I_runtime_setup gets the runtime ready for execution
char I_runtime_setup(I_Runtime *runtime);

#endif
