#include <stdio.h>

#define SIZE 10
int arr[SIZE];
int n = 0;

void insert(int pos, int value) {
    if (n >= SIZE) {
        printf("List full!\n");
        return;
    }
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos] = value;
    n++;
}

void delete(int pos) {
    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos; i < n-1; i++) {
        arr[i] = arr[i+1];
    }
    n--;
}

void search(int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            printf("Found %d at position %d\n", value, i);
            return;
        }
    }
    printf("Not Found\n");
}

void traverse() {
    printf("List: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    insert(0, 10);
    insert(1, 20);
    insert(2, 30);
    traverse();
    search(20);
    delete(1);
    traverse();
    return 0;
}