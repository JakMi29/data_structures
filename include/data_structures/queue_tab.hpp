#ifndef QUEUE_HPP_
#define QUEUE_HPP_

// TODO: zaimplementuj klasę QueueTab - kolejka z implementacją tablicową cykliczną
template<typename T>
class QueueTab {
private:
    int f{};
    int currentSize{};
    int capacity{};
    int r{};
    int *tab{};
public:
    QueueTab();

    explicit QueueTab(std::size_t initialCapacity);

    void enqueue(const T &newElement);

    T dequeue();

    bool empty();

    std::size_t size();

    const T &front();

    void print();

    ~QueueTab();

    void addPlace();
};

template<typename T>
void QueueTab<T>::addPlace() {

    T *t = new T[this->capacity *2];
    int pom=this->f;
    for(int i =0;i<this->currentSize;i++)
    {
        t[i]= this->tab[pom%this->capacity];
        pom++;
        this->r =i;
    }
    this->capacity = this->capacity *2;
    this->f = 0;

    delete[]this->tab;
    this->tab = t;
}

template<typename T>
void QueueTab<T>::print() {
    if (this->currentSize == 0) {
        std::cout << "queue is empty" << std::endl;
        return;
    }
    int pom=this->f;
   for(int i =0;i<this->currentSize;i++)
   {
       std::cout<< this->tab[pom%this->capacity]<<" ";
       pom++;
   }
    std::cout << std::endl;

}

template<typename T>
QueueTab<T>::QueueTab() {
    this->capacity = 5;
    this->f = 0;
    this->currentSize = 0;
    this->r = this->capacity - 1;
    this->tab = new T[capacity];
}

template<typename T>
QueueTab<T>::~QueueTab() {
    delete[] this->tab;
}

template<typename T>
QueueTab<T>::QueueTab(std::size_t initialCapacity) {
    this->capacity = initialCapacity;
    this->f = 0;
    this->currentSize = 0;
    this->r = this->capacity - 1;
    this->tab = new T[initialCapacity];
}

template<typename T>
void QueueTab<T>::enqueue(const T &newElement) {
    if (this->currentSize == this->capacity)
        this->addPlace();
    this->r = (this->r + 1) % this->capacity;
    this->tab[this->r] = newElement;
    this->currentSize = this->currentSize + 1;
}

template<typename T>
T QueueTab<T>::dequeue() {
    if (this->empty()) {
        std::cout << "queue is empty" << std::endl;
        return T();
    }
    T item = (this->tab[this->f]);
    this->f = (this->f + 1) % this->capacity;
    this->currentSize = this->currentSize - 1;
    return item;
}

template<typename T>
bool QueueTab<T>::empty() {
    return (this->currentSize == 0);
}

template<typename T>
std::size_t QueueTab<T>::size() {
    return this->currentSize;
}

template<typename T>
const T &QueueTab<T>::front() {
    static T t;

    if (this->empty()) {
        std::cout << "queue is empty" << std::endl;
        return t;
    }
    t = this->tab[this->f];
    return t;
}

#endif /* QUEUE_HPP_ */
