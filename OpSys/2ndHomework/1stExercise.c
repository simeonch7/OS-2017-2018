#include <stdio.h>
#include <stdint.h>

void *read_image( const char *filepath );

int main(int argc, char **argv){
        char* add = read_image(argv[1]);
        int32_t *width = add + 18;
        int32_t *height = add + 22;
        printf("BMP image width: %d\n", *width);
        printf("BMP image height: %d\n", *height);
        return 0;
}
