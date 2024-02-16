#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _empleado
{
    char *nombre;
    char *apP;
    char *apM;
    char *id;

}Templeado;

typedef struct _nodo
{
    Templeado empleado;
    struct nodo *siguiente;
    
}Tnodo;

typedef struct _lista
{
    Tnodo *cabeza;
}Tlista;

Tnodo* CrearNodo(Templeado* empleado)
{
    Tnodo* nodo=(Tnodo*) malloc(sizeof(Tnodo));
    strcpy(nodo->empleado.id,empleado->id);
    strcpy(nodo->empleado.nombre,empleado->nombre);
    strcpy(nodo->empleado.apP,empleado->apP);
    strcpy(nodo->empleado.apM,empleado->apM);
    nodo->siguiente=NULL;
    return nodo;
}
void DestruirNodo(Tnodo *nodo)
{
    free(nodo);
}

void InsertarAlPrincipio(Tlista* lista, Templeado* empleado)
{
    Tnodo* nodo = CrearNodo(empleado);
    nodo->siguiente = lista->cabeza;   
}

int main()
{
   

}