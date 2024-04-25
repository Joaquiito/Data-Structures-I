#ifndef LSOBT_H_INCLUDED
#define LSOBT_H_INCLUDED

#endif // LSOBT_H_INCLUDED
//Grupo 3. Integrantes: Guiñazu Joaquin Miguel y Rodrigo Francisco

#include "LSO.h"
typedef struct {
    vendedor list [MAX-1];
    int contador ;
} lsobt;

int localizarbt(lsobt *lista, unsigned long long x, int *pos){
    int li, ls, i=0;
    li=-1;
    ls=lista->contador-1;
    while((li+1)<ls){
        i=(li+1+ls)/2;
        if(lista->list[i].documento==x){
            *pos=i;
            return 1;
        }
        else if(lista->list[i].documento>x){
            ls=i-1;
        }
        else{
            li=i;
        }
    }
    if(lista->list[li+1].documento<x && lista->contador!=0){
        *pos=li+2;
    }
    else{
      *pos=li+1;
    }

    if(lista->list[li+1].documento==x){
        return 1;
    }
    else{
        return 0;
    }
}

int altabt(lsobt *lista, vendedor x/*in*/) {
    int pos;
    int i = 0;
    if (localizarbt (lista, x.documento, &pos) == 1) {
        return 0;
    } else {
        for (i = lista->contador; i > pos; i--) {
            lista->list[i] = lista->list[i-1];
        }
        lista->list[pos] = x;
        lista->contador++;
        return 1;
    }
}

int bajabt(lsobt *lista, unsigned long doc) {
    int pos, op, i;
    if (localizarbt(lista,doc, &pos) == 0) {
        return 0;
    } else {
        muestraPantalla(lista->list[pos]);
        printf("Desea eliminar este vendedor? 1=SI, 2=NO \n");
        scanf("%d", &op);
        if (op == 1) {
            i = pos;
            while (i < lista->contador-1) {
                lista->list[i] = lista->list[i+1];
                i++;
            }
            lista->contador--;
            return 1;
        } else {
            return 2;
        }
    }
}

int pertenecebt(lsobt *lista, vendedor x) {
    int pos;
    if (localizarbt(lista ,x.documento, &pos)==1 && strcmp(lista->list[pos].nombre, x.nombre) == 0 &&
            (strcmp(lista->list[pos].telefono, x.telefono)==0)    &&
        lista->list[pos].monto == x.monto && lista->list[pos].cantidad == x.cantidad &&
        strcmp(lista->list[pos].canal, x.canal) == 0){
        return 1;
    }
    else {
        return 0;
    }
}

vendedor evocacionbt(lsobt *lista, unsigned long doc ,int *res){
    int pos;
    vendedor auxvend;
    auxvend.documento=100000000;
    if (localizarbt(lista, doc, &pos)==1){
        *res=1;
        return lista->list[pos];
    }
    else{
        *res=0;
        return auxvend;
    }
}



