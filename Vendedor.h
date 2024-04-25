#ifndef VENDEDOR_H_INCLUDED
#define VENDEDOR_H_INCLUDED

#endif // VENDEDOR_H_INCLUDED

//Grupo 3. Integrantes: Guiñazu Joaquin Miguel y Rodrigo Francisco

#include <malloc.h>
#include <string.h>

typedef struct {
    unsigned long documento;
    char nombre [52];
    char telefono [17];
    float monto;
    unsigned int cantidad;
    char canal[22];
}vendedor;

void muestraPantalla(vendedor x){
    printf("\n");
    printf("Nombre: %s\n", x.nombre);
    printf("DNI: %lu\n", x.documento);
    printf("Telefono: %s\n", x.telefono);
    printf("Monto: %f\n", x.monto);
    printf("Cantidad vendida: %u\n", x.cantidad);
    printf("Canal de venta: %s\n", x.canal);
}



