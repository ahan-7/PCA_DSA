#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
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

    // Link nodes in circular fashion
    head->next = second;
    second->next = third;
    third->next = head;     // points back to head to make it circular

    // Display the circular list
    printf("Circular Linked List elements: ");
    struct Node *ptr = head;
    if (head != NULL) {
        do {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        } while (ptr != head);   // stop when we come back to head
    }
    printf("\n");

    return 0;
}