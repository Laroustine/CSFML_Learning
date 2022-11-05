/**
 * @ Author: Laroustine
 * @ Modified time: 05/11 16:01
 * @ Modified by: Laroustine
 * @ Description: This script has been made by me ↖(^▽^)↗
 */

#include <SFML/Window/VideoMode.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Audio/Sound.h>
#include "ressources.h"
#include "event.h"

sfSprite *setup_sprite(ressources_t *res)
{
    sfSprite *sp = sfSprite_create();

    if (sp && res)
    {
        sfSprite_setTexture(sp, res->texture[t_mech], sfTrue);
        sfSprite_setPosition(sp, (sfVector2f){20, 20});
    }
    return (sp);
}

sfSprite *setup_sprite_keyboard(ressources_t *res)
{
    sfSprite *sp = sfSprite_create();

    if (sp && res)
    {
        sfSprite_setTexture(sp, res->texture[t_keybord], sfTrue);
        sfSprite_setTextureRect(sp, (sfIntRect){16, 0, 16, 15});
        sfSprite_setPosition(sp, (sfVector2f){1280 / 2, 720 / 2});
        sfSprite_setOrigin(sp, (sfVector2f){16 / 2, 15.0 / 2});
        sfSprite_setScale(sp, (sfVector2f){4, 4});
    }
    return (sp);
}

sfSound *setup_sound(ressources_t *res)
{
    sfSound *sp = sfSound_create();

    if (sp && res)
    {
        sfSound_setBuffer(sp, res->sound[s_laser]);
    }
    return (sp);
}

int core(int argc, char const *argv[])
{
    ressources_t *res = load_ressources();
    sfSound *sound = setup_sound(res);
    sfSprite *sprite = setup_sprite(res);
    sfSprite *key = setup_sprite_keyboard(res);
    sfVideoMode mode = {1280, 720, 32};
    sfRenderWindow *rwin = sfRenderWindow_create(mode, "Name", sfDefaultStyle, NULL);

    sfRenderWindow_setFramerateLimit(rwin, 60);
    sfRenderWindow_setVerticalSyncEnabled(rwin, sfTrue);
    while (res != NULL && rwin != NULL && sfRenderWindow_isOpen(rwin))
    {
        sfRenderWindow_clear(rwin, sfBlack);
        handle_event(rwin, res, sound, key);
        sfRenderWindow_drawSprite(rwin, key, NULL);
        sfRenderWindow_drawSprite(rwin, sprite, NULL);
        sfRenderWindow_display(rwin);
    }
    unload_ressources(res);
    sfSound_destroy(sound);
    sfSprite_destroy(sprite);
    sfRenderWindow_destroy(rwin);
    return (0);
}