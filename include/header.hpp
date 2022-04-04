#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

#include <time.h>
#include <windows.h>
#include <math.h>
#include <string.h>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "json/json.h"

#define MAX_KEYS_NUM 50

extern sf::RenderWindow window;

DWORD WINAPI ThreadProcPY(LPVOID lpParam);
namespace data
{
extern Json::Value cfg;

void error_msg(std::string error, std::string title);

bool init();

sf::Texture &load_texture(std::string path);
sf::Texture &load_texture2(std::string path);
};

namespace mouse
{
	bool init();

	void draw();
}; 

namespace morekeys
{
	bool init();

	void draw();

	void drawDmkReaction(int);
}; 

namespace morekeys_keybordonly
{
	bool init();

	void draw();
}; 

