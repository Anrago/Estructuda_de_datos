#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo
{
    int dato;
    struct _nodo *nodoI;
    struct _nodo *nodoD;
} Tnodo;

//-----------Inicializacion de funciones----------

int menu();

Tnodo *CreateNodo(int dato);

void InsertNodo(Tnodo *raiz, int dato);

void PostOrden(Tnodo *raiz);
void Inorden(Tnodo *raiz);
void PreOrden(Tnodo *raiz);

//-------------Funcion principal------------------

int main()
{
    int datos[8] = {81, 3, 1, 20, 5, 10, 7, 4};
    Tnodo *raiz = CreateNodo(datos[0]);
    int i;

    for (i = 1; i < 7; i++)
        InsertNodo(raiz, datos[i]);
    printf("PREORDEN\n\n");
    PreOrden(raiz);
    printf("\n\nInORDEN\n\n");
    Inorden(raiz);
    printf("\n\nPostOrden\n\n");
    PostOrden(raiz);
}

//------------Funciones----------------------------

Tnodo *CreateNodo(int dato)
{
    Tnodo *nodo = (Tnodo *)malloc(sizeof(Tnodo));
    nodo->dato = dato;
    nodo->nodoI = NULL;
    nodo->nodoD = NULL;
    return nodo;
}

void InsertNodo(Tnodo *raiz, int dato)
{
    if (dato > raiz->dato)
    {
        if (raiz->nodoD == NULL)
            raiz->nodoD = CreateNodo(dato);
        else
            InsertNodo(raiz->nodoD, dato);
    }
    else
    {
        if (raiz->nodoI == NULL)
            raiz->nodoI = CreateNodo(dato);
        else
            InsertNodo(raiz->nodoI, dato);
    }
}

void PostOrden(Tnodo *raiz)
{
    if (raiz != NULL)
    {
        PostOrden(raiz->nodoI);
        PostOrden(raiz->nodoD);
        printf("%d", raiz->dato);
    }
}

void Inorden(Tnodo *raiz)
{
    if (raiz != NULL)
    {
        printf("%d", raiz->dato);
        Inorden(raiz->nodoI);
        Inorden(raiz->nodoD);
    }
}

void PreOrden(Tnodo *raiz)
{
    if (raiz != NULL)
    {
        Inorden(raiz->nodoI);
        printf("%d", raiz->dato);
        Inorden(raiz->nodoD);
    }
}
