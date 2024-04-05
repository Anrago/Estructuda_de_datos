#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo
{
    int dato;
    struct _nodo *nodoI;
    struct _nodo *nodoD;
} Tnodo;

//-----------Inicializacion de funciones----------

Tnodo *CreateNodo(int dato);

void InsertNodo(Tnodo *raiz, int dato);

void PostOrden(Tnodo *raiz);
void Inorden(Tnodo *raiz);
void PreOrden(Tnodo *raiz);
int ContarHojas(Tnodo *raiz);
int AlturaArbol(Tnodo *raiz);


//-------------Funcion principal------------------

int main()
{
    int datos[8] = {10, 3, 1, 20, 5, 2, 7, 4};
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
    int hojas = ContarHojas(raiz);
    printf("\n\nHOJAS DEL ARBOL: %d \n\n", hojas);

    int altura = AlturaArbol(raiz);
    printf("\n\nALTURA DEL ARBOL: %d \n\n", altura);
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

int ContarHojas(Tnodo *raiz)
{
    if (raiz == NULL)
        return 0;
    if (raiz->nodoI == NULL && raiz->nodoD == NULL)
        return 1;

    return ContarHojas(raiz->nodoI) + ContarHojas(raiz->nodoD);
}

int AlturaArbol(Tnodo *raiz)
{


}
