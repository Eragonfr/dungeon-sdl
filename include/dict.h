#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// <summary>
///  Struct which represents a dictionary item
/// </summary>
typedef struct dict_t_struct
{
    /// <summary>
    ///  Key
    /// </summary>
    char* key;

    /// <summary>
    ///  Value
    /// </summary>
    void* value;

    /// <summary>
    ///  Pointer to next element
    /// </summary>
    struct dict_t_struct* next;
} dict_t;

/// <summary>
///  Allocate memory in order to work with this dictionary
/// </summary>
/// <returns>Pointer to allocated memory</returns>
dict_t** dict_alloc(void);

/// <summary>
///  Add an item to the dictionary, if an item with the key already exists, replace it
/// </summary>
/// <param name="dict">Target dictionary</param>
/// <param name="key">Target key</param>
/// <param name="value">Value to set</param>
void dict_addItem(dict_t** dict, char* key, void* value);

/// <summary>
///  Get an item in a dictionary
/// </summary>
/// <param name="dict">Target dictionary</param>
/// <param name="key">Target key</param>
/// <returns>Pointer to item</returns>
void* dict_getItem(dict_t* dict, char* key);

/// <summary>
///  Remove an item from the dictionary, doesn't fails if key doesn't exists
/// </summary>
/// <param name="dict">Target dictionary</param>
/// <param name="key">Target key</param>
void dict_delItem(dict_t** dict, char* key);

/// <summary>
///  Get the size of a dictionary
/// </summary>
/// <param name="dict">Target dictionary</param>
/// <returns>Size of the dictionary</returns>
int dict_size(dict_t* dict);

/// <summary>
///  Free memory for a dictionary
/// </summary>
/// <param name="dict">Target dictionary</param>
void dict_free(dict_t** dict);