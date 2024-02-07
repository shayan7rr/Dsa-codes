#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertEnd(Node* last, int data) {
    if (last == NULL) {
        last = createNode(data);
        last->next = last;
    } else {
        Node* newNode = createNode(data);
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    return last;
}

void displayList(Node* last) {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = last->next;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

int main() {
    Node* last = NULL;

    last = insertEnd(last, 1);
    last = insertEnd(last, 2);
    last = insertEnd(last, 3);

    printf("Circular Linked List: ");
    displayList(last);

    return 0;
}
