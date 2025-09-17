#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to calculate sum of all node data
int sumOfNodes(struct Node *head) {
    int sum = 0;
    struct Node *temp = head;

    while (temp != NULL) {
        sum += temp->data;     // add current node’s data
        temp = temp->next;     // move to next node
    }
    return sum;
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

    // Display nodes
    printf("Linked List elements: ");
    struct Node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    // Find sum of all nodes
    int total = sumOfNodes(head);
    printf("Sum of all node data: %d\n", total);

    return 0;
}
