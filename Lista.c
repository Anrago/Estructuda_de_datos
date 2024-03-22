#include <stdio.h>
#include <stdlib.h>
typedef struct _Dato
{
    int num;
} Tdatos;

typedef struct _nodo
{
    Tdatos numero;
    struct _nodo *siguiente;

} Tnodo;

typedef struct _lista
{
    Tnodo *cabeza;
    int cantlist;
} Tlista;

Tnodo *CrearNodo(Tdatos *dato)
{
    Tnodo *nodo = (Tnodo *)malloc(sizeof(Tnodo));
    nodo->numero.num = dato->num;
    nodo->siguiente=NULL;
    return nodo;
}
void DestruirNodo(Tnodo *nodo)
{
    free(nodo);
}

void AgregarInicio(Tlista *lista, Tdatos *dato)
{
    Tnodo *nodo = CrearNodo(dato);
    nodo->siguiente = lista->cabeza;
    lista->cabeza = nodo;
    lista->cantlist++;
    printf("DATO AGREGADO\n");
}

void AgregarFinal(Tlista *lista, Tdatos *datos)
{
    if (lista->cabeza == NULL)
    {
        AgregarInicio(lista, datos);
    }
    else
    {
        Tnodo *nodo = CrearNodo(datos);
        Tnodo *puntero = lista->cabeza;

        while (puntero->siguiente)
        {
            puntero = puntero->siguiente;
        }
        puntero->siguiente = nodo;
        lista->cantlist++;
    }
}

void Agregar(Tlista *lista, Tdatos *datos, int n)
{
    if (lista->cabeza == NULL || n - 1 == 0)
    {
        AgregarInicio(lista, datos);
    }
    else
    {
        Tnodo *nodo = CrearNodo(datos);
        Tnodo *puntero = lista->cabeza;
        int pos = 0;
        while (pos < n && puntero->siguiente)
        {
            puntero = puntero->siguiente;
            pos++;
        }
        nodo->siguiente = puntero->siguiente;
        puntero->siguiente = nodo;
        lista->cantlist++;
    }
}

void EliminarInicio(Tlista *lista)
{
    if (lista->cabeza)
    {
        Tnodo *eliminado = lista->cabeza;
        lista->cabeza = eliminado->siguiente;
        DestruirNodo(eliminado);
        lista->cantlist--;
    }
}

void EliminadoFinal(Tlista *lista)
{
    if (lista->cabeza)
    {
        if (lista->cabeza->siguiente)
        {
            Tnodo *puntero = lista->cabeza;
            while (puntero->siguiente->siguiente)
            {
                puntero = puntero->siguiente;
            }
            Tnodo *eliminado = puntero->siguiente;
            puntero->siguiente = NULL;
            DestruirNodo(eliminado);
            lista->cantlist--;
        }
        else
        {
            EliminarInicio(lista);
        }
    }
}

void Eliminar(Tlista *lista, int n)
{
    if (lista->cabeza)
    {
        if (n == 0)
        {
            EliminarInicio(lista);
        }
        else
        {
            Tnodo *puntero = lista->cabeza;
            int pos = 0;
            while (pos < n - 1 && puntero->siguiente)
            {
                puntero = puntero->siguiente;
                pos++;
            }
            Tnodo *eliminado = puntero->siguiente;
            puntero->siguiente = eliminado->siguiente;
            DestruirNodo(eliminado);
            lista->cantlist--;
        }
    }
}

int main()
{
    int opc;
    Tlista *lista = (Tlista *)malloc(sizeof(Tlista));
    lista->cabeza = NULL;
    lista->cantlist = 0;
    Tdatos *datos = (Tdatos *)malloc(sizeof(Tdatos));
    do
    {
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            printf("INGRESA NUMERO: ");
            scanf("%d", &datos->num);
            AgregarInicio(lista, datos);
            break;
        case 2:
            printf("INGRESA FINAL: ");
            scanf("%d", &datos->num);
            AgregarFinal(lista, datos);
            break;
        case 3:
            int pos;
            printf("INGRESA EN ALGUNA PARTE: ");
            scanf("%d", &datos->num);
            printf("\nINGRESA LUGAR: ");
            scanf("%d", &pos);
            Agregar(lista, datos, pos);
        default:
            break;
                }
        printf("%d", lista->cabeza->numero);

    } while (opc != 0);
}