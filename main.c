#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node *createnode(int value) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->next = NULL;

    return newnode;
}

void insertatstarting(int value) {
    struct node *newnode = createnode(value);

    newnode->next = head;
    head = newnode;

    printf("Inserted at starting: %d\n", value);
}

void insertatend(int value) {
    struct node *newnode = createnode(value);

    if (head == NULL) {
        head = newnode;
    } 
    else {
        struct node *temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    printf("Inserted at end: %d\n", value);
}

void deletefromstart() {
    if (head == NULL) {
        printf("List is empty.\n");
    } 
    else {
        struct node *temp = head;

        head = head->next;

        printf("Deleted from beginning: %d\n", temp->data);

        free(temp);
    }
}

void deletefromend() {
    if (head == NULL) {
        printf("List is empty.\n");
    } 
    else if (head->next == NULL) {
        printf("Deleted from end: %d\n", head->data);

        free(head);
        head = NULL;
    } 
    else {
        struct node *temp = head;

        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        printf("Deleted from end: %d\n", temp->next->data);

        free(temp->next);
        temp->next = NULL;
    }
}

void displaylist() {
    struct node *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
    } 
    else {
        printf("Linked list: ");

        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main() {
    int choice, value;

    while (1) {

        printf("\n1. Insert at beginning");
        printf("\n2. Insert at end");
        printf("\n3. Delete at beginning");
        printf("\n4. Delete from end");
        printf("\n5. Display");
        printf("\n6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);

                insertatstarting(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);

                insertatend(value);
                break;

            case 3:
                deletefromstart();
                break;

            case 4:
                deletefromend();
                break;

            case 5:
                displaylist();
                break;

            case 6:
                exit(0);

            default:
                printf("Check input again!\n");
        }
    }

    return 0;
}
