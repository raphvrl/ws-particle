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

particle_t *create_particle_flame(sfVector2f pos);
particle_t *create_particle_leaf(sfVector2f pos);

typedef particle_t* (*particle_creator)(sfVector2f pos);

static particle_creator particle_creator_list[] = {
    create_particle_flame,
    create_particle_leaf
};

void update_particle_flame(particle_t *particle);
void update_particle_leaf(particle_t *particle);

typedef void (*particle_updater)(particle_t *particle);

static particle_updater particle_updater_list[] = {
    update_particle_flame,
    update_particle_leaf
};

void destroy_particle_flame(particle_t *particle);
void destroy_particle_leaf(particle_t *particle);

typedef void (*particle_destroyer)(particle_t *particle);

static particle_destroyer particle_destroyer_list[] = {
    destroy_particle_flame,
    destroy_particle_leaf
};

void add_particle(particle_list_t **list, enum particle_type type, sfVector2f pos);
void delete_particle(particle_list_t **list, particle_list_t *to_delete);
void clean_particle_list(particle_list_t **list);
void render_particles(sfRenderWindow *window, particle_list_t *list);
void update_particles(particle_list_t **list);

