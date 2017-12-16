//------------------------------------------------------------------------
// NAME: Simeon Chakarov
// CLASS: XIb
// NUMBER: 24
// PROBLEM: #1
// FILE NAME: multifork.c (unix file name)
// FILE PURPOSE:
//A program which executes an imputted program multiple times at 
//the same time
//------------------------------------------------------------------------

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

int main (int argc, char **argv) {

	char *path = argv[2];

	for(int count = 0; count < atoi(argv[1]); count++){
		pid_t process_id = fork();
		
		if(process_id == 0){
				if(execl(path, path, argv[3], (char *)0) == -1){					
				char err[100] = "./multifork: \0";
				
				strcat(err, argv[2]);
				perror(err);
				kill(process_id, SIGKILL);				
			}	
		}
		else if (process_id < 0){ 
			perror("OOOPS!!! FORK ERROR!");			
		}
		else
		{
			waitpid(process_id, 0, 0);
		}
	}	
}
