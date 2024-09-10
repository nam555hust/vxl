#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <GLFW/glfw3.h>           // Include GLFW header
#include "MusicPlayerUI.hpp"
#include "AudioService.hpp"
#include "imgui.h"
#include "imgui_impl_glfw.h"      // Include ImGui GLFW binding
#include "imgui_impl_opengl3.h"   // Include ImGui OpenGL binding
#include <sqlite3.h>
int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        return -1;
    }
    // Database database("music_player.db");
    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Music Player", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Initialize ImGui
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.DisplaySize = ImVec2(1280, 720); // Example display size

    // Setup ImGui binding
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    sf::Music music;
    AudioService audioService(music);

    // Create MusicPlayerUI instance
    MusicPlayUI playerUI(audioService);
    // MediaLibrary mediaLibrary;
    // Main loop to render UI and handle logic
    while (!glfwWindowShouldClose(window)) {
        // Poll and handle events
        glfwPollEvents();

        // Start a new ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Render the music player UI
        playerUI.RenderUI("C:\\Users\\Admin\\Downloads");

        // End the ImGui frame and render to screen
        ImGui::Render();

        // Clear the screen
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Render ImGui draw data
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Swap buffers
        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
