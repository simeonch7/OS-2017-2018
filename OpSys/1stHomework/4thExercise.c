//------------------------------------------------------------------------
//// NAME: Simeon Chakarov
//// CLASS: XIb
//// NUMBER: 24
//// PROBLEM: #4
//// FILE NAME: 4thExercise.c (unix file name)
//// FILE PURPOSE: A function which swaps the values of 2 arguments
////------------------------------------------------------------------------
//

#include <stdio.h>
#include <stdlib.h>

void swap(void* a, void* b, size_t size){
	char* first_swapper = a;
	char* second_swapper = b;
	char helper;
	for(int i = 0; i != size; ++i){
	helper = first_swapper[i];
	first_swapper[i] = second_swapper[i];
	second_swapper[i] = helper;
	}
}
