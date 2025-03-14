#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INTENTOS 3


int validarPIN(int pinIngresado, int pin) {
        return(pinIngresado == pin);
    }

void consultarSaldo(double saldo, int cuenta)
{
        printf("Tu saldo es: $%.2f\n", saldo);
}

double depositar(double saldo, double cantidad)
{
        if (cantidad > 0)
        {
                saldo += cantidad;
                printf("Deposito exitoso. Nuevo saldo: $%.2f\n", saldo);
        }
        else
        {
                printf("Cantidad invalida.\n");
        }
        return saldo;
}

double retirar(double saldo, double cantidad)
{
        if (cantidad > 0 && cantidad <= saldo)
        {
                saldo -= cantidad;
                printf("Retiro exitoso. Nuevo saldo: $%.2f\n", saldo);
        }
        else
        {
                printf("Cantidad invalida o saldo insuficiente.\n");
        }
        return saldo;
}

void menu(int cuenta)
{
        int pinIngresado;
        int intentos = 0;
        double saldo[3] = {1000, 1500, 2000};
        int opcion;
        int  pin[3] = {1234,1233,1222};
        while (intentos < MAX_INTENTOS)
        {
                printf("Introduce tu PIN: ");
                scanf("%d", &pinIngresado); // Limita la lectura a 4 caracteres

                if (validarPIN(pinIngresado, pin[cuenta]))
                {
                        // PIN correcto, mostrar menú
                        do
                        {
                                printf("\n--- Cajero Automatico ---\n");
                                printf("1. Consultar saldo\n");
                                printf("2. Depositar\n");
                                printf("3. Retirar\n");
                                printf("4. Salir\n");
                                printf("Elige una opcion: ");
                                scanf("%d", &opcion);

                                switch (opcion)
                                {
                                case 1:
                                        consultarSaldo(saldo[cuenta],cuenta);
                                        break;
                                case 2:
                                        double cantidadDeposito;
                                        printf("Introduce la cantidad a depositar: ");
                                        scanf("%lf", &cantidadDeposito,cuenta);
                                        saldo[cuenta] = depositar(saldo[cuenta], cantidadDeposito);
                                        break;
                                case 3:
                                        double cantidadRetiro;
                                        printf("Introduce la cantidad a retirar: ");
                                        scanf("%lf", &cantidadRetiro);
                                        saldo[cuenta] = retirar(saldo[cuenta], cantidadRetiro);
                                        break;
                                case 4:
                                        printf("Gracias por usar el cajero automatico.\n");
                                        break;
                                default:
                                        printf("Opcion invalida.\n");
                                }
                        } while (opcion != 4);
                        exit(0); // Salir del programa después de un acceso exitoso
                }
                else
                {
                        printf("PIN incorrecto\n");
                        intentos++;
                }
        }

        // Si se exceden los intentos, bloquear el acceso y cerrar el programa
        printf("Acceso bloqueado");
        exit(0);
}

int main()
{
        int cuenta;
        int opcion;

        while (1)
        {

                printf("1.- Cuenta 1\n2.- Cuenta 2\n3.- Cuenta 3\n");
                scanf("%d", &cuenta);
                switch (cuenta)
                {
                case 1:
                        menu(cuenta-1);
                        break;
                case 2:
                        menu(cuenta-1);
                        break;
                        break;
                case 3:
                        menu(cuenta-1);
                        break;
                        break;

                default:
                        printf("Ingrese una cuenta valida");
                        break;
                }
        }
}