#include <stdio.h>
#include <string.h>

char to_upper(char c){
    if('a' <= c && c <= 'z')
        return c - 'a' + 'A';
    return c;
}

int main(int argc, char ** argv){
    int flag = 0;
    for(int i = 1; i < argc; i++){
        if(strncmp(*(argv + i), "-D", 2) == 0)
            flag = 1;
    }
    FILE * in = stdin;
    FILE * out = stdout;
    FILE * err = stderr;
    char c;
    while((c = fgetc(in)) != EOF){
        if(flag){
            if(c != '\n')
                fprintf(err, "%X %X\n", c, to_upper(c));
            else
                fputc(c, err);
        }
        fputc(to_upper(c), out);
    }
    return 0;
}