//------------------------------------------------------------------------
// NAME: Simeon Chakarov
// CLASS: XIb
// NUMBER: 24
// PROBLEM: #1
// FILE NAME: tail.c
// FILE PURPOSE:
// Tail function made by us
//-------------------------------------------------------------------------
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h> 
#include <stdlib.h> 
#include <fcntl.h> 
#include <stdio.h>
int main(int argc, char **argv){

  for(int count = 1; count < argc; count++){

    char *doc = argv[count];
    int open_doc = open(doc, O_RDONLY); //Here we open the files which are given.

    if(open_doc < 0){ // Checker if we can't open the file.
      char *err = malloc(strlen("tail: cannot open '") + strlen(doc) + strlen("' for reading")); 
      strcat(err, "tail: cannot open '");
      strcat(err, doc);
      strcat(err, "' for reading");
      perror(err);// We don't know how big the name of the file which is given is 
      free(err);  //so we take dynamic memory, build the error, then free the memory.

      continue;
    }
    
    char buff;   
    int reader = read(open_doc, & buff, 1);
    
    if(reader < 0){  // Checker if we can't read the file.
      char *err = malloc(strlen("tail: error reading '") + strlen(doc) + strlen("'"));
      strcat(err, "tail: error reading '");
      strcat(err, doc);
      strcat(err, "'");
      perror(err);// We don't know how big the name of the file which is given is 
      free(err);  //so we take dynamic memory, build the error, then free the memory.
      
      continue;
    }
    if(argc > 2){
      write(1, "==> ", 4);
      write(1, argv[count], strlen(argv[count]));
      write(1, " <==\n", 5); // If there are more than 1 file to read, we must print their names before their last 10 lines.
    }

    off_t size = lseek(open_doc, 0, SEEK_END); //Search for the last item so it will be faster on big files than to start from the 1st one.
    int row = 0;

    for(int r = -2; row < 10; r--){ //0 is '0', -1 is \n so we start from -2 and keep going 'til we hit the 9th line.
      size = lseek(open_doc, r, SEEK_END);
      ssize_t taken = read(open_doc, & buff, 1); //Already read items.
      if (buff == '\n'){
			 row++;
			}
    }

    row = 0;
    ssize_t read_bs;
    do{
      read_bs = read(open_doc, & buff, 1); //Here we start to read from the top.
      ssize_t write_bs = write(STDOUT_FILENO, & buff, 1); //And print from the top.
      if (buff == '\n'){
		 		row++;
			}

      if (write_bs < 0){
        char *first = "tail: error writing 'standard output'";
        perror(first); //Checker for write/frm.
        
        break;
      }
    }while (read_bs != 0 && row < 10);

    if(count != argc - 1){
			write(STDOUT_FILENO, "\n", 1);
		}

    int close_file = close(open_doc);

    if(close_file < 0){  // Checker if we can't close the file.
      char *err = malloc(strlen("tail: error reading '") + strlen(doc) + strlen("'"));
      strcat(err, "tail: error reading '");
      strcat(err, doc);
      strcat(err, "'");
      perror(err); // We don't know how big the name of the file which is given is 
      free(err); //so we take dynamic memory, build the error, then free the memory.
    }
  }
  return 0;
}
