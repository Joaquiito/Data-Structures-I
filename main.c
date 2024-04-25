#include <stdlib.h>
#include <stdio.h>
#include "LSOBT.h"

//Grupo 3. Integrantes: Guiñazu Joaquin Miguel y Rodrigo Francisco


void cargaVendedor(vendedor *auxvendedor){
    printf("Ingrese el documento: \n");
    scanf("%lu",&auxvendedor->documento);
    getchar();
    printf("Ingrese el nombre:\n");
    fgets(auxvendedor->nombre,52,stdin);
    strtok(auxvendedor->nombre,"\n");
    printf("Ingrese el numero de telefono: \n");
    fgets(auxvendedor->telefono,17,stdin);
    strtok(auxvendedor->telefono,"\n");
    printf("Ingrese el monto: \n");
    scanf("%f",&auxvendedor->monto);
    printf("Ingrese la cantidad de ventas: \n");
    scanf("%u", &auxvendedor->cantidad);
    getchar();
    printf("Ingrese el canal de ventas: \n");
    fgets(auxvendedor->canal,21,stdin);
    strtok(auxvendedor->nombre,"\n");

}

void inicializar(lso *lso1 ,lsobt *lsobt1){
    lso1->contador=0;
    lso1->list[0].documento=100000000;
    lsobt1->contador=0;
}

