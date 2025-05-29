#include "arrow.h"
#include "../sprites.h"
arrowClass::arrowClass()
{
	speed=0;
	x=100;
	y=100;
	dir=1;
	score = 0;
	arrow_bmp = nullptr;
}
arrowClass::~arrowClass()
{
	al_destroy_bitmap(arrow_bmp);
}
void arrowClass::drawArrow()
{
	float angle = get_angle(dir); // dir is your direction (0-3)
	al_draw_rotated_bitmap(arrow_bmp, 32, 32, x + 32, y + 32, angle, 0);
}

float get_angle(int dir) {
	switch (dir) {
	case 0: return 0.0f;                         // UP
	case 1: return ALLEGRO_PI / 2;               // RIGHT
	case 2: return ALLEGRO_PI;                   // DOWN
	case 3: return 3 * ALLEGRO_PI / 2;           // LEFT
	default: return 0.0f;
	}
}

void arrowClass::create_arrow_bitmap(ALLEGRO_DISPLAY* display) {
	if (arrow_bmp) {
		al_destroy_bitmap(arrow_bmp); // clean up previous bitmap
	}
	arrow_bmp = create_custom_sprite();
}
void arrowClass::erase_arrow()
{

	al_draw_filled_rectangle(x, y, x + 64, y + 64, al_map_rgb(0, 0, 0));
}

void arrowClass::up()
{
	dir=0;
	speed++;
	if (speed > MAXSPEED)
		speed = MAXSPEED;
}

void arrowClass::down()
{
	dir=2;
	speed++;
	if (speed > MAXSPEED)
		speed = MAXSPEED;

}


void arrowClass::left()
{
	dir=3;
	speed++;
	if (speed > MAXSPEED)
		speed = MAXSPEED;

}

void arrowClass::right()
{
	dir=1;
	speed++;
	if (speed > MAXSPEED)
		speed = MAXSPEED;

}
int arrowClass::getDirection()
{
	return dir;
}
int arrowClass::getSpeed()
{
	return speed;
}
int arrowClass::getX()
{
	return x;
}
int arrowClass::getY()
{
	return y;
}
void arrowClass::move_arrow(int width, int height)
{

	//update arrow position based on direction
	switch(dir)
	{
	case 0:
		y -= speed;
		break;
	case 1:
		x += speed;
		break;
	case 2:
		y += speed;
		break;
	case 3:
		x -= speed;
	}

	//keep arrow inside the screen
	if (x > width-32)
	{
		x = width-32;
		speed = 0;
	}
	if (x < 0)
	{
		x = 0;
		speed = 0;
	}
	if (y > height-32)
	{
		y = height-32;
		speed = 0;
	}
	if (y < 0)
	{
		y = 0;
		speed = 0;
	}
}
