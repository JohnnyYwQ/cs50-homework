#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct dllnode
{
    struct dllnode *prev;
    int value;
    struct dllnode *next;
}dllnode;

// insert a element in the double linked list
dllnode *insert_new_node(dllnode *head, int value)
{
    // insert at the begaining of the list
        // allocate memory for the new node
    dllnode *new = malloc(sizeof(dllnode));
        // check if we run out of our memory
    if (new == NULL)
    {
        return NULL;
    }
    new->value = value;
    new->prev = NULL;
        // insert
    new->next = head;
    if (head != NULL)
    {
        head->prev = new;
    }
    head = new;
    return head;
}


// delete a element in the double linked list
dllnode *delete(dllnode *head, int value)
{
    dllnode *curr = head;
    while(curr != NULL)
    {
        dllnode *next = curr->next;
        if (curr->value == value)
        {
            // check if head node
            if (curr->prev == NULL)
            {
                head = curr->next;
                if (head != NULL)
                {
                    head->prev == NULL
                }
            }
            // in the mid or at end
            else
            {
                curr->prev->next = curr->next;
                if (curr->next != NULL)
                {
                    curr->next->prev = curr->prev;
                }
            }
            free(curr);
        }
        curr = next;
    }
    return head;
}
