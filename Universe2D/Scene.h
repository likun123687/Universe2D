#pragma once
#include "Object.h"

class Scene : public virtual Object
{
public:
    Scene() {};
    virtual ~Scene() {};

public:
    void Render() override { Object::Render(); }
    void Update(float deltaTime) override {}
};
