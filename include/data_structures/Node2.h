#ifndef DATA_STRUCTURES_NODE2_H
#define DATA_STRUCTURES_NODE2_H
template<typename T>
class Node2{
public:
    T value;
    Node2<T> *next;
    Node2<T> *previous;

    explicit Node2(T value){
        this->value=value;
        this->next = nullptr;
        this->previous = nullptr;
    }
};
#endif //DATA_STRUCTURES_NODE2_H
