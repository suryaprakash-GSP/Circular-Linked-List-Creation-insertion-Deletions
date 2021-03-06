#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next
    } * last;
void create(struct node *);
void display(struct node *);
struct node *insertAtBeginning(struct node *);
struct node *insertAtPosition(struct node *);
struct node *insertAtEnd(struct node *);
struct node *deleteFirstNode(struct node *);
struct node *deleteAtPosition(struct node *);
struct node *deleteLastNode(struct node *);
int nodeCount(struct node *);

int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    int option;
    printf("Enter 1 to Create a Circular Linked List\n");
    printf("Enter 2 to display the Circular Linked List\n");
    printf("Enter 3 to Insert a node at beginning\n");
    printf ("Enter 4 to Insert a node at a given position\n");
    printf("Enter 5 to Innsert a node at End\n");
    printf("Enter 6 to Delete First Node\n");
    printf("Enter 7 to Delete a node at given position\n");
    printf("Enter 8 to Delete Last Node\n");
    printf("Enter 9 to get the count of nodes\n");
    printf("Enter 10 to exit\n");
    do {
        printf("\nEnter your choice: ");
        scanf("%d",&option);

        switch(option) {
        case 1:
            create(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            head=insertAtBeginning(head);
            break;
        case 4:
            head=insertAtPosition(head);
            break;
        case 5:
            head=insertAtEnd(head);
            break;
        case 6:
            head=deleteFirstNode(head);
                break;
        case 7:
            head=deleteAtPosition(head);
            break;
        case 8:
            head=deleteLastNode(head);
            break;
        case 9:
            printf("The count is %d: ",nodeCount(head));
            printf("\n");
            break;
        


        }
    }while(option!=10);
    return 0;
}
//create
void create(struct node *head)
{
    struct node *newnode, *temp;
    int n, data;
    printf("Enter no of Nodes you want to create: ");
    scanf("%d", &n);

    if (head == NULL)
    {
        printf("Memory not Allocated\n");
    }
    else
    {

        printf("Enter the data of Node 1: ");
        scanf("%d", &data);
        head->data = data;
        head->next = head;
        temp = head;
        for (int i = 2; i <= n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter the of data Node %d: ", i);
            scanf("%d", &data);
            newnode->data = data;
            newnode->next = head;
            temp->next = newnode;
            temp = temp->next;
        }
        last = temp;
    }
}
//display
void display(struct node *head)
{
    struct node *temp = head;
    printf("The Linkest List data is:\n");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}
//insert beginning
struct node *insertAtBeginning(struct node *head)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    int data;
    printf("Enter the data of the node u want to insert: ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = head;
    last->next = newnode;
    return newnode;
}
struct node *insertAtPosition(struct node *head)
{
    int pos, data, i = 1;
    printf("Enter the position at which u want to insert: ");
    scanf("%d", &pos);
    struct node *newnode, *temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data to insert at given position: ");
    scanf("%d", &data);
    while (i != pos - 1)
    {
        temp = temp->next;
        i++;
    }
    newnode->data = data;
    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}
struct node *insertAtEnd(struct node *head)
{
    struct node *temp = head, *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data to insert at end: ");
    int data;
    scanf("%d", &data);
    newnode->data = data;
    last->next = newnode;
    newnode->next = head;
    last = newnode;
    return head;
}
struct node *deleteFirstNode(struct node *head)
{
    struct node *temp = head;
    head = head->next;
    last->next = head;
    free(temp);
    return head;
}
struct node *deleteAtPosition(struct node *head)
{
    int pos, i = 1;
    struct node *temp = head;
    printf("Enter the position at which u want to delete: ");
    scanf("%d", &pos);
    while (i != pos - 1)
    {
        temp = temp->next;
        i++;
    }
    struct node *ptr = temp->next;
    temp->next = ptr->next;
    free(ptr);
    return head;
}
struct node *deleteLastNode(struct node *head)
{
    struct node *temp = head;
    while (temp->next != last)
    {
        temp = temp->next;
    }
    struct node *ptr = last;
    temp->next = head;
    last = temp;
    free(ptr);
    return head;
}
int nodeCount(struct node* head) {
    int i=0;
    struct node *temp=head;
    do
    {
        i++;
        temp=temp->next;
    } while (temp!=head);

    return i;
}
