#include "Precompiled.h"
#include "AutoReleasePool.h"

#include "Reference.h"

AutoReleasePool::AutoReleasePool()
{
	m_ManagedObjectList.reserve(128);
}
AutoReleasePool::~AutoReleasePool()
{
	Clear();
}

void AutoReleasePool::AddObject(Reference* object)
{
	m_ManagedObjectList.push_back(object);
}

void AutoReleasePool::Clear()
{
	// ���ο� ����Ʈ ������ ���� ������ ��ȯ
	std::vector<Reference*> releaseObjectList;

	releaseObjectList.swap(m_ManagedObjectList);

	for (const auto& obj : releaseObjectList)
	{
		obj->Release();
	}
}

bool AutoReleasePool::Contains(Reference* object)
{
	auto iterator = std::find(std::begin(m_ManagedObjectList), std::end(m_ManagedObjectList), object);
	if (iterator == std::end(m_ManagedObjectList))
		return false;

	return true;
}
