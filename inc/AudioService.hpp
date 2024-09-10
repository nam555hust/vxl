#ifndef __AUDIO_SERVICE_HPP__
#define __AUDIO_SERVICE_HPP__
#include <SFML/Audio.hpp>
#include <string>
#include <sqlite3.h>
#include "Database.hpp"
#include "FileService.hpp"
class AudioService {
public:
    AudioService(sf::Music& music)
        : music(music), currentVolume(50) {
        music.setVolume(currentVolume);
    }
    bool Play(const std::string& filepath);
    void Pause();
    void Stop();
    void SetVolume(float volume);
    float GetVolume() const;
    sf::Music& GetCurrentTrack();
    sf::SoundSource::Status getStatus() const {
        return music.getStatus();
    }
    sf::Time getCurrentTime() const {
        return music.getPlayingOffset();
    }
    sf::Time getDuration() const {
        return music.getDuration();
    }
private:
    sf::Music& music;
    float currentVolume;
};



#endif