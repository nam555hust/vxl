#include "AudioService.hpp"
#include <iostream>
bool AudioService::Play(const std::string& filePath) {
        if (music.openFromFile(filePath)) {
            music.play();
            return true;
        } else {
            std::cout << "Error: Could not load music file!" << std::endl;
            return false;
        }
    }

void AudioService::Pause() {
    if(music.getStatus() == sf::SoundSource::Playing)
        music.pause();
}

void AudioService::Stop() {
    music.stop();
}

void AudioService::SetVolume(float volume) {
    currentVolume = volume;
    music.setVolume(currentVolume);
}

float AudioService::GetVolume() const {
    return music.getVolume();
}

sf::Music& AudioService::GetCurrentTrack() {
    return music;
}