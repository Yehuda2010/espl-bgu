#include <stdio.h>

int main(){
    int iarray[3];
    float farray[3];
    double darray[3];
    char carray[3];

    printf("%p\n", iarray);
    printf("%p\n", iarray + 1);
    printf("%p\n", farray);
    printf("%p\n", farray + 1);
    printf("%p\n", darray);
    printf("%p\n", darray + 1);
    printf("%p\n", carray);
    printf("%p\n", carray + 1);
    return 0;
}