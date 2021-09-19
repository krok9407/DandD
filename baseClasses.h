#pragma once
#include <iostream>
using namespace std;
class Npc {
protected:
	int health;
	int damage;
	int armor;
	int gold;
	string name;
	bool warrior;
	bool wizard;
	bool paladin;
	int lvl;
public:
	Npc() {
		health = 10;
		damage = 5;
		armor = 2;
		lvl = 1;
		gold = 1000;
	}
	void lvlUp() {
		this->lvl++;
	}
	int getLvl() {
		return lvl;
	}
	int getDamage() {
		return damage;
	}
	void setDamage(int damage) {
		this->damage = damage;
	}
	int getHealth() {
		return health;
	}
	void setHealth(int health) {
		this->health = health;
	}
	int getGold() {
		return gold;
	}
	void setGold(int gold) {
		this->gold = gold;
	}
	virtual void create() { }
	virtual void getStats() {
		cout << "Ваше имя " << name << endl;
		cout << "Ваш уровень - " << lvl << endl;
		cout << "Ваш урон - " << damage << endl;
		cout << "Ваше здоровье - " << health << endl;
		cout << "Ваша броня - " << armor << endl;
	}
};

class Player {
public:
	void create(Npc* player) {
		player->create();
	}
};