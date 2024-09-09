#ifndef __MUSIC_PLAYER_UI_HPP__
#define __MUSIC_PLAYER_UI_HPP__

#include "AudioService.hpp"
#include "imgui.h"
#include "MediaLibrary.hpp"
void RenderUI(Database& db, MediaLibrary library);

#endif