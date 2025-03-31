#include <stdio.h>

char to_upper(char c){
    if('a' <= c && c <= 'z')
        return c - 'a' + 'A';
    return c;
}

int main(int argc, char ** argv){
    FILE * in = stdin;
    FILE * out = stdout;
    char c;
    while((c = fgetc(in)) != EOF){
        fputc(to_upper(c), out);
    }
    return 0;
}