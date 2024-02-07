#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} list;

list *createlist() {
    list *head = NULL, *temp = NULL;
    int choice = 1;
    while (choice == 1) {
        list *newnode = (list *)malloc(sizeof(list));
        if (newnode == NULL) {
            printf("\nOverFlow! Can't add the element.\n");
            exit(0);
        } else {
            printf("Enter the number: ");
            scanf("%d", &newnode->data);
            newnode->next = NULL;
            newnode->prev = NULL;
        }
        if (head == NULL) {
            head = temp = newnode;
            temp = newnode;
        } else {
            newnode->prev = temp;
            temp->next = newnode;
            temp = newnode;
        }
        printf("\nPress 1 to exit and 0 to continue: ");
        scanf("%d", &choice);
    }
    return head;
}

void printlist(list *head) {
    if (head == NULL) {
        printf("\nList is empty\n");
    } else {
        list *temp = head;
        while (temp != NULL) {
            printf(" %d ", temp->data);
            temp = temp->next;
        }
    }
}

list *beginsert(list **head) {
    list *newnode = (list *)malloc(sizeof(list));
    if (newnode == NULL) {
        printf("\nMemory overflow\n");
    } else {
        printf("\nEnter the data to be inserted: ");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newnode;
        }
        *head = newnode;
    }
    return *head;
}

void endinsert(list **head) {
    list *newnode = (list *)malloc(sizeof(list));
    if (newnode == NULL) {
        printf("\nMemory overflow\n");
    } else {
        printf("\nEnter the data to be inserted: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (*head == NULL) {
            newnode->prev = NULL;
            *head = newnode;
        } else {
            list *temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
        }
    }
}

void insertafternode(list **head) {
    list *newnode = (list *)malloc(sizeof(list));
    if (newnode == NULL) {
        printf("\nMemory overflow\n");
    } else {
        printf("\nEnter the nodevalue after which data is to be inserted: ");
        int nodevalue;
        scanf("%d", &nodevalue);
        printf("\nEnter the data to be inserted: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        list *temp = *head;
        while (temp != NULL && temp->data != nodevalue) {
            temp = temp->next;
        }
        if (temp != NULL) {
            newnode->next = temp->next;
            temp->next = newnode;
            newnode->prev = temp;
            if (newnode->next != NULL) {
                newnode->next->prev = newnode;
            }
        } else {
            printf("\nNode not found\n");
            free(newnode);
        }
    }
}

void insertatloc(list **head) {
    list *newnode = (list *)malloc(sizeof(list));
    if (newnode == NULL) {
        printf("\nMemory overflow\n");
    } else {
        printf("Enter the data to be inserted: ");
        scanf("%d", &newnode->data);
        printf("Enter the location after which data is to be inserted: ");
        int loc;
        scanf("%d", &loc);
        newnode->next = NULL;
        newnode->prev = NULL;
        list *temp = *head;
        int i = 1;
        while (i < loc && temp != NULL) {
            temp = temp->next;
            i++;
        }
        if (temp == NULL) {
            printf("\nLocation not found\n");
            free(newnode);
        } else {
            newnode->next = temp->next;
            temp->next = newnode;
            newnode->prev = temp;
            if (newnode->next != NULL) {
                newnode->next->prev = newnode;
            }
        }
    }
}

list *begdelete(list **head) {
    if (*head == NULL) {
        printf("\nList is empty\n");
        return NULL;
    } else {
        list *temp = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        printf("\nDeleted element: %d\n", temp->data);
        free(temp);
        return *head;
    }
}

list *endelete(list **head) {
    if (*head == NULL) {
        printf("\nList is empty\n");
        return NULL;
    } else {
        list *temp = *head;
        if (temp->next == NULL) {
            printf("\nDeleted element: %d\n", temp->data);
            free(temp);
            *head = NULL;
        } else {
            while (temp->next != NULL) {
                temp = temp->next;
            }
            printf("\nDeleted element: %d\n", temp->data);
            temp->prev->next = NULL;
            free(temp);
        }
        return *head;
    }
}

void deleteafternode(list **head) {
    if (*head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    printf("Enter the nodevalue after which node is to be deleted: ");
    int nodevalue;
    scanf("%d", &nodevalue);
    list *temp = *head;
    while (temp != NULL && temp->data != nodevalue) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\nNode not found\n");
        return;
    }
    if (temp->next == NULL) {
        printf("\nNo node to delete after\n");
        return;
    }
    list *temp2 = temp->next;
    temp->next = temp2->next;
    if (temp2->next != NULL) {
        temp2->next->prev = temp;
    }
    printf("\nDeleted element: %d\n", temp2->data);
    free(temp2);
}

void deleteatloc(list **head) {
    if (*head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    printf("Enter the location after which node is to be deleted: ");
    int loc;
    scanf("%d", &loc);
    list *temp = *head;
    int i = 1;
    while (i < loc && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("\nLocation not found\n");
        return;
    }
    list *temp2 = temp->next;
    temp->next = temp2->next;
    if (temp2->next != NULL) {
        temp2->next->prev = temp;
    }
    printf("\nDeleted element at location %d: %d\n", loc, temp2->data);
    free(temp2);
}

int main() {
    list *head = createlist();
    int choice;

    while (choice != 10) {
        printf("\n------DOUBLE LINKED LIST MENU-----\n");
        printf("\n____Choose among____\n1. INSERT AT BEGINNING\n2. INSERT AT END\n3. INSERT AFTER NODE\n4. INSERT AT A SPECIFIC LOCATION\n5. DISPLAY\n6. DELETE AT BEGINNING\n7. DELETE AT END\n8. DELETE AFTER NODE\n9. DELETE AT SPECIFIC LOCATION\n10. EXIT\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                head = beginsert(&head);
                break;
            case 2:
                endinsert(&head);
                break;
            case 3:
                insertafternode(&head);
                break;
            case 4:
                insertatloc(&head);
                break;
            case 5:
                printlist(head);
                break;
            case 6:
                head = begdelete(&head);
                break;
            case 7:
                endelete(&head);
                break;
            case 8:
                deleteafternode(&head);
                break;
            case 9:
                deleteatloc(&head);
                break;
            case 10:
                printf("\n----Exiting-----\n");
                break;
            default:
                printf("\nEnter values within the range given\n");
        }
    }

    return 0;
}
