#ifndef __PLAY_LIST_MANAGER_HPP__
#define __PLAY_LIST_MANAGER_HPP__

#include <vector>
#include <string>
#include "Song.hpp"
class PlaylistManager {
public:
    Song getCurrentTrack() const{
        if (currentIndex >= 0 && currentIndex < playlist.size()){
            return playlist[currentIndex];
        }
        return Song("No Song", "Unknow", "Unknow", "");
    }
    void addTrack(const Song& track) {
        playlist.push_back(track);
        if(currentIndex == -1) currentIndex = 0;
    }
    bool hasNext() const{
        return currentIndex < playlist.size() - 1;
    }
    bool hasPrevious(){
        return currentIndex > 0;
    }
    Song nextTrack(){
        if(hasNext()){
            currentIndex ++;
        }
        return getCurrentTrack();
    }
    Song preTrack(){
        if(hasPrevious()){
            currentIndex --;
        }
        return getCurrentTrack();
    }
    // void removeTrack(const std::string& track) {
    //     // tracks.erase(std::remove(tracks.begin(), tracks.end(), track), tracks.end());
    // }

    // const std::vector<std::string>& getTracks() const {
    //     return tracks;
    // }
private:
    std::vector<Song> playlist;
    int currentIndex;
};


#endif