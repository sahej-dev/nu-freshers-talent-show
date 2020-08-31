#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "..\vc2019\Rain.h"

using namespace ci;
using namespace ci::gl;
using namespace ci::app;
using namespace std;

class HelloWorldApp : public App {
public:
	static void prepareSettings(Settings*);
	void setup() override;
	void mouseDown(MouseEvent event) override;
	void update() override;
	void draw() override;

private:
	Rain rain;
	vec2 initial_pos, final_pos;
};

void HelloWorldApp::prepareSettings(Settings* settings)
{
	settings->setWindowSize(1280, 720);
	//settings->setFullScreen();
	settings->setFrameRate((float)60);
}

CINDER_APP(HelloWorldApp, RendererGl, &HelloWorldApp::prepareSettings);

void HelloWorldApp::setup()
{
	rain = Rain();
	initial_pos = vec2(600, 300);
	final_pos = vec2(610, 350);
}

void HelloWorldApp::mouseDown(MouseEvent event)
{
}

void HelloWorldApp::update()
{
	rain.update();
}

void HelloWorldApp::draw()
{
	clear(Color(0, 0, 0));


	rain.render();
}