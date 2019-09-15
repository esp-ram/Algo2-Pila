#include "pila.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#define ELEMENTOS_PRUEBA_VOLUMEN 1100

/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

bool apilar_volumen(pila_t* pila, int* vector_pruebas){
    for(int i = 0; i < ELEMENTOS_PRUEBA_VOLUMEN; i++){
        if (pila_apilar(pila,&vector_pruebas[i]) == false){
            return false;
        }
    }
    return true;
}


bool desapilar_volumen(pila_t* pila, int* vector_pruebas){
    int limite = ELEMENTOS_PRUEBA_VOLUMEN - 1 ;
    while (pila_esta_vacia(pila) == false){
        if (pila_ver_tope(pila) != &vector_pruebas[limite]){
            return false;
        }
        pila_desapilar(pila);
        limite -= 1;
    }
    return true;
}

void prueba_crear_destruir(){
    pila_t* pi = pila_crear();
    pila_destruir(pi);
}


void prueba_volumen(){
    pila_t* pi = pila_crear();
    int vector_temporal[ELEMENTOS_PRUEBA_VOLUMEN];
    print_test("apilando muchos elementos",apilar_volumen(pi,vector_temporal) == true);
    print_test("despilando los elementos de la pila y verificando tope de pila",desapilar_volumen(pi,vector_temporal) == true);
    print_test("pila vacia? ",pila_ver_tope(pi) == NULL);
    pila_destruir(pi);
}


void prueba_null(){
    pila_t* pi = pila_crear();
    print_test("apilo NULL",pila_apilar(pi,NULL) != false);
    print_test("desapilo NULL",pila_desapilar(pi) == NULL);
    print_test("pila vacia? ",pila_ver_tope(pi) == NULL);
    pila_destruir(pi);
}


void prueba_pila_nueva(){
    pila_t* pi = pila_crear();
    print_test("pila vacia? ",pila_ver_tope(pi) == NULL);
    print_test("desapilar pila vacia:",pila_desapilar(pi) == NULL);
    print_test("ver tope de pila vacia:",pila_ver_tope(pi) == NULL);
    pila_destruir(pi);
}


void prueba_apilar_desapilar(){
    int a = 2;
    int b = 6;
    int c = 374;
    int d = 52;
    pila_t* pi = pila_crear();
    print_test("apilo elemento ",pila_apilar(pi,&a) != false);
    print_test("se verifica el tope de la pila",*(int*)pila_ver_tope(pi) == a);
    print_test("apilo elemento ",pila_apilar(pi,&b) != false);
    print_test("se verifica el tope de la pila",*(int*)pila_ver_tope(pi) == b);
    print_test("apilo elemento ",pila_apilar(pi,&c) != false);
    print_test("se verifica el tope de la pila",*(int*)pila_ver_tope(pi) == c);
    print_test("apilo elemento ",pila_apilar(pi,&d) != false);
    print_test("se verifica el tope de la pila",*(int*)pila_ver_tope(pi) == d);
    print_test("desapilo un elemento:",*(int*)pila_desapilar(pi) == d);
    print_test("se verifica el tope de la pila",*(int*)pila_ver_tope(pi) == c);
    print_test("desapilo un elemento:",*(int*)pila_desapilar(pi) == c);
    print_test("se verifica el tope de la pila",*(int*)pila_ver_tope(pi) == b);
    print_test("desapilo un elemento:",*(int*)pila_desapilar(pi) == b);
    print_test("se verifica el tope de la pila",*(int*)pila_ver_tope(pi) == a);
    print_test("desapilo un elemento:",*(int*)pila_desapilar(pi) == a);
    printf("comprobacion si la pila funciona como recien creada\n");
    print_test("verificacion tope de pila ",pila_ver_tope(pi) == NULL);
    print_test("intento desapilar la pila ",pila_desapilar(pi) == NULL);
    print_test("veo si la pila esta vacia ",pila_esta_vacia(pi) == true);
    pila_destruir(pi);
}


void destruccion_elementos(){
    int a = 2;
    int b = 5;
    pila_t* pi = pila_crear();
    print_test("apilo elemento ",pila_apilar(pi,&a) != false);
    print_test("apilo elemento ",pila_apilar(pi,&b) != false);
    pila_destruir(pi);
}


void pruebas_pila_alumno(){
    printf("prueba creacion y destruccion de pila:\n");
    prueba_crear_destruir();

    printf("\nprueba comportamiento de pila vacia:\n");
    prueba_pila_nueva();

    printf("\nprueba apilar elemento NULL:\n");
    prueba_null();

    printf("\nprueba de apilado y desapilado de elementos:\n");
    prueba_apilar_desapilar();

    printf("\nprueba con %d elementos:\n",ELEMENTOS_PRUEBA_VOLUMEN);
    prueba_volumen();

    printf("\nprueba destruccion de pila con elementos:\n");
    destruccion_elementos();
}
