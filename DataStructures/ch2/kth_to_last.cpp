#include "ctci_linked_list.h"

#include <iostream>

using std::cin; using std::cout; using std::endl;

int kth_to_last_recursive(Node* list, int k) {
    if (list == nullptr) {
        return 0;
    } else {
        int index = kth_to_last_recursive(list->next, k) + 1;

        if (index == k) {
            cout << list->data << endl;
        }

        return index;
    }
}

int main() {
    int list_length, k;
    cin >> list_length >> k;

    Node* list;
    for (int i = 0; i != list_length; ++i) {
        int temp;
        cin >> temp;

        if (i == 0) {
            list = new Node(temp);
        } else {
            list->appendToTail(temp);
        }
    }

    //cout << kth_to_last(list, k) << endl;

    //for (Node* n = list; n != nullptr; n = n->next) {
        //cout << n->data << " ";
    //}
    
    kth_to_last_recursive(list, k);
}
