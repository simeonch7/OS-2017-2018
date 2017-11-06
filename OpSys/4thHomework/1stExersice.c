//------------------------------------------------------------------------
// NAME: Simeon Chakarov
// CLASS: XIB
// NUMBER: 24
// PROBLEM: #1
// FILE NAME: 1stExercise.c (unix file name)
// FILE PURPOSE: A program in C that opens a file which is set as first argument, miss X lines which is set as second argument and print the characters 'til the file ends or 'til X characters are printed which is set as third argument.
//------------------------------------------------------------------------
//------------------------------------------------------------------------
// FUNCTION: main
// It's only one function which does the things described in "FILE PURPOSE"
// PARAMETERS:
// The first four are described in "FILE PURPOSE"
// buffer - parsed symbol ATM
// porter - Sets the file to atoi(argv[2])-nd byte
//------------------------------------------------------------------------

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv){
	const char *doc = argv[1];
	int opener = open(doc, 0, O_RDONLY);
	int number_of_bytes_to_skip = atoi(argv[2]);
	int number_of_bytes_to_print = atoi(argv[3]);
	
	off_t porter = lseek(opener, number_of_bytes_to_skip, SEEK_SET);

	for(int b = 0; b < number_of_bytes_to_print; ++b){
		char buffer;
		int reader = read(opener, &buffer, 1);
		if(reader == 0)		
			break;
		write(1, &buffer, 1);
	}
	close(opener);
	return 0;
}
