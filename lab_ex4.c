#include <stdio.h>
#include <stdlib.h>

// structure for a mental health patient
typedef struct
{
    int patient_ID;
    char patient_Name[50];

} MentalHealthPatient;

// node structure for the linked list
typedef struct Node
{
    MentalHealthPatient data;
    struct Node *next;
} Node;

// Define a structure for the queue
typedef struct
{
    Node *front;
    Node *rear;
} Queue;

// Initialize an empty queue
void initializeQueue(Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

// Check if the queue is empty
int isEmpty(Queue *q)
{
    return (q->front == NULL);
}

// Function to enqueue a new patient
void enqueue(Queue *q, MentalHealthPatient newPatient)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation error!\n");
        return;
    }
    newNode->data = newPatient;
    newNode->next = NULL;

    if (isEmpty(q))
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Patient %s added to the queue.\n", newPatient.patient_Name);
}

// Function to dequeue a patient
void dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf(" Empty Queue , no patient to dequeue.\n");
        return;
    }
    Node *temp = q->front;
    printf("Dequeued Patient: ID - %d, Name - %s\n", temp->data.patient_ID, temp->data.patient_Name);
    q->front = q->front->next;
    free(temp);
}

// Function to display the menu
void displayMenu()
{
    printf("\n--- Mental Health Queue Operations ---\n");
    printf("1. Enqueue a Patient\n");
    printf("2. Dequeue a Patient\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

int main()
{
    Queue mentalHealthQueue;
    initializeQueue(&mentalHealthQueue);

    int choice;
    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            MentalHealthPatient newPatient;
            printf("Enter patient ID: ");
            scanf("%d", &newPatient.patient_ID);
            printf("Enter patient name: ");
            scanf("%s", newPatient.patient_Name);
            enqueue(&mentalHealthQueue, newPatient);
            break;
        }
        case 2:
            dequeue(&mentalHealthQueue);
            break;
        case 3:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}
