#ifndef __AUDIO_SERVICE_HPP__
#define __AUDIO_SERVICE_HPP__
#include "SFML/Audio.hpp"
#include <string>

class AudioService {
public:
    AudioService();
    void Play(const std::string& filepath);
    void Pause();
    void Stop();
    void SetVolume(float volume);
    float GetVolume() const;
    sf::Music& GetCurrentTrack();
private:
    sf::Music music;
};



#endif