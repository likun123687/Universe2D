 #pragma once

class SampleScene1 : public Scene
{
private:

public:
    SampleScene1();
    ~SampleScene1();

	static Scene* Create();

public:
	bool Initialize() override;

public:
    void Update(float deltaTime) override;
    void Render() override;
};