/*
** EPITECH PROJECT, 2024
** ws-paticle [WSL: Ubuntu]
** File description:
** particle_list
*/

#include "particle_list.h"

void add_particle(particle_list_t **list, enum particle_type type, sfVector2f pos)
{
    particle_list_t *new = malloc(sizeof(particle_list_t));
    if (!new)
        return;
    new->particle = particle_creator_list[type](pos);
    new->next = *list;
    *list = new;
}

void delete_particle(particle_list_t **list, particle_list_t *to_delete)
{
    particle_list_t *tmp = *list;

    if (tmp == to_delete) {
        *list = tmp->next;
        particle_destroyer_list[tmp->particle->type](tmp->particle);
        free(tmp);
        return;
    }

    while (tmp->next != to_delete)
        tmp = tmp->next;
    tmp->next = to_delete->next;
    particle_destroyer_list[to_delete->particle->type](to_delete->particle);
    free(to_delete);
}

void clean_particle_list(particle_list_t **list)
{
    particle_list_t *tmp = *list;
    particle_list_t *next = NULL;

    while (tmp) {
        next = tmp->next;
        free(tmp->particle->sprite);
        free(tmp->particle->texture);
        free(tmp->particle);
        free(tmp);
        tmp = next;
    }
    *list = NULL;
}

void render_particles(sfRenderWindow *window, particle_list_t *list)
{
    particle_list_t *tmp = list;

    while (tmp) {
        sfRenderWindow_drawSprite(window, tmp->particle->sprite, NULL);
        tmp = tmp->next;
    }
}

void update_particles(particle_list_t **list)
{
    particle_list_t *tmp = *list;

    while (tmp) {
        particle_updater_list[tmp->particle->type](tmp->particle);
        if (!tmp->particle->is_alive) {
            particle_list_t *to_delete = tmp;
            tmp = tmp->next;
            delete_particle(list, to_delete);
        } else {
            tmp = tmp->next;
        }
    }
}
