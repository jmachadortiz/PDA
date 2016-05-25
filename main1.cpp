#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <string.h>
#include <stdlib.h>
#define pausa system("pause>p.txt")
#define limpiar system("cls")

    using namespace std;

#include "cliente.h"
#include "menu.h"
#include "transaccion.h"
#include "cuenta.h"



int main(){
    Cliente cl;
    Cuenta cu;
    Transaccion tr;
    char op1, op2;

    do{
        op1=menu();
        switch(op1)
        {
            case '1': cl.guardar(); break;
            case '2': cu.guardar(cl); break;
            case '3': cu.modificar(cl, tr); break;
            case '4': cu.eliminar(cl, tr); break;
            case '5': tr.guardar(); break;
            case '6': {
                do{
                    op2=menu2();
                    switch(op2)
                    {
                        case '1': tr.mostrar(); pausa; break;
                        case '2': cl.mostrar_unico(); pausa; break;
                        case '3': cu.mostrarsaldo(cl); pausa; break;
                        case '4': cu.mostrar(); pausa; break;
                        case '5': cl.mostrar(); pausa; break;
                        case '6': break;
                        default: cout<<"Opcion no valida"<<endl; break;
                    }
                }while(op2!='6');
                        }break;
            case '7': break;
            default: cout<<"Opcion no valida"<<endl; break;
        }
    }while(op1!='7');
}


