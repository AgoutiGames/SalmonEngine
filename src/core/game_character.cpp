#include "core/game_character.hpp"

#include <iostream>

#include "core/game_scene.hpp"

const char* GameCharacter::type_string = "type";

GameCharacter::GameCharacter(salmon::Actor actor, GameScene* scene) : salmon::Actor(actor), m_scene{scene} {}

bool GameCharacter::put(bool& var, std::string name) {
    salmon::DataBlock data = get_data();
    if(data.check_val_bool(name)) {var = data.get_val_bool(name);}
    else {return false;}
    return true;
}
bool GameCharacter::put(int& var, std::string name) {
    salmon::DataBlock data = get_data();
    if(data.check_val_int(name)) {var = data.get_val_int(name);}
    else {return false;}
    return true;
}
bool GameCharacter::put(float& var, std::string name) {
    salmon::DataBlock data = get_data();
    if(data.check_val_float(name)) {var = data.get_val_float(name);}
    else {return false;}
    return true;
}
bool GameCharacter::put(std::string& var, std::string name) {
    salmon::DataBlock data = get_data();
    if(data.check_val_string(name)) {var = data.get_val_string(name);}
    else {return false;}
    return true;
}

GameCharacter* GameCharacter::parse_character(salmon::Actor actor, GameScene* scene) {
    std::string type = actor.get_data().get_val_string(type_string);
    if(get_dict().find(type) == get_dict().end()) {
        std::cerr << "Unknown Game Character type: \"" << type << "\" supplied!\n";
        return nullptr;
    }
    else {
        return get_dict().at(type)->create(actor, scene);
    }
}

std::map<std::string, GameCharacter*>& GameCharacter::get_dict() {
    static std::map<std::string, GameCharacter*> character_dict;
    return character_dict;
}

bool GameCharacter::kill() {
    if(m_dead) {return false;}
    else {
        m_dead = true;
        m_scene->remove_character(this);
        return true;
    }
}
