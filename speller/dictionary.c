// Implements a dictionary's functionality

#include <stdio.h>      // FILE, fopen, fscanf, etc.
#include <stdlib.h>     // malloc, free
#include <string.h>     // strcpy, strcasecmp
#include <strings.h>
#include <ctype.h>      // toupper, strcasecmp
#include <stdbool.h>    // bool, true, false
#include "dictionary.h" // 包含 LENGTH 和函数声明

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
#define N 26


// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    node *ptr = table[hash(word)];
    while(ptr != NULL)
    {
        if (strcasecmp(ptr->word, word) == 0)
        {
            return true;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // open file 
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    // read data
    char word[LENGTH + 1];
    while(fscanf(file, "%s", word) != EOF)
    {
        // find hash bucket
        node *ptr = malloc(sizeof(node));
        if (ptr == NULL)
        {
            fclose(file);
            return false;
        }
        // insert dictionary
        else
        {
            strcpy(ptr->word, word);
            ptr->next = table[hash(word)];
            table[hash(word)] = ptr;
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    unsigned int size = 0;
    for (int i = 0; i < N; i++)
    {
        node *ptr = table[i];
        while (ptr != NULL)
        {
            size++;
            ptr = ptr->next;
        }
    }
    return size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *temp = table[i];
            table[i] = table[i]->next;
            free(temp);
        }
    }
    return true;
}
