/*
** EPITECH PROJECT, 2020
** CSFML_Good_Practice
** File description:
** ressources
*/

#ifndef RESSOURCES_H_
#define RESSOURCES_H_

#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Audio/Music.h>
#include <SFML/Audio/SoundBuffer.h>

typedef enum font_e
{
    f_basic = 0,
    f_total = 1,
} font_t;

typedef enum texture_e
{
    t_icon = 0,
    t_mech = 1,
    t_total = 2,
} texture_t;

typedef enum music_e
{
    m_tuba_knight_boss = 0,
    m_total = 1,
} music_t;

typedef enum sound_e
{
    s_laser = 0,
    s_total = 1,
} sound_t;

typedef struct ressources_s
{
    sfFont **font;
    sfTexture **texture;
    sfMusic **music;
    sfSoundBuffer **sound;
} ressources_t;

ressources_t *load_ressources(void);
void unload_ressources(ressources_t *res);

#endif /* !RESSOURCES_H_ */
