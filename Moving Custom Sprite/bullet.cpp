#include "bullet.h"
#include <iostream>
#include <cstdlib>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>

bullet::bullet()
{
	alive = false;;
	srand(time(0));
}
bool bullet::getStatus()
{
	return alive;
}

void bullet::fire()
{
	x=rand()%615+10;
	y = 10;
	alive=true;

}
void bullet::erase_bullet()
{
	al_draw_filled_rectangle(x,y,x+5,y+5,al_map_rgb(0,0,0)); //black color
}
int bullet::move_bullet (int arrowX, int arrowY, int width, int length, int height)
{
	y++;
	al_draw_bitmap(bullet_bmp, x, y, 0);


	if (x > arrowX && x < arrowX+width && y > arrowY && y < arrowY+length) {
		al_draw_filled_rectangle(x,y,x+5,y+5,al_map_rgb(0,0,0)); //BLACK
		alive=false;
		return 1;
	}
	if (y> height)
		alive = false;
	return 0;


} void bullet::create_bullet_bitmap() {

	// Create a bitmap for the bullet
	bullet_bmp = al_create_bitmap(16, 16);
	if (!bullet_bmp) {
		std::cerr << "Failed to create bullet bitmap.\n";
		return;
	}

	// Set the target bitmap to the bullet bitmap
	al_set_target_bitmap(bullet_bmp);

	//blue background
	al_clear_to_color(al_map_rgb(0, 0, 255));

	// yellow filled circle (center)
	al_draw_filled_circle(8, 8, 5, al_map_rgb(255, 255, 0));

	//red diagonal line
	al_draw_line(2, 2, 14, 14, al_map_rgb(255, 0, 0), 2);

	// Restore drawing to backbuffer (main screen)
	al_set_target_backbuffer(al_get_current_display());

	

}


