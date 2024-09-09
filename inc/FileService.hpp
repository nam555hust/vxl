#ifndef __FILE_SERVICE_HPP__
#define __FILE_SERVICE_HPP__
#include <vector>
#include "Song.hpp"
class FileService {
public:
    std::vector<Song> loadPlaylist(const std::string& filePath);
    void savePlaylist(const std::string& filePath, const std::vector<Song>& playlist);
};

#endif