/*
** LAROUS PROJECT, 2020
** CSFML_Good_Practice
** FiIe description:
** core
*/

#include <SFML/Window/VideoMode.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Audio/Sound.h>
#include "ressources.h"
#include "event.h"

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

int core(int argc, char const *argv[])
{
    ressources_t *res = load_ressources();
    sfSound *sound = setup_sound(res);
    sfSprite *sprite = setup_sprite(res);
    sfVideoMode mode = {1280, 720, 32};
    sfRenderWindow *rwin = sfRenderWindow_create(mode, "Name", sfDefaultStyle, NULL);

    sfRenderWindow_setFramerateLimit(rwin, 60);
    sfRenderWindow_setVerticalSyncEnabled(rwin, sfTrue);
    while (res != NULL && rwin != NULL && sfRenderWindow_isOpen(rwin)) {
        sfRenderWindow_clear(rwin, sfBlack);
        handle_event(rwin, res, sound);
        sfRenderWindow_drawSprite(rwin, sprite, NULL);
        sfRenderWindow_display(rwin);
    }
    unload_ressources(res);
    sfSound_destroy(sound);
    sfSprite_destroy(sprite);
    sfRenderWindow_destroy(rwin);
    return (0);
}