#include "sprites.h"
#include <allegro5/allegro_primitives.h>
#include <iostream>

ALLEGRO_BITMAP* create_custom_sprite() {
    ALLEGRO_BITMAP* bitmap = al_create_bitmap(64, 64);
    if (!bitmap) {
        std::cerr << "Failed to create bitmap.\n";
        return nullptr;
    }

    al_set_target_bitmap(bitmap);
    al_clear_to_color(al_map_rgb(0, 0, 0));

    int cx = 32;
    int cy = 32;

    al_draw_filled_circle(cx, cy, 10, al_map_rgb(255, 255, 0));          // Yellow circle
    al_draw_filled_rectangle(cx - 20, cy - 2, cx + 20, cy + 2, al_map_rgb(0, 255, 255)); // Cyan bar
    al_draw_line(cx, cy - 30, cx, cy + 30, al_map_rgb(255, 0, 255), 2);  // Magenta line
    al_draw_filled_triangle(cx - 10, cy - 20, cx + 10, cy - 20, cx, cy - 35, al_map_rgb(255, 0, 0)); // Red triangle

    al_set_target_backbuffer(al_get_current_display());
    return bitmap;
}