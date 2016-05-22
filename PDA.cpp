#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<iomanip>
#define pausa system("pause>p.txt")
#define limpiar system("cls")

using namespace std;

class Cliente
{
    string nombre, apellido, direccion;
    int cedula;
    bool estado;
public:
    void guardar();
    void modificar();
    bool validar(int);
    void mostrar();
}cl;

bool Cliente::validar(int ce){
        char linea[256];
        string clave;
        bool va=false;
        int cc;
        ifstream in;
        in.open("clientes.txt", ios::in);
        while(in && !in.eof())
        {
            in.getline(linea, 256);
            clave=linea;
            cc=atoi((clave.substr(0,10)).c_str());
            if(ce==cc)
                va=true;
        }
        return va;
        in.close();
    }

void Cliente::guardar(){
        bool v=false;
        estado=true;
        fstream o;
        o.open("clientes.txt", ios::out | ios::app);

        do{
        cout<<"Cedula del cliente: "; cin>>cedula;
        v=validar(cedula);
        if(v==true)
            cout<<"Cedula existente";
        }while(v==true);
        cout<<"Nombre del cliente: "; cin>>nombre;
        cout<<"Apellido del cliente: "; cin>>apellido;
        cout<<"Direccion: "; cin>>direccion;

        o<<setiosflags(ios::left)<<setw(10)<<cedula;
        o<<setiosflags(ios::left)<<setw(15)<<nombre;
        o<<setiosflags(ios::left)<<setw(15)<<apellido;
        o<<setiosflags(ios::left)<<setw(30)<<direccion;
        o<<setiosflags(ios::left)<<setw(2)<<estado;
        o<<endl;

        o.close();
    }

void Cliente::mostrar()
{
    char reg[120];
    fstream is;
    is.open("clientes.txt", ios::in);
    if(!is)
    {
        cout<<"Error de apertura"<<endl; pausa;
        exit(1);
    }


    while(is && !is.eof())
    {
        is.getline(reg, 120);
        cout<<reg<<endl;
    }
    is.close();

}


class cuentas
{
    int numero, cedula;
    float saldo;
    string tipo;
    bool estado;
public:
    void guardar();
    bool validar(int);
    void mostrar();
}cu;

void cuentas::mostrar()
{
    ifstream in;
    char linea[80];
    string clave;
    in.open("cuentas.txt", ios::in);
    while(in && !in.eof())
    {
        in.getline(linea, 80);
        clave=linea;
        if(clave.substr(60)=="1")
            cout<<clave.substr(0, 59)<<endl;
    }
    in.close();
}

bool cuentas::validar(int ce){
        char linea[80];
        string clave;
        bool va=false;
        int cc;
        ifstream in;
        in.open("cuentas.txt", ios::in);
        while(in && in.eof())
        {
            in.getline(linea, 80);
        }
        in.close();
        return va;
    }


void cuentas::guardar(){
        bool v=false;
        estado=true;
        ofstream o;

        do{
        cout<<"Ingrese la cedula: "; cin>>cedula;
        v=cl.validar(cedula);
        if(v==false)
        cout<<"la cedula no existe"<<endl;
        }while(v==false);
        v=false;
        do{
        cout<<"Ingrese el numero de cuenta: "; cin>>numero;
        v=validar(numero);
        if(v==true)
        cout<<"el numero de cuenta ya existe"<<endl;
        }while(v==true);
        cout<<"Ingrese el tipo de cuenta: "; cin>>tipo;
        cout<<"Ingrese el saldo: "; cin>>saldo;
        o.open("cuentas.txt", ios::out | ios::app);
        o<<setiosflags(ios::left)<<setw(10)<<cedula;
        o<<setiosflags(ios::left)<<setw(30)<<numero;
        o<<setiosflags(ios::left)<<setw(10)<<tipo;
        o<<setiosflags(ios::left)<<setw(10)<<saldo;
        o<<setiosflags(ios::left)<<setw(2)<<estado;
        o<<endl;

        o.close();

    }


class transacciones
{
    int numero, codigo;
    float monto;
    string tipo;
    bool estado;
    public:
    void guardar();
    bool validar(int);
    void mostrar();
}tr;

bool transacciones::validar(int n)
{
    bool v=false;
    char linea[80];
    string clave;
    int nc;
    ifstream in;
    in.open("cuentas.txt", ios::in);
    while(in && !in.eof())
    {
        in.getline(linea, 80);
        clave=linea;
        nc=atoi((clave.substr(11,22)).c_str());
        if(n==nc)
            v=true;
    }
    in.close();
    return v;


}

void transacciones::guardar()
{
    estado=true;
    bool v=false;
    do{
        cout<<"Nro cuenta:"; cin>>numero;
        v=validar(numero);
        if(v==false)
            cout<<"El numero de cuenta no existe"<<endl;
    }while(!v);
    cout<<"Tipo de transaccion:";cin>>tipo; cin.ignore();
    cout<<"Monto de la transaccion: "; cin>>monto; cin.ignore();
    cout<<"Codigo de operacion: "; cin>>codigo; cin.ignore();
    ofstream o;
    o.open("Transacciones.txt", ios::app);
    o<<setiosflags(ios::left)<<setw(30)<<numero;
    o<<setiosflags(ios::left)<<setw(9)<<tipo;
    o<<setiosflags(ios::left)<<setw(5)<<codigo;
    o.close();
}

char menu()
{
    char op;
    limpiar;
    cout<<"1. Agregar cliente"<<endl;
    cout<<"2. Crear cuenta"<<endl;
    cout<<"3. Modificar datos de una cuenta"<<endl;
    cout<<"4. Eliminar datos de una cuenta"<<endl;
    cout<<"5. Transaccion"<<endl;
    cout<<"6. Reportes"<<endl;
    cout<<"7. Salir"<<endl;
    cin>>op;
    limpiar;
    return op;
}


char menu2()
{
    char op;
    limpiar;
    cout<<"1. Transacciones de una cuenta "<<endl;
    cout<<"2. Datos de un cliente"<<endl;
    cout<<"3. Saldos de cuentas de un cliente"<<endl;
    cout<<"4. Cuentas en el banco"<<endl;
    cout<<"5. Clientes"<<endl;
    cout<<"6. Salir"<<endl;
    cin>>op;
    limpiar;
    return op;
}

main()
{
    char op1, op2;
    do{
        op1=menu();
        switch(op1)
        {
            case '1': cl.guardar(); break;
            case '2': cu.guardar(); break;
            case '3': break;
            case '4': break;
            case '5': tr.guardar(); break;
            case '6': {
                do{
                    op2=menu2();
                    switch(op2)
                    {
                        case '1': break;
                        case '2': break;
                        case '3': break;
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
