#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to delete a node by key
struct Node* deleteNode(struct Node *head, int key) {
    struct Node *temp = head, *prev = NULL;

    // Case 1: head node itself holds the key
    if (temp != NULL && temp->data == key) {
        head = temp->next;   // move head to next node
        free(temp);          // free old head
        return head;
    }

    // Case 2: search for the key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key not found
    if (temp == NULL) {
        printf("Element %d not found in list.\n", key);
        return head;
    }

    // Unlink the node and free memory
    prev->next = temp->next;
    free(temp);

    return head;
}

int main() {
    struct Node *head = NULL, *second = NULL, *third = NULL;

    // Allocate 3 nodes
    head   = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third  = (struct Node*)malloc(sizeof(struct Node));

    // Assign data and link nodes
    head->data = 10;  head->next = second;
    second->data = 20; second->next = third;
    third->data = 30;  third->next = NULL;

    // Display original list
    printf("Original Linked List: ");
    struct Node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    // Delete a node
    int key;
    printf("Enter element to delete: ");
    scanf("%d", &key);

    head = deleteNode(head, key);

    // Display updated list
    printf("Updated Linked List: ");
    ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    return 0;
}