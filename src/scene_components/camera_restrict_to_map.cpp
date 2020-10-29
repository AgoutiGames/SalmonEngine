#include "scene_components/camera_restrict_to_map.hpp"

void CameraRestrictToMap::init(salmon::PixelDimensions map_dimensions) {
    m_map_dimensions = map_dimensions;
}

void CameraRestrictToMap::set_crop(int l, int r, int u, int d) {
    m_crop_left = l;
    m_crop_right = r;
    m_crop_up = u;
    m_crop_down = d;
}

void CameraRestrictToMap::update() {
    salmon::Transform& cam_transform = get_camera().get_transform();
    salmon::Point up_left_corner = cam_transform.get_relative(0,0);
    salmon::Point lower_right_corner = cam_transform.get_relative(1,1);
    // Check if map is less wide than the effective camera frame
    if( static_cast<float>(m_map_dimensions.w) - m_crop_left - m_crop_right < cam_transform.get_dimensions().w ) {
        // Center the camera horizontally relative to map
        salmon::Point c_center = cam_transform.get_relative(0.5,0.5);
        float map_x_center = ((m_map_dimensions.w - m_crop_right) / 2) + m_crop_left;
        cam_transform.move_pos(map_x_center - c_center.x,0);
    }
    else {
        // Check horizontal borders
        if(up_left_corner.x < m_crop_left) {
            cam_transform.move_pos(m_crop_left - up_left_corner.x,0);
        }
        else if(lower_right_corner.x > static_cast<float>(m_map_dimensions.w)- m_crop_right) {
            cam_transform.move_pos((static_cast<float>(m_map_dimensions.w)- m_crop_right) - lower_right_corner.x,0);
        }
    }

    // Check if map is less high than the effective camera frame
    if( static_cast<float>(m_map_dimensions.h) - m_crop_up - m_crop_down < cam_transform.get_dimensions().h ) {
        // Center the camera vertically relative to map
        salmon::Point c_center = cam_transform.get_relative(0.5,0.5);
        float map_y_center = ((m_map_dimensions.h - m_crop_down) / 2) + m_crop_up;
        cam_transform.move_pos(0,map_y_center - c_center.y);
    }
    else {
        // Check vertical borders
        if(up_left_corner.y < m_crop_up) {
            cam_transform.move_pos(0,m_crop_up - up_left_corner.y);
        }
        else if(lower_right_corner.y > static_cast<float>(m_map_dimensions.h) - m_crop_down) {
            cam_transform.move_pos(0,(static_cast<float>(m_map_dimensions.h)- m_crop_down) - lower_right_corner.y);
        }
    }
}
