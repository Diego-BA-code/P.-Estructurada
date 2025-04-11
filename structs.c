#include <stdio.h>
#include <string.h>

struct Estudiante{
    char nombre[50];
    int edad;
    float promedio;
};

struct Materias{
    char nombre[50];
    float calificacion;
    int creditos;
};
void imprimir_datos_estudiante(struct Estudiante *estudiante){
    printf("Nombre del estudiante: %s\n",estudiante->nombre);
    printf("Edad del estudiante: %d\n", estudiante->edad);
    printf("Promedio del estudiante: %.2f\n", estudiante->promedio);
}


void calcular_promedio(struct Estudiante *estudiante, struct Materias segundo[]){
    for(int i = 0; i < 3; i++){
        printf("Ingrese la calificacion de %s: ", segundo[i].nombre);
        scanf("%f",&segundo[i].calificacion);
    }
    estudiante->promedio = (segundo[0].calificacion + segundo[1].calificacion + segundo[2].calificacion)/3;
}

int main()
{

    struct Estudiante ana = {"Ana Garcia", 19,9.5};
    struct Materias segundo[3] = {{"Programacion estructurada",0,8},{"Matematicas",0,8},{"Ingles",0,8}};


    imprimir_datos_estudiante(&ana);

    calcular_promedio(&ana,&segundo);

    imprimir_datos_estudiante(&ana);

    return 0;
}
