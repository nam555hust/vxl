// #include "Database.hpp"
// void Database::createTables() {
//         const char* sql = R"(
//         CREATE TABLE IF NOT EXISTS MediaFiles (
//             id INTEGER PRIMARY KEY AUTOINCREMENT,
//             file_path TEXT NOT NULL,
//             file_name TEXT NOT NULL,
//             file_type TEXT NOT NULL,
//             track_name TEXT,
//             artist TEXT,
//             album TEXT,
//             genre TEXT,
//             duration INTEGER,
//             bitrate INTEGER,
//             codec TEXT,
//             year INTEGER
//         );

//         CREATE TABLE IF NOT EXISTS Playlists (
//             id INTEGER PRIMARY KEY AUTOINCREMENT,
//             playlist_name TEXT NOT NULL
//         );

//         CREATE TABLE IF NOT EXISTS PlaylistMedia (
//             playlist_id INTEGER,
//             media_id INTEGER,
//             FOREIGN KEY (playlist_id) REFERENCES Playlists(id),
//             FOREIGN KEY (media_id) REFERENCES MediaFiles(id)
//         );

//         CREATE TABLE IF NOT EXISTS PlaybackSettings (
//             setting_id INTEGER PRIMARY KEY AUTOINCREMENT,
//             volume INTEGER,
//             last_played_file_id INTEGER,
//             last_played_position INTEGER,
//             FOREIGN KEY (last_played_file_id) REFERENCES MediaFiles(id)
//         );
//         )";

//         char* errMsg = 0;
//         if (sqlite3_exec(db, sql, 0, 0, &errMsg) != SQLITE_OK) {
//             std::cerr << "SQL error: " << errMsg << std::endl;
//             sqlite3_free(errMsg);
//         } else {
//             std::cout << "Tables created successfully." << std::endl;
//         }
//     }
// void Database::addMediaFile(const std::string& trackName, const std::string& artist, const std::string& album, const std::string& genre, int duration) {
//     const char* sql_insert = R"(
//         INSERT INTO MediaFiles (track_name, artist, album, genre, duration)
//         VALUES (?, ?, ?, ?, ?);
//     )";

//     sqlite3_stmt* stmt;
//     if (sqlite3_prepare_v2(db, sql_insert, -1, &stmt, 0) == SQLITE_OK) {
//         sqlite3_bind_text(stmt, 1, trackName.c_str(), -1, SQLITE_STATIC);
//         sqlite3_bind_text(stmt, 2, artist.c_str(), -1, SQLITE_STATIC);
//         sqlite3_bind_text(stmt, 3, album.c_str(), -1, SQLITE_STATIC);
//         sqlite3_bind_text(stmt, 4, genre.c_str(), -1, SQLITE_STATIC);
//         sqlite3_bind_int(stmt, 5, duration);
//         sqlite3_step(stmt);
//     }
//     sqlite3_finalize(stmt);
// }
// void Database::addPlaylist(const std::string& playlistName) {
//     const char* sql_insert = R"(
//         INSERT INTO Playlists (playlist_name)
//         VALUES (?);
//     )";

//     sqlite3_stmt* stmt;
//     if (sqlite3_prepare_v2(db, sql_insert, -1, &stmt, 0) == SQLITE_OK) {
//         sqlite3_bind_text(stmt, 1, playlistName.c_str(), -1, SQLITE_STATIC);
//         sqlite3_step(stmt);
//     }
//     sqlite3_finalize(stmt);
// }
// std::vector<std::string> Database::fetchMediaFiles() {
//     std::vector<std::string> mediaFiles;
//     const char* sql_select = "SELECT track_name FROM MediaFiles;";

//     sqlite3_stmt* stmt;
//     if (sqlite3_prepare_v2(db, sql_select, -1, &stmt, 0) == SQLITE_OK) {
//         while (sqlite3_step(stmt) == SQLITE_ROW) {
//             std::string trackName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
//             mediaFiles.push_back(trackName);
//         }
//     }
//     sqlite3_finalize(stmt);
//     return mediaFiles;
// }
// std::vector<std::string> Database::fetchSongsInPlaylist(std::string playlist) {
//     std::vector<std::string> mediaFiles;
//     const char* sql_select = "SELECT track_name FROM MediaFiles;";

//     sqlite3_stmt* stmt;
//     if (sqlite3_prepare_v2(db, sql_select, -1, &stmt, 0) == SQLITE_OK) {
//         while (sqlite3_step(stmt) == SQLITE_ROW) {
//             std::string trackName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
//             mediaFiles.push_back(trackName);
//         }
//     }
//     sqlite3_finalize(stmt);
//     return mediaFiles;
// }
// Metadata Database::getMediaMetadata(const std::string& trackName) {
//     Metadata metadata;
//     const char* sql_select = R"(
//         SELECT track_name, artist, album, genre, duration
//         FROM MediaFiles
//         WHERE track_name = ?;
//     )";

//     sqlite3_stmt* stmt;
//     if (sqlite3_prepare_v2(db, sql_select, -1, &stmt, 0) == SQLITE_OK) {
//         sqlite3_bind_text(stmt, 1, trackName.c_str(), -1, SQLITE_STATIC);
//         if (sqlite3_step(stmt) == SQLITE_ROW) {
//             metadata.setTrackName(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
//             metadata.setArtist(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
//             metadata.setAlbum(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
//             metadata.setGenre(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
//             metadata.setDuration(sqlite3_column_int(stmt, 4));
//         }
//     }
//     sqlite3_finalize(stmt);
//     return metadata;
// }
// void Database::updateMetadata(const std::string& trackName, const std::string& newArtist, const std::string& newAlbum, const std::string& newGenre) {
//     const char* sql_update = R"(
//         UPDATE MediaFiles
//         SET artist = ?, album = ?, genre = ?
//         WHERE track_name = ?;
//     )";

//     sqlite3_stmt* stmt;
//     if (sqlite3_prepare_v2(db, sql_update, -1, &stmt, 0) == SQLITE_OK) {
//         sqlite3_bind_text(stmt, 1, newArtist.c_str(), -1, SQLITE_STATIC);
//         sqlite3_bind_text(stmt, 2, newAlbum.c_str(), -1, SQLITE_STATIC);
//         sqlite3_bind_text(stmt, 3, newGenre.c_str(), -1, SQLITE_STATIC);
//         sqlite3_bind_text(stmt, 4, trackName.c_str(), -1, SQLITE_STATIC);
//         sqlite3_step(stmt);
//     }
//     sqlite3_finalize(stmt);
// }
// void Database::deleteMediaFile(const std::string& trackName) {
//     const char* sql_delete = R"(
//         DELETE FROM MediaFiles WHERE track_name = ?;
//     )";

//     sqlite3_stmt* stmt;
//     if (sqlite3_prepare_v2(db, sql_delete, -1, &stmt, 0) == SQLITE_OK) {
//         sqlite3_bind_text(stmt, 1, trackName.c_str(), -1, SQLITE_STATIC);
//         sqlite3_step(stmt);
//     }
//     sqlite3_finalize(stmt);
// }
