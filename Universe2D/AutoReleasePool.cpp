#include "Precompiled.h"
#include "AutoReleasePool.h"
#include "Object.h"

AutoReleasePool::AutoReleasePool()
{
	m_ManagedObjectList.reserve(128);
}
AutoReleasePool::~AutoReleasePool()
{
	Clear();
}

void AutoReleasePool::AddObject(Object* object)
{
	m_ManagedObjectList.push_back(object);
}

void AutoReleasePool::Clear()
{
	// ���ο� ����Ʈ ������ ���� ������ ��ȯ
	std::vector<Object*> managedObjectList;
	managedObjectList.swap(m_ManagedObjectList);

	for (const auto& obj : managedObjectList)
	{
		obj->Release();
	}
}

bool AutoReleasePool::Contains(Object* object)
{
	auto iterator = std::find(std::begin(m_ManagedObjectList), std::end(m_ManagedObjectList), object);
	if (iterator == std::end(m_ManagedObjectList))
		return false;

	return true;
}
