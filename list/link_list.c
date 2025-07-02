#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(void)
{
    node *list = NULL;
    for (int i = 0; i < 4; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        // sorted list
        n->number = get_int("Number: ");
        n->next = NULL;
        // initial condition
        if (list == NULL)
        {
            list = n;
        }
        // at begin
        else if (n->number < list->number)
        {
            n->next = list;
            list = n;
        }
        else
        {
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // at last
                if (ptr->next == NULL)
                {
                    ptr->next = n;
                    break;
                }
                // at middle
                if (n->number < ptr->next->number)
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    break;   
                }
            }


        }
    }

    // for loop
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr -> number);
    }

    while (list != NULL)
    {
        node *tmp = list;
        list = list->next;
        free(tmp);
    }
    
    return 0;
}