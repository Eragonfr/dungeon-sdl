#include "../headers/dict.h"

dict_t** dict_alloc(void) 
{
    return malloc(sizeof(dict_t));
}

void dict_free(dict_t** dict) 
{
    free(dict);
}

void* dict_getItem(dict_t* dict, char* key)
{
    dict_t* ptr;
    // iterate over each item until next is null
    for (ptr = dict; ptr != NULL; ptr = ptr->next) 
    {
        // return value from ptr if key correspond
        if (strcmp(ptr->key, key) == 0) 
        {
            return ptr->value;
        }
    }

    return NULL;
}

void dict_delItem(dict_t** dict, char* key)
{
    dict_t* ptr, * prev;
    // iterate over each item until next is null, and stors previous in prev
    for (ptr = *dict, prev = NULL; ptr != NULL; prev = ptr, ptr = ptr->next) 
    {
        // if key correspond
        if (strcmp(ptr->key, key) == 0) 
        {
            // if this isn't the last item
            if (ptr->next != NULL) 
            {
                // it's the first item
                if (prev == NULL) 
                {
                    // replace the item with the next one
                    *dict = ptr->next;
                }
                // it's not the first ietm
                else 
                {
                    // shift by one to the left
                    prev->next = ptr->next;
                }
            }
            // it's the last, item, but check if it's not the first one
            else if (prev != NULL)
            {
                // remove last item
                prev->next = NULL;
            }
            // it's the first item, and the last one at the same time
            else 
            {
                // empty dictionary
                *dict = NULL;
            }

            // free item data
            free(ptr->key);
            free(ptr);

            return;
        }
    }
}

void dict_addItem(dict_t** dict, char* key, void* value)
{
    // if we already have a item with this key, delete it
    dict_delItem(dict, key);

    // memory allocation
    dict_t* d = malloc(sizeof(struct dict_t_struct));
    if (d == NULL) { return; }

    // set key
    d->key = malloc(strlen(key) + 1);

    strcpy(d->key, key);

    // set value and next
    d->value = value;
    d->next = *dict;
    
    *dict = d;
}