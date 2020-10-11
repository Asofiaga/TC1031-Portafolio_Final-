#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>

using namespace std;

#include "DoubleLinkedList.h"

/*
Equipo 10
Autores:
Karla Susana Olvera Vazquez  A01379097
Ana Sofia Gutierrez Aldape   A00827191
Carlos Gabriel Mora Madrigal A01379575

Programa que lee datos de una bitacora, los ordena de manera ascendente.
Pregunta al usuario por un un intervalo de direcciones ip en formato xxx.xxx.xxx.xxx:xxxx
Despliega en consola y en un archivo de salida este intervalo ya ordenado.

Ultima Feha de Modificaci—n: 10/10/2020
*/


//Carga una lista doblemente enlazada con los datos del archivo
//Complejidad o(n)
void cargarBase(DoubleLinkedList &lista){
    string mes,dia,horario,ip,err;
    Datos bob = Datos();
    ifstream database;
    long long cont = 0;
    database.open("bitacora.txt");
    cout << "Cargando base, por favor espere"<<endl;
    while(database >> mes){
        database >> dia;
        database >> horario;
        database >> ip;
        getline(database, err);
        bob = Datos(mes, dia, horario, ip, err);
        lista.appendNode(bob);
        cont++;
        if(cont==1000){ //Failsafe para recibir solo 1000 datos
            break;      //El programa puede recibir los registros de la base completa, pero
        }               //tarda mucho tiempo en cargarlos a la LinkedList
    }
    database.close();
}

int main() {
    DoubleLinkedList DLL;
    int opcion=3;
    string ipInicio, ipFin;
    Datos bufferInicio, bufferFin;
    cargarBase(DLL);
    DLL.bubbleSort();
    cout<<"BASE DE DATOS DLL ver. 1.1"<<endl;
    cout<<endl;

    while(opcion != 0){
        cout<<"Consultas:"<<endl;
        cout<<"1- Imprimir Base de datos completa"<<endl;
        cout<<"2- Imprimir seccion de Base de datos"<<endl;
        cout<<"0- Salir"<<endl;
        cin >> opcion;

        switch(opcion){
            case 1:
                DLL.printList();
                break;
            case 2:
                cout << "Introduce la ip de inicio: "; cin >> ipInicio;
                cout << "Introduce la ip final: "; cin >> ipFin;
                bufferInicio = Datos("", "", "", ipInicio, "");
                bufferFin = Datos("", "", "", ipFin, "");
                DLL.selectPrint(bufferInicio.generateKey(), bufferFin.generateKey());
                break;
        }
    }
    DLL.~DoubleLinkedList();
    return 0;
}
