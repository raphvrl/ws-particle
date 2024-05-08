/*
** EPITECH PROJECT, 2024
** ws-paticle [WSL: Ubuntu]
** File description:
** main
*/

#include "stdio.h"

#include "SFML/Graphics.h"
#include "SFML/Window.h"
#include "SFML/System.h"

#include "particle_list.h"

int main(void)
{
    sfVideoMode mode = {640, 480, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "Particle Workshop", sfResize | sfClose, NULL);

    particle_list_t *list = NULL;

    sfRenderWindow_setFramerateLimit(window, 60);

    sfClock *clock = sfClock_create();

    while (sfRenderWindow_isOpen(window)) {

        add_particle(&list, FLAME, (sfVector2f){200, 240});

        if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 1000) {
            add_particle(&list, LEAF, (sfVector2f){500, 240});
            sfClock_restart(clock);
        }

        update_particles(&list);

        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);

        render_particles(window, list);

        sfRenderWindow_display(window);
    }

    sfRenderWindow_destroy(window);
    clean_particle_list(&list);

    return 0;
}