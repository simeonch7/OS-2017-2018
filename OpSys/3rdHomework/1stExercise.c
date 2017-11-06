//------------------------------------------------------------------------
// NAME: Simeon Chakarov
// CLASS: XIB
// NUMBER: 24
// PROBLEM: #1
// FILE NAME: 1stExercise.c (unix file name)
// FILE PURPOSE: A program in C that prints the first 10 lines of the file a.txt
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// FUNCTION: main
// Open a.txt, read the same file and print it's first 10 lines
// PARAMETERS:
// doc - open the file with it
// parsed - parse every single letter(byte) and put it into this var
//------------------------------------------------------------------------

#include <stdio.h>
#include <fcntl.h> //so we can use read(); write(); open(); close();

int main() {
  int doc = open("a.txt", O_RDONLY);
  char parsed;
  for (int n = 0; read(doc, & parsed, 1) > 0 && n < 10;) {
    write(1, & parsed, 1); // realisation of the output of the program.
    if (parsed == '\n') n++; // if the byte is a new line, we mark it down so we count 10 lines.
  }
  close(doc);//here we close the file.
  return 0;
}
