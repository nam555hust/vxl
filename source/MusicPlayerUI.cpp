#include <vector>
#include <string>
#include "Database.hpp"
#include "MusicPlayerUI.hpp"
void RenderUI(Database& db, MediaLibrary library) {
    // Khởi tạo cửa sổ UI cho music player
    ImGui::Begin("Music Player");
    std::vector<std::string> mediaFiles = library.scanDirectory("C:\\Users\\Admin\\Downloads");
    // Hiển thị danh sách tệp nhạc
    ImGui::Text("Media Files:");
    static std::vector<std::string> mediaFiles;
    mediaFiles = db.fetchMediaFiles();  // Lấy danh sách từ database
    
    static int selectedIndex = 0;
    ImGui::BeginChild("MediaList", ImVec2(300, 400), true);
    for (int i = 0; i < mediaFiles.size(); i++) {
        if (ImGui::Selectable(mediaFiles[i].c_str(), selectedIndex == i)) {
            selectedIndex = i;  // Chọn tệp nhạc
        }
    }
    ImGui::EndChild();

    // Hiển thị metadata của tệp được chọn
    ImGui::Separator();
    if (!mediaFiles.empty()) {
        ImGui::Text("Metadata for: %s", mediaFiles[selectedIndex].c_str());
        auto metadata = db.getMediaMetadata(mediaFiles[selectedIndex]);
        
        // Hiển thị thông tin metadata
        ImGui::Text("Track Name: %s", metadata.getTrackName().c_str());
        ImGui::Text("Artist: %s", metadata.getArtist().c_str());
        ImGui::Text("Album: %s", metadata.getAlbum().c_str());
        ImGui::Text("Genre: %s", metadata.getGenre().c_str());
        ImGui::Text("Duration: %d", metadata.getDuration());
        
        // Cho phép chỉnh sửa metadata
        static char trackName[128];
        strcpy(trackName, metadata.getTrackName().c_str());
        ImGui::InputText("Track Name", trackName, IM_ARRAYSIZE(trackName));
        
        static char artist[128];
        strcpy(artist, metadata.getArtist().c_str());
        ImGui::InputText("Artist", artist, IM_ARRAYSIZE(artist));
        
        static char album[128];
        strcpy(album, metadata.getAlbum().c_str());
        ImGui::InputText("Album", album, IM_ARRAYSIZE(album));
        
        if (ImGui::Button("Save Metadata")) {
            db.updateMetadata(mediaFiles[selectedIndex], trackName, artist, album);
        }
    }

    // Hiển thị danh sách phát
    ImGui::Separator();
    ImGui::Text("Playlists:");
    static std::vector<std::string> playlists;
    playlists = db.fetchMediaFiles();  // Lấy danh sách phát từ database

    static int selectedPlaylistIndex = 0;
    ImGui::BeginChild("PlaylistList", ImVec2(300, 200), true);
    for (int i = 0; i < playlists.size(); i++) {
        if (ImGui::Selectable(playlists[i].c_str(), selectedPlaylistIndex == i)) {
            selectedPlaylistIndex = i;  // Chọn playlist
        }
    }
    ImGui::EndChild();

    // Hiển thị các bài hát trong playlist được chọn
    ImGui::Separator();
    ImGui::Text("Songs in playlist: %s", playlists[selectedPlaylistIndex].c_str());
    static std::vector<std::string> songsInPlaylist;
    songsInPlaylist = db.fetchSongsInPlaylist(playlists[selectedPlaylistIndex]);
    
    ImGui::BeginChild("SongList", ImVec2(300, 200), true);
    for (const auto& song : songsInPlaylist) {
        ImGui::Text("%s", song.c_str());
    }
    ImGui::EndChild();

    ImGui::End();
}
