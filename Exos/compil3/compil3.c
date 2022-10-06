#include <stdlib.h>
#include <stdio.h>

int var_globale_non_init;
int  var_globale_init = 1;
const int var_const = 2;

int foo()
{
    int var_locale2;
    printf("pile2 %p\n", &var_locale2);
}

int main ()
{
    int var_locale1;
    int* adresse_var_tas = (int*) malloc (sizeof(int));

    printf("pile1 %p\n", &var_locale1);
    foo();
    printf("data %p\n",&var_globale_init);
    printf("rodata %p\n", &var_const);
    printf("bss %p\n", &var_globale_non_init); 
    printf("tas %p\n", adresse_var_tas);
    printf("txt %p\n", main);

	return 0;
}