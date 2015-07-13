#ifndef HASH_MAP_HPP
#define HASH_MAP_HPP

#define NUM_BINS 10

#include "hash_linked_list.hpp"
#include <iostream>

template<class K, class V>
class HashMap {
    public:
        HashMap();
        void insert(K key, V value);
        V operator[](K key);
    private:
        int hash_index(K key);
        int hash_function(K key);
        LinkedList<K, V> *bins[NUM_BINS];
};

template<class K, class V>
HashMap<K, V>::HashMap() {
    for (int i = 0; i != NUM_BINS; ++i) {
        bins[i] = new LinkedList<K, V>();
    }
}

template<class K, class V>
void HashMap<K, V>::insert(K key, V value) {
    int index = hash_index(key);
    bins[index]->add(key, value);
}

template<class K, class V>
V HashMap<K, V>::operator[](K key) {
    int index = hash_index(key);
    return bins[index]->find(key);
}

template<class K, class V>
int HashMap<K, V>::hash_index(K key) {
    return hash_function(key)%NUM_BINS;
}

template<class K, class V>
int HashMap<K, V>::hash_function(K key) {
    return key*256;
}

#endif
