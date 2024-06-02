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

//Declaracion de funciones
Tnodo *CreateNodo(Tval *datos);
Tval Front(Tcola *cola);
void DestroyNodo(Tnodo *nodo);
void Enqueue(Tcola *cola, Tval *datos);
void Dequeue(Tcola *cola);
void IsEmpy(Tcola *cola);
void Clear(Tcola *cola);
int PrintMenu();




// Funcion principal
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
        system("CLEAR");
        opc = PrintMenu();
        system("CLEAR");
        switch (opc)
        {
        case 1:
            printf("INGRESA UN VALOR A LA COLA\n");
            scanf("%d", &datos->num);
            Enqueue(cola, datos);
            break;
        case 2:
            printf("ELIMINANDO ELEMENTO DE LA COLA\n");
            Dequeue(cola);
            break;
        case 3:
            printf("OBTENER ELEMENTO CABEZA\n");
            Tval elemento=Front(cola);
            printf("Elemento cabeza = %d\n",elemento);
            system("PAUSE");
            break;
        case 4:
            printf("IS EMPTY?\n");
            IsEmpy(cola);
            break;
        case 5:
            printf("VACIAR COLA\n");
            Clear(cola);
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

void Enqueue(Tcola *cola, Tval *datos)
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

void Dequeue(Tcola *cola)
{
    Tnodo *temp;
    printf("DATO ELIMNADO DE LA LISTA: ");
    if (cola->cabeza)
    {
        temp = cola->cabeza;
        cola->cabeza = cola->cabeza->siguiente;
        cola->cantCola--;
        printf("%d \n", temp->datos);
        DestroyNodo(temp);
        system("PAUSE");
    }
}

Tval Front(Tcola *cola)
{
    return cola->cabeza->datos;
}

void IsEmpy(Tcola *cola)
{
    if(cola->cabeza != NULL)
        printf("LA COLA NO ESTA VACIA\n");
    else
        printf("LA COLA ESTA VACIA\n");
    system("PAUSE");
}

void Clear(Tcola *cola)
{
    while (cola->cabeza != NULL)
    {
        Tnodo * temp = cola->cabeza;
        cola->cabeza=cola->cabeza->siguiente;
        DestroyNodo(temp);
    }
    cola->Ultimo = NULL;
    printf("COLA VACIADA CON EXITO \n");
    system("PAUSE");
}

int PrintMenu()
{
    int opc;
    printf("MENU\n");
    printf("1.-Agregar\n");
    printf("2.-Eliminar\n");
    printf("3.-Obtener elemento cabeza\n");
    printf("4.-IsEmpty\n");
    printf("5.-Vaciar cola\n");
    printf("0.-Salir\n");
    printf("Elije una opcion: ");
    scanf("%d", &opc);
    return opc;
}
