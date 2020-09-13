/* Equipo 10
Autores:
Karla Susana Olvera Vazquez  A01379097
Ana Sofia Gutierrez Aldape   A00827191
Carlos Gabriel Mora Madrigal A01379575
Progrma que lee datos de una bitacora, los ordena de manera ascendente y pregunta al usuario por un un intervalo de fechas (mes y día) y despliega en consola y en un archivo de salida este intervalo.
Ultima Feha de Modificación: 12/09/2020 */

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

//Struct de datos
//Crear un nuevo tipo de dato para almacenar todos los atributos de la lista
//Complejidad constante n
struct datos{
  int fecha;
  int dia;
  string mes, horario, IP, err;
};

//ConvertirMes
//Convierte la nomenclatura de letra a numero los meses
//Complejidad Constante n
int convertirMes(string mes){
  int num;
  if(mes == "Jun"){
    num = 6;
  }
  else if(mes == "Jul"){
    num = 7;
  }
  else if(mes == "Aug"){
    num = 8;
  }
  else if(mes == "Sep"){
    num = 9;
  }
  else if(mes == "Oct"){
    num = 10;
  }
  return num;
}

//ConvertirDia
//Adapta la nomenclatura de los numeros del dia para trabajar en centenas
//Complejidad Constante n
string convertirDia(string dia){
    string num;
    num = dia;
    if(dia=="1"){
        num = "0"+dia;
        return num;
    }
    if(dia=="2"){
        num = "0"+dia;
        return num;
    }
    if(dia=="3"){
        num = "0"+dia;
        return num;
    }
    if(dia=="4"){
        num = "0"+dia;
        return num;
    }
    if(dia=="5"){
        num = "0"+dia;
        return num;
    }
    if(dia=="6"){
        num = "0"+dia;
        return num;
    }
    if(dia=="7"){
        num = "0"+dia;
        return num;
    }
    if(dia=="8"){
        num = "0"+dia;
        return num;
    }
    if(dia=="9"){
        num = "0"+dia;
        return num;
    }
    return num;
}

//Concatenar
//Genera el identificador de posicion en la lista a ordenar
//Complejidad Constante n
string concatenar(string mes, string dia){
  string fecha = mes+convertirDia(dia);
  return fecha;
}


//cargarBase
//Carga un vector con los datos del archivo, separado por atributos
//Complejidad Lineal O(n)
void cargarBase(vector<datos> &lista){
  ifstream database;
  int dia, fecha, numMes, cont, numDia;
  string mes, horario, IP, err, mesS, diaS;

  database.open("bitacora.txt");
  cont = 0;
  while(database >> mes){
    database >> dia;
    getline(database, horario, ' ');
    getline(database, IP, ' ');
    getline(database, err);

    //Convertir de mes a numero
    numMes = convertirMes(mes);
    numDia = dia;

    mesS = to_string(numMes);
    diaS = to_string(numDia);

    //Concatenar
    fecha = stoi(concatenar(mesS, diaS));

    //Almacenar en vector
    lista.push_back(datos());
    lista[cont].fecha = fecha;
    lista[cont].mes = mes;
    lista[cont].dia = dia;
    lista[cont].horario = horario;
    lista[cont].IP = IP;
    lista[cont].err = err;
    cont++;
  }
}


//Merge Sort Function
//En conjunto funcion une y funcion ordenaMerge
//Función dentro de ordenaMerge() que realiza la unión de los subarreglos y contabiliza las comparaciones. Complejidad Lineal O(n)
void une(vector<datos> &vec, vector<datos> &aux, long ini, long fin){
  int m = (ini+fin)/2;
  int i = ini, j = m+1, k = ini;
  while(i<=m && j<=fin){
    if(vec[i].fecha <= vec[j].fecha){
      aux[k++] = vec[i++];
    }
    else{
       aux[k++] = vec[j++];
    }
  }
  while(i <= m){
    aux[k++] = vec[i++];
  }
  while(j <= fin){
    aux[k++] = vec[j++];
  }
  for(int z=ini; z<=fin; z++){
    vec[z] = aux[z];
  }
}

//Ordena el vector de manera ascendente usando un merge sort
//Complejidad logaritmica O(n log(n))
void ordenaMerge(vector<datos> &vec, vector<datos> &aux, long inicio, long fin){
  if(inicio < fin){
    //cout << "entre bien" << endl;
    int mitad = (inicio+fin)/2;
    ordenaMerge(vec,aux,inicio,mitad); //divide mitad, mitad, mitad hasta llegar a una unidad, de lado izquierdo y derecho
    ordenaMerge(vec,aux,mitad+1,fin);
    une(vec,aux,inicio,fin);
  }
}

//Busqueda Binaria
//Busca un dato dentro de un vector y regresa su posicion dentro del vector
//Si no lo encuentra, vuelve a ejecutar la funcion con el valor anterior al dato original
//Complejidad logaritmica o(log base 2(n))
int busquedaBinaria(vector<datos> &vec, int dato){
  //busqueda del primer dato
  int ini = 0, fin = vec.size()-1, mit;
  while(ini <= fin){
    mit = (ini+fin)/2;
    if(vec[mit].fecha == dato){
      return mit;
    }
    if(vec[mit].fecha > dato){
      fin = mit-1;
    }
    else{
      ini = mit+1;
    }
  }
  //si no los encuentra, busca de nuevo el valor
  //proximo anterior
  return busquedaBinaria(vec, dato-1);
}

//Print Seleccion
//Imprime en consola un intervalo de los datos del vector
//Complejidad lineal O(n)
void printSeccion(vector<datos> lista, long ini, long fin){
  cout << "---------------- Informacion del intervalo -----------------" << endl;
  for (int i=ini;i<=fin;i++){
    cout << lista[i].fecha << " " << lista[i].mes << " " << lista[i].dia << " " <<
    lista[i].horario << " " << lista[i].IP << " " << lista[i].err << endl;
  }
  cout << "----------------------------------------------------------------------------" << endl;
}

//Print lista
//Imprime en consola todos los datos de la lista
//Complejidad lineal o(n)
void printLista(vector<datos> lista){
  cout << "---------------- Informacion de archivo original ordenados -----------------" << endl;
  for (int i=0;i<lista.size();i++){
    cout << lista[i].fecha << " " << lista[i].mes << " " << lista[i].dia << " " <<
    lista[i].horario << " " << lista[i].IP << " " << lista[i].err << endl;
  }
  cout << "----------------------------------------------------------------------------" << endl;
}

//exportar seleccion
//Exporta a un archivo de salida un intervalo de datos de un vector de datos
//Complejidad lineal o(n)
void exportarSeleccion(vector<datos> lista, long ini, long fin){
  ofstream ofs;
  string nombre;
  cout << "Ingresa el nombre de salida: " << endl;
  cin >> nombre;
  ofs.open(concatenar(nombre, ".txt"));
  for (int i=ini;i<=fin;i++){
    ofs << lista[i].mes << " " << lista[i].dia << " " <<lista[i].horario << " "
    << lista[i].IP << " " << lista[i].err << endl;
  }
  ofs.close();
}


//intervalos
//En el vector de datos, busca un intervalo de valores y los imprime, despues
//pregunta si se quiere exportar a un archivo externo esa seleccion
//Complejidad lineal o(n)
void intervalos(vector<datos> lista){
  int fechaI, fechaF, pos1, pos2, opcion;
  int d1,d2,nm1,nm2;
  string m1, m2;
  cout << "Ingrese los intervalos de las fechas (De Jun a Oct): " << endl;
  cout << "Fecha 1: " << "\nMes: "; cin >> m1;
  cout << "dia: "; cin >> d1;
  cout << "\nFecha 2: " << "\nMes: "; cin >> m2;
  cout << "dia: "; cin >> d2;
  //convertir mes a numero
  nm1 = convertirMes(m1); nm2 = convertirMes(m2);
  //convierte el num//Complejidad lineal o(n)ero del mes a string
  string mS1 = to_string(nm1); string mS2 = to_string(nm2);
  //convierte los dias a string
  string d1S = to_string(d1); string d2S = to_string(d2);
  //concatena mes y dias
  fechaI = stoi(concatenar(mS1,d1S)); fechaF = stoi(concatenar(mS2,d2S));
  pos1 = busquedaBinaria(lista,fechaI);
  pos2 = busquedaBinaria(lista,fechaF);
  printSeccion(lista, pos1, pos2);

  cout << "Quieres exportar el archivo?" << endl;
  cout << "Si = 1 | No = 0" << endl;
  cin >> opcion;
  if(opcion==1){
    exportarSeleccion(lista, pos1, pos2);
  }
}

int main(){
  //Preparar base de datos y ordenarla
  vector<datos> database;
  cargarBase(database);
  long tam = database.size();
  vector<datos> aux(tam);
  ordenaMerge(database, aux, 0, tam-1);

  //Imprimir lista completa
  printLista(database);

  int opcion;
  cout << "¿Quieres realizar una busqueda?" << endl;
  cout << "Si = 1 | No = 0" << endl;
  cin >> opcion;
  while(opcion!=0){
    intervalos(database);
    cout << endl;
    cout << "Quieres realizar otra busqueda?" << endl;
    cout << "Si = 1 | No = 0" << endl;
    cin >> opcion;
  }

  return 0;
}

