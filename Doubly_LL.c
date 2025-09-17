#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *second = NULL, *third = NULL;

    // Allocate nodes
    head   = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third  = (struct Node*)malloc(sizeof(struct Node));

    // Assign data
    head->data = 10;
    second->data = 20;
    third->data = 30;

    // Link nodes (forward and backward)
    head->prev = NULL;
    head->next = second;

    second->prev = head;
    second->next = third;

    third->prev = second;
    third->next = NULL;   // last node

    // Display in forward direction
    printf("Doubly Linked List (Forward): ");
    struct Node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    // Display in backward direction
    printf("Doubly Linked List (Backward): ");
    ptr = third;   // start from last node
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");

    return 0;
}