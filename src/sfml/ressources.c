/**
 * @ Author: Laroustine
 * @ Modified time: 05/11 14:56
 * @ Modified by: Laroustine
 * @ Description: This script has been made by me ↖(^▽^)↗
 */

#include <stdlib.h>
#include "ressources.h"
#include "ressources_list.h"

static void load_list(ressources_t *res)
{
    for (size_t i = 0; i < f_total; i++) {
        res->font[i] = sfFont_createFromFile(font_l[i]);
    }
    for (size_t i = 0; i < t_total; i++) {
        res->texture[i] = sfTexture_createFromFile(texture_l[i], NULL);
    }
    for (size_t i = 0; i < s_total; i++) {
        res->sound[i] = sfSoundBuffer_createFromFile(sound_l[i]);
    }
    for (size_t i = 0; i < m_total; i++) {
        res->music[i] = sfMusic_createFromFile(music_l[i]);
    }
}

ressources_t *load_ressources(void)
{
    ressources_t *res = malloc(sizeof(ressources_t));

    if (res) {
        res->font = malloc(sizeof(sfFont *) * f_total);
        res->texture = malloc(sizeof(sfTexture *) * t_total);
        res->music = malloc(sizeof(sfMusic *) * m_total);
        res->sound = malloc(sizeof(sfSound *) * s_total);
        if (!res->font || !res->texture || !res->music || !res->sound) {
            unload_ressources(res);
            return (NULL);
        } else {
            load_list(res);
            return (res);
        }
    }
    return (NULL);
}

static void unload_list(ressources_t *res)
{
    if (res->font) {
        for (int i = 0; i < f_total; i++)
            sfFont_destroy(res->font[i]);
        free(res->font);
    }
    if (res->texture) {
        for (int i = 0; i < t_total; i++)
            sfTexture_destroy(res->texture[i]);
        free(res->texture);
    }
    if (res->sound) {
        for (int i = 0; i < s_total; i++)
            sfSoundBuffer_destroy(res->sound[i]);
        free(res->sound);
    }
    if (res->music) {
        for (int i = 0; i < m_total; i++)
            sfMusic_destroy(res->music[i]);
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
