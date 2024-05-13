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

    sfRenderWindow_setFramerateLimit(window, 60);

    while (sfRenderWindow_isOpen(window)) {

        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);

        sfRenderWindow_display(window);
    }

    sfRenderWindow_destroy(window);

    return 0;
}