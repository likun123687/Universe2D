#include "Precompiled.h"
#include "Scene.h"
#include "Application.h"

Scene::Scene()
{
	// ȭ�� ũ�� ����
	SetSize({
		static_cast<float>(Application::GetInstance()->GetWidth()),
		static_cast<float>(Application::GetInstance()->GetHeight())
	});
}