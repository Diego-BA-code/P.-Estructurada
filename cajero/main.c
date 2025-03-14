#include <stdio.h>
#include <stdlib.h>
#include "atm.h"

int main()
{
        int cuenta = 0;

        while (cuenta != 4)
        {
                printf("1.- Cuenta 1\n2.- Cuenta 2\n3.- Cuenta 3\n4.- Salir\n");
                scanf("%d", &cuenta);
                if (cuenta == 4) 
                {
                        break;
                }
                if (cuenta > 0 && cuenta < 4) 
                {
                        menu(cuenta - 1);
                } 
                else 
                {
                        printf("Ingrese un numero de cuenta valido\n");
                }
        }       
}
