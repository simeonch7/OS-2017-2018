//------------------------------------------------------------------------
//// NAME: Simeon Chakarov
//// CLASS: XIb
//// NUMBER: 24
//// PROBLEM: #6
//// FILE NAME: ex6.c (unix file name)
//// FILE PURPOSE:
//// Different stack functions
//------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>

typedef struct{
	size_t size;
        size_t capacity;
	int *elements;
}stack;
//------------------------------------------------------------------------
//// FUNCTION: stack_init
//// Initializates the stack
////------------------------------------------------------------------------
void stack_init( stack *my_stack ){
	my_stack->size = 0;
	my_stack->capacity = 100;
	my_stack->elements = malloc( my_stack->capacity * sizeof(int));
}	
//------------------------------------------------------------------------
//// FUNCTION: stack_destroy
//// Deinitializates the stack
////------------------------------------------------------------------------
void stack_destroy( stack *my_stack ){
	my_stack->size = 0;
	my_stack->capacity = 0;
	free(my_stack->elements);
}
//------------------------------------------------------------------------
//// FUNCTION: stack_empty
//// Chekcs if the stack is empty
////----------------------------------------------------------------------
int stack_empty( stack *my_stack ){
	if(my_stack->size != 0)
	{
	return 0;
	}else
	{
	return 1;	
	}
}
//------------------------------------------------------------------------
//// FUNCTION: stack_push
//// Pushes an element in the stack
////----------------------------------------------------------------------
void stack_push( stack *my_stack, int new_element){
	if(my_stack->size == my_stack->capacity)
	{
	my_stack->elements = realloc( my_stack->elements, my_stack->capacity + 100);
	}
	my_stack->elements[my_stack->size++] = new_element;
}
//------------------------------------------------------------------------
//// FUNCTION: stack_top
//// Returns the last pushed element in the stack
////----------------------------------------------------------------------
int stack_top( stack *my_stack ){
	return my_stack->elements[my_stack->size - 1];
}
//------------------------------------------------------------------------
//// FUNCTION: stack_top
//// Removes the last pushed element in the stack
////----------------------------------------------------------------------
void stack_pop( stack *my_stack ){
	my_stack->size--;
}