void inicio(){
    int op=0;
    int auxop=0;
    int auxres;
    int i = 0;
    lso lso1;
    lsobt lsobt1;
    vendedor auxvendedor;
    char auxchar;
    unsigned long auxdocumento;
    FILE *f1;
    inicializar(&lso1, &lsobt1);
    printf("        Bienvenido al sistema! Que lista desea usar? \n\n\n");
    printf("<1>         Lista Secuencial Ordenada (LSO). \n\n");
    printf("<2>         Lista Secuencial Ordenada con Busqueda Binaria (LSOBT).  \n\n");
    printf("<3>         Salir.\n\n\n");
    do {
        printf("Ingrese una operacion: ");
        scanf("%d",&op);
    }while (0>=op || op>3);
    while (op!=3 && auxop!=8){
        if (op!=3){
            printf("\n\n       Que operacion desea realizar? \n\n");
            printf("<1>         Cargar vendedor. \n\n");
            printf("<2>         Eliminar vendedor.  \n\n");
            printf("<3>         Consultar por un vendedor. \n\n");
            printf("<4>         Determinar si un vendedor esta presente.\n\n");
            printf("<5>         Mostrar lista.\n\n");
            printf("<6>         Precarga. \n\n");
            printf("<7>         Cambiar lista. \n\n");
            printf("<8>         Salir. \n\n\n");
            do {
                printf("Ingrese una operacion: \n");
                scanf("%d",&auxop);
            }while (0>=op || auxop>8);
            system("cls");
            switch (auxop){


                //ALTA
                case 1:
                    auxres=2;
                    if(op==1){
                        if(lso1.contador!=MAX-1){
                            cargaVendedor(&auxvendedor);
                            auxres=alta(&lso1,auxvendedor);
                        }
                        else{
                            printf("La lista esta llena, no pueden cargarse mas elementos. \n");
                        }

                    }
                    else{
                        if(lsobt1.contador!=MAX-1){
                            cargaVendedor(&auxvendedor);
                            auxres=altabt(&lsobt1,auxvendedor);
                        }
                        else{
                            printf("la lista esta llena, no pueden cargarse mas vendedores.\n");
                        }
                    }
                    if (auxres==1){
                        printf("El vendedor se cargo correctamente.\n");
                    }
                    else if(auxres==0){
                        printf("Ya existe un vendedor con ese documento.\n");
                    }

                    break;


                //BAJA
                case 2:
                    if(op==1){
                        if(lso1.contador!=0){
                            printf("Ingrese el documento del vendedor a eliminar \n");
                            scanf("%lu",&auxdocumento);
                            auxres=baja(&lso1,auxdocumento);
                            if(auxres==1){
                                printf("Baja realizada con exito.\n");
                            }
                            else if(auxres==0){
                                printf("No existe un vendedor con ese documento.\n");
                            }
                        }
                        else{
                            printf("La lista esta vacia, no puede eliminarse un elemento \n");
                        }

                    }
                    else{
                        if(lsobt1.contador!=0){
                            printf("Ingrese el documento del vendedor a eliminar: \n");
                            scanf("%lu",&auxdocumento);
                            auxres=bajabt(&lsobt1,auxdocumento);
                            if(auxres==1){
                                printf("Baja realizada con exito.\n");
                            }
                            else if(auxres==0){
                                printf("No existe un vendedor con ese documento.\n");
                            }
                        }
                        else{
                            printf("La lista esta vacia, no puede eliminarse un elemento. \n");
                        }
                    }


                    break;


                //CONSULTAR
                case 3:
                    if(op==1){
                        if(lso1.contador!=0){
                            printf("Ingrese el documento del vendedor a consultar: \n");
                            scanf("%lu",&auxdocumento);
                            getchar();
                            auxvendedor=evocacion(&lso1,auxdocumento,&auxres);
                            if(auxres==1){
                                muestraPantalla(auxvendedor);
                            }
                            else{
                                printf("No existe un vendedor con ese documento \n");
                            }

                        }
                        else{
                            printf("La lista esta vacia, no se puede consultar. \n");
                        }

                    }
                    else{
                        if(lsobt1.contador!=0){
                            printf("Ingrese el documento del vendedor a consultar: \n");
                            scanf("%lu",&auxdocumento);
                            getchar();
                            auxvendedor=evocacionbt(&lsobt1,auxdocumento,&auxres);
                            if(auxres==1){
                                muestraPantalla(auxvendedor);
                            }
                            else{
                                printf("No existe un vendedor con ese documento \n");
                            }
                        }
                        else{
                            printf("La lista esta vacia, no se puede consultar \n");
                        }
                    }

                    break;


                //PERTENECE
                case 4:
                    if(op==1){
                        if(lso1.contador!=0){
                            cargaVendedor(&auxvendedor);
                            auxres=pertenece(&lso1,auxvendedor);
                            if (auxres==1){
                                printf("El vendedor esta cargado en la lista.\n");
                            }
                            else{
                                printf("El vendedor no esta cargado en la lista.\n");
                            }
                        }
                        else{
                            printf("La lista esta vacia, no se puede realizar la operacion. \n");
                        }

                    }
                    else{
                        if(lsobt1.contador!=0){
                            cargaVendedor(&auxvendedor);
                            auxres=pertenecebt(&lsobt1,auxvendedor);
                            if (auxres==1){
                                printf("El vendedor esta cargado en la lista.\n");
                            }
                            else{
                                printf("El vendedor no esta cargado en la lista.\n");
                            }
                        }
                        else{
                            printf("la lista esta vacia, no se puede realizar la operacion\n");
                        }
                    }

                    break;



                //Mostrar toda la lista
                case 5:
                    getchar();
                    if(op==1){
                        if(lso1.contador!=0){
                            for(i=0;i<lso1.contador;i++){
                                muestraPantalla(lso1.list[i]);
                                getchar();
                            }
                        }
                        else{
                            printf("La lista esta vacia. \n");
                        }
                    }
                    else{
                        if(lsobt1.contador!=0){
                            for(i=0;i<lsobt1.contador;i++){
                                muestraPantalla(lsobt1.list[i]);
                                getchar();
                            }
                        }
                        else{
                            printf("La lista esta vacia. \n");
                        }
                    }

                    break;


                //Precarga
                case 6:


                  if((f1=fopen("vendedores.txt","r"))==NULL){
                      printf("El archivo no pudo ser arbierto, por favor intentelo de nuevo mas tarde\n");
                  }
                  else{
                      if(op==1){
                        if(lso1.contador >= 110){
                            printf("La lista esta llena. \n");
                        }else{
                        while(feof(f1)==0&& lso1.contador<110){


                              //Documento
                              fscanf(f1,"%lu",&auxvendedor.documento);
                              fscanf(f1,"%c",&auxchar);

                              //Nombre
                              /*https://stackoverflow.com/questions/1247989/how-do-you-allow-spaces-to-be-entered-using-scanf*/
                              /*usamos una funcion que permite espacios y tiene proteccion de buffer.*/
                              fgets(auxvendedor.nombre,51,f1);
                              /*https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input*/
                              /*strtok limpia el caracter\n*/
                              strtok(auxvendedor.nombre,"\n");

                              //Telefono
                              /*https://stackoverflow.com/questions/1247989/how-do-you-allow-spaces-to-be-entered-using-scanf*/
                              /*usamos una funcion que permite espacios y tiene proteccion de buffer.*/
                              fgets(auxvendedor.telefono,17,f1);
                              /*https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input*/
                              /*strtok limpia el caracter\n*/
                              strtok(auxvendedor.telefono,"\n");



                              //Monto
                              fscanf(f1,"%f",&auxvendedor.monto);
                              fscanf(f1,"%c",&auxchar);

                              //Cantidad
                              fscanf(f1,"%d",&auxvendedor.cantidad);
                              fscanf(f1,"%c",&auxchar);

                              //Canal venta
                              fgets(auxvendedor.canal,21, f1);
                              strtok(auxvendedor.canal,"\n");

                              //Alta
                              alta(&lso1,auxvendedor);
                          }
                          printf("La precarga se realizo con exito. \n");
                        }

                      }
                      else{
                        if(lsobt1.contador >=110){
                            printf("La lista esta llena. \n");
                        }else {
                        while(feof(f1)==0&& lsobt1.contador<110){

                              //Documento
                              fscanf(f1,"%lu",&auxvendedor.documento);
                              fscanf(f1,"%c",&auxchar);

                              //Nombre
                              /*https://stackoverflow.com/questions/1247989/how-do-you-allow-spaces-to-be-entered-using-scanf*/
                              /*usamos una funcion que permite espacios y tiene proteccion de buffer.*/
                              fgets(auxvendedor.nombre,51,f1);
                              /*https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input*/
                              /*strtok limpia el caracter \n*/
                              strtok(auxvendedor.nombre,"\n");

                              //Telefono
                              /*https://stackoverflow.com/questions/1247989/how-do-you-allow-spaces-to-be-entered-using-scanf*/
                              /*usamos una funcion que permite espacios y tiene proteccion de buffer.*/
                              fgets(auxvendedor.telefono,17,f1);
                              /*https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input*/
                              /*strtok limpia el caracter\n*/
                              strtok(auxvendedor.telefono,"\n");

                              //Monto
                              fscanf(f1,"%f",&auxvendedor.monto);
                              fscanf(f1,"%c",&auxchar);

                              //Cantidad
                              fscanf(f1,"%d",&auxvendedor.cantidad);
                              fscanf(f1,"%c",&auxchar);

                              //Canal venta
                              fgets(auxvendedor.canal,22, f1);
                              strtok(auxvendedor.canal,"\n");

                              //Alta
                              altabt(&lsobt1,auxvendedor);
                          }
                          printf("La precarga se realizo con exito. \n");
                        }
                    }
                    fclose(f1);
                  }

                  break;


                //Cambiar lista
                case 7:
                    printf("      Sobre que lista desea operar?\n\n");
                    printf("<1>         Lista Secuencial Ordenada (LSO). \n\n\n");
                    printf("<2>         Lista Secuencial Ordenada con Busqueda Binaria (LSOBT).  \n\n\n");
                    printf("<3>         Salir.\n\n\n");
                    do {
                        printf("Ingrese una operacion: ");
                        scanf("%d",&op);
                    }while (0>=op || op>3);
                    break;
            }
        }
    }
}


int main() {
    inicio();
    system("cls");
    printf("Gracias por usar nuestro sistema! \n");
    return 0;
}
