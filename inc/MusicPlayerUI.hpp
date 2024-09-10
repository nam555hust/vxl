#ifndef __MUSIC_PLAYER_UI_HPP__
#define __MUSIC_PLAYER_UI_HPP__

#include "AudioService.hpp"
#include "imgui.h"
#include "MediaLibrary.hpp"
#include "Database.hpp"
class MusicPlayUI{
    public:
        MusicPlayUI(AudioService m_audioService) : audioService(m_audioService){}
        void RenderUI(std::string path);
    private:
        AudioService audioService;
};


#endif