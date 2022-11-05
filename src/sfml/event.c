/**
 * @ Author: Laroustine
 * @ Modified time: 05/11 16:00
 * @ Modified by: Laroustine
 * @ Description: This script has been made by me ↖(^▽^)↗
 */

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Event.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/Music.h>
#include <SFML/Graphics/Sprite.h>
#include "ressources.h"

static void music_event(sfEvent event, ressources_t *res, void *obj)
{
    (void) obj;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace) {
        if (sfMusic_getStatus(res->music[m_tuba_knight_boss]) == sfStopped)
            sfMusic_play(res->music[m_tuba_knight_boss]);
        else if (sfMusic_getStatus(res->music[m_tuba_knight_boss]) == sfPlaying)
            sfMusic_stop(res->music[m_tuba_knight_boss]);
    }
}

static void quit_event(sfEvent event, ressources_t *res, void *obj)
{
    (void) res;
    if (event.type == sfEvtClosed)
        sfRenderWindow_close((sfRenderWindow *)obj);
}

static void sound_play_event(sfEvent event, ressources_t *res, void *obj)
{
    (void) res;
    if (event.type == sfEvtMouseButtonPressed) {
        float distance = ((float)event.mouseMove.y - (1280.0 / 2)) * 8 / 1280;
        sfSound_setPosition((sfSound *)obj, (sfVector3f){0, distance, 0});
        sfSound_play((sfSound *)obj);
    }
}

static void keylogger_event(sfEvent event, ressources_t *res, void *obj)
{
    (void) res;
    if (event.type == sfEvtKeyPressed && event.key.code <= 25) {
        sfSprite_setTextureRect((sfSprite *)(obj), (sfIntRect){16 * (event.key.code + 1), 0, 16, 15});
        sfSprite_setRotation((sfSprite *)(obj), sfSprite_getRotation((sfSprite *)(obj)) + 5);
    }
}

void handle_event(sfRenderWindow *rwin, ressources_t *res, sfSound *sound, sfSprite *sprite)
{
    sfEvent event;
    void (*event_list[])(sfEvent e, ressources_t *res, void *item) = {&quit_event, &sound_play_event, &music_event, &keylogger_event};
    void *object_list[] = {rwin, sound, NULL, sprite};

    while (sfRenderWindow_pollEvent(rwin, &event)) {
        for (size_t i = 0; i < 4; i++) {
            event_list[i](event, res, object_list[i]);
        }
    }
}