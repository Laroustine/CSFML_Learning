/*
** EPITECH PROJECT, 2020
** CSFML_Good_Practice
** File description:
** basic
*/

#include <stdlib.h>
#include "entity/basic.h"

// Constructor
basic_t *init_entity_basic(void)
{
    basic_t *entity = malloc(sizeof(basic_t));

    return (entity);
}

// Destructor
void destroy_entity_basic(basic_t *entity)
{
    free(entity);
}

//Update
int update_entity_basic(basic_t *entity)
{
    if (!entity)
        return (1);
    return (0);
}