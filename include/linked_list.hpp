#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <initializer_list>

template<class T>
class LinkedList {
    public:
        LinkedList();
        LinkedList(std::initializer_list<T> il);
        void add(T x);
        T find(T x);
        void print();

    private:
        class LN {
            public:
                LN();
                LN(T x): value(x) {};

                T value;
                LN* next = nullptr;
        };
        LN* head = nullptr;
};

template<class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
}

template<class T>
LinkedList<T>::LinkedList(std::initializer_list<T> il) {
    for (auto i = il.begin(); i != il.end(); ++i) {
        this->add(*i);
    }
}

template<class T>
void LinkedList<T>::add(T x) {
    LN* node = head;
    if (node != nullptr) {
        for (;node->next != nullptr; node = node->next); //iterate until last node is found
        node->next = new LN(x);
    } else {
        head = new LN(x);
    }
}

template<class T>
T LinkedList<T>::find(T x) {
    std::cout << "FINDING " << x << std::endl;
    for (LN* node = head; node != nullptr; node = node->next)
        if (node->value == x)
            return node->value;
    return -1;
}

template<class T>
void LinkedList<T>::print() {
    for (LN* node = head; node != nullptr; node = node->next) {
        std::cout << node->value << std::endl;
    }
}

#endif
