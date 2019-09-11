#include "pila.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>

/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void pruebas_pila_alumno() {
    pila_t* pi = pila_crear();
    int a = 2;
    int b = 5;
    int c = 7;
    int d = 9;
    printf("pruebas con pila vacia \n");

    print_test("desapilar pila vacia:",pila_desapilar(pi) == NULL);
    print_test("ver tope de pila vacia:",pila_ver_tope(pi) == NULL);
    print_test("ver si la pila esta vacia:",pila_esta_vacia(pi) == true);
    printf("se apilan varios valores\n");
    //apilar los tres elementos
    print_test("apilo elemento ",pila_apilar(pi,&a) != false);
    print_test("apilo elemento ",pila_apilar(pi,&b) != false);
    print_test("apilo elemento ",pila_apilar(pi,&c) != false);
    print_test("apilo elemento ",pila_apilar(pi,&d) != false);
    print_test("apilo elemento ",pila_apilar(pi,&a) != false);
    print_test("se verifica el tope de la pila",*(int*)pila_ver_tope(pi) == 2);
    print_test("desapilo un elemento:",*(int*)pila_desapilar(pi) == 2);
    print_test("verificacion si esta vacia",pila_esta_vacia(pi) == false);
    printf("desapillo toda la pila\n");
    //despilar toda la pila
    print_test("desapilo un elemento:",*(int*)pila_desapilar(pi) == 9);
    print_test("desapilo un elemento:",*(int*)pila_desapilar(pi) == 7);
    print_test("desapilo un elemento:",*(int*)pila_desapilar(pi) == 5);
    print_test("desapilo un elemento:",*(int*)pila_desapilar(pi) == 2);
    printf("verificacion con la pila ya vacia\n");
    print_test("verificacion tope de pila",pila_ver_tope(pi) == NULL);
    print_test("intento desapilar la pila",pila_desapilar(pi) == NULL);
    print_test("veo si esta vacia",pila_esta_vacia(pi) == true);
    //prueba con 1000 elementos
    printf("apilo 1000 elementos\n");
    int vector_prueba[1000];
    for(int i=0; i < 1000; i++){
        pila_apilar(pi,&vector_prueba[i]);
    }
    pila_apilar(pi,&a);
    print_test("verificacion tope de pila ",*(int*)pila_ver_tope(pi) == 2);
    printf("deapilando los 1000 elementos de la pila \n" );
    /*
    while(pila_esta_vacia(pi) != true){
        pila_desapilar(pi);
    }
    */
    for(int j = 999; i >= 0 ,j--){
        pila_desapilar(pi) == vector_prueba[j];
    }
    printf("verificacion pila \n");
    print_test("pila vacia? ",pila_ver_tope(pi) == NULL);
    print_test("intento de desapilar pila vacia ",pila_desapilar(pi) == NULL);
    pila_destruir(pi);

}

/*

#include <stdlib.h>
#define TAM_INICIAL 2
#include <stdbool.h>

typedef struct pila {
    void** datos;
    size_t cantidad;  // Cantidad de elementos almacenados.
    size_t capacidad;  // Capacidad del arreglo 'datos'.
}pila_t;


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
    if (pila->cantidad != 0){
        return false;
    }
    return true;
}


bool pila_apilar(pila_t *pila, void* valor){
    if (pila->cantidad == pila->capacidad){
        pila_t* pila_auxiliar = realloc(pila->datos,pila->capacidad*2 * sizeof(double));
        if (pila_auxiliar == NULL){
            return false;
        }
        pila->datos = pila_auxiliar;
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
    void* dato_desapilado = pila->datos[pila->cantidad - 1];
    pila->cantidad -= 1;
    if (pila->cantidad *4 <= pila->capacidad){
        pila_t* pila_reducida = realloc(pila->datos,pila->capacidad / 2 *sizeof(double));
        if (pila_reducida != NULL){
            pila->datos = pila_reducida;
            pila->capacidad /= 2;
            return (dato_desapilado);
        }
    }
    return(dato_desapilado);
}


void main(){
  pila_t* pi = pila_crear();
  int a = 1;
//  int b = 2;
  int c = 3;
  int d = 5;
  pila_apilar(pi,&a);
  printf("%d",*(int*)pila_ver_tope(pi));
  pila_apilar(pi,&b);
  printf("%d",*(int*)pila_ver_tope(pi));
  pila_apilar(pi,&c);
  printf("%d",*(int*)pila_ver_tope(pi));
  pila_apilar(pi,&d);
  printf("%d",*(int*)pila_ver_tope(pi));

  for(int i = 0;i < 9; i++){
   if (i % 5 == 0){
     pila_apilar(pi,&d);
   }else if (i % 3 == 0){
     pila_apilar(pi,&c);
   }else{
     pila_apilar(pi,&a);
   }
  }

  printf("%d",*(int*)pila_desapilar(pi));
  printf("%d",*(int*)pila_desapilar(pi));
  printf("%d",*(int*)pila_ver_tope(pi));
  printf("%d",*(int*)pila_desapilar(pi));
  printf("%d",*(int*)pila_ver_tope(pi));
  printf("%d",*(int*)pila_desapilar(pi));

  for(int i = 8;i>0;i--){
    pila_desapilar(pi);
  }
  pila_esta_vacia(pi);
  //pila_destruir(pi);
}

*/
