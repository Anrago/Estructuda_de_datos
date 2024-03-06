#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _datos
{
    int numero;

}Tdatos;

typedef struct _nodo
{
    Tdatos datos;
    struct _nodo* siguiente;
    
}Tnodo;

typedef struct _pila
{
    Tnodo* cabeza;
    int cantList;

}Tpila;

void Push(Tpila* pila, Tdatos* Datos);
Tnodo* CrearNodo(Tdatos* Datos);
void Pop(Tpila* pila);
void DestruirNodo(Tnodo* nodo);
int menu();
void ImprimirPila(Tpila* pila);

int main()
{
    int opc;
    Tdatos *num=(Tdatos*)malloc(sizeof(Tdatos));;
    Tpila* pila=(Tpila*)malloc(sizeof(Tpila));
    pila->cabeza=NULL;
    pila->cantList=0;
    do
    {
        opc=menu();
        switch (opc)
        {
        case 1:
            printf("Ingresa numero para agregar a pila: ");
            scanf("%d",&num->numero);
            Push(pila,num);
            break;
        
        case 2:
            Pop(pila);
            printf("Se ha eliminado un dato de la pila\n");
            break;
        case 3:
            ImprimirPila(pila);
            break;

        }
    } while (opc!=0);
    
    free(num); 
    free(pila);
    return 0;
}

void Push(Tpila* pila, Tdatos* Datos)
{
    Tnodo* nodo = CrearNodo(Datos);
    Tnodo* temp = pila->cabeza;
    if (pila->cabeza == NULL)
    {
        pila->cabeza = nodo;
    }
    
    if (temp == NULL) {
    pila->cabeza = nodo;
    }
    else 
    {
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nodo;
    }
  
}

Tnodo* CrearNodo(Tdatos* Datos)
{
    Tnodo* nodo = (Tnodo*)malloc(sizeof(Tnodo));
    if (nodo != NULL)
    {
        nodo->datos.numero = Datos->numero;
        nodo->siguiente = NULL;
    }
    return nodo;
}

void DestruirNodo(Tnodo* nodo)
{
    free(nodo);
}

void Pop(Tpila* pila)
{
    if (pila->cabeza)
    {
        if(pila->cabeza->siguiente)
        {
            Tnodo* puntero = pila->cabeza;
            while (puntero->siguiente->siguiente)
            {
                puntero = puntero->siguiente;
            }
            Tnodo* eliminado= puntero ->siguiente;
            puntero->siguiente=NULL;
            DestruirNodo(eliminado);
            pila->cantList--;
        }
        else
        {
            Tnodo* eliminado = pila->cabeza;
            pila->cabeza=NULL;
            DestruirNodo(eliminado);
            pila->cantList--;
        }
        
    }
    
}

int menu()
{
    int opc;
    printf("1.-Agregar a Pila\n");
    printf("2.-Eliminar de Pila\n");
    printf("3.-Imprimir Pila\n");
    printf("0.-Salir\n");
    printf("Escoge una opcion: ");
    scanf("%d",&opc);
    return opc;
}

void ImprimirPila(Tpila* pila)
{
    Tnodo* temp = pila->cabeza;
    printf("pila de empleados\n");
    printf("Datos\n");
    while (temp)
    {
        printf("%d\n",temp->datos.numero);
        temp = temp->siguiente;
    }


}