#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "core/game_character.hpp"
#include "sound.hpp"

class GameScene;

class Button : public GameCharacter {
    public:
        Button(salmon::Actor actor, GameScene* scene);
        virtual Button* create(salmon::Actor actor, GameScene* scene) const override {return new Button(actor,scene);}

        void init() override;
        void update() override;
        std::string get_type() const override {return type;}

        static const char* type;
    protected:
        // Add members here
        std::string m_id;

    private:
        static const bool good;
};


#endif // BUTTON_HPP_INCLUDED
