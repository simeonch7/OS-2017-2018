//------------------------------------------------------------------------
//// NAME: Simeon Chakarov
//// CLASS: XIb
//// NUMBER: 24
//// PROBLEM: #5
//// FILE NAME: ex5.c
//// FILE PURPOSE:
//// returns a pointer to new dynamic memory in which there is a copy of the input
//// ...
////------------------------------------------------------------------------
//
#include <stdio.h>
#include <stdlib.h>
char *strdup( const char *str)                        
{
	char *c = malloc(sizeof(str));
	for(int  i = 0;i < strlen(str);i++)
	{
		c[i] = str[i];		
	}
	return c;
}
