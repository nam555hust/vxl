#ifndef __FILE_SERVICE_HPP__
#define __FILE_SERVICE_HPP__
#include <vector>
#include "Song.hpp"
class FileService {
public:
    FileService(std::string m_path) : path(m_path){}
    std::vector<Song> loadPlaylist();
    void savePlaylist(const std::vector<Song>& playlist);
private:
    std::string path;
};

#endif