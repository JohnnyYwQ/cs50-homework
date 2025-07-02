#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct sllnode
{
    int value;
    struct sllnode *next;
}sllnode;


// create a link list if not exist
sllnode *create_linked_list()
{
    // dynamically allocate space for new sllnode
    sllnode *new = malloc(sizeof(sllnode));
    // check to make sure we didn't run out of memory
    if (new == NULL)
    {
        return NULL;
    }
    // initailize node's value field
    new->value = 0;
    // initialize node's next field
    new->next = NULL;
    // return a pointer to the newly created node
    return new;
}
// search through a link list to find an element
bool find(sllnode *head, int value)
{
    // create a traversal pointer pointing to the list's head
    sllnode *node = head;
    // if the current node value field is what we are looking for, report success
    // if not set the traversal point to the next point in the list then go back to step b
    while (node != NULL)
    {
        if (node->value == value)
        {
            return true;
        }
        node = node->next;
    }
    // if you reach the end of list, report failure.
    return false;
}

// insert a new node in a link list at the begining of our link list

sllnode *insert_new_node(sllnode *head, int value)
{
    // allocate space for a new node
    sllnode *new = malloc(sizeof(sllnode));
    // check if we have run out of our memory
    if (new == NULL)
    {
        return NULL;
    }
    // connect new node with old node
    new->value = value;
    new->next = head;
    head = new;
    return head;
}

// delete an element in the link list
sllnode *delete_element(sllnode *head, int value)
{
    // if element in at head
    while (head != NULL && head->value == value)
    {
        sllnode *temp = head;
        head = head->next;
        free(temp);
    }
    // delete element in the link list
    // iterate link list
    sllnode *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->next->value == value)
        {
            sllnode *temp = curr;
            curr->next = curr->next->next;
            free(temp->next);
        }
        else
        {
            curr = curr->next;
        }
    }
}

// delete entire link list
void delete_linked_list(sllnode *head)
{
    // base case
    if (head == NULL)
    {
        return;
    } 
    // recursion
        // free current node then point to next node
        // create a pointer pointing to the head pointing to
    sllnode *temp = head;
        // upgrade head to head point next
    head = head->next;
        // free pointer point to the old head point to
    free(temp); 
    delete_linked_list(head);
}