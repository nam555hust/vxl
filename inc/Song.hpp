#ifndef __SONG_HPP__
#define __SONG_HPP__
#include <string>

class Song{
private:
    std::string title;
    std::string artist;
    std::string album;
    std::string filePath;

public:
    Song(const std::string& t, const std::string& a, const std::string& al, const std::string& fp)
        : title(t), artist(a), album(al), filePath(fp) {}

    std::string getTitle() const { return title; }
    std::string getArtist() const { return artist; }
    std::string getAlbum() const { return album; }
    std::string getFilePath() const { return filePath; }
};
#endif