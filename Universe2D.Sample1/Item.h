#pragma once

namespace ItemID {
	enum Enum {
		����,
		// ����
		������,
		��ġ,
		�յ���,
		���,
		��,
		����,
		// ������
		��,
		������,
		�����ٱ�,
		��������,
		������,
		����,
		// �ǹ�
		��,
		���ۼ�,
		�칰,
		// ����ǰ
		���,
		����,
		Ȱ,
		ȭ��,
		������,
		Ư������
	};
}

class Item {
public:
	ItemID::Enum ID;

public:
	std::string Name;
	std::string Description;

public:
	Item()
		: ID(ItemID::����)
		, Name("������ �̸�")
		, Description("����") {};
	~Item() {};
};

