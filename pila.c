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
    nueva->datos = malloc(TAM_INICIAL* 8 );

    if (nueva->datos == NULL){
        free(nueva);
        return NULL;
    }

    nueva->cantidad = 0;
    nueva->capacidad = TAM_INICIAL;
    return nueva;
}


bool redimensionar(pila_t* pila, size_t nuevo_tam){
    void* resized = realloc(pila->datos,nuevo_tam * sizeof(void*));
    if (resized == NULL){
        return false;
    }
    pila->datos = resized;
    pila->capacidad = nuevo_tam;
    return true;
}


bool pila_esta_vacia(const pila_t *pila){
    if (pila->cantidad == 0){
        return true;
    }
    return false;
}


void pila_destruir(pila_t *pila){
    free(pila->datos);
    free(pila);
}


void* pila_ver_tope(const pila_t *pila){
    if (pila_esta_vacia(pila)){
        return NULL;
    }
    return pila->datos[pila->cantidad - 1];
}


bool pila_apilar(pila_t *pila, void* valor){
    if (pila->cantidad == pila->capacidad){
        if (redimensionar(pila,pila->capacidad * 2) == false){
            return false;
            }
        }
    pila->datos[pila->cantidad] = valor;
    pila->cantidad += 1;
    return true;
}


void* pila_desapilar(pila_t *pila){
    if (pila_esta_vacia(pila)){
        return NULL;
    }
    void* dato_desapilado = pila->datos[pila->cantidad - 1];
    pila->cantidad -= 1;
    if ((pila->cantidad * 4 <= pila->capacidad) && (pila->capacidad > TAM_INICIAL)){
        redimensionar(pila,pila->capacidad / 2);
    }
    return (dato_desapilado);
}
