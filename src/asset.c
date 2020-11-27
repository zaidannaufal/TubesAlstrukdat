#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 128

// $ ********** IMPLEMENTASI **********

void print_image(char *filename) {
    FILE *fptr = NULL;

    if ((fptr = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "error opening %s\n", filename);
    }
    char read_string[MAX_LEN];
    while (fgets(read_string, sizeof(read_string), fptr) != NULL)
        printf("%s", read_string);
    fclose(fptr);
}

void Menuawal() {
    print_image("../external/menuawal.txt");
}
void Menu() {
    print_image("../external/menu.txt");
}