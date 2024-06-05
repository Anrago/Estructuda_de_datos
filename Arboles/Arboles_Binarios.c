//Antonio Ramos Gonzalez
//372576
//Practica 4.- Arboles binarios

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
Tnodo *BuscarNodo(Tnodo *raiz, int dato);
void InsertNodo(Tnodo *raiz, int dato);
void PostOrden(Tnodo *raiz);
void Inorden(Tnodo *raiz);
void PreOrden(Tnodo *raiz);
void ModificarNodo(Tnodo *raiz, int datoActual, int nuevoDato);
int PrintMenu();
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
    Tnodo *raiz;
    int band = 0;
    int opc;
    int dato;
    do
    {
        system("CLS");
        opc = PrintMenu();
        system("CLS");
        switch (opc)
        {
        case 1:
            printf("INGRESE DATO: ");
            scanf("%d", &dato);
            if (band == 0)
            {
                raiz = CreateNodo(dato);
                band = 1;
            }
            else
                InsertNodo(raiz, dato);
            break;
        case 2:
            printf("INGRESE DATO A BUSCAR: ");
            scanf("%d", &dato);
            BuscarNodo(raiz, dato);
            system("PAUSE");
            break;
        case 3:
            printf("INGRESE DATO: ");
            scanf("%d", &dato);
            BorrarNodo(raiz, dato);
            break;
        case 4:
            printf("RECORRIDOS\n");
            printf("PreOrden\n");
            PreOrden(raiz);
            printf("\nInOrden\n");
            Inorden(raiz);
            printf("\nPostOrden\n");
            PostOrden(raiz);
            system("PAUSE");
            break;
        case 5:
            printf("NUMERO DE NODOS EN ARBOL: %d\n", contarNodos(raiz));
            system("PAUSE");
            break;
        case 6:
            printf("EL ARBOL TIENE UNA PROFUNDIDAD DE: %d\n", AlturaArbol(raiz));
            system("PAUSE");
            break;
        case 7:
            if (esCompleto(raiz) == 1)
                printf("EL ARBOL ES COMPLETO\n");
            else
                printf("EL ARBOL NO ES COMPLETO\n");
            system("PAUSE");
            break;
        case 8:
            if (arbolBalanceado(raiz) == 1)
                printf("EL ARBOL ESTA BALANCEADO\n");
            else
                printf("EL ARBOL NO ESTA BALANCEADO\n");
            system("PAUSE");
            break;
        case 9:
            printf("INGRESE DATO ACTUAL: ");
            scanf("%d", &dato);
            int nuevoDato;
            printf("INGRESE NUEVO DATO: ");
            scanf("%d", &nuevoDato);
            ModificarNodo(raiz, dato, nuevoDato);
            system("PAUSE");
        default:
            break;
        }
    } while (opc != 0);

}

//------------Funciones----------------------------
//Crea un nodo
Tnodo *CreateNodo(int dato)
{
    Tnodo *nodo = (Tnodo *)malloc(sizeof(Tnodo));
    nodo->dato = dato;
    nodo->nodoI = NULL;
    nodo->nodoD = NULL;
    return nodo;
}

//Inserta nodo en alguno de los subarboles
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

//Imprime en postorden
void PostOrden(Tnodo *raiz)
{
    if (raiz != NULL)
    {
        PostOrden(raiz->nodoI);
        PostOrden(raiz->nodoD);
        printf("%d", raiz->dato);
    }
}
//Imprime en inorden
void Inorden(Tnodo *raiz)
{
    if (raiz != NULL)
    {
        printf("%d", raiz->dato);
        Inorden(raiz->nodoI);
        Inorden(raiz->nodoD);
    }
}
//Imprime en preorden
void PreOrden(Tnodo *raiz)
{
    if (raiz != NULL)
    {
        Inorden(raiz->nodoI);
        printf("%d", raiz->dato);
        Inorden(raiz->nodoD);
    }
}

//Cuenta las hojas del arbol
int ContarHojas(Tnodo *raiz)
{
    if (raiz == NULL)
        return 0;
    if (raiz->nodoI == NULL && raiz->nodoD == NULL)
        return 1;

    return ContarHojas(raiz->nodoI) + ContarHojas(raiz->nodoD);
}

//Da la alura del arbol
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

//Cuenta los nodos del arbol
int contarNodos(Tnodo *raiz)
{
    if (raiz == NULL)
        return 0;
    else
        return 1 + contarNodos(raiz->nodoI) + contarNodos(raiz->nodoD);
}

//Devuelve si el subarbol es completo
int ArbolComp(Tnodo *raiz, int x, int cantN)
{
    if (raiz == NULL)
        return 1;
    if (x >= cantN)
        return 0;
    return ArbolComp(raiz->nodoI, 2 * x + 1, cantN) &&
           ArbolComp(raiz->nodoD, 2 * x + 2, cantN);
}

//Devueelve si es completo
int esCompleto(Tnodo *raiz)
{
    int nodos = contarNodos(raiz);
    return ArbolComp(raiz, 0, nodos);
}

//Devuelve si el arbol esta lleno
int arbolLleno(Tnodo *raiz)
{
    if (raiz == NULL)
        return 1;

    if (raiz->nodoI == NULL || raiz->nodoD == NULL)
        return 0;

    return arbolLleno(raiz->nodoI) && arbolLleno(raiz->nodoD);
}

//Devuelve si esta balanceado
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

//Nos permite modificar un nodo
void ModificarNodo(Tnodo *raiz, int datoActual, int nuevoDato)
{
    if (raiz == NULL)
    {
        printf("Nodo no encontrado.\n");
        return;
    }

    if (raiz->dato == datoActual)
    {
        raiz->dato = nuevoDato;
        printf("Nodo modificado exitosamente.\n");
    }
    else if (datoActual < raiz->dato)
    {
        ModificarNodo(raiz->nodoI, datoActual, nuevoDato);
    }
    else
    {
        ModificarNodo(raiz->nodoD, datoActual, nuevoDato);
    }
}

//Da el nodo menor
Tnodo *NodoMenor(Tnodo *raiz)
{
    while (raiz->nodoI != NULL)
        raiz = raiz->nodoI;

    return raiz;
}

//Nos permite borrar nodo
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

//Nos permite buscar nodo
Tnodo *BuscarNodo(Tnodo *raiz, int dato)
{
    if (raiz == NULL)
    {
        printf("Nodo no encontrado.\n");
        return NULL;
    }

    if (raiz->dato == dato)
    {
        printf("Nodo encontrado: %d\n", raiz->dato);
        return raiz;
    }
    else if (dato < raiz->dato)
    {
        return BuscarNodo(raiz->nodoI, dato);
    }
    else
    {
        return BuscarNodo(raiz->nodoD, dato);
    }
}

//Imprime menu de opciones
int PrintMenu()
{
    int opc;
    printf("MENU ARBOL\n");
    printf("1.-Agregar a arbol\n");
    printf("2.-Buscar en arbol\n");
    printf("3.-Eliminar nodo\n");
    printf("4.-Recorridos\n");
    printf("5.-Numero de nodos\n");
    printf("6.-Profundidad\n");
    printf("7.-Completo\n");
    printf("8.-Balanceado\n");
    printf("9.-Modificar nodo\n");
    printf("0.-Salir\n");
    printf("Elige una opcion: ");
    scanf("%d", &opc);
    return opc;
}
