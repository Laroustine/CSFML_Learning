/*
** LAROUS PROJECT, 2020
** CSFML_Good_Practice
** FiIe description:
** basic
*/

#ifndef BASIC_H_
#define BASIC_H_

typedef struct basic_s
{
    /* data */
}basic_t;

basic_t *init_entity_basic(void);
void destroy_entity_basic(basic_t *entity);
int update_entity_basic(basic_t *entity);

#endif /* !BASIC_H_ */
