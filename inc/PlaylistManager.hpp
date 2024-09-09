#ifndef __PLAY_LIST_MANAGER_HPP__
#define __PLAY_LIST_MANAGER_HPP__

#include <vector>
#include <string>

class PlaylistManager {
public:
    void addTrack(const std::string& track) {
        tracks.push_back(track);
    }

    void removeTrack(const std::string& track) {
        // tracks.erase(std::remove(tracks.begin(), tracks.end(), track), tracks.end());
    }

    const std::vector<std::string>& getTracks() const {
        return tracks;
    }
private:
    std::vector<std::string> tracks;
};


#endif