//
// Created by Binh Nguyen Thanh on 5/5/26.
//

#ifndef ASTEROID_SPLINECAMERACOMPONENT_H
#define ASTEROID_SPLINECAMERACOMPONENT_H
#include <vector>

#include "CameraComponent.h"

struct Spline
{
    // Control points for spline
    // (Requires n+2 points where n is number
    // of points in segment)
    std::vector<Vector3> mControlPoints;
    // Given spline segment where startIdx = P1,
    // compute position based on t value
    Vector3 Compute(size_t startIdx, float t) const;
    // Returns number of control points
    size_t GetNumPoints() const { return mControlPoints.size(); }
};

class SplineCameraComponent : public CameraComponent{
public:
    SplineCameraComponent(class Actor* actor);
    void Update(float deltaTime) override;
    void Restart();

    void SetSpeed(float speed) { mSpeed = speed; }
    void SetPaused(bool paused) { mPaused = paused; }
    void SetSpline(const Spline& spline) { mPath = spline; }

private:
    Spline mPath;
    size_t mIndex;
    float mT;
    // Amount t changes/sec
    float mSpeed;
    // Whether to move the camera long the path
    bool mPaused;
};


#endif //ASTEROID_SPLINECAMERACOMPONENT_H