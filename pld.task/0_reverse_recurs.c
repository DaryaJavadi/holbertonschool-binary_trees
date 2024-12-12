#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

void printReverseRecursive(struct ListNode* head);
void printReverseNonRecursive(struct ListNode* head);
void freeList(struct ListNode* head);

void printReverseRecursive(struct ListNode* head)
{
    if (head == NULL) 
    {
        return;
    }

    printReverseRecursive(head->next);
    printf("%d ", head->val);
}

struct ListNode* createNode(int val)
{
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}


void printReverseNonRecursive(struct ListNode* head)
{
    int stack[100];
    int top = -1;

    while (head != NULL) {
        stack[++top] = head->val;
        head = head->next;
    }

    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
}


void freeList(struct ListNode* head)
{
    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}


int main()
{

    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    printf("Reverse (Recursive): ");
    printReverseRecursive(head);
    printf("\n");

    printf("Reverse (Non-Recursive): ");
    printReverseNonRecursive(head);
    printf("\n");
    freeList(head);
    return 0;

