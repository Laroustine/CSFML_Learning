/*
** EPITECH PROJECT, 2020
** CSFML_Good_Practice
** File description:
** ressources
*/

#include <stdlib.h>
#include "ressources.h"

static void load_list(ressources_t *res)
{
    res->font[f_basic] = sfFont_createFromFile("res/font/Wild Hazelnut.ttf");
    res->texture[t_icon] = sfTexture_createFromFile("res/img/icon.png", NULL);
    res->texture[t_mech] = sfTexture_createFromFile("res/img/mech.jpg", NULL);
    res->sound[s_laser] = sfSoundBuffer_createFromFile("res/sound/laser.wav");
    res->music[m_tuba_knight_boss] = sfMusic_createFromFile("res/music/Tuba Knight Boss Theme.ogg");
}

ressources_t *load_ressources(void)
{
    ressources_t *res = malloc(sizeof(ressources_t));

    if (res) {
        res->font = malloc(sizeof(sfFont *) * f_total);
        res->texture = malloc(sizeof(sfTexture *) * t_total);
        res->music = malloc(sizeof(sfMusic *) * m_total);
        res->sound = malloc(sizeof(sfSound *) * s_total);
        if (res->font && res->texture && res->music && res->sound) {
            unload_ressources(res);
        } else {
            load_list(res);
        }
    }
    return (res);
}

static void unload_list(ressources_t *res)
{
    if (res->font) {
        for (int i = 0; i < f_total; i++)
            free(res->font[i]);
        free(res->font);
    }
    if (res->texture) {
        for (int i = 0; i < t_total; i++)
            free(res->texture[i]);
        free(res->texture);
    }
    if (res->sound) {
        for (int i = 0; i < s_total; i++)
            free(res->sound[i]);
        free(res->sound);
    }
    if (res->music) {
        for (int i = 0; i < m_total; i++)
            free(res->music[i]);
        free(res->music);
    }
}

void unload_ressources(ressources_t *res)
{
    if (res) {
        unload_list(res);
        free(res);
    }
}
