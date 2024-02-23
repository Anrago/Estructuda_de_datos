//ANRONIO RAMOS GONZALEZ
//MATRICULA: 372576
//LISTAS ENLAZADAS
//FECHA: 10/11/2020
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _empleado
{
    char *nombre;
    char *apP;
    char *apM;
    char *id;

}Templeado;

typedef struct _nodo
{
    Templeado empleado;
    struct _nodo* siguiente;
    
}Tnodo;

typedef struct _lista
{
    Tnodo* cabeza;
    int cantList;

}Tlista;

Tnodo* CrearNodo(Templeado* empleado)
{
    Tnodo* nodo = (Tnodo*)malloc(sizeof(Tnodo));
    nodo->empleado.nombre = (char*)malloc((strlen(empleado->nombre) + 1) * sizeof(char));
    strcpy(nodo->empleado.nombre, empleado->nombre);
    nodo->empleado.apP = (char*)malloc((strlen(empleado->apP) + 1) * sizeof(char));
    strcpy(nodo->empleado.apP, empleado->apP);
    nodo->empleado.apM = (char*)malloc((strlen(empleado->apM) + 1) * sizeof(char));
    strcpy(nodo->empleado.apM, empleado->apM);
    nodo->empleado.id = (char*)malloc((strlen(empleado->id) + 1) * sizeof(char));
    strcpy(nodo->empleado.id, empleado->id);
    nodo->siguiente = NULL;
    return nodo;
}


void DestruirNodo(Tnodo *nodo)
{
    free(nodo);
}

void InsertarInicio(Tlista *lista, Templeado *empleado)
{
    Tnodo *nodo = CrearNodo(empleado);
    nodo->siguiente = lista->cabeza;
    lista->cabeza = nodo;
}

void InsprintertarFinal(Tlista* lista, Templeado* empleado)
{
    Tnodo* nodo = CrearNodo(empleado);
    Tnodo* temp = lista->cabeza;
    if (lista->cabeza==NULL)
    {
        lista->cabeza=nodo;
    }
    
    while (temp->siguiente)
    {
        temp=temp->siguiente;
    }
    temp->siguiente=nodo;   
}

void Insertar(int n,Tlista* lista, Templeado* empleado)
{
    Tnodo* nodo=CrearNodo(empleado);
    if (lista->cabeza==NULL)
    {
        lista->cabeza=nodo;
    }
    else
    {
        Tnodo* temp = lista->cabeza;
        int pos=0;
        while (pos<n && temp->siguiente)
        {
            temp=temp->siguiente;
            pos++;
        }
        nodo->siguiente=temp->siguiente;
        temp->siguiente=nodo;
    }
}

void EliminarDeInicio(Tlista* lista)
{
    if (lista->cabeza)
    {
        Tnodo* eliminar = lista->cabeza;
        lista->cabeza= lista->cabeza->siguiente;
        DestruirNodo(eliminar);
        lista->cantList--;
    } 
}

void EliminarDeUltimo(Tlista* lista)
{
    if (lista->cabeza)
    {
        if(lista->cabeza->siguiente)
        {
            Tnodo* puntero = lista->cabeza;
            while (puntero->siguiente->siguiente)
            {
                puntero = puntero->siguiente;
            }
            Tnodo* eliminado= puntero ->siguiente;
            puntero->siguiente=NULL;
            DestruirNodo(eliminado);
            lista->cantList--;
        }
        else
        {
            Tnodo* eliminado = lista->cabeza;
            lista->cabeza=NULL;
            DestruirNodo(eliminado);
            lista->cantList--;
        }
        
    }
    
}

void EliminarElemento(int n, Tlista* lista)
{
    if (lista->cabeza)
    {
        if (n==0)
        {
            Tnodo* eliminado = lista->cabeza;
            lista->cabeza=lista->cabeza->siguiente;
            DestruirNodo(eliminado);
            lista->cantList--;
        }
        else
        {
            Tnodo* puntero = lista->cabeza;
            int pos=0;
            while (pos<n-1 && puntero->siguiente)
            {
                puntero=puntero->siguiente;
                pos++;
            }
            if (puntero->siguiente)
            {
                Tnodo* eliminado = puntero->siguiente;
                puntero->siguiente=eliminado->siguiente;
                DestruirNodo(eliminado);
                lista->cantList--;
            }
        }
    }
    
}

