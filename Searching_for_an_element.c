#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to search for a key in the linked list
int search(struct Node *head, int key) {
    struct Node *temp = head;
    int position = 1;     // to track the node position (1-based)

    while (temp != NULL) {
        if (temp->data == key) {
            return position;   // element found at this position
        }
        temp = temp->next;
        position++;
    }
    return -1;  // element not found
}

int main() {
    struct Node *head = NULL, *second = NULL, *third = NULL;
    int key;

    // Allocate 3 nodes
    head   = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third  = (struct Node*)malloc(sizeof(struct Node));

    // Assign data and link nodes
    head->data = 10;  head->next = second;
    second->data = 25; second->next = third;
    third->data = 15;  third->next = NULL;

    // Display nodes
    printf("Linked List elements: ");
    struct Node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    // Input key to search
    printf("Enter element to search: ");
    scanf("%d", &key);

    // Search the element
    int pos = search(head, key);
    if (pos != -1)
        printf("Element %d found at position %d\n", key, pos);
    else
        printf("Element %d not found in the list\n", key);

    return 0;
}