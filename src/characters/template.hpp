#ifndef TEMPLATE_HPP_INCLUDED
#define TEMPLATE_HPP_INCLUDED

#include "core/game_character.hpp"

class GameScene;

class Template : public GameCharacter {
    public:
        Template(salmon::Actor actor, GameScene* scene);
        virtual Template* create(salmon::Actor actor, GameScene* scene) const override {return new Template(actor,scene);}

        void init() override;
        void update() override;
        std::string get_type() const override {return type;}

        static const char* type;
    protected:
        // Add members here
        
    private:
        static const bool good;
};


#endif // TEMPLATE_HPP_INCLUDED
