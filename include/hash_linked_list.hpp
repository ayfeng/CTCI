#ifndef HASH_LINKED_LIST_HPP
#define HASH_LINKED_LIST_HPP
#include <initializer_list>

//same as linkedlist but with key member in LN
template<class K, class V>
class LinkedList {
    public:
        LinkedList();
        void add(K key, V value);
        V find(K key);
        void print();

    private:
        class LN {
            public:
                LN();
                LN(K key, V value): key(key), value(value) {};

                K key;
                V value;
                LN* next = nullptr;
        };
        LN* head = nullptr;
};

template<class K, class V>
LinkedList<K, V>::LinkedList() {
    head = nullptr;
}

template<class K, class V>
void LinkedList<K, V>::add(K key, V value) {
    LN* node = head;
    if (node != nullptr) {
        for (;node->next != nullptr; node = node->next); //iterate until last node is found
        node->next = new LN(key, value);
    } else {
        head = new LN(key, value);
    }
}

template<class K, class V>
V LinkedList<K, V>::find(K key) {
    std::cout << "FINDING " << key << std::endl;
    for (LN* node = head; node != nullptr; node = node->next)
        if (node->key == key)
            return node->value;
    return -1;
}

template<class K, class V>
void LinkedList<K, V>::print() {
    for (LN* node = head; node != nullptr; node = node->next) {
        std::cout << node->value << std::endl;
    }
}

#endif
