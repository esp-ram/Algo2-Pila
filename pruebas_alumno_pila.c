#include "pila.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#define ELEMENTOS_PRUEBA_GRANDE 1100
/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

bool apilar_grande(pila_t* pila, int* vector_pruebas){
    for(int i = 0; i < ELEMENTOS_PRUEBA_GRANDE; i++){
        if (pila_apilar(pila,&vector_pruebas[i]) == false){
            return false;
        }
    }
    return true;
}


bool desapilar_grande(pila_t* pila, int* vector_pruebas){
    int limite = ELEMENTOS_PRUEBA_GRANDE - 1 ;
    while (pila_esta_vacia(pila) == false){
        if (pila_ver_tope(pila) != &vector_pruebas[limite]){
            return false;
        }
        pila_desapilar(pila);
        limite -= 1;
    }
    return true;
}



void pruebas_pila_alumno() {
    pila_t* pi = pila_crear();
    int a = 2;
    int b = 5;
    int c = 7;
    int d = 9;

    print_test("desapilar pila vacia:",pila_desapilar(pi) == NULL);
    print_test("ver tope de pila vacia:",pila_ver_tope(pi) == NULL);
    print_test("ver si la pila esta vacia:",pila_esta_vacia(pi) == true);
    print_test("apilo NULL",pila_apilar(pi,NULL) != false);
    print_test("desapilo NULL",pila_desapilar(pi) == NULL);
    //apilar los tres elementos
    print_test("apilo elemento ",pila_apilar(pi,&a) != false);
    print_test("apilo elemento ",pila_apilar(pi,&b) != false);
    print_test("apilo elemento ",pila_apilar(pi,&c) != false);
    print_test("apilo elemento ",pila_apilar(pi,&d) != false);
    print_test("apilo elemento ",pila_apilar(pi,&a) != false);
    print_test("se verifica el tope de la pila",*(int*)pila_ver_tope(pi) == 2);
    print_test("desapilo un elemento:",*(int*)pila_desapilar(pi) == 2);
    print_test("verificacion si esta vacia",pila_esta_vacia(pi) == false);
    //despilar toda la pila
    print_test("desapilo un elemento:",*(int*)pila_desapilar(pi) == 9);
    print_test("desapilo un elemento:",*(int*)pila_desapilar(pi) == 7);
    print_test("desapilo un elemento:",*(int*)pila_desapilar(pi) == 5);
    print_test("desapilo un elemento:",*(int*)pila_desapilar(pi) == 2);
    print_test("verificacion tope de pila",pila_ver_tope(pi) == NULL);
    print_test("intento desapilar la pila",pila_desapilar(pi) == NULL);
    print_test("veo si la pila esta vacia",pila_esta_vacia(pi) == true);
    //prueba con un numero grande de elementos definidos anteriormente
    int vector_temporal[ELEMENTOS_PRUEBA_GRANDE];
    print_test("apilando muchos elementos",apilar_grande(pi,vector_temporal));
    print_test("despilando los elementos de la pila y verificando tope de pila",desapilar_grande(pi,vector_temporal) == true);
    print_test("pila vacia? ",pila_ver_tope(pi) == NULL);
    print_test("intento de desapilar pila vacia ",pila_desapilar(pi) == NULL);
    printf("destruir pila con elementos\n");
    pila_apilar(pi,&a);
    pila_destruir(pi);
}
