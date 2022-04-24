#pragma once

#include "../defines.hpp"
#include <list>
#include <unordered_map>
#include "../helpers/AnimatedVariable.hpp"
#include "../helpers/BezierCurve.hpp"

class CAnimationManager {
public:

    CAnimationManager();

    void            tick();
    void            addBezierWithName(std::string, const Vector2D&, const Vector2D&);
    void            removeAllBeziers();

    std::list<CAnimatedVariable*> m_lAnimatedVariables;

private:
    bool            deltaSmallToFlip(const Vector2D& a, const Vector2D& b);
    bool            deltaSmallToFlip(const CColor& a, const CColor& b);
    bool            deltaSmallToFlip(const float& a, const float& b);
    bool            deltazero(const Vector2D& a, const Vector2D& b);
    bool            deltazero(const CColor& a, const CColor& b);
    bool            deltazero(const float& a, const float& b);

    std::unordered_map<std::string, CBezierCurve> m_mBezierCurves;
};

inline std::unique_ptr<CAnimationManager> g_pAnimationManager;