#ifndef RAIN_DROP_H
#define RAIN_DROP_H

#pragma once

#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

class RainDrop
{
public:
	RainDrop(int min_size, int max_size);
	void reset_x();
	void reset_y(int min_size, int max_size);
	void update(int min_size, int max_size, int min_v, int max_v);
	void render();

private:
	static constexpr int MIN_COL = 128;
	static constexpr int MAX_COL = 256;
	ci::vec2 posI;
	ci::vec2 posF;
	ci::Color col;
	short int size;
	float offset;

};

#endif