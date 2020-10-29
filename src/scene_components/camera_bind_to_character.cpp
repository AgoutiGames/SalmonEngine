#include "scene_components/camera_bind_to_character.hpp"

#include "camera.hpp"

void CameraBindToCharacter::update() {
    if(target != nullptr && is_alive(target)) {
        salmon::Transform& cam_trans = get_camera().get_transform();
        salmon::Point char_center = target->get_transform().get_relative(0.5,0.5);
        cam_trans.set_pos(0.5,0.5,char_center.x,char_center.y);
    }
}