void ImprimirLista(Tlista* lista)
{
    Tnodo* temp = lista->cabeza;
    printf("Lista de empleados\n");
    printf("Nombre     Apellido Paterno     Apellido Materno     ID\n");
    while (temp)
    {
        printf("%5s %5s %5s %5s\n", temp->empleado.nombre, temp->empleado.apP, temp->empleado.apM, temp->empleado.id);
        temp = temp->siguiente;
    }


}
void Buscar(Tlista* lista, char* id)
{
    Tnodo* temp = lista->cabeza;
    while (temp)
    {
        if (strcmp(temp->empleado.id, id) == 0)
        {
            printf("Nombre: %s\n", temp->empleado.nombre);
            printf("Apellido Paterno: %s\n", temp->empleado.apP);
            printf("Apellido Materno: %s\n", temp->empleado.apM);
            printf("ID: %s\n", temp->empleado.id);
        }
        temp = temp->siguiente;
    }
}

int menu()
{
    int opc;
    printf("1.- Insertar al inicio\n");
    printf("2.- Insertar al final\n");
    printf("3.- Insertar en una posicion\n");
    printf("5.- Imprimir\n");
    printf("6.- Buscar\n");
    printf("7.- Salir\n");
    printf("Opcion: ");
    scanf("%d",&opc);
    return opc;
}

int menu2()
{
    int opc;
    printf("1.- Eliminar al inicio\n");
    printf("2.- Eliminar al final\n");
    printf("3.- Eliminar en una posicion\n");
    printf("4.- Regresar\n");
    printf("Opcion: ");
    scanf("%d",&opc);
    return opc;
}

int main() {
    Tlista* lista = (Tlista*)malloc(sizeof(Tlista)); // Asignar memoria para la lista
    lista->cabeza = NULL;
    Templeado *empleado = (Templeado*)malloc(sizeof(Templeado)); // Asignar memoria para el empleado

    int opc;
    do {
        opc = menu();
        switch (opc) {
            case 1:
                system("clear");
                printf("Nombre: ");
                empleado->nombre = malloc(100 * sizeof(char));
                scanf("%s", empleado->nombre);
                printf("Apellido Paterno: ");
                empleado->apP = malloc(100 * sizeof(char));
                scanf("%s", empleado->apP);
                printf("Apellido Materno: ");
                empleado->apM = malloc(100 * sizeof(char));
                scanf("%s", empleado->apM);
                printf("ID: ");
                empleado->id = malloc(100 * sizeof(char));
                scanf("%s", empleado->id);
                InsertarInicio(lista, empleado);
                break;
            case 2:
                system("clear");
                printf("Nombre: ");
                empleado->nombre = malloc(100 * sizeof(char));
                scanf("%s", empleado->nombre);
                printf("Apellido Paterno: ");
                empleado->apP = malloc(100 * sizeof(char));
                scanf("%s", empleado->apP);
                printf("Apellido Materno: ");
                empleado->apM = malloc(100 * sizeof(char));
                scanf("%s", empleado->apM);
                printf("ID: ");
                empleado->id = malloc(100 * sizeof(char));
                scanf("%s", empleado->id);
                InsprintertarFinal(lista, empleado);
                break;
            case 3:
                system("clear");
                printf("Nombre: ");
                empleado->nombre = malloc(100 * sizeof(char));
                scanf("%s", empleado->nombre);
                printf("Apellido Paterno: ");
                empleado->apP = malloc(100 * sizeof(char));
                scanf("%s", empleado->apP);
                printf("Apellido Materno: ");
                empleado->apM = malloc(100 * sizeof(char));
                scanf("%s", empleado->apM);
                printf("ID: ");
                empleado->id = malloc(100 * sizeof(char));
                scanf("%s", empleado->id);
                int n;
                printf("Posicion: ");
                scanf("%d", &n);
                Insertar(n, lista, empleado);
                break;
            case 4:
                system("clear");
                do {
                    opc = menu2();
                    switch (opc) {
                        case 1:
                            EliminarDeInicio(lista);
                            break;
                        case 2:
                            EliminarDeUltimo(lista);
                            break;
                        case 3:
                            int n;
                            printf("Posicion: ");
                            scanf("%d", &n);
                            EliminarElemento(n, lista);
                            break;
                    }
                } while (opc != 4);
            case 5:
                system("clear");
                ImprimirLista(lista);
                break;
            case 6:
                system("clear");
                printf("ID: ");
                char *id = malloc(100 * sizeof(char));
                scanf("%s", id);
                Buscar(lista, id);
                break;
                

        }
    } while (opc != 7);
    
    free(lista);
    free(empleado);
    return 0;
}