#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _datos
{
    int numero;

} Tdatos;

typedef struct _nodo
{
    Tdatos datos;
    struct _nodo *siguiente;

} Tnodo;

typedef struct _pila
{
    Tnodo *cabeza;
    int cantPila;

} Tpila;

Tnodo *CrearNodo(Tdatos *Datos);
int menu();
void Pop(Tpila *pila);
void IsEmpy(Tpila *pila);
void Push(Tpila *pila, Tdatos *Datos);
void DestruirNodo(Tnodo *nodo);
void ImprimirPila(Tpila *pila);
void VaciarPila(Tpila *pila);
int Size(Tpila *pila);

int main()
{
    int opc;
    Tdatos *num = (Tdatos *)malloc(sizeof(Tdatos));
    Tpila *pila = (Tpila *)malloc(sizeof(Tpila));
    pila->cabeza = NULL;
    pila->cantPila = 0;
    do
    {
        system("CLEAR");
        opc = menu();
        system("CLEAR");
        switch (opc)
        {
        case 1:
            printf("Ingresa numero para agregar a pila: ");
            scanf("%d", &num->numero);
            Push(pila, num);
            break;
        case 2:
            Pop(pila);
            break;
        case 3:
            IsEmpy(pila);
            break;
        case 4:
            VaciarPila(pila);
            break;
        case 5:
            printf("Tamanio de pila: %d\n", Size(pila));
            break;
        case 6:
            ImprimirPila(pila);
            break;
        }
        system("PAUSE");
    } while (opc != 0);

    free(num);
    free(pila);
    return 0;
}

void Push(Tpila *pila, Tdatos *Datos)
{
    Tnodo *nodo = CrearNodo(Datos);
    nodo->siguiente = pila->cabeza;
    pila->cabeza = nodo;
    pila->cantPila++;
}

Tnodo *CrearNodo(Tdatos *Datos)
{
    Tnodo *nodo = (Tnodo *)malloc(sizeof(Tnodo));
    if (nodo != NULL)
    {
        nodo->datos.numero = Datos->numero;
        nodo->siguiente = NULL;
    }
    return nodo;
}

void DestruirNodo(Tnodo *nodo)
{
    free(nodo);
}

void Pop(Tpila *pila)
{
    if (pila->cabeza)
    {

        Tnodo *eliminado = pila->cabeza;
        pila->cabeza = pila->cabeza->siguiente;
        printf("ELEMENTO ELIMINADO: %d\n", eliminado->datos);
        DestruirNodo(eliminado);
        pila->cantPila--;
    }
    else
        printf("NO HAY ELEMENTOS A ELIMINAR EN LA PILA\n");
}

int menu()
{
    int opc;
    printf("1.-Push\n");
    printf("2.-Pop\n");
    printf("3.-Is Empy\n");
    printf("4.-Clear\n");
    printf("5.-Size\n");
    printf("6.-PrintPila\n");
    printf("0.-Salir\n");
    printf("Escoge una opcion: ");
    scanf("%d", &opc);
    return opc;
}

void ImprimirPila(Tpila *pila)
{
    if (pila->cabeza)
    {
        Tnodo *temp = pila->cabeza;
        while (temp)
        {
            printf("%d\n", temp->datos.numero);
            temp = temp->siguiente;
        }
    }
    else
        printf("NO HAY ELEMENTOS A IMPRIMIR\n");
}

void IsEmpy(Tpila *pila)
{
    if (pila->cabeza != NULL)
        printf("LA PILA NO ESTA VACIA\n");
    else
        printf("LA PILA ESTA VACIA\n");
}

void VaciarPila(Tpila *pila)
{
    while (pila->cabeza != NULL)
    {
        Tnodo *temp = pila->cabeza;
        pila->cabeza = pila->cabeza->siguiente;
        DestruirNodo(temp);
        pila->cantPila--;
    }
    printf("PILA VACIADA CON EXITO \n");
}

int Size(Tpila *pila)
{
    return pila->cantPila;
}
