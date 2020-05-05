#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANIO 100

typedef struct Tarea {
    int TareaID; //Numerado en ciclo iterativo
    char *Descripcion; //
    int Duracion; // entre 10 – 100
}Tarea;

void cargarTareas (Tarea **pTPendientes, int cantidadT);
void controlarTareas(Tarea **pTPendientes, Tarea **pTRealizadas, int cantidad);
void mostrar (Tarea **pTPendientes, int cantidad);


int main(int argc, char const *argv[])
{
    int cantidadTareas;
    Tarea **TareasPendientes, **TareasRealizadas;

    printf("Ingrese la cantidad de tareas a realizar:");
    scanf("%d",&cantidadTareas);
    getchar();
    TareasPendientes = (Tarea**) malloc(sizeof(Tarea *) * cantidadTareas);
    TareasRealizadas = (Tarea**) malloc(sizeof(Tarea *) * cantidadTareas);
    cargarTareas(TareasPendientes, cantidadTareas);
    controlarTareas(TareasPendientes, TareasRealizadas, cantidadTareas);
    printf("\nLas tareas pendientes son :\n");
    mostrar(TareasPendientes, cantidadTareas);
    printf("\nLas tareas realizadas son :\n");
    mostrar(TareasRealizadas, cantidadTareas);
    free(*TareasPendientes);
    free(*TareasRealizadas);
    return 0;
}

void cargarTareas (Tarea **pTPendientes, int cantidadT)
{
    char descripcion[TAMANIO];
    
    for (int i = 0; i < cantidadT; i++)
    {
        pTPendientes[i]= (Tarea *) malloc(sizeof(Tarea));
        pTPendientes[i]->TareaID = i + 1;
        printf("El ID de la tarea es: %d\n",pTPendientes[i]->TareaID);
        printf("Ingrese una breve descripcion de la tarea a realizar:");
        gets(descripcion);
        getchar();
        pTPendientes[i]->Descripcion = (char *) malloc(sizeof(char)* strlen(descripcion));
        strcpy(pTPendientes[i]->Descripcion,descripcion);
        pTPendientes[i]->Duracion = 10+ rand()%(101-10);
    }
    printf("\nSe cargaron todas las tareaas\n");
}

void controlarTareas(Tarea **pTPendientes, Tarea **pTRealizadas, int cantidad)
{
    char respuesta;

    printf("\nModulo que verifica si la tarea fue realizada\n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("La tarea con el ID %d ¿Se realizo? Ingrese s para SI y n para NO", pTPendientes[i]->TareaID);
        scanf("%c", &respuesta);
        printf("\n");
        getchar();
        
        if (respuesta =='s')
        {
            pTRealizadas[i] = (Tarea *) malloc(sizeof(Tarea));
            pTRealizadas[i] = pTPendientes[i];
            pTPendientes[i] = NULL;
        }
    }
    printf("Se controlaron todas las tareas\n");
}
void mostrar(Tarea **pTPendientes, int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        if (pTPendientes[i])
        {
        printf("El ID de la tarea es: %d\n",pTPendientes[i]->TareaID);
        printf("Breve descripcion de la tarea:");
        puts(pTPendientes[i]->Descripcion);
        printf("La duracion de la tarea es : %d \n", pTPendientes[i]->Duracion);
        }
        
    
    }
}

