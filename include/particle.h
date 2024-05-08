/*
** EPITECH PROJECT, 2024
** ws-paticle [WSL: Ubuntu]
** File description:
** particle
*/

#pragma once

#include <SFML/Graphics.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

#define MIN(a, b) ((a < b) ? a : b)


enum particle_type {
    FLAME = 0,
    LEAF
};

typedef struct particle_s {
    enum particle_type type;
    sfVector2f vel;
    sfTexture *texture;
    sfSprite *sprite;
    float frame;
    bool is_alive;
} particle_t;
