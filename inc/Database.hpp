#ifndef __DATABASE_HPP__
#define __DATABASE_HPP__
#include <sqlite3.h>
#include <iostream>
#include <vector>
#include "Metadata.hpp"
class Database {
public:
    Database(const std::string& db_name) {
        if (sqlite3_open(db_name.c_str(), &db)) {
            std::cout << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        } else {
            std::cout << "Opened database successfully." << std::endl;
        }
    }

    ~Database() {
        sqlite3_close(db);
    }

    void createTables();
    void addMediaFile(const std::string& trackName, const std::string& artist, const std::string& album, const std::string& genre, int duration);
    void addPlaylist(const std::string& playlistName);
    std::vector<std::string> fetchMediaFiles();
    std::vector<std::string> fetchSongsInPlaylist(std::string playlist);
    Metadata getMediaMetadata(const std::string& trackName);
    void updateMetadata(const std::string& trackName, const std::string& newArtist, const std::string& newAlbum, const std::string& newGenre);
    void deleteMediaFile(const std::string& trackName);
private:
    sqlite3* db;
};
#endif