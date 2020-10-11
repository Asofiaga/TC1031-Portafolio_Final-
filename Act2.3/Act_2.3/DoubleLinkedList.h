#include "Node.h"
class DoubleLinkedList{
public:

    //Default Constructor and Destructor
    DoubleLinkedList();
    ~DoubleLinkedList();

    //Append a node to a list - Add Last in the og Linked List
    void appendNode(Datos data);

    //Delete all the nodes from memory
    void deleteAll();

    //Bubble sort for the nodes
    void bubbleSort();

    //Export data to a .txt file
    void exportData(DoubleLinkedList lista);

    //Select Data Ranges
    void selectPrint(long long inicio, long long fin);

    //Print in console the entire thing
    void printList(); 

private:
    Node* head;
    Node* tail;
    int size;
};

DoubleLinkedList::DoubleLinkedList(){
    head=nullptr;
    size=0;
}

DoubleLinkedList::~DoubleLinkedList(){
    deleteAll();
}

//Genera un nodo nuevo y lo agrega al final de la lista
//Complejidad Constante o(1)
void DoubleLinkedList::appendNode(Datos n){
    if(head==nullptr){
        head = new Node(n);
        tail = head;
        //cout<<"Node Appended as Head Node"<<endl;
        size++;
    }
    else{
        tail = new Node(n,nullptr,tail);
        tail->previous->next=tail;
        //cout << "Node Appended" << endl;
        size++;
    }
}

//Borra de memoria todos los nodos de la lista
//Complejidad lineal o(n)
void DoubleLinkedList::deleteAll(){
    Node *curr = head;
    while(head!=nullptr){
        head = head->next;
        delete curr;
        curr = head;
    }
}

//Ordena de manera ascendente las llaves de identidad de los nodos
//Complejidad cuadratica o(n^2)
void DoubleLinkedList::bubbleSort(){
    Node *curr=head, *other=nullptr;
    Datos temporal;
    while (curr != nullptr){
        other=curr->next;
        while (other!=nullptr){
            if (curr->data.generateKey() > other->data.generateKey()){
                temporal=curr->data;
                curr->data=other->data;
                other->data=temporal;
            }
            other= other->next;
        }
        curr=curr->next;
    }
}

//Exporta los datos de una seleccion de la lista original a un archivo externo
//Complejidad lineal o(n)
void DoubleLinkedList::exportData(DoubleLinkedList lista){
    ofstream ofs;
    string nombre;
    cout << "Ingresa el nombre de salida: " << endl;
    cin >> nombre;
    Node* temp = lista.head;
    ofs.open(nombre+".txt");
    while(temp!=nullptr){
        ofs << temp->data.getRegistroPrint() << endl;
        temp = temp->next;
    }
    ofs.close();
}

//Genera un intervalo de busqueda por el usuario, lo imprime en consola
//y pregunta si quiere exportar la seleccion a un archivo externo

//Complejidad lineal o(n)
void DoubleLinkedList::selectPrint(long long inicio, long long fin){
    DoubleLinkedList bufferExport;
    int opcion;
    if(head==nullptr){
        cout<<endl;
        cout<<"No nodes in double linked list"<< endl;
        cout<<endl;
    }
    else{
        cout<<endl<<"List data: "<<endl;
        Node* temp = head;
        while(temp!=nullptr){
            if(temp->data.generateKey()>=inicio && temp->data.generateKey()<=fin){
                bufferExport.appendNode(temp->data);
                cout << temp->data.getRegistroPrint() << endl;
            }
            temp = temp->next;
        }
        cout << endl;
        cout << "Quieres exportar la seleccion?" << endl;
        cout << "1- Si" << endl;
        cout << "2- No" << endl;
        cin >> opcion;
        if(opcion==1){
            exportData(bufferExport);
        }
    }
}

//Imprime en consola todos los registros de la lista
//Complejidad o(n)
void DoubleLinkedList::printList(){
    if(head==nullptr){
        cout<<endl;
        cout<<"No nodes in double linked list"<< endl;
        cout<<endl;
    }
    else{
        cout<<endl<<"List data: "<<endl;
        Node* temp = head;
        while(temp!=nullptr){
            cout << temp->data.getRegistroPrint() << endl;
            temp = temp->next;
        }
        cout << endl;
    }
}
