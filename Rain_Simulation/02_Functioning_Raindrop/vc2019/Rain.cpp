#include "Rain.h"
#include "RainDrop.h"
#include "cinder/app/App.h"


Rain::Rain()
{
	for (int i = 0; i < this->RAIN_SIZE; i++)
	{
		this->Drops.push_back(RainDrop(this->MIN_SIZE, this->MAX_SIZE));
	}

	rain_voice = ci::audio::Voice::create(ci::audio::load(ci::app::loadAsset("rain_sound.mp3")));	
}

void Rain::update()
{
	for (auto& Drop : Drops)
	{
		Drop.update(this->MIN_SIZE, this->MAX_SIZE, this->MIN_V, this->MAX_V);
	}
}

void Rain::render()
{
	for (auto& Drop : Drops)
	{
		Drop.render();
	}
}

void Rain::play_noise()
{
	if (!rain_voice->isPlaying())
		rain_voice->start();
}
