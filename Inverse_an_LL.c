#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to reverse the linked list
struct Node* reverseList(struct Node *head) {
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = NULL;

    while (curr != NULL) {
        next = curr->next;    // store next node
        curr->next = prev;    // reverse the link
        prev = curr;          // move prev one step ahead
        curr = next;          // move curr one step ahead
    }
    return prev;  // prev becomes the new head
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

    // Reverse the list
    head = reverseList(head);

    // Display reversed list
    printf("Reversed Linked List: ");
    ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    return 0;
}