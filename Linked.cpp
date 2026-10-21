#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node first{10, nullptr};
    Node second{20, nullptr};
    Node third{30, nullptr};

    first.next = &second;
    second.next = &third;

    Node* current = &first;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}