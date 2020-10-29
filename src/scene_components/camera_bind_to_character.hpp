#ifndef CAMERA_BIND_TO_CHARACTER_HPP_INCLUDED
#define CAMERA_BIND_TO_CHARACTER_HPP_INCLUDED

#include "core/game_scene.hpp"
#include "core/game_character.hpp"

class SceneManager;

class CameraBindToCharacter : public virtual GameScene {
    public:

    protected:
        void update();
        // Add members here
        GameCharacter* target = nullptr;

    private:

};

#endif // CAMERA_BIND_TO_CHARACTER_HPP_INCLUDED
