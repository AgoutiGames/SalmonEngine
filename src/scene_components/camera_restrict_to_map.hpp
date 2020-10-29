#ifndef CAMERA_RESTRICT_TO_MAP_HPP_INCLUDED
#define CAMERA_RESTRICT_TO_MAP_HPP_INCLUDED

#include "core/game_scene.hpp"

class SceneManager;

class CameraRestrictToMap : public virtual GameScene {
    public:

    protected:
        void init(salmon::PixelDimensions map_dimensions);
        void set_crop(int l, int r, int u, int d);
        // Add members here
        void update();
    private:
        salmon::PixelDimensions m_map_dimensions;
        int m_crop_left = 0;
        int m_crop_right = 0;
        int m_crop_up = 0;
        int m_crop_down = 0;
};

#endif // CAMERA_RESTRICT_TO_MAP_HPP_INCLUDED
