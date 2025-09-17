#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *second = NULL, *third = NULL;

    // Allocate 3 nodes in the heap
    head   = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third  = (struct Node*)malloc(sizeof(struct Node));

    // Assign data and link the nodes
    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;   // Last node points to NULL

    // ---- Traversal / Display ----
    printf("Linked List elements: ");
    struct Node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;   // move to next node
    }
    printf("\n");

    return 0;
}
