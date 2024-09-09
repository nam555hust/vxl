#include "FileService.hpp"
#include <fstream>
#include <iostream>

std::vector<Song> FileService::loadPlaylist(const std::string& filePath) {
    std::vector<Song> playlist;
    std::ifstream file(filePath);
    std::string title, artist, album, path;

    if (file.is_open()) {
        while (file >> title >> artist >> album >> path) {
            playlist.emplace_back(title, artist, album, path);
        }
        file.close();
    } else {
        std::cerr << "Unable to open playlist file!" << std::endl;
    }

    return playlist;
}

void FileService::savePlaylist(const std::string& filePath, const std::vector<Song>& playlist) {
    std::ofstream file(filePath);

    if (file.is_open()) {
        for (const auto& song : playlist) {
            file << song.getTitle() << " " << song.getArtist() << " " << song.getAlbum() << " " << song.getFilePath() << "\n";
        }
        file.close();
    } else {
        std::cerr << "Unable to save playlist file!" << std::endl;
    }
}