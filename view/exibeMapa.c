#include <stdio.h>

void exibeMapa(void) {
    
    char *filename = "mapa.txt";
    FILE *fp = fopen(filename, "r");
    
    if (fp == NULL) {
        printf("Error: could not open file %s", filename);
    }
    
    // read one character at a time and
    // display it to the output
    char ch;
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);

    // close the file
    fclose(fp);
    
}
