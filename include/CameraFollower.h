#ifndef CAMERAFOLLOWER_H
#define CAMERAFOLLOWER_H

#include "Component.h"

/**
 * @brief Flags a component. Follow the camera.
 * 
 */
class CameraFollower : public Component {
    public:
        CameraFollower(GameObject& go);

        void Update(float dt);

        void Render();

        bool Is(std::string type);
};

#endif

