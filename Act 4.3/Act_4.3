//
//  main.cpp
//  Act 4.3
//
//  Created by sofía gtz on 18/11/20.
//

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

/*
Integrantes
Karla Susana Olvera Vazquez     A01379097
Ana Sofia Gutierrez Aldape      A00827191
Carlos Gabriel Mora Madrigal    A01379575

Actividad 4.3 - Actividad Integral de grafos
Ultima modificacion: 20/11/2020

Buscar los botmasters de una base de datos(direcciones Ip con mayor out degree)
*/



/*
Cargar Lista UMAP
Carga un unordered map con direcciones ip, posiciones en una lista lineal y su out degree
Carga una lista adjacente con las direcciones ip y sus direcciones adjacentes
Busca e imprime las direcciones ip con mayor out degree
*/
//Complejidad: O(n)
void cargarListaUMAP(unordered_map<string, pair<int, int>> &umapNodos, vector<vector<string>> &listAdj){
    string dato, mes, dia, horario, source, destination, message;
    string ODMip;
    int n, m, cont=0, ODmax=0;
    ifstream file;

    //Leer archivo de bitacora
    file.open("bitacoraACT4_3(B).txt");

    //Leer nodos y arcos
    file >> n >> m;
    vector<vector<string>> listaAuxiliar(n);

    //Agregar todas las direcciones ip
    while(file>>dato){
        umapNodos[dato] = make_pair(cont, 0);
        if(cont==n-1)
            break;
        cont++;
    }

    while(file >> mes >> dia >> horario >> source >> destination, getline(file, message)){
        //Eliminar los dos puntos y puerto ":XXXX" de la direccion ip
        source.erase(source.begin()+source.size()-5, source.end());
        destination.erase(destination.begin()+destination.size()-5, destination.end());

        listaAuxiliar[umapNodos[source].first].push_back(destination);

        //Incrementar el outdegree de source
        umapNodos[source].second++;

        //Comparar si el nodo actual es mas grande que el buffer
        if(umapNodos[source].second>ODmax){
            ODmax = umapNodos[source].second;
        }
    }

    listAdj = listaAuxiliar;

    //Imprimir el nodo con out degree mas grande
    cout << endl;
    cout << "Botmasters: " << endl;
    cout << "Pos  " << "OutDeg " << "IP" << endl;
    for(auto x : umapNodos)
        if(x.second.second == ODmax)
            cout << x.second.first << " " << x.second.second << "     " << x.first << endl;

}

int main(){
    unordered_map<string, pair<int, int>> umapNodos;
    vector<vector<string>> listAdj;
    cargarListaUMAP(umapNodos, listAdj);

    return 0;
}
