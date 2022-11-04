/**
 * @ Author: Laroustine
 * @ Modified time: 05/11 00:25
 * @ Modified by: Laroustine
 * @ Description: This script has been made by me ↖(^▽^)↗
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