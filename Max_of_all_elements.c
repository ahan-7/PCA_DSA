#include <stdio.h>
#include <stdlib.h>
#include <limits.h>   // for INT_MIN

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to find maximum element
int maxInList(struct Node *head) {
    int maxVal = INT_MIN;          // start with smallest possible int
    struct Node *temp = head;

    while (temp != NULL) {
        if (temp->data > maxVal) {  // update max if current data is bigger
            maxVal = temp->data;
        }
        temp = temp->next;          // move to next node
    }
    return maxVal;
}

int main() {
    struct Node *head = NULL, *second = NULL, *third = NULL;

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

    // Find maximum
    int maxVal = maxInList(head);
    printf("Maximum element in the list: %d\n", maxVal);

    return 0;
}
