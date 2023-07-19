#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("%d inserted at the beginning of the list.\n", data);
}
void insertAfter(struct Node *prevNode, int data)
{
    if (prevNode == NULL)
    {
        printf("The previous node cannot be NULL!\n");
        return;
    }
    struct Node *newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    printf("%d inserted after the given node.\n", data);
}
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        printf("%d inserted at the end of the list.\n", data);
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("%d inserted at the end of the list.\n", data);
}
void deleteNode(struct Node **head, int key)
{
    struct Node *temp = *head;
    struct Node *prev = NULL;

    if (temp != NULL && temp->data == key)
    {
        *head = temp->next;
        free(temp);
        printf("Node with key %d deleted.\n", key);
        return;
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node not found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node with key %d deleted.\n", key);
}
void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty!\n");
        return;
    }
    struct Node *temp = head;
    printf("Linked list elements:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    struct Node *head = NULL;
    int choice, data, key;

    while (1)
    {
        printf("\nSingle Linked List Operations:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert after a given node\n");
        printf("3. Insert at the end\n");
        printf("4. Delete a node\n");
        printf("5. Display the linked list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to insert at the beginning: ");
            scanf("%d", &data);
            insertAtBeginning(&head, data);
            break;
        case 2:
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            printf("Enter the key after which to insert: ");
            scanf("%d", &key);
            insertAfter(head, data);
            break;
        case 3:
            printf("Enter the data to insert at the end: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;
        case 4:
            printf("Enter the key of the node to delete: ");
            scanf("%d", &key);
            deleteNode(&head, key);
            break;
        case 5:
            display(head);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice! Please enter a valid option.\n");
            break;
        }
    }

    return 0;
}
