/*
** EPITECH PROJECT, 2024
** ws-paticle [WSL: Ubuntu]
** File description:
** particle
*/

#include "particle.h"

particle_t *create_particle_flame(sfVector2f pos)
{
    particle_t *particle = malloc(sizeof(particle_t));
    if (!particle)
        return NULL;

    particle->type = FLAME;

    particle->vel = (sfVector2f){rand() % 7 - 3, -6};

    particle->texture = sfTexture_createFromFile("img/flame.png", NULL);
    particle->sprite = sfSprite_create();
    sfSprite_setTexture(particle->sprite, particle->texture, sfTrue);
    sfSprite_setPosition(particle->sprite, pos);
    sfSprite_setOrigin(particle->sprite, (sfVector2f){6, 6});
    particle->frame = 0;
    particle->is_alive = true;
    return particle;
}

void update_particle_flame(particle_t *particle)
{
    if (!particle->is_alive || !particle)
        return;

    sfSprite_move(particle->sprite, particle->vel);
    particle->frame += 0.1;

    particle->vel.y += 0.1;
    if (particle->vel.x > 0)
        particle->vel.x -= 0.1;
    if (particle->vel.x < 0)
        particle->vel.x += 0.1;

    sfSprite_setTextureRect(particle->sprite, (sfIntRect){(int)particle->frame * 12, 0, 12, 12});

    if (particle->vel.y > 0)
        particle->is_alive = false;

    if (particle->frame > 5)
        particle->is_alive = false;

}

void destroy_particle_flame(particle_t *particle)
{
    sfSprite_destroy(particle->sprite);
    sfTexture_destroy(particle->texture);
    free(particle);
}
