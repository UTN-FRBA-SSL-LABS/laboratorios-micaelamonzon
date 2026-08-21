#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

int test_compra_con_descuento(void){
    printf("\n[total con descuento]\n");
    Carrito c;
    carrito_init(&c);
    Producto pan = {"Pan",200,3};
    carrito_agregar(&c,pan);
    Producto leche = {"Leche",350,2};
    carrito_agregar(&c,leche);
    ASSERT_IGUAL(1300, carrito_total(&c));
    ASSERT_IGUAL(1170, carrito_descuento(1300,10));
} 

int test_agregar_hasta_llenar(void){
    printf("\n[carrito lleno]\n");
    Carrito c;
    carrito_init(&c);
    Producto pan = {"Pan",200,4};
    carrito_agregar(&c,pan);
    carrito_agregar(&c,pan);
    carrito_agregar(&c,pan);
    carrito_agregar(&c,pan);
    ASSERT_IGUAL(MAX_ITEMS, c.cantidad);
    ASSERT_IGUAL(0,carrito_agregar(&c,pan));
    ASSERT_IGUAL(MAX_ITEMS, c.cantidad);
}

int main(void) {
    printf("=== Tests de integracion ===");
    test_compra_con_descuento(); 
    test_agregar_hasta_llenar(); 
    RESUMEN();
    return EXIT_CODE();
}
