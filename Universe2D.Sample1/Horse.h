#pragma once

class Horse : public Object {
public:
	Sprite* sprite;

public:
	// ��ȣ
	int Numebr;

	// ���׹̳�
	int Stemina;

	// �ӵ�
	int Speed;

	// ���� ���� �ӵ�
	int SpurtSpeed;

	// ������ ���� �ӵ�
	int LastSpurtSpeed;
	
public:
	Horse() {};
	virtual ~Horse() {};

public:

};