#include <stdio.h>
#include <stdlib.h>

typedef struct _val
{
    int num;
} Tval;

typedef struct _nodo
{
    Tval datos;
    struct _nodo *siguiente;

} Tnodo;

typedef struct _cola
{
    Tnodo *cabeza;
    Tnodo *Ultimo;
    int cantCola;

} Tcola;

Tnodo *CreateNodo(Tval *datos);
void DestroyNodo(Tnodo *nodo);
void Push(Tcola *cola, Tval *datos);
void Pop(Tcola *cola);
int PrintMenu();

int main()
{
    Tval *datos = (Tval *)malloc(sizeof(Tval));
    Tcola *cola = (Tcola *)malloc(sizeof(Tcola));
    cola->cabeza = NULL;
    cola->Ultimo = NULL;
    cola->cantCola = 0;
    int opc;
    do
    {
        opc = PrintMenu();

        switch (opc)
        {
        case 1:
            printf("INGRESA UN VALOR A LA COLA\n");
            scanf("%d", &datos->num);
            Push(cola, datos);
            break;
        case 2:
            printf("ELIMINANDO ELEMENTO DE LA COLA\n");
            Pop(cola);
            getchar();
            break;
        case 3:
            printf("IMPRIMIENDO COLA\n");

            break;
        default:
            break;
        }
    } while (opc != 0);
}

Tnodo *CreateNodo(Tval *datos)
{
    Tnodo *nodo = (Tnodo *)malloc(sizeof(Tnodo));
    if (nodo != NULL)
    {
        nodo->datos.num = datos->num;
        nodo->siguiente = NULL;
    }
    return nodo;
}

void DestroyNodo(Tnodo *nodo)
{
    free(nodo);
}

void Push(Tcola *cola, Tval *datos)
{
    Tnodo *nodo = CreateNodo(datos);
    Tnodo *temp = cola->cabeza;
    if (cola->cabeza == NULL)
    {
        cola->cabeza = nodo;
        cola->Ultimo = nodo;
    }
    else
    {
        while (temp->siguiente)
        {
            temp = temp->siguiente;
        }
        temp->siguiente = nodo;
        cola->Ultimo = temp;
        cola->cantCola++;
    }
}

void Pop(Tcola *cola)
{
    Tnodo *temp;
    printf("DATOS ELIMNADO DE LA LISTA");
    if (cola->cabeza)
    {
        temp = cola->cabeza;
        cola->cabeza = cola->cabeza->siguiente;
        cola->cantCola--;
        printf("%d", temp->datos);
        DestroyNodo(temp);
    }
}

int PrintMenu()
{
    int opc;
    printf("MENU\n");
    printf("1.-Agregar\n");
    printf("2.-Eliminar\n");
    printf("3.-Imprimir\n");
    printf("0.-Salir\n");
    printf("Elije una opcion: ");
    scanf("%d", &opc);
    return opc;
}
