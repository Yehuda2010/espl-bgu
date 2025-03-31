#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char to_upper(char c){
    if('a' <= c && c <= 'z')
        return c - 'a' + 'A';
    return c;
}

int main(int argc, char ** argv){
    int flag_enc_plus = 0;
    int flag_enc_minus = 0;
    int flag_debug = 0;
    char * enc;
    int enc_index = 0;
    FILE * in = stdin;
    FILE * out = stdout;
    FILE * err = stderr;
    char c;
    for(int i = 1; i < argc; i++){
        if(strncmp(*(argv + i), "-D", 2) == 0)
            flag_debug = 1;
        if(strncmp(*(argv + i), "+e", 2) == 0){
            flag_enc_plus = 1;
            enc = *(argv + i) + 2;
        }
        if(strncmp(*(argv + i), "-e", 2) == 0){
            flag_enc_minus = 1;
            enc = *(argv + i) + 2;
        }
        if(strncmp(*(argv + i), "-i", 2) == 0){
            in = fopen(*(argv + i) + 2, "r");
            if(in == NULL){
                fprintf(err, "Can not open file...\n");
                exit(EXIT_FAILURE);
            }
        }
            
    }
    while((c = fgetc(in)) != EOF){
        if(flag_debug){
            if(c != '\n')
                fprintf(err, "%X %X\n", c, to_upper(c));
            else
                fputc(c, err);
        }
        if(c != '\n'){
            if(flag_enc_plus){
                fputc(c + *(enc + enc_index++ % strlen(enc)) - '0', out);
                continue;
            }   
            else if(flag_enc_minus){
                fputc(c - *(enc + enc_index++ % strlen(enc)) + '0', out);
                continue;
            }
        }
        else{
            enc_index = 0;
        }
        fputc(to_upper(c), out);
    }
    fclose(in);
    return 0;
}