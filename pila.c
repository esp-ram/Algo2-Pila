#include "pila.h"
#include <stdlib.h>
#define TAM_INICIAL 4

/* Definición del struct pila proporcionado por la cátedra.
 */
struct pila {
    void** datos;
    size_t cantidad;  // Cantidad de elementos almacenados.
    size_t capacidad;  // Capacidad del arreglo 'datos'.
};

/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/


pila_t* pila_crear(void){
    pila_t* nueva = malloc(sizeof(pila_t));

    if (nueva == NULL) {
        return NULL;
    }
    nueva->datos = malloc(TAM_INICIAL*sizeof(double));

    if (nueva->datos == NULL){
        free(nueva);
        return NULL;
    }

    nueva->cantidad = 0;
    nueva->capacidad = TAM_INICIAL;
    return nueva;
}


bool pila_esta_vacia(const pila_t *pila){
    if (pila->cantidad == 0{
        return true;
    }
    return false;
}


bool pila_apilar(pila_t *pila, void* valor){
    if (pila->cantidad == pila->capacidad){
        pila_t* pila_aumentada = realloc(pila->datos,pila->capacidad*2 * sizeof(double));
        if (pila_aumentada == NULL){
            return false;
        }
        pila->datos = pila_aumentada;
        pila->capacidad *= 2;
    }
    pila->datos[pila->cantidad] = valor;
    pila->cantidad += 1;

}


void* pila_ver_tope(const pila_t *pila){
    if (pila_esta_vacia(pila)){
        return NULL;
    }
    return pila->datos[pila->cantidad - 1];
}

void pila_destruir(pila_t *pila){
    free(pila->datos);
    free(pila);
}


void* pila_desapilar(pila_t *pila){
    if (pila_esta_vacia(pila)){
        return NULL;
    }
    dato_desapilado = pila->datos[pila->cantidad - 1];
    pila->cantidad -= 1;
    if (pila->cantidad * 4 <= pila->capacidad){
        pila_t* pila_reducida = realloc(pila->datos,pila->capacidad / 2 *sizeof(double));
        if (pila_reducida != NULL){
            pila->datos = pila_aumentada;
            pila->capacidad /= 2;
            return (dato_desapilado);
        }
    }
    return(dato_desapilado);
}
