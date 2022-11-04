/**
 * @ Author: Laroustine
 * @ Modified time: 05/11 00:23
 * @ Modified by: Laroustine
 * @ Description: This script has been made by me ↖(^▽^)↗
 */

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Event.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/Music.h>
#include "ressources.h"

static void music_event(sfEvent event, void *obj)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace) {
        if (sfMusic_getStatus((sfMusic *)obj) == sfStopped)
            sfMusic_play((sfMusic *)obj);
        else if (sfMusic_getStatus((sfMusic *)obj) == sfPlaying)
            sfMusic_stop((sfMusic *)obj);
    }
}

static void quit_event(sfEvent event, void *obj)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close((sfRenderWindow *)obj);
}

static void sound_play_event(sfEvent event, void *obj)
{
    if (event.type == sfEvtMouseButtonPressed) {
        float distance = ((float)event.mouseMove.y - (1280.0 / 2)) * 8 / 1280;
        sfSound_setPosition((sfSound *)obj, (sfVector3f){0, distance, 0});
        sfSound_play((sfSound *)obj);
    }
}

void handle_event(sfRenderWindow *rwin, ressources_t *res, sfSound *sound)
{
    sfEvent event;
    void (*event_list[3])(sfEvent e, void *item) = {&quit_event, &sound_play_event, &music_event};
    void *object_list[3] = {rwin, sound, res->music[m_tuba_knight_boss]};

    while (sfRenderWindow_pollEvent(rwin, &event)) {
        for (size_t i = 0; i < 3; i++) {
            event_list[i](event, object_list[i]);
        }
    }
}