#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert node at the end
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Count occurrences and delete all
int deleteOccurrences(struct Node** head, int key) {
    int count = 0;

    // Remove occurrences from the beginning
    while (*head != NULL && (*head)->data == key) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        count++;
    }

    // Remove occurrences from the rest of the list
    struct Node* current = *head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == key) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
            count++;
        } else {
            current = current->next;
        }
    }

    return count;
}
 
// Display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Empty List\n");
        return;
    }
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf("->");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int arr[] = {1,2,1,2,1,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Create the linked list
    for (int i = 0; i < n; i++) {
        insertAtEnd(&head, arr[i]);
    }

    int key = 1;
    printf("Original Linked List: ");
    displayList(head);

    int count = deleteOccurrences(&head, key);

    printf("Count: %d\n", count);
    printf("Updated Linked List: ");
    displayList(head);

    return 0;
}
