#include <iostream>
#include <ctime>
#include <stdio.h>
#include <windows.h>
#include "baseClasses.h"
#include "evil.h"
#include "gameClasses.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Warrior warrior;
	Wizard wizard;
	Paladin paladin;
	Player firstPlayer;
	cout << "Здравствуй, путник\nОтдохни, присядь у костра" << endl;
	cout << "Я вижу, что ты один из героев?" << endl;
	cout << "Скажи, кто ты?" << endl;
	cout << "(\t1 - Воин\n2 - Волшебник\n 3 - Палладин)" << endl;
	int choise;
	cin >> choise;
	switch (choise) {
	case 1:
	{
		firstPlayer.create(&warrior);
		warrior.getWeapons();
		break;
	}
	case 2:
	{
		firstPlayer.create(&wizard);
		break;
	}
	case 3:
	{
		firstPlayer.create(&paladin);
		break;
	}
	}
	cout << "Куда будем держать путь?" << endl;
	cout << "(\t1 - Королевство Бумбург \n2 - Направиться к пещерам\n3 - Осмотреться \n4 - Передохнуть)" << endl;
	int ways;
	cin >> ways;
	srand(time(NULL));
	int chance = rand() % 99 + 1; //от 1 до 100%
	int randHealth = rand() % 19 + 1; //случайное значение здоровья злодея
	int randDamage = rand() % 29 + 1; //случайное значение урона злодея
	Evil evil1("Злой кролик", randHealth, randDamage); //создаем случайную злого кролика
	randHealth = rand() % 19 + 1; //случайное значение здоровья злодея
	randDamage = rand() % 29 + 1; //случайное значение урона злодея
	Evil evil2("Фермер Антон", randHealth, randDamage); //создаем случайную Фермер Антон
	randHealth = rand() % 19 + 1; //случайное значение здоровья злодея
	randDamage = rand() % 29 + 1; //случайное значение урона злодея
	Evil evil3("Зелибоба из улицы Сезам", randHealth, randDamage); //создаем случайную Покемон Мяут
	randHealth = rand() % 19 + 1; //случайное значение здоровья злодея
	randDamage = rand() % 29 + 1; //случайное значение урона злодея
	Evil evil4("Покемон Мяут", randHealth, randDamage); //создаем случайную Зелибоба из улицы Сезам
	randHealth = rand() % 19 + 1; //случайное значение здоровья злодея
	randDamage = rand() % 29 + 1; //случайное значение урона злодея
	Evil evil5("Работники ТСЖ", randHealth, randDamage); //создаем случайного Работники ТСЖ
	switch (ways) {
	case 1: {
		cout << "Вы отправляетесь в путь\nПожалуйста подождите..." << endl;
		for (int i = 1; i < 6; i++) {
			Sleep(1000);
			cout << "Вы прошли " << 20 * i << "% пути" << endl;
			if (chance < 50) {
				if (i == 1) {
					evil1.getStats();
				}
				if (i == 2) {
					evil2.getStats();
				}
				if (i == 3) {
					evil3.getStats();
				}
				if (i == 4) {
					evil4.getStats();
				}
				if (i == 5) {
					evil5.getStats();
				}
				cout << "Ваша действия?" << endl;
				cout << "1 - вступить в бой\n2 - сбежать\n3 - попробовать договориться" << endl;
				int battle;
				cin >> battle;
				if (battle == 1) {
					int hitEvil;
					bool fight = true;
					int hitHero;
					if (choise == 1) {
						if (i == 1)
						{
							while (fight)
							{
								//бьет вас
								cout << endl;
								cout << "Вам нанесли урон = " << evil1.getDamage() << endl;
								hitEvil = warrior.getHealth() - evil1.getDamage();
								warrior.setHealth(hitEvil);
								cout << "Ваше здоровье = " << warrior.getHealth() << endl;
								//бьете вы
								cout << "Вы нанесли урон = " << warrior.getDamage() << endl;
								hitHero = evil1.getHealth() - warrior.getDamage();
								evil1.setHealth(hitHero);
								cout << "Здоровье противника = " << evil1.getHealth() << endl;
								if (warrior.getHealth() <= 0)
								{
									cout << "Вы погибли = " << endl;
									fight = false;
								}
								if (evil1.getHealth() <= 0)
								{
									cout << "Вы победили!" << endl;
									cout << "Желаете отдохнуть?\n1 - Да\n2 - Нет";
									int relax;
									cin >> relax;
									if (relax == 1) {
										cout << "Вы сели отдыхать\nПодождите 1 минуту до полного восстановления здоровья" << endl;
										Sleep(60000);
										warrior.setHealth(50 * warrior.getLvl());
										cout << "Ваше здоровье полностью восстановилось = " << warrior.getHealth() << "hp" << endl;
									}
									else {
										cout << "Вы продолжаете путь" << endl;
									}
									fight = false;
								}
							}
						}
					}
				}
				else if (battle == 2) {
					chance = rand() % 99 + 1;
					if (chance > 50) {
						cout << "Вы успешно убежали с поля боя" << endl;
					}
					else
					{
						cout << "вас догнали и вы вступаете в бой" << endl;
						int hitEvil;
						bool fight = true;
						int hitHero;
						if (choise == 1) {
							if (i == 1)
							{
								while (fight)
								{
									//бьет вас
									cout << endl;
									cout << "Вам нанесли урон = " << evil1.getDamage() << endl;
									hitEvil = warrior.getHealth() - evil1.getDamage();
									warrior.setHealth(hitEvil);
									cout << "Ваше здоровье = " << warrior.getHealth() << endl;
									//бьете вы
									cout << "Вы нанесли урон = " << warrior.getDamage() << endl;
									hitHero = evil1.getHealth() - warrior.getDamage();
									evil1.setHealth(hitHero);
									cout << "Здоровье противника = " << evil1.getHealth() << endl;
									if (warrior.getHealth() <= 0)
									{
										cout << "Вы погибли = " << endl;
										fight = false;
									}
									if (evil1.getHealth() <= 0)
									{
										cout << "Вы победили!" << endl;
										cout << "Желаете отдохнуть?\n1 - Да\n2 - Нет";
										int relax;
										cin >> relax;
										if (relax == 1) {
											cout << "Вы сели отдыхать\nПодождите 1 минуту до полного восстановления здоровья" << endl;
											Sleep(60000);
											warrior.setHealth(50 * warrior.getLvl());
											cout << "Ваше здоровье полностью восстановилось = " << warrior.getHealth() << "hp" << endl;
										}
										else {
											cout << "Вы продолжаете путь" << endl;
										}
										fight = false;
									}
								}
							}
						}
					}
				}
				else if (battle == 3) {
					int spendGold;
					if (i == 1) {
						cout << "купите и дайте кролику морковку\n(Потратить 5 золотых монет на морковку?)\n1 - да\n2 - нет" << endl;
						cin >> spendGold;
						if (spendGold == 1) {
							cout << "кролик довольно хрумкает морковку, а вы спокойно проходите дальше" << endl;
						}
						else if (spendGold == 2) {
							int hitEvil;
							bool fight = true;
							int hitHero;
							if (choise == 1) {
								if (i == 1)
								{
									while (fight)
									{
										//бьет вас
										cout << endl;
										cout << "Вам нанесли урон = " << evil1.getDamage() << endl;
										hitEvil = warrior.getHealth() - evil1.getDamage();
										warrior.setHealth(hitEvil);
										cout << "Ваше здоровье = " << warrior.getHealth() << endl;
										//бьете вы
										cout << "Вы нанесли урон = " << warrior.getDamage() << endl;
										hitHero = evil1.getHealth() - warrior.getDamage();
										evil1.setHealth(hitHero);
										cout << "Здоровье противника = " << evil1.getHealth() << endl;
										if (warrior.getHealth() <= 0)
										{
											cout << "Вы погибли = " << endl;
											fight = false;
										}
										if (evil1.getHealth() <= 0)
										{
											cout << "Вы победили!" << endl;
											cout << "Желаете отдохнуть?\n1 - Да\n2 - Нет";
											int relax;
											cin >> relax;
											if (relax == 1) {
												cout << "Вы сели отдыхать\nПодождите 1 минуту до полного восстановления здоровья" << endl;
												Sleep(60000);
												warrior.setHealth(50 * warrior.getLvl());
												cout << "Ваше здоровье полностью восстановилось = " << warrior.getHealth() << "hp" << endl;
											}
											else {
												cout << "Вы продолжаете путь" << endl;
											}
											fight = false;
										}
									}
								}
							}
						}
					}
					if (i == 2) {
						cout << "Помочь вспахать огород фермеру?\n(Длительность ожилания = 2 минуты)\n1 - да\n2 - нет" << endl;
						cin >> spendGold;
						if (spendGold == 1) {
							cout << "Вы начинаете копать грядки" << endl;
							Sleep(60000);
							cout << "Вы сажаете картошку" << endl;
							Sleep(60000);
							cout << "Фермер доволен вашей работой\nВы продолжаете свой путь\n";
						}
						else if (spendGold == 2) {
							int hitEvil;
							bool fight = true;
							int hitHero;
							if (choise == 1) {
								while (fight)
								{
									//бьет вас
									cout << endl;
									cout << "Вам нанесли урон = " << evil2.getDamage() << endl;
									hitEvil = warrior.getHealth() - evil2.getDamage();
									warrior.setHealth(hitEvil);
									cout << "Ваше здоровье = " << warrior.getHealth() << endl;
									//бьете вы
									cout << "Вы нанесли урон = " << warrior.getDamage() << endl;
									hitHero = evil2.getHealth() - warrior.getDamage();
									evil2.setHealth(hitHero);
									cout << "Здоровье противника = " << evil2.getHealth() << endl;
									if (warrior.getHealth() <= 0)
									{
										cout << "Вы погибли = " << endl;
										fight = false;
									}
									if (evil2.getHealth() <= 0)
									{
										cout << "Вы победили!" << endl;
										cout << "Желаете отдохнуть?\n1 - Да\n2 - Нет";
										int relax;
										cin >> relax;
										if (relax == 1) {
											cout << "Вы сели отдыхать\nПодождите 1 минуту до полного восстановления здоровья" << endl;
											Sleep(60000);
											warrior.setHealth(50 * warrior.getLvl());
											cout << "Ваше здоровье полностью восстановилось = " << warrior.getHealth() << "hp" << endl;
										}
										else {
											cout << "Вы продолжаете путь" << endl;
										}
										fight = false;
									}
								}
							}
						}
					}
					if (i == 3) {
						cout << "Зелибоба хочет проверить ваши знания по ОБЖ\n(ответьте правильно на 3 вопроса)\n1 - согласиться\n2 - отказаться" << endl;
						cin >> spendGold;
						bool correct = true;
						if (spendGold == 1) {
							cout << "Первый вопрос\nГде следует находиться в автобусе, если в нем нет свободных сидячих мест?" << endl;
							cout << "1) рядом с подножкой;\n2) в проходе у выхода;\n3) в центральном проходе;\n4) там, где есть место;\n";
							int answer;
							cin >> answer;
							if (answer == 2) {
								cout << "Правильно! Следующий вопрос.\n";
								cout << "Что необходимо предпринять человеку, если он всё-таки вошёл в лифт с незнакомцем?\n";
								cout << "1) не следует ничего предпринимать, вести себя как обычно;\n2) заговорить с незнакомцем;\nв) нажать кнопки «диспетчер» и «стоп», после ответа диспечера нажать кнопку нужного этажа, завязать разговор с диспетчером и ехать на свой этаж;\n4) постоянно наблюдать за действиями незнакомца.\n";
								cin >> answer;
								if (answer == 3) {
									cout << "Правильно! Последний вопрос.\n";
									cout << "Как необходимо действовать, если подошёл к остановке пустой автобус (троллейбус, трамвай)?\n";
									cout << "1) не следует садиться;\n2) следует сесть на заднее сидение;\n3) следует сесть, где понравится;\n4) следует сесть поближе к водителю.\n";
									cin >> answer;
									if (answer == 1) {
										cout << "Вы успешно ответили на все вопросы и можете продолжать свой путь дальше\n";
									}
									else
									{
										correct = false;
									}
								}
								else
								{
									correct = false;
								}
							}
							else
							{
								correct = false;
							}
						}
						if (spendGold == 2 || correct == false) {
							int hitEvil;
							bool fight = true;
							int hitHero;
							if (choise == 1) {
								while (fight)
								{
									//бьет вас
									cout << endl;
									cout << "Вам нанесли урон = " << evil3.getDamage() << endl;
									hitEvil = warrior.getHealth() - evil3.getDamage();
									warrior.setHealth(hitEvil);
									cout << "Ваше здоровье = " << warrior.getHealth() << endl;
									//бьете вы
									cout << "Вы нанесли урон = " << warrior.getDamage() << endl;
									hitHero = evil3.getHealth() - warrior.getDamage();
									evil3.setHealth(hitHero);
									cout << "Здоровье противника = " << evil3.getHealth() << endl;
									if (warrior.getHealth() <= 0)
									{
										cout << "Вы погибли = " << endl;
										fight = false;
									}
									if (evil3.getHealth() <= 0)
									{
										cout << "Вы победили!" << endl;
										cout << "Желаете отдохнуть?\n1 - Да\n2 - Нет";
										int relax;
										cin >> relax;
										if (relax == 1) {
											cout << "Вы сели отдыхать\nПодождите 1 минуту до полного восстановления здоровья" << endl;
											Sleep(60000);
											warrior.setHealth(50 * warrior.getLvl());
											cout << "Ваше здоровье полностью восстановилось = " << warrior.getHealth() << "hp" << endl;
										}
										else {
											cout << "Вы продолжаете путь" << endl;
										}
										fight = false;
									}
								}
							}
						}
					}
					if (i == 4) {
						cout << "У вас есть шанс попасть в покемона покеболом,\n чтобы получить его в качестве напаркника\n(стоимость 1 броска = 250 монет)\n1 - да\n2 - нет" << endl;
						bool miss = false;
						cin >> spendGold;
						if (spendGold == 1) {
							warrior.setGold(warrior.getGold() - 250);
							chance = rand() % 99 + 1;
							if (chance < 20) {
								cout << "Вы поймали покемона\nтеперь он служит вам\nваш урон увеличился на 20 едениц\n";
								warrior.setDamage(warrior.getDamage() + 20);
								cout << "Теперь ваш урон составляет = " << warrior.getDamage() << endl;
							}
							else {
								cout << "Вы промахнулись покеболом\nПокемон вас заметил и напал\n";
								miss = true;
							}
						}
						if (spendGold == 2 || miss == true) {
							int hitEvil;
							bool fight = true;
							int hitHero;
							if (choise == 1) {
								while (fight)
								{
									//бьет вас
									cout << endl;
									cout << "Вам нанесли урон = " << evil2.getDamage() << endl;
									hitEvil = warrior.getHealth() - evil2.getDamage();
									warrior.setHealth(hitEvil);
									cout << "Ваше здоровье = " << warrior.getHealth() << endl;
									//бьете вы
									cout << "Вы нанесли урон = " << warrior.getDamage() << endl;
									hitHero = evil2.getHealth() - warrior.getDamage();
									evil2.setHealth(hitHero);
									cout << "Здоровье противника = " << evil2.getHealth() << endl;
									if (warrior.getHealth() <= 0)
									{
										cout << "Вы погибли = " << endl;
										fight = false;
									}
									if (evil2.getHealth() <= 0)
									{
										cout << "Вы победили!" << endl;
										cout << "Желаете отдохнуть?\n1 - Да\n2 - Нет";
										int relax;
										cin >> relax;
										if (relax == 1) {
											cout << "Вы сели отдыхать\nПодождите 1 минуту до полного восстановления здоровья" << endl;
											Sleep(60000);
											warrior.setHealth(50 * warrior.getLvl());
											cout << "Ваше здоровье полностью восстановилось = " << warrior.getHealth() << "hp" << endl;
										}
										else {
											cout << "Вы продолжаете путь" << endl;
										}
										fight = false;
									}
								}
							}
						}
					}
					if (i == 5) {
					}
				}
			}
			chance = rand() % 99 + 1;
		}
		break;
	}
	case 2: {
		if (chance < 70) {
		}
		break;
	}
	case 3: {
		if (chance < 10) {
		}
		break;
	}
	case 4: {
		break;
	}
	}
	return 0;
}
