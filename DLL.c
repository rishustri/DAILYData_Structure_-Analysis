#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// ─────────────────────────────────
// 1. CREATE NODE
// ─────────────────────────────────
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// ─────────────────────────────────
// 2. INSERT AT BEGINNING
// ─────────────────────────────────
struct Node* insertBegin(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    if(head != NULL)
        head->prev = newNode;
    return newNode;
}

// ─────────────────────────────────
// 3. INSERT AT END
// ─────────────────────────────────
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// ─────────────────────────────────
// 4. INSERT AT POSITION
// ─────────────────────────────────
void insertPos(struct Node** head, int data, int pos) {
    if(pos == 1) {
        *head = insertBegin(*head, data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    for(int i = 1; i < pos-1 && temp != NULL; i++)
        temp = temp->next;
    if(temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if(temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
}

// ─────────────────────────────────
// 5. DELETE AT BEGINNING
// ─────────────────────────────────
struct Node* deleteBegin(struct Node* head) {
    if(head == NULL) {
        printf("Empty list\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    if(head != NULL)
        head->prev = NULL;
    free(temp);
    return head;
}

// ─────────────────────────────────
// 6. DELETE AT END
// ─────────────────────────────────
void deleteEnd(struct Node** head) {
    if(*head == NULL) {
        printf("Empty list\n");
        return;
    }
    if((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
}

// ─────────────────────────────────
// 7. DELETE AT POSITION
// ─────────────────────────────────
void deletePos(struct Node** head, int pos) {
    if(*head == NULL) return;
    if(pos == 1) {
        *head = deleteBegin(*head);
        return;
    }
    struct Node* temp = *head;
    for(int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;
    if(temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    temp->prev->next = temp->next;
    if(temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
}

// ─────────────────────────────────
// 8. DELETE BY KEY
// ─────────────────────────────────
void deleteKey(struct Node** head, int key) {
    if(*head == NULL) return;
    struct Node* curr = *head;
    while(curr != NULL) {
        if(curr->data == key) {
            if(curr->prev != NULL)
                curr->prev->next = curr->next;
            else
                *head = curr->next;
            if(curr->next != NULL)
                curr->next->prev = curr->prev;
            free(curr);
            printf("Deleted %d\n", key);
            return;
        }
        curr = curr->next;
    }
    printf("Key not found\n");
}

// ─────────────────────────────────
// 9. SEARCH
// ─────────────────────────────────
void search(struct Node* head, int key) {
    struct Node* temp = head;
    int pos = 1;
    while(temp != NULL) {
        if(temp->data == key) {
            printf("Found %d at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Not found\n");
}

// ─────────────────────────────────
// 10. DISPLAY FORWARD
// ─────────────────────────────────
void displayForward(struct Node* head) {
    if(head == NULL) {
        printf("Empty list\n");
        return;
    }
    struct Node* temp = head;
    printf("Forward: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// ─────────────────────────────────
// 11. DISPLAY BACKWARD
// ─────────────────────────────────
void displayBackward(struct Node* head) {
    if(head == NULL) return;
    struct Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    printf("Backward: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// ─────────────────────────────────
// 12. COUNT NODES
// ─────────────────────────────────
int count(struct Node* head) {
    int cnt = 0;
    struct Node* temp = head;
    while(temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

// ─────────────────────────────────
// MAIN — Testing all operations
// ─────────────────────────────────
int main() {
    struct Node* head = NULL;

    // Insert
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    head = insertBegin(head, 5);
    insertPos(&head, 25, 4);

    displayForward(head);
    // Forward: 5 10 20 25 30 40

    displayBackward(head);
    // Backward: 40 30 25 20 10 5

    // Delete
    head = deleteBegin(head);
    displayForward(head);
    // Forward: 10 20 25 30 40

    deleteEnd(&head);
    displayForward(head);
    // Forward: 10 20 25 30

    deleteKey(&head, 25);
    displayForward(head);
    // Forward: 10 20 30

    deletePos(&head, 2);
    displayForward(head);
    // Forward: 10 30

    // Search
    search(head, 30);
    // Found 30 at position 2

    // Count
    printf("Total nodes: %d\n", count(head));
    // Total nodes: 2

    return 0;
}