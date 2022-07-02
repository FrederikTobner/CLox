#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"
#include "value.h"

#define STACK_MAX 256

//Single Global VM object
typedef struct
{
    Chunk* chunk;
    uint8_t* ip;
    //Stack based VM
    Value stack[STACK_MAX];
    Value* stackTop;
} VM;

typedef enum
{
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR,
}InterpretResult;

//Creates a new VM
void initVM();

//Deallocates the memory used by tthe VM
void freeVM();

InterpretResult interpret(Chunk* chunk);

//Pushes a new Value on the stack
void push(Value value);

//Pops a value from the stack
Value pop();

#endif