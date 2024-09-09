#ifndef __META_DATA_HPP__
#define __META_DATA_HPP__

#include "Song.hpp"
#include <iostream>
class Metadata {
private:
    std::string trackName;   // Tên bài hát
    std::string artist;      // Tên nghệ sĩ
    std::string album;       // Album
    std::string genre;       // Thể loại
    int duration;            // Thời lượng bài hát (giây)

public:
    // Constructors
    Metadata() : trackName(""), artist(""), album(""), genre(""), duration(0) {}

    Metadata(const std::string& trackName, const std::string& artist,
             const std::string& album, const std::string& genre, int duration)
        : trackName(trackName), artist(artist), album(album), genre(genre), duration(duration) {}

    // Getters
    std::string getTrackName() const {
        return trackName;
    }

    std::string getArtist() const {
        return artist;
    }

    std::string getAlbum() const {
        return album;
    }

    std::string getGenre() const {
        return genre;
    }

    int getDuration() const {
        return duration;
    }

    // Setters
    void setTrackName(const std::string& trackName) {
        this->trackName = trackName;
    }

    void setArtist(const std::string& artist) {
        this->artist = artist;
    }

    void setAlbum(const std::string& album) {
        this->album = album;
    }

    void setGenre(const std::string& genre) {
        this->genre = genre;
    }

    void setDuration(int duration) {
        this->duration = duration;
    }
};

#endif