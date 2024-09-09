#ifndef __PLAY_BACK_CONTROLLER_HPP__
#define __PLAY_BACK_CONTROLLER_HPP__

#include "PlaylistManager.hpp"
#include "AudioService.hpp"

class PlaybackController {
private:
    PlaylistManager* playlistManager;
    AudioService* audioService;

public:
    PlaybackController(PlaylistManager* pm, AudioService* as)
        : playlistManager(pm), audioService(as) {}

    void play() {
        Song currentTrack = playlistManager->getCurrentTrack();
        audioService->playTrack(currentTrack);
    }

    void pause() {
        audioService->pauseTrack();
    }

    void stop() {
        audioService->stopTrack();
    }

    void next() {
        if (playlistManager->hasNext()) {
            Song nextTrack = playlistManager->nextTrack();
            audioService->playTrack(nextTrack);
        }
    }

    void previous() {
        if (playlistManager->hasPrevious()) {
            Song prevTrack = playlistManager->previousTrack();
            audioService->playTrack(prevTrack);
        }
    }

    void setVolume(int volume) {
        audioService->setVolume(volume);
    }

    PlaylistManager* getPlaylistManager() {
        return playlistManager;
    }
};

#endif