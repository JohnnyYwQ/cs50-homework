#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    // old list
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }
    
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // mid list
    int *tmp = realloc(list, 4 * sizeof(int));
    if (tmp == NULL)
    {
        return 2;
    }
    
    tmp[3] = 4;

    // enlarge array
    list = tmp;
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    free(list);
}
