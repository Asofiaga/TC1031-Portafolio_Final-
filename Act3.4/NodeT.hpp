//
//  BST.hpp
//  Act3.4
//
//  Created by sofía gtz on 23/10/20.
//

#ifndef NodeT_hpp
#define NodeT_hpp

class NodeT{
public:
    NodeT(long long key, string ip, long long longIp);
    NodeT(long long key,string ip, NodeT *left, NodeT *right);
    long long getKey();
    void setKey(long long key);
    long long getLongIp();
    void setLongIp(long long longIp);
    string getIp();
    void setIp(string ip);

    NodeT* getLeft();
    void setLeft(NodeT *left);
    NodeT* getRight();
    void setRight(NodeT *right);

private:
    long long key;
    long long longIp;
    string ip;
    NodeT *left;
    NodeT *right;

};

NodeT::NodeT(long long key, string ip, long long longIp){
    this->key=key;
    this->longIp=longIp;
    this->ip=ip;
    this->left=nullptr;
    this->right=nullptr;
}

NodeT::NodeT(long long key,string ip, NodeT *left, NodeT *right){
    this->key=key;
    longIp=0;
    this->ip=ip;
    this->left=left;
    this->right=right;
}

long long NodeT::getKey(){
    return key;
}

void NodeT::setKey(long long key){
    this->key=key;
}

long long NodeT::getLongIp(){
    return longIp;
}

void NodeT::setLongIp(long long longIp){
    this->longIp = longIp;
}

string NodeT::getIp(){
    return ip;
}

void NodeT::setIp(string ip){
    this->ip=ip;
}

NodeT* NodeT::getLeft(){
    return left;
}

void NodeT::setLeft(NodeT *left){
    this->left=left;
}

NodeT* NodeT::getRight(){
    return right;
}

void NodeT::setRight(NodeT *right){
    this->right=right;
}


#endif /* Node_hpp */
