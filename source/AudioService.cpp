#include "AudioService.hpp"

AudioService::AudioService() {
    music.setVolume(50.f);
}

void AudioService::Play(const std::string& filepath) {
    music.openFromFile(filepath);
    music.play();
}

void AudioService::Pause() {
    music.pause();
}

void AudioService::Stop() {
    music.stop();
}

void AudioService::SetVolume(float volume) {
    music.setVolume(volume);
}

float AudioService::GetVolume() const {
    return music.getVolume();
}

sf::Music& AudioService::GetCurrentTrack() {
    return music;
}