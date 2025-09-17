#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to reverse the linked list
struct Node* reverse(struct Node *head) {
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = NULL;

    while (curr != NULL) {
        next = curr->next;    // 1️⃣ store next node
        curr->next = prev;    // 2️⃣ reverse the link
        prev = curr;          // 3️⃣ move prev one step forward
        curr = next;          // 4️⃣ move curr one step forward
    }
    return prev;  // prev is the new head
}

int main() {
    struct Node *head = NULL, *second = NULL, *third = NULL;

    // Allocate nodes
    head   = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third  = (struct Node*)malloc(sizeof(struct Node));

    // Link nodes and assign data
    head->data = 10;  head->next = second;
    second->data = 20; second->next = third;
    third->data = 30;  third->next = NULL;

    // Display original list
    printf("Original list: ");
    struct Node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    // Reverse the list
    head = reverse(head);

    // Display reversed list
    printf("Reversed list: ");
    ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    return 0;
}