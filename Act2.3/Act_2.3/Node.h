#include "Datos.h"
struct Node{

    //Atributos
    Datos data;
    Node* next;
    Node* previous;

    //Metodos
    Node(Datos data);
    Node(Datos data, Node* next, Node* previous);

};

Node::Node(Datos data){
    this->data=data;
    next=nullptr;
    previous=nullptr;
}

Node::Node(Datos data, Node* next, Node* previous){
    this->data=data;
    this->next = next;
    this->previous = previous;
}
