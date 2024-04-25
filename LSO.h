#ifndef LSO_H_INCLUDED
#define LSO_H_INCLUDED

#endif // LSO_H_INCLUDED

//Grupo 3. Integrantes: Gui�azu Joaquin Miguel y Rodrigo Francisco

#define MAX 111
#include "Vendedor.h"

typedef struct {
    vendedor list [MAX];
    int contador ;
} lso;

int localizar(lso *lista, unsigned long x/*documento, in*/, int *pos/*posicion, out*/ ) {
    int i = 0;
    while (lista->list[i].documento < x) {
        i++;
    }
    *pos = i;
    if (lista->list[i].documento == x) {
        //�xito
        return 1;
    } else {
        //fracaso
        return 0;
    }
}

int alta(lso *lista, vendedor x/*in*/) {
    int pos;
    int i = 0;
    if (localizar (lista, x.documento, &pos) == 1) {
        return 0;
    } else {
        for (i = lista->contador; i >= pos; i--) {
            lista->list[i + 1] = lista->list[i];
        }
        lista->list[pos] = x;
        lista->contador++;
        return 1;
    }
}

int baja(lso *lista, unsigned long doc) {
    int pos, op, i;
    if (localizar(lista,doc, &pos) == 0) {
        return 0;
    } else {
        muestraPantalla(lista->list[pos]);
        printf("Desea eliminar este vendedor? 1=SI, 2=NO \n");
        scanf("%d", &op);
        if (op == 1) {
            i = pos;
            while (i <= lista->contador) {
                lista->list[i] = lista->list[i + 1];
                i++;
            }
            lista->contador--;
            return 1;
        } else {
            return 2;
        }
    }
}

int pertenece(lso *lista, vendedor x) {
    int pos;
    if (localizar(lista ,x.documento, &pos)==1 && strcmp(lista->list[pos].nombre, x.nombre) == 0 &&
                                            (strcmp(lista->list[pos].telefono, x.telefono)==0)&&
                                            lista->list[pos].monto == x.monto && lista->list[pos].cantidad == x.cantidad &&
                                            strcmp(lista->list[pos].canal, x.canal) == 0){
        return 1;
    }
    else {
        return 0;
    }
}

vendedor evocacion(lso *lista, unsigned long doc ,int *res){
    int pos;
    vendedor auxvend;
    auxvend.documento=100000000;
    if (localizar(lista, doc, &pos)==1){
        *res=1;
        return lista->list[pos];

    }
    else{
        *res=0;
        return auxvend;
    }
}
