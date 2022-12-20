#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node *ptr)
{
    //hum ek head node naam ka pointer lenge jo head ko point krega 
    //(head will be passed in the argument from the main function at time of function call)

    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data); //ye initially pointer ke data ko print krega
        ptr = ptr -> next; //aur ye pointer ke data ko update krega next data m
    }
}


struct  Node * insertAtIndex(struct Node *head, int data, int index)
{
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    
    struct Node * p = head;
     int i = 0;
      while (i!= index - 1 )
      {
        p = p -> next ;
        i++;
      }
    ptr -> data = data;
    ptr -> next = p -> next;
    p -> next = ptr;
    return head;
}

int main()
{

    struct Node * head;   
    struct Node * second; 
    struct Node * third;   
    struct Node * fourth;   

    //Allocate memory for nodes in the linked list in Heap.
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    //Link first and second nodes
    head -> data = 11;
    head -> next = second;

    //Link second and third nodes
    second -> data = 8;  
    second -> next = third;

    //Link third and fourth nodes
    third -> data = 2;
    third -> next = fourth;

    //Terminate the list at fourth node
    fourth -> data = 3;
    fourth -> next = NULL;

    printf("Linked list before Insertion : \n");
    linkedListTraversal(head);

    printf("-------------------------------------------------------------------------------------------");
    printf("\n");

    printf("Linked list after Insertion : \n");
    head = insertAtIndex(head,55,2);
    linkedListTraversal(head);

    return 0;


}