/*
** EPITECH PROJECT, 2024
** ws-paticle [WSL: Ubuntu]
** File description:
** particleList
*/

#pragma once

#include "particle.h"

typedef struct particle_list_s {
    particle_t *particle;
    struct particle_list_s *next;
} particle_list_t;
