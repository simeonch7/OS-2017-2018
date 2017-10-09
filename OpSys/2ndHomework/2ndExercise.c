#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>

void *read_image( const char *filepath );

int main(int argc, char **argv){
	if(read_image(argv[1]) == NULL){
	printf("Unable to open file\n");
	}else{
		char *last_symbol;
		for(last_symbol = argv[1]; *last_symbol!='\0'; last_symbol++);
		if(*(last_symbol - 1) != 'g' &&
			*(last_symbol - 2) != 'n' &&
			*(last_symbol - 3) != 'g'){
		printf("Unable to parse file\n");
		}
		else{
		char* add = read_image(argv[1]);
		uint32_t *width = add + 16;
		uint32_t *height = add + 20;
		uint32_t height1 = ntohl(*height);
		uint32_t width1 = ntohl(*width);
		printf("PNG image width: %d\n", width1);
		printf("PNG image height: %d\n", height1);
		int size = 0;
		for(;;){
			if(add[size] == 'I' &&
			add[size+1] == 'E' &&
			add[size+2] == 'N' &&
			add[size+3] == 'D'){
			break;
			}
			size++;
		}
		size += 8;
		printf("PNG file size: %d\n", size);
		}
	}
	return 0;	
}
