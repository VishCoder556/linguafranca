#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "include/exec.h"

I_Runtime *I_runtime_init(I_Parser *parser){
    I_Runtime *runtime = malloc(sizeof(I_Runtime));

    runtime->I_AST_Body_head = parser->asts.asthead;
    runtime->I_AST_Body_tail = parser->asts.asttail;
    runtime->I_AST_Body_len = parser->asts.astlen;

    InitLinkedList((*runtime), I_Runtime_Arg);
    InitLinkedList((*runtime), I_Runtime_Function);

    runtime->cur = GetLinkedListHead((*runtime), I_AST_Body);
    runtime->idx = 0;

    return runtime;
}

char I_runtime_advance(I_Runtime *runtime){
    if (runtime->idx >= GetLinkedListLen((*runtime), I_AST_Body)){
        return 1;
    }
    runtime->cur = GetLinkedListNextElem(runtime->cur);
    runtime->idx++;
    return 0;
}


char I_runtime_setup(I_Runtime *runtime){
    I_AST_Body *cur = runtime->cur;
    if (cur->type == I_AST_BODY_FUNCDEF){
// Runtime Setup is pretty simple: it just gets all of the structures ready
        I_Runtime_Function func = (I_Runtime_Function){0};
        SetLinkedList(func, cur->data.funcdef, I_AST_Statement);
        AppendToLinkedList((*runtime), I_Runtime_Function, func);
    };
    if (I_runtime_advance(runtime) == 1){
        return 0;
    };
    return 1;
    // I_AST_Body body = ;
}
