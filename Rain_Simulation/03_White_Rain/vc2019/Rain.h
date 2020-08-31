#ifndef RAIN_H
#define RAIN_H
#pragma once

#include "cinder/audio/Voice.h"
#include "RainDrop.h"
#include <vector>

class Rain
{
public:
	Rain();

	// Updates and Resets each drop
	void update();

	// Renders each drop
	void render();

	// Plays rain noise
	void play_noise();

private:
	static constexpr int RAIN_SIZE  = 1000;
	static constexpr int MIN_V = 10;
	static constexpr int MAX_V = 20;
	static constexpr int MIN_SIZE = 10;
	static constexpr int MAX_SIZE = 30;
	std::vector <RainDrop> Drops;
	ci::audio::VoiceRef rain_voice;
};


#endif