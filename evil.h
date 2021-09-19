#pragma once
#include "baseClasses.h"

class Evil : public Npc {
public:
	Evil(string name) {
		this->name = name;
		health = -1;
		damage = -1;
	}
	Evil(string name, int health) {
		this->name = name;
		this->health = health;
		damage = -1;
	}
	Evil(string name, int health, int damage) {
		this->name = name;
		this->health = health;
		this->damage = damage;
	}
	void getStats() override {
		cout << endl;
		cout << "�� ��� ����� " << name << endl;
		if (health >= 0 && damage < 0) {
			cout << "�������� - " << health << endl;
		}
		if (health < 0 && damage >= 0) {
			cout << "���� - " << damage << endl;
		}
		if (health >= 0 && damage >= 0) {
			cout << "�������� - " << health << endl;
			cout << "���� - " << damage << endl;
		}
	}
};