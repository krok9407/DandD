#pragma once
#include "gameClasses.h"

class Horse : public Npc {
protected:
	int speed;
public:
	Horse() {
		health = 5;
		damage = 0;
		speed = 100;
	}
	void getSpeed() {
		cout << "���� �������� �� ���� ����� = " << speed << endl;
	}
};

class WarriorOnHorse : public Horse, public Warrior {
public:
	~WarriorOnHorse() {
		speed = 5;
		cout << "����� ������ ��������� ���������" << endl;
		cout << "���� �������� ��� ���� = " << speed << endl;
	}
};

class WizardOnHorse : public Horse, public Wizard {
public:
	~WizardOnHorse() {
		speed = 5;
		cout << "���� ������ ������������ � ����" << endl;
		cout << "���� �������� ��� ���� = " << speed << endl;
	}
};

class PaladinOnHorse : public Horse, public Paladin {
public:
	~PaladinOnHorse() {
		speed = 5;
		cout << "���� ������ ����������� �� ������" << endl;
		cout << "���� �������� ��� ���� = " << speed << endl;
	}
};
