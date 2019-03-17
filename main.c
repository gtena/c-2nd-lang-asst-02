#include <stdio.h>
#include <stdlib.h>

struct LinkedList{
    int data;
    struct LinkedList *next;
};

struct LinkedList* head = NULL;
//struct LinkedList* current = NULL;
struct LinkedList* tail = NULL;
//struct LinkedList* tempNext = NULL;

void list_insert(int data) {

    //allocate new node, initialize to head
    if (head == NULL) {

        head = (struct LinkedList *) malloc(sizeof(struct LinkedList));
        head->next = 0;
        head->data = data;
        tail = head;
    }

        //append node to end of list if larger than tail
    else {
        if (data >= tail->data) {
            tail->next = (struct LinkedList *) malloc(sizeof(struct LinkedList));
            tail = tail->next;
            tail->data = data;
            tail->next = NULL;
        }
            //add to front of list if data less than head
        else if(data < head->data) {
            struct LinkedList *temp = head;
            head = (struct LinkedList*) malloc(sizeof(struct LinkedList));
            head->data = data;
            head->next = temp;
        }
    }

}

struct LinkedList *del (struct LinkedList *current, int data) {
    //check if we are at the end of the list
    if (current == NULL) {
        return NULL;
    }
    //check if current is the one to be deleted
    if (current->data == data){
        struct LinkedList *tempNext; //create temp
        tempNext = current->next;    //store next pointer to temp
        free(current);               //deallocate current
        return tempNext;             //return new pointer
    }
    //check rest of the recursively
    current->next = del(current->next, data);
    //return the pointer where it was called from
    return current;
}



/*void del (struct LinkedList *before_del)
{
    struct LinkedList *temp;
    temp = before_del->next;
    before_del->next = temp->next;
    free(temp);
}
*/
void printList(struct LinkedList *head)
{
    while (head != NULL)
    {
        printf(" %d ", head->data);
        head = head->next;
    }
}

void run_linked_list() {

    printf("Running linked list\n");
    //list_insert(1);
    list_insert(4);
    list_insert(5);
    list_insert(8);
    list_insert(9);
    list_insert(10);
    list_insert(12);
    list_insert(1);
    printList(head);
    del(head,9);
    printf("\n");
    printList(head);
    del(head,4);
    printf("\n");
    printList(head);
}


int main() {
    run_linked_list();

    return 0;
}