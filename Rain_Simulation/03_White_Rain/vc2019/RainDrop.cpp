#include "RainDrop.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"

#include <random>

short int random(short int L, short int U)
{
	return (rand() % (U - L)) + L;
}

float map(float value, float l_i, float h_i, float l_f, float h_f)
{
	if (h_i - l_i == 0) throw "Divide by zero in function map!";
	return value * (h_f - l_f) / (h_i - l_i);
}

ci::Color gen_color(const int MIN_COL, const int MAX_COL)
{
	float R, G, B;
	R = G = B = -1;
	switch (random(0, 3))
	{
	case 0:
		R = random(MIN_COL, MAX_COL);
		G = random(0, 256);
		B = random(0, 256);
		break;

	case 1:
		R = random(0, 256);
		G = random(MIN_COL, MAX_COL);
		B = random(0, 256);
		break;

	case 2:
		R = random(0, 256);
		G = random(0, 256);
		B = random(MIN_COL, MAX_COL);
		break;
	default:
		break;
	}

	if (R == -1 || G == -1 || B == -1) throw "Failed to initialize colors!";


	return ci::Color(R / 255.0, G / 255.0, B / 255.0);
}

RainDrop::RainDrop(int min_size, int max_size)
{
	// Initial positions
	int x_max = ci::app::getWindowWidth();
	int u_limit = 0 - ci::app::getWindowHeight()/2;

	int x = random(0, x_max);
	int y = random(u_limit, 0);


	// Size and angle(offset)
	this->size = random(min_size, max_size);
	this->offset = map(size, min_size, max_size, min_size / 6, max_size / 6);
	posI = ci::vec2(x, y);
	posF = ci::vec2(x + offset, y + size);


	// Color
	this->col = gen_color(MIN_COL, MAX_COL);
}

void RainDrop::reset_x()
{
	this->posI.x = -this->offset - 2;
	this->posF.x = -2;
}

void RainDrop::reset_y(int min_size, int max_size)
{
	this->size = random(min_size, max_size);
	this->offset = map(size, min_size, max_size, min_size / 6, max_size / 6);


	int x_max = ci::app::getWindowWidth();

	int x = random(0, x_max);
	int y = -size - 2;

	posI = ci::vec2(x, y);
	posF = ci::vec2(x + offset, y + size);


	this->col = gen_color(MIN_COL, MAX_COL);

}

void RainDrop::update(int min_size, int max_size, int min_v, int max_v)
{
	float g = map(this->size, min_size, max_size, min_v, max_v);
	posI += ci::vec2(g/4.5, g);
	posF += ci::vec2(g/4.5, g);

	int w_height = ci::app::getWindowHeight();
	int w_width  = ci::app::getWindowWidth();

	if (posI.x > w_width)
		this->reset_x();

	if (posI.y > w_height)
		this->reset_y(min_size, max_size);
}

void RainDrop::render()
{
	ci::gl::color(1, 1, 1);
	ci::gl::drawLine(this->posI, this->posF);
}
