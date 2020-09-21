#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node_t;

void push(node_t** head, int data) {
    node_t* tmp = (node_t*)calloc(sizeof(node_t), 1);
    if(tmp == NULL) return;
    tmp->data = data;
    tmp->next = (*head);
    (*head) = tmp;
}

void pop(node_t** head) {
    if(*head == NULL) return;
    node_t* prev = NULL;
    prev = (*head);
    (*head) = (*head)->next;
    free(prev);
}

void print_list(node_t* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(void)
{
    node_t* head = NULL;
    int command, number;

    printf("Command list\n");
    printf("1 - add\n");
    printf("2 - delete\n");
    printf("3 - print\n");
    printf("4 - exit\n\n");

    while(1) {
        printf("Enter command\n");
        scanf("%d", &command);

        if(command == 1) {
            printf("Enter number to add\n");
            scanf("%d", &number);
            push(&head, number);
            printf("Done!\n\n");
        }
        else if(command == 2) {
            printf("Deleting...\n");
            pop(&head);
            printf("Done!\n\n");
        }
        else if(command == 3) {
            print_list(head);
            printf("Done!\n\n");
        }
        else if(command == 4) {
            printf("Shutdown!\n");
            break;
        }
        else printf("Wrong command!\n");
    }
    return 0;
}
