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
		cout << "Вы создали война" << endl << "Введите имя персонажа\t";
		cin >> name;
		cout << endl;
		getStats();
		cout << "Ваша сила - " << strange << endl;
	}
	void getWeapons() {
		cout << "Вы взяли " << weapons << " в руки" << endl;
	}
	~Warrior() {
		if (warrior)
			cout << "Воин " << name << " пал в сражение" << endl;
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
		cout << "Вы создали Волшебник" << endl << "Введите имя персонажа\t";
		cin >> name;
		cout << endl;
		getStats();
		cout << "Ваш интеллект - " << intellect << endl;
	}
	void castSpell() {
		cout << "Произнесите заклинание\t";
		cin >> spell;
		cout << endl;
		cout << spell << " используется на противнике" << endl;
		cout << endl;
	}
	~Wizard() {
		if (wizard)
			cout << "Волшебник " << name << " испускает дух" << endl;
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
		cout << "Вы создали Паладина" << endl << "Введите имя персонажа\t";
		cin >> name;
		cout << endl;
		getStats();
		cout << "Ваш интеллект - " << intellect << endl;
		cout << "Ваша сила - " << strange << endl;
	}
	~Paladin() {
		if (paladin)
			cout << name << " отправился к праотцам" << endl;
	}
};