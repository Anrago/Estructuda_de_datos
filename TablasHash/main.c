// Antonio Ramos Gonzalez
// 372576
// Practica 5.- Tablas Hash

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SizeT 15

typedef struct _nodo
{
    char *Clave;
    char *Nombre;
    struct _nodo *Siguiente;
} Tnodo;

int PrintMenu();
unsigned int Hash(char *Clave);
Tnodo *CreateNodo(char *clave, char *nombre);
void Insertar(Tnodo *TablaH[], char *Clave, char *Nombre);
char *Buscar(Tnodo *TablaH[], char *Clave);
void Eliminar(Tnodo *TablaH[], char *Clave);
void Modificar(Tnodo *TablaH[], char *Clave);
void ImprimirTabla(Tnodo *TablaH[]);
void LiberarTabla(Tnodo *TablaH[]);

int main()
{
    Tnodo *TablaH[SizeT] = {NULL};
    int opc;
    char Clave[256];
    char Nombre[256];
    do
    {
        system("CLS");
        opc = PrintMenu();
        system("CLS");
        switch (opc)
        {
        case 1:
            printf("Ingrese la clave: ");
            scanf("%s", Clave);
            printf("Ingrese el nombre: ");
            scanf("%s", Nombre);
            Insertar(TablaH, Clave, Nombre);
            break;
        case 2:
            printf("Ingrese la clave: ");
            scanf("%s", Clave);
            printf("Nombre: %s\n", Buscar(TablaH, Clave));
            system("PAUSE");
            break;
        case 3:
            printf("Ingrese la clave: ");
            scanf("%s", Clave);
            Eliminar(TablaH, Clave);
            system("PAUSE");
            break;
        case 4:
            printf("Ingrese la clave: ");
            scanf("%s", Clave);
            Modificar(TablaH, Clave);
            break;
        case 5:
            ImprimirTabla(TablaH);
            system("PAUSE");
            break;
        }
    } while (opc != 0);
    LiberarTabla(TablaH);
    return 0;
}

Tnodo *CreateNodo(char *clave, char *nombre)
{
    Tnodo *nodo = (Tnodo *)malloc(sizeof(Tnodo));
    nodo->Clave = strdup(clave);
    nodo->Nombre = strdup(nombre);
    nodo->Siguiente = NULL;
    return nodo;
}

unsigned int Hash(char *Clave)
{
    unsigned int hash = 0;
    while (*Clave)
    {
        hash = (hash << 5) + *Clave++;
    }
    return hash % SizeT;
}

void Insertar(Tnodo *TablaH[], char *Clave, char *Nombre)
{
    unsigned int Indice = Hash(Clave);
    Tnodo *nodo = CreateNodo(Clave, Nombre);
    if (TablaH[Indice] == NULL)
    {
        TablaH[Indice] = nodo;
    }
    else
    {
        Tnodo *temp = TablaH[Indice];
        while (temp->Siguiente != NULL)
        {
            temp = temp->Siguiente;
        }
        temp->Siguiente = nodo;
    }
}

char *Buscar(Tnodo *TablaH[], char *Clave)
{
    unsigned int Indice = Hash(Clave);

    Tnodo *temp = TablaH[Indice];
    while (temp != NULL)
    {
        if (strcmp(temp->Clave, Clave) == 0)
            return temp->Nombre;
        temp = temp->Siguiente;
    }
    return NULL;
}

void Eliminar(Tnodo *TablaH[], char *Clave)
{
    unsigned int Indice = Hash(Clave);
    Tnodo *temp = TablaH[Indice];
    Tnodo *prev = NULL;

    while (temp != NULL && strcmp(temp->Clave, Clave) != 0)
    {
        prev = temp;
        temp = temp->Siguiente;
    }

    if (temp == NULL)
        return;

    if (prev == NULL)
    {
        TablaH[Indice] = temp->Siguiente;
    }
    else
    {
        prev->Siguiente = temp->Siguiente;
    }
}

void Modificar(Tnodo *TablaH[], char *Clave)
{
    unsigned int Indice = Hash(Clave);
    char NuevoNombre[256];
    printf("INGRESE NUEVO NOMBRE: ");
    scanf("%s", NuevoNombre);
    Tnodo *temp = TablaH[Indice];
    while (temp != NULL)
    {
        if (strcmp(temp->Clave, Clave) == 0)
        {
            free(temp->Nombre);
            temp->Nombre = strdup(NuevoNombre);
            break;
        }
        temp = temp->Siguiente;
    }
}

void ImprimirTabla(Tnodo *TablaH[])
{
    printf("Tabla Hash\n");
    for (int i = 0; i < SizeT; i++)
    {
        Tnodo *temp = TablaH[i];
        printf("Indice %d ->  ", i);
        while (temp != NULL)
        {
            printf("[Clave: %s, Nombre: %s]->", temp->Clave, temp->Nombre);
            temp = temp->Siguiente;
        }
        printf("NULL\n");
    }
}

void LiberarTabla(Tnodo *TablaH[])
{
    for (int i = 0; i < SizeT; i++)
    {
        Tnodo *temp = TablaH[i];
        while (temp != NULL)
        {
            Tnodo *eliminar = temp;
            temp = temp->Siguiente;
            free(eliminar->Clave);
            free(eliminar->Nombre);
            free(eliminar);
        }
        TablaH[i] = NULL;
    }
}

int PrintMenu()
{
    int opcion;
    printf("1.- Insertar\n");
    printf("2.- Buscar\n");
    printf("3.- Eliminar\n");
    printf("4.- Modificar\n");
    printf("5.- Imprimir Tabla\n");
    printf("0.- Salir\n");
    printf("Opcion: ");
    scanf("%d", &opcion);
    return opcion;
}
