#ifndef FINAL_PROJECT_PLANE_H
#define FINAL_PROJECT_PLANE_H

#include "cinder/gl/gl.h"
#include "bird.h"
#include <vector>

namespace flappybird {
    class Plane {
    public:
        Plane() = default;
        
        Plane(const glm::vec2 &point1, const glm::vec2 &point2, const glm::vec2 &point3,
              const glm::vec2 &velocity);
        
        void UpdatePosition();
        
        void SetVelocity(const glm::vec2 &velocity);
        
        void StopMoving();
        
        const glm::vec2& GetPoint1() const;

        const glm::vec2& GetPoint2() const;

        const glm::vec2& GetPoint3() const;

        const ci::Color GetColor() const;
        
        void HandleBirdCollision(Bird &bird);
        
        bool HasBirdHit(Bird &bird);
    
    private:
        glm::vec2 point1_;
        glm::vec2 point2_;
        glm::vec2 point3_;
        glm::vec2 velocity_;
        
        ci::Color color_;
    };
}
#endif//FINAL_PROJECT_PLANE_H
