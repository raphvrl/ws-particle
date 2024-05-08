/*
** EPITECH PROJECT, 2024
** ws-paticle
** File description:
** leaf
*/

#include "particle.h"

particle_t *create_particle_leaf(sfVector2f pos)
{
    particle_t *particle = malloc(sizeof(particle_t));
    if (!particle)
        return NULL;

    particle->type = LEAF;

    particle->vel = (sfVector2f){0.0f, 0.0f};

    particle->texture = sfTexture_createFromFile("img/leaf.png", NULL);
    particle->sprite = sfSprite_create();
    sfSprite_setTexture(particle->sprite, particle->texture, sfTrue);
    sfSprite_setPosition(particle->sprite, pos);
    sfSprite_setOrigin(particle->sprite, (sfVector2f){3, 3});
    particle->frame = 0;
    particle->is_alive = true;
    return particle;
}

void update_particle_leaf(particle_t *particle)
{
    if (!particle->is_alive || !particle)
        return;

    particle->frame += 0.1f;

    particle->vel.y = 1.0f;

    particle->vel.x = sin(particle->frame * 0.5);
    sfSprite_move(particle->sprite, particle->vel);

    sfSprite_setTextureRect(particle->sprite, (sfIntRect){(int)particle->frame * 6, 0, 6, 6});

    if (sfSprite_getPosition(particle->sprite).y > 800)
        particle->is_alive = false;

    if (particle->frame > 15)
        particle->is_alive = false;
}

void destroy_particle_leaf(particle_t *particle)
{
    sfSprite_destroy(particle->sprite);
    sfTexture_destroy(particle->texture);
    free(particle);
}
