//
//  BST.hpp
//  Act3.4
//
//  Created by sofía gtz on 23/10/20.
//

#ifndef BST_hpp
#define BST_hpp

#include <iostream>
#include "NodeT.hpp"
class BST{
public:
    BST();
    ~BST();
    void add(long long key, string ip, long long longIp);
    //Metodos individuales para impresion de datos
    void printInOrden();
    void printTop5();

private:
    NodeT *root;
    void inOrden(NodeT *r);
    void destruye(NodeT *r);
    void cargarQueueIO(NodeT *r, queue<NodeT*> &fila);
};

BST::BST(){
    root=nullptr;
}

BST::~BST(){
    destruye(root);
}

//Complejidad O(n)
void BST::destruye(NodeT *r){
    if(r!=nullptr){
        destruye(r->getLeft());
        destruye(r->getRight());
        delete r;
    }
}

//Complejidad O(altura del arbol)
void BST::add(long long key, string ip, long long longIp){
    NodeT *curr = root;
    NodeT *father = nullptr;
    while(curr!=nullptr){
        if(curr->getLongIp()== longIp){
            return;
        }
        father = curr;
        curr = (curr->getKey()>key) ? curr->getLeft() : curr->getRight();
    }
    if(father==nullptr){
        root = new NodeT(key, ip, longIp);
    }
    else{
        //One liner poderoso
        (father->getKey() > key) ? father->setLeft(new NodeT(key, ip, longIp)) :
                                      father->setRight(new NodeT(key, ip, longIp));
    }
}

//Complejidad o(n)
//imprime los valores en inorden
void BST::inOrden(NodeT *r){
    queue<NodeT> fila;
    if(r!=nullptr){
        inOrden(r->getRight());
        cout << r->getIp() << " Freq: " << r->getKey() << endl;
        inOrden(r->getLeft());
    }
}

//Complejidad o(n)
//Ejecuta funcion de imprimir en in orden
void BST::printInOrden(){
    inOrden(root);
    cout<<endl;
}

//Complejidad o(n)
//Carga un Queue para imprimir el Top5 de datos repetidos
void BST::cargarQueueIO(NodeT *r, queue<NodeT*> &fila){
    if(r!=nullptr){
        cargarQueueIO(r->getRight(), fila);
        fila.push(r);
        cargarQueueIO(r->getLeft(), fila);
    }
}

//Complejidad O(n)
//Imprime los 5 datos mas repetidos del BST (Key mas grande)
void BST::printTop5(){
    queue<NodeT*> q;
    cargarQueueIO(root, q);
    for(int i=0;i<5;i++){
        cout << q.front()->getIp() << " Freq: " << q.front()->getKey() << endl;
        q.pop();
    }
}


#endif /* BST_hpp */
