#pragma once

class SampleScene1 : public Scene
{
private:
    Sprite* sprite1;
    Sprite* sprite2;

public:
    SampleScene1();
    ~SampleScene1();

    void Update(float deltaTime);
    void Render();
};