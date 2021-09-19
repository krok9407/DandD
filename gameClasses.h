#pragma once
#include "baseClasses.h"

class Warrior : virtual public Npc {
protected:
	int strange;
	string weapons;
public:
	Warrior() {
		warrior = true;
		wizard = false;
		paladin = false;
		health = 50;
		damage = 30;
		strange = 33;
	}
	void create() override {
		cout << endl;
		cout << "�� ������� �����" << endl << "������� ��� ���������\t";
		cin >> name;
		cout << endl;
		getStats();
		cout << "���� ���� - " << strange << endl;
	}
	void getWeapons() {
		cout << "�� ����� " << weapons << " � ����" << endl;
	}
	~Warrior() {
		if (warrior)
			cout << "���� " << name << " ��� � ��������" << endl;
	}
};

class Wizard : virtual public Npc {
protected:
	int intellect;
	string spell;
public:
	Wizard() {
		warrior = false;
		wizard = true;
		paladin = false;
		health = 35;
		damage = 55;
		intellect = 40;
		armor = 20;
		spell = "Fireball";
	}
	void create() override {
		cout << endl;
		cout << "�� ������� ���������" << endl << "������� ��� ���������\t";
		cin >> name;
		cout << endl;
		getStats();
		cout << "��� ��������� - " << intellect << endl;
	}
	void castSpell() {
		cout << "����������� ����������\t";
		cin >> spell;
		cout << endl;
		cout << spell << " ������������ �� ����������" << endl;
		cout << endl;
	}
	~Wizard() {
		if (wizard)
			cout << "��������� " << name << " ��������� ���" << endl;
	}
};

class Paladin : public Wizard, public Warrior {
public:
	Paladin() {
		warrior = false;
		wizard = false;
		paladin = true;
		health = 40;
		damage = 40;
		intellect = 30;
		armor = 120;
		strange = 30;
		spell = "HollyShock";
	}

	void create() override {
		cout << endl;
		cout << "�� ������� ��������" << endl << "������� ��� ���������\t";
		cin >> name;
		cout << endl;
		getStats();
		cout << "��� ��������� - " << intellect << endl;
		cout << "���� ���� - " << strange << endl;
	}
	~Paladin() {
		if (paladin)
			cout << name << " ���������� � ��������" << endl;
	}
};