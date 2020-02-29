#include "core/scene_manager.hpp"
int main() {
    // The very sleek game loop
    // The map "entry point" is kinda hardcoded in here.
    // Either change to your liking or stick to defaults.
    SceneManager game("scenes/menu.tmx");

    // Run the game until it doesn't run anymore :-D
    while(game.run()) {}
    return 0;
}
