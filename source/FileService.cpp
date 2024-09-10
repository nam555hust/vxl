#include "FileService.hpp"
#include <fstream>
#include <iostream>

std::vector<Song> FileService::loadPlaylist() {
    std::vector<Song> playlist;
    std::ifstream file(path);
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

void FileService::savePlaylist(const std::vector<Song>& playlist) {
    std::ofstream file(path);

    if (file.is_open()) {
        for (const auto& song : playlist) {
            file << song.getTitle() << " " << song.getArtist() << " " << song.getAlbum() << " " << song.getFilePath() << "\n";
        }
        file.close();
    } else {
        std::cerr << "Unable to save playlist file!" << std::endl;
    }
}
// int main(){

// }