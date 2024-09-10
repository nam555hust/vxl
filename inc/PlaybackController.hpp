#ifndef __PLAY_BACK_CONTROLLER_HPP__
#define __PLAY_BACK_CONTROLLER_HPP__

#include "PlaylistManager.hpp"
#include "AudioService.hpp"
#include "Song.hpp"
class PlaybackController {
private:
    PlaylistManager* playlistManager;
    AudioService* audioService;

public:
    PlaybackController(PlaylistManager* pm, AudioService* as)
        : playlistManager(pm), audioService(as) {}

    void play() {
        Song currentTrack = playlistManager->getCurrentTrack();
        audioService->Play(currentTrack.getFilePath());
    }

    void pause() {
        audioService->Pause();
    }

    void stop() {
        audioService->Stop();
    }

    void next() {
        if (playlistManager->hasNext()) {
            Song nextTrack = playlistManager->nextTrack();
            audioService->Play(nextTrack.getFilePath());
        }
    }

    void previous() {
        if (playlistManager->hasPrevious()) {
            Song prevTrack = playlistManager->preTrack();
            audioService->Play(prevTrack.getFilePath());
        }
    }

    void setVolume(float volume) {
        audioService->SetVolume(volume);
    }

    PlaylistManager* getPlaylistManager() {
        return playlistManager;
    }
};

#endif