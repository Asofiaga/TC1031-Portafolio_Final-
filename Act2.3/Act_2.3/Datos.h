class Datos{
public:
    Datos();
    Datos(string m, string d, string hr, string dirIp, string msj);
    long long generateKey();
    void setKey(long long key);
    string getRegistroPrint();
    string concatenarKey(int, int, int, int, int);

private:
    long long key;
    string mes;
    string dia;
    string horario;
    string ip;
    string msg;
};

//constructor sin parametros
Datos::Datos(){
    key = 1;
    mes = "Jun";
    dia = "1";
    horario = "00:00:00";
    ip = "000.00.000.000:0000";
    msg = "error";
}

//constructor con parametros
Datos::Datos(string m, string d, string hr, string dirIp, string msj){
    mes = m;
    dia = d;
    horario = hr;
    ip = dirIp;
    msg = msj;
    key = generateKey();
}

//Genera un string con el formato de la llave
//Complejidad Constante o(1)
string Datos::concatenarKey(int kI1, int kI2, int kI3, int kI4, int kI5){
    string k1 = to_string(kI1);
    string k2 = to_string(kI2);
    string k3 = to_string(kI3);
    string k4 = to_string(kI4);
    string k5 = to_string(kI5);

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
    string llave = k1 + k2 + k3 + k4 + k5;
    return llave;
}

//Genera un long long con la key unica del registro
//Complejidad constante O(1)
long long Datos::generateKey(){
    string key = ip;
    int keyI1,keyI2,keyI3,keyI4,keyI5;
    string keyS, keySCor;
    long long keyL;
    char point, points;

    stringstream stream(stringstream::in | stringstream::out);
    stream << key;

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
    keyS = concatenarKey(keyI1,keyI2,keyI3,keyI4,keyI5);

    //convierte el string key en long
    keyL = stoll(keyS);
    return keyL;
}

//Set Key
//Complejidad constante o(1)
void Datos::setKey(long long key){
    this->key=key;
}

//Genera un String con los datos del registro
//Complejidad constante o(1)
string Datos::getRegistroPrint(){
    string registro = mes + " " + dia + " " + horario + " " + ip + " " + msg;
    return registro;
}
