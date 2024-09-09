#include "PlaylistManager.hpp"

void PlaylistManager::AddToPlaylist(const std::string& track) {
    playlist.push_back(track);
}

const std::vector<std::string>& PlaylistManager::GetPlaylist() const {
    return playlist;
}