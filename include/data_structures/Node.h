//
// Created by jakub on 09.03.2023.
//

#ifndef DATA_STRUCTURES_NODE_H
#define DATA_STRUCTURES_NODE_H
template<typename T>
class Node{
public:
    T value;
    Node<T> *next;
      explicit Node(T value){
        this->value=value;
        this->next = nullptr;
    }
};
#endif //DATA_STRUCTURES_NODE_H
