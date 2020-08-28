/*
** EPITECH PROJECT, 2020
** CSFML_Learning
** File description:
** event
*/

#ifndef EVENT_H_
#define EVENT_H_
#include <SFML/Graphics/RenderWindow.h>
#include "ressources.h"

void handle_event(sfRenderWindow *rwin, ressources_t *res, sfSound *sound);

#endif /* !EVENT_H_ */
