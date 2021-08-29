// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 5000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int h = hash(word);

    for (node *n = table[h]; n != NULL; n = n->next)
    {
        if (!strcasecmp(n->word, word))
            return (true);
    }
    return (false);
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int h = 0;

    for (int i = 0; word[i]; i++)
    {
        if (isupper(word[i]))
        {
            h = h + tolower(word[i]);
        }
        else
        {
            h = h + word[i];
        }
    }
    return (h % N);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *input = fopen(dictionary, "r");
    if (input == NULL)
    {
        return false;
    }

    char word[46];
    while (fscanf(input, "%s", word) != EOF)
    {
        //creating memory for current word
        node *n = malloc(sizeof(node));
        if (n == NULL)
            return (false);

        //input values into node
        strcpy(n->word, word);
        n->next = NULL;

        //hashing each word and allocating their location in the hash table
        unsigned int h;
        h = hash(word);
        if (table[h] == NULL)
        {
            table[h] = n;
        }
        else
        {
            n->next = table[h];
            table[h] = n;
        }
    }

    fclose(input);
    //return true if loading of dictionary is successful
    return (true);
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    int size = 0;

    for (int i = 0; i < N; i++)
    {
        for (node *n = table[i]; n != NULL; n = n->next)
        {
            size++;
        }
    }
    return size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *n = NULL;

    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            n = table[i]->next;
            free(table[i]);
            table[i] = n;
        }
    }
    return true;
}
