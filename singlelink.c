#include <stdio.h>
#include <stdlib.h>
int data;
int loc;
int nodevalue;

typedef struct node{
    int data;
    struct node *next;
} list;


list *beginsert(list **head)
{
    list *newnode = (list *)malloc(sizeof(list));
    if(newnode==NULL){
        printf("\nMemory overflow\n");
    }
    else{
        printf("\nEnter the data to be inserted: ");
        scanf("%d", &data);
        newnode->data=data;
        newnode->next = *head;
        *head = newnode;
    }
    return *head;
}

void endinsert(list **head){
    list *newnode = (list *)malloc(sizeof(list));
    list *temp = *head;
    if(newnode==NULL){
        printf("\nMemory overflow\n");
    }
    else{
        printf("\nEnter the data to be inserted: ");
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void insertafternode(list **head){
    list *newnode = (list *)malloc(sizeof(list));
    list *temp = *head;

    if(newnode==NULL){
        printf("\nMemory overflow\n");
    }
    else{
        printf("\nEnter the nodevalue after which data is to be inserted: ");
        scanf("%d", &nodevalue);
        printf("\nEnter the data to be inserted: ");
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;
        while(temp->data!=nodevalue){
            temp = temp->next;
            if(temp==NULL){
                printf("\nValue not present\n");
                break;
            }
        }
        if(temp!=NULL){
            newnode->next = temp->next;
            temp->next = newnode;
        }

    }
}

void insertatloc(list **head){
    list *temp = *head;
    list *newnode = (list*)malloc(sizeof(list));
    if(newnode==NULL){
        printf("\nMemory overflow\n");
    }
    else{
        printf("Enter the data to be inserted: ");
        scanf("%d", &data);
        printf("Enter the location after which data is to be inserted: ");
        scanf("%d", &loc);
        newnode->data=data;
        newnode->next=NULL;
        int i = 1;
        while(temp!=NULL && i<loc){
            temp=temp->next;
            i++;
        }
        if(temp==NULL){
            printf("\nLocation not found\n");
        }
        else{
            newnode->next = temp->next;
        temp->next = newnode;
        }
        
    }
}
list *begdelete(list **head){
    list *temp = *head;
    if(*head==NULL){
        printf("\nList is empty\n");
    }
    else{
        *head = temp->next;
        int deleted = temp->data;
        printf("\nDeleted element: %d", temp->data);
        free(temp);
    }
    return *head;
}

list *endelete(list **head){
    list *prev,*temp = *head;
    if(*head == NULL) {
        printf("\nList is empty\n");
    }
    else{
        while(temp->next!=NULL){
            temp = temp->next;
        }
        while(prev->next!=temp){
            prev = prev->next;
        }
        prev->next = NULL;
        printf("Deleted element: %d", temp->data);
        free(temp);
    }
}

void deleteafternode(list **head){
    list *temp = *head;
    list *curr = *head;
    if(*head==NULL){
        printf("\nList is empty\n");
    }
    else{
        printf("Enter the nodevalue after which node is to be deleted: ");
        scanf("%d", &nodevalue);
        while(temp != NULL && temp->data != nodevalue){
            temp = temp->next;
        }
        if(temp == NULL){
            printf("\nNode not found\n");
        }
        else{
            while(curr != temp->next){
                curr = curr->next;
            }
            printf("Deleted element: %d", curr->data);
            temp->next = curr->next;
            free(curr);
        }
    }
}

void deleteatloc(list **head){
    list *temp = *head;
    list *curr = *head;
    if(*head==NULL){
        printf("\nList is empty\n");
    }
    else{
        int i = 1;
        printf("Enter the location after which node is to be deleted: ");
        scanf("%d", &loc);
        while(i<loc && temp!=NULL){
            temp = temp->next;
            i++;
        }
        if(temp==NULL){
            printf("\nLocation out of range\n");
        }
        else{
            while(curr!=temp->next){
            curr = curr->next;
        }
        printf("Deleted element at location %d : %d \n", loc, curr->data);
        temp->next = curr->next;
        free(curr);
        }
        
    }
}


list *createlist()
{
    list *head = NULL;
    list *temp = NULL;
    int choice = 1;
    while(choice == 1){
        list *newnode = (list *)malloc(sizeof(list));
        if(newnode==NULL){
            printf("\nMemory overflow\n");
        }
        else{
            printf("\nEnter the element to be inserted: ");
            scanf("%d", &newnode->data);
            newnode->next = NULL;
            if(head==NULL){
                head = temp = newnode;
            }
            else{
                temp->next=newnode;
                temp = newnode;
            }
        }
        printf("\nPress 1 to enter new node and 0 to exit: ");
        scanf("%d", &choice);
    }
  
    return head;
}

void printlist(list *head){
    if(head==NULL){
        printf("\nList is empty\n");
    }
    else{
        list *temp = head;
        while(temp!=NULL){
            printf(" %d ", temp->data);
            temp = temp->next;
        }
    }

}

int main(){
    list *head = createlist();
    int choice;
   
    while(choice!=10){
         printf("\n------SINGLE LINKED LIST MENU-----\n");
    printf("\n____Choose among____\n1. INSERT AT BEGINNING\n2. INSERT AT END\n3. INSERT AFTER NODE\n 4. INSERT AT A SPECIFIC LOCATION\n5. DISPLAY\n6. DELETE AT BEGINNING\n7. DELETE AT END\n8. DELETE AFTER NODE\n9. DELETE AT SPECIFIC LOCATION\n10. EXIT\n");
    scanf("%d", &choice);
         switch(choice){
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
            printf("\n----Exiting-----");
            break;
        default:
            printf("\nEnter values within the range given\n");
    }


    }
   
    return 0;
}
