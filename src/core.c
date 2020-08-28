/*
** LAROUS PROJECT, 2020
** CSFML_Good_Practice
** FiIe description:
** core
*/

#include <SFML/Window/VideoMode.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Audio/Sound.h>
#include "ressources.h"

sfSprite *setup_sprite(ressources_t *res)
{
    sfSprite *sp = sfSprite_create();

    if (sp && res) {
        sfSprite_setTexture(sp, res->texture[t_mech], sfTrue);
        sfSprite_setPosition(sp, (sfVector2f){20, 20});
    }
    return (sp);
}

sfSound *setup_sound(ressources_t *res)
{
    sfSound *sp = sfSound_create();

    if (sp && res) {
        sfSound_setBuffer(sp, res->sound[s_laser]);
    }
    return (sp);
}

void music_event(sfEvent event, sfMusic *obj)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace) {
        if (sfMusic_getStatus(obj) == sfStopped)
            sfMusic_play(obj);
        else if (sfMusic_getStatus(obj) == sfPlaying)
            sfMusic_stop(obj);
    }
}

void quit_event(sfEvent event, sfMusic *obj)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(obj);
}

void sound_play_event(sfEvent event, sfSound *obj)
{
    if (event.type == sfEvtMouseButtonPressed)
        sfSound_play(obj);
}

int core(int argc, char const *argv[])
{
    ressources_t *res = load_ressources();
    sfEvent event;
    sfSound *sound = setup_sound(res);
    sfSprite *sprite = setup_sprite(res);
    sfVideoMode mode = {1280, 720, 32};
    sfRenderWindow *rwin = sfRenderWindow_create(mode, "Name", sfDefaultStyle, NULL);
    void (*event_list[3])(sfEvent e, void *item) = {&quit_event, &sound_play_event, &music_event};
    void *object_list[3] = {rwin, sound, res->music[m_tuba_knight_boss]};

    sfRenderWindow_setFramerateLimit(rwin, 60);
    sfRenderWindow_setVerticalSyncEnabled(rwin, sfTrue);
    while (res != NULL && rwin != NULL && sfRenderWindow_isOpen(rwin)) {
        sfRenderWindow_clear(rwin, sfBlack);
        while (sfRenderWindow_pollEvent(rwin, &event)) {
            for (size_t i = 0; i < 3; i++) {
                event_list[i](event, object_list[i]);
            }
        }
        sfRenderWindow_drawSprite(rwin, sprite, NULL);
        sfRenderWindow_display(rwin);
    }
    unload_ressources(res);
    sfSound_destroy(sound);
    sfSprite_destroy(sprite);
    sfRenderWindow_destroy(rwin);
    return (0);
}