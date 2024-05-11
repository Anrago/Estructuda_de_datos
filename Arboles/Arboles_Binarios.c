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
Tnodo *NodoMenor(Tnodo *raiz);
Tnodo *BorrarNodo(Tnodo *raiz, int dato);
void InsertNodo(Tnodo *raiz, int dato);
void PostOrden(Tnodo *raiz);
void Inorden(Tnodo *raiz);
void PreOrden(Tnodo *raiz);
int ContarHojas(Tnodo *raiz);
int AlturaArbol(Tnodo *raiz);
int contarNodos(Tnodo *raiz);
int ArbolComp(Tnodo *raiz, int x, int cantN);
int esCompleto(Tnodo *raiz);
int arbolLleno(Tnodo *raiz);
int arbolBalanceado(Tnodo *raiz);

//--------/* condition */-----Funcion principal------------------

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

    // if (arbolLleno(raiz) == 1)
    //     printf("EL ARBOL ES LLENO");
    // else
    //     printf("EL ARBOL NO ES LLENO\n");

    // if (esCompleto(raiz) == 1)
    //     printf("EL ARBOL ES COMPLETO");
    // else
    //     printf("EL ARBOL NO ES COMPLETO");

    Tnodo *temp = NodoMenor(raiz);
    printf("Nodo menor: %d\n", temp->dato);
    Inorden(raiz);
    printf("\n");
    BorrarNodo(raiz, 1);
    Inorden(raiz);
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
    int act = 0, izq = 0, der = 0;
    if (raiz == NULL)
        return 0;
    else
    {
        izq = AlturaArbol(raiz->nodoI);
        der = AlturaArbol(raiz->nodoD);
        if (izq > der)
            act = 1 + izq;
        else
            act = 1 + der;
        return act;
    }
}

int contarNodos(Tnodo *raiz)
{
    if (raiz == NULL)
        return 0;
    else
        return 1 + contarNodos(raiz->nodoI) + contarNodos(raiz->nodoD);
}

int ArbolComp(Tnodo *raiz, int x, int cantN)
{
    if (raiz == NULL)
        return 1;
    if (x >= cantN)
        return 0;
    return ArbolComp(raiz->nodoI, 2 * x + 1, cantN) &&
           ArbolComp(raiz->nodoD, 2 * x + 2, cantN);
}

int esCompleto(Tnodo *raiz)
{
    int nodos = contarNodos(raiz);
    return ArbolComp(raiz, 0, nodos);
}

int arbolLleno(Tnodo *raiz)
{
    if (raiz == NULL)
        return 1;

    if (raiz->nodoI == NULL || raiz->nodoD == NULL)
        return 0;

    return arbolLleno(raiz->nodoI) && arbolLleno(raiz->nodoD);
}

int arbolBalanceado(Tnodo *raiz)
{
    if (raiz == NULL)
        return 1;
    int Izq = AlturaArbol(raiz->nodoI);
    int Der = AlturaArbol(raiz->nodoD);

    if (abs(Izq - Der) > 1)
        return 0;
    return arbolBalanceado(raiz->nodoI) && arbolBalanceado(raiz->nodoD);
}

Tnodo *NodoMenor(Tnodo *raiz)
{
    while (raiz->nodoI != NULL)
        raiz = raiz->nodoI;

    return raiz;
}

Tnodo *BorrarNodo(Tnodo *raiz, int dato)
{
    if (raiz == NULL)
        return raiz;
    if (dato < raiz->dato)
        raiz->nodoI = BorrarNodo(raiz->nodoI, dato);
    else
    {
        if (dato > raiz->dato)
            raiz->nodoD = BorrarNodo(raiz->nodoD, dato);
        else
        { // Eliminar con un solo hijo o sin hijo
            if (raiz->nodoI == NULL)
            {
                Tnodo *temp = (Tnodo *)malloc(sizeof(Tnodo));
                temp = raiz->nodoD;
                free(raiz);
                return temp;
            }
            else
            {
                if (raiz->nodoD == NULL)
                {
                    Tnodo *temp = (Tnodo *)malloc(sizeof(Tnodo));
                    temp = raiz->nodoI;
                    free(raiz);
                    return temp;
                }
                // nodo con dos hijos
                Tnodo *temp = NodoMenor(raiz->nodoD);
                raiz->dato = temp->dato;
                raiz->nodoD = BorrarNodo(raiz->nodoD, temp->dato);
            }
        }
    }
    return raiz;
}
