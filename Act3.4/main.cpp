//
//  main.cpp
//  Act3.4
//
//  Created by sofía gtz on 23/10/20.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <queue>

using namespace std;
#include "BST.hpp"

/*

Integrantes
Karla Susana Olvera Vazquez     A01379097
Ana Sofia Gutierrez Aldape      A00827191
Carlos Gabriel Mora Madrigal    A01379575

Actividad 3.4 - Actividad Integral BST
Ultima modificacion: 25/10/2020

Busca las direcciones Ip de una lista ordenada y
obtiene el Top 5 de direciones Ip mas accesadas

*/

//Genera un string con el formato de la llave
//Complejidad Constante o(1)
string concatenarKey(int kI1, int kI2, int kI3, int kI4){
    string k1 = to_string(kI1);
    string k2 = to_string(kI2);
    string k3 = to_string(kI3);
    string k4 = to_string(kI4);

    if(k1.size() != 3 && k1.size() != 2){
        k1 = "00" + k1;
    }
    else if(k1.size() == 2){
        k1 = "0" + k1;
    }
    if(k2.size() != 3 && k2.size() != 2){
        k2 = "00" + k2;
    }
    else if(k2.size() == 2){
        k2 = "0" + k2;
    }
    if(k3.size() != 3 && k3.size() != 2){
        k3 = "00" + k3;
    }
    else if(k3.size() == 2){
        k3 = "0" + k3;
    }
    if(k4.size() != 3 && k4.size() != 2){
        k4 = "00" + k4;
    }
    else if(k4.size() == 2){
        k4 = "0" + k4;
    }
    string llave = k1 + k2 + k3 + k4;
    return llave;
}

//Genera un long long con la key unica del registro
//Complejidad constante O(1)
long long generateKey(string ip){
    int keyI1,keyI2,keyI3,keyI4,keyI5;
    string keyS, keySCor;
    long long keyL;
    char point, points;

    stringstream stream(stringstream::in | stringstream::out);
    stream << ip;

    //separa el string ip en unidades (long), punto y dos puntos
    stream >> keyI1;
    stream >> point;
    stream >> keyI2;
    stream >> point;
    stream >> keyI3;
    stream >> point;
    stream >> keyI4;
    stream >> points;
    stream >> keyI5;

    //convierte las variables ints en strings, completa ip si faltan 0's y concatena
    keyS = concatenarKey(keyI1,keyI2,keyI3,keyI4);

    //convierte el string key en long
    keyL = stoll(keyS);
    return keyL;
}

//Carga un BST con los datos del archivo
//Complejidad o(n)
void cargarBase(BST &lista){
    string mes, dia, horario, ip, err, bufferIp;
    ifstream database;
    long long cont=1, currIp, bufferLongIp;
    database.open("bitacoraOrdenada.txt");

    while(database >> mes, database >> dia, database >> horario, getline(database, ip, ':')){
        getline(database, err);
        currIp = generateKey(ip);

        if(currIp == bufferLongIp){
            cont++;
        }
        else{
            lista.add(cont, bufferIp, bufferLongIp);
            bufferIp = ip;
            bufferLongIp = currIp;
            cont = 1;
        }
    }
    database.close();
}

int main()
{
    BST lista;
    cargarBase(lista);
    cout << "Top 5 direcciones Ip mas frecuentadas:" << endl;
    //lista.printInOrden();
    lista.printTop5();
    return 0;
}
