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
	cout << "����������, ������\n�������, ������� � ������" << endl;
	cout << "� ����, ��� �� ���� �� ������?" << endl;
	cout << "�����, ��� ��?" << endl;
	cout << "(\t1 - ����\n2 - ���������\n 3 - ��������)" << endl;
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
	cout << "���� ����� ������� ����?" << endl;
	cout << "(\t1 - ����������� ������� \n2 - ����������� � �������\n3 - ����������� \n4 - �����������)" << endl;
	int ways;
	cin >> ways;
	srand(time(NULL));
	int chance = rand() % 99 + 1; //�� 1 �� 100%
	int randHealth = rand() % 19 + 1; //��������� �������� �������� ������
	int randDamage = rand() % 29 + 1; //��������� �������� ����� ������
	Evil evil1("���� ������", randHealth, randDamage); //������� ��������� ����� �������
	randHealth = rand() % 19 + 1; //��������� �������� �������� ������
	randDamage = rand() % 29 + 1; //��������� �������� ����� ������
	Evil evil2("������ �����", randHealth, randDamage); //������� ��������� ������ �����
	randHealth = rand() % 19 + 1; //��������� �������� �������� ������
	randDamage = rand() % 29 + 1; //��������� �������� ����� ������
	Evil evil3("�������� �� ����� �����", randHealth, randDamage); //������� ��������� ������� ����
	randHealth = rand() % 19 + 1; //��������� �������� �������� ������
	randDamage = rand() % 29 + 1; //��������� �������� ����� ������
	Evil evil4("������� ����", randHealth, randDamage); //������� ��������� �������� �� ����� �����
	randHealth = rand() % 19 + 1; //��������� �������� �������� ������
	randDamage = rand() % 29 + 1; //��������� �������� ����� ������
	Evil evil5("��������� ���", randHealth, randDamage); //������� ���������� ��������� ���
	switch (ways) {
	case 1: {
		cout << "�� ������������� � ����\n���������� ���������..." << endl;
		for (int i = 1; i < 6; i++) {
			Sleep(1000);
			cout << "�� ������ " << 20 * i << "% ����" << endl;
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
				cout << "���� ��������?" << endl;
				cout << "1 - �������� � ���\n2 - �������\n3 - ����������� ������������" << endl;
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
								//���� ���
								cout << endl;
								cout << "��� ������� ���� = " << evil1.getDamage() << endl;
								hitEvil = warrior.getHealth() - evil1.getDamage();
								warrior.setHealth(hitEvil);
								cout << "���� �������� = " << warrior.getHealth() << endl;
								//����� ��
								cout << "�� ������� ���� = " << warrior.getDamage() << endl;
								hitHero = evil1.getHealth() - warrior.getDamage();
								evil1.setHealth(hitHero);
								cout << "�������� ���������� = " << evil1.getHealth() << endl;
								if (warrior.getHealth() <= 0)
								{
									cout << "�� ������� = " << endl;
									fight = false;
								}
								if (evil1.getHealth() <= 0)
								{
									cout << "�� ��������!" << endl;
									cout << "������� ���������?\n1 - ��\n2 - ���";
									int relax;
									cin >> relax;
									if (relax == 1) {
										cout << "�� ���� ��������\n��������� 1 ������ �� ������� �������������� ��������" << endl;
										Sleep(60000);
										warrior.setHealth(50 * warrior.getLvl());
										cout << "���� �������� ��������� �������������� = " << warrior.getHealth() << "hp" << endl;
									}
									else {
										cout << "�� ����������� ����" << endl;
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
						cout << "�� ������� ������� � ���� ���" << endl;
					}
					else
					{
						cout << "��� ������� � �� ��������� � ���" << endl;
						int hitEvil;
						bool fight = true;
						int hitHero;
						if (choise == 1) {
							if (i == 1)
							{
								while (fight)
								{
									//���� ���
									cout << endl;
									cout << "��� ������� ���� = " << evil1.getDamage() << endl;
									hitEvil = warrior.getHealth() - evil1.getDamage();
									warrior.setHealth(hitEvil);
									cout << "���� �������� = " << warrior.getHealth() << endl;
									//����� ��
									cout << "�� ������� ���� = " << warrior.getDamage() << endl;
									hitHero = evil1.getHealth() - warrior.getDamage();
									evil1.setHealth(hitHero);
									cout << "�������� ���������� = " << evil1.getHealth() << endl;
									if (warrior.getHealth() <= 0)
									{
										cout << "�� ������� = " << endl;
										fight = false;
									}
									if (evil1.getHealth() <= 0)
									{
										cout << "�� ��������!" << endl;
										cout << "������� ���������?\n1 - ��\n2 - ���";
										int relax;
										cin >> relax;
										if (relax == 1) {
											cout << "�� ���� ��������\n��������� 1 ������ �� ������� �������������� ��������" << endl;
											Sleep(60000);
											warrior.setHealth(50 * warrior.getLvl());
											cout << "���� �������� ��������� �������������� = " << warrior.getHealth() << "hp" << endl;
										}
										else {
											cout << "�� ����������� ����" << endl;
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
						cout << "������ � ����� ������� ��������\n(��������� 5 ������� ����� �� ��������?)\n1 - ��\n2 - ���" << endl;
						cin >> spendGold;
						if (spendGold == 1) {
							cout << "������ �������� �������� ��������, � �� �������� ��������� ������" << endl;
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
										//���� ���
										cout << endl;
										cout << "��� ������� ���� = " << evil1.getDamage() << endl;
										hitEvil = warrior.getHealth() - evil1.getDamage();
										warrior.setHealth(hitEvil);
										cout << "���� �������� = " << warrior.getHealth() << endl;
										//����� ��
										cout << "�� ������� ���� = " << warrior.getDamage() << endl;
										hitHero = evil1.getHealth() - warrior.getDamage();
										evil1.setHealth(hitHero);
										cout << "�������� ���������� = " << evil1.getHealth() << endl;
										if (warrior.getHealth() <= 0)
										{
											cout << "�� ������� = " << endl;
											fight = false;
										}
										if (evil1.getHealth() <= 0)
										{
											cout << "�� ��������!" << endl;
											cout << "������� ���������?\n1 - ��\n2 - ���";
											int relax;
											cin >> relax;
											if (relax == 1) {
												cout << "�� ���� ��������\n��������� 1 ������ �� ������� �������������� ��������" << endl;
												Sleep(60000);
												warrior.setHealth(50 * warrior.getLvl());
												cout << "���� �������� ��������� �������������� = " << warrior.getHealth() << "hp" << endl;
											}
											else {
												cout << "�� ����������� ����" << endl;
											}
											fight = false;
										}
									}
								}
							}
						}
					}
					if (i == 2) {
						cout << "������ �������� ������ �������?\n(������������ �������� = 2 ������)\n1 - ��\n2 - ���" << endl;
						cin >> spendGold;
						if (spendGold == 1) {
							cout << "�� ��������� ������ ������" << endl;
							Sleep(60000);
							cout << "�� ������� ��������" << endl;
							Sleep(60000);
							cout << "������ ������� ����� �������\n�� ����������� ���� ����\n";
						}
						else if (spendGold == 2) {
							int hitEvil;
							bool fight = true;
							int hitHero;
							if (choise == 1) {
								while (fight)
								{
									//���� ���
									cout << endl;
									cout << "��� ������� ���� = " << evil2.getDamage() << endl;
									hitEvil = warrior.getHealth() - evil2.getDamage();
									warrior.setHealth(hitEvil);
									cout << "���� �������� = " << warrior.getHealth() << endl;
									//����� ��
									cout << "�� ������� ���� = " << warrior.getDamage() << endl;
									hitHero = evil2.getHealth() - warrior.getDamage();
									evil2.setHealth(hitHero);
									cout << "�������� ���������� = " << evil2.getHealth() << endl;
									if (warrior.getHealth() <= 0)
									{
										cout << "�� ������� = " << endl;
										fight = false;
									}
									if (evil2.getHealth() <= 0)
									{
										cout << "�� ��������!" << endl;
										cout << "������� ���������?\n1 - ��\n2 - ���";
										int relax;
										cin >> relax;
										if (relax == 1) {
											cout << "�� ���� ��������\n��������� 1 ������ �� ������� �������������� ��������" << endl;
											Sleep(60000);
											warrior.setHealth(50 * warrior.getLvl());
											cout << "���� �������� ��������� �������������� = " << warrior.getHealth() << "hp" << endl;
										}
										else {
											cout << "�� ����������� ����" << endl;
										}
										fight = false;
									}
								}
							}
						}
					}
					if (i == 3) {
						cout << "�������� ����� ��������� ���� ������ �� ���\n(�������� ��������� �� 3 �������)\n1 - �����������\n2 - ����������" << endl;
						cin >> spendGold;
						bool correct = true;
						if (spendGold == 1) {
							cout << "������ ������\n��� ������� ���������� � ��������, ���� � ��� ��� ��������� ������� ����?" << endl;
							cout << "1) ����� � ���������;\n2) � ������� � ������;\n3) � ����������� �������;\n4) ���, ��� ���� �����;\n";
							int answer;
							cin >> answer;
							if (answer == 2) {
								cout << "���������! ��������� ������.\n";
								cout << "��� ���������� ����������� ��������, ���� �� ��-���� ����� � ���� � �����������?\n";
								cout << "1) �� ������� ������ �������������, ����� ���� ��� ������;\n2) ���������� � �����������;\n�) ������ ������ ���������� � �����, ����� ������ ��������� ������ ������ ������� �����, �������� �������� � ����������� � ����� �� ���� ����;\n4) ��������� ��������� �� ���������� ����������.\n";
								cin >> answer;
								if (answer == 3) {
									cout << "���������! ��������� ������.\n";
									cout << "��� ���������� �����������, ���� ������� � ��������� ������ ������� (����������, �������)?\n";
									cout << "1) �� ������� ��������;\n2) ������� ����� �� ������ �������;\n3) ������� �����, ��� ����������;\n4) ������� ����� ������� � ��������.\n";
									cin >> answer;
									if (answer == 1) {
										cout << "�� ������� �������� �� ��� ������� � ������ ���������� ���� ���� ������\n";
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
									//���� ���
									cout << endl;
									cout << "��� ������� ���� = " << evil3.getDamage() << endl;
									hitEvil = warrior.getHealth() - evil3.getDamage();
									warrior.setHealth(hitEvil);
									cout << "���� �������� = " << warrior.getHealth() << endl;
									//����� ��
									cout << "�� ������� ���� = " << warrior.getDamage() << endl;
									hitHero = evil3.getHealth() - warrior.getDamage();
									evil3.setHealth(hitHero);
									cout << "�������� ���������� = " << evil3.getHealth() << endl;
									if (warrior.getHealth() <= 0)
									{
										cout << "�� ������� = " << endl;
										fight = false;
									}
									if (evil3.getHealth() <= 0)
									{
										cout << "�� ��������!" << endl;
										cout << "������� ���������?\n1 - ��\n2 - ���";
										int relax;
										cin >> relax;
										if (relax == 1) {
											cout << "�� ���� ��������\n��������� 1 ������ �� ������� �������������� ��������" << endl;
											Sleep(60000);
											warrior.setHealth(50 * warrior.getLvl());
											cout << "���� �������� ��������� �������������� = " << warrior.getHealth() << "hp" << endl;
										}
										else {
											cout << "�� ����������� ����" << endl;
										}
										fight = false;
									}
								}
							}
						}
					}
					if (i == 4) {
						cout << "� ��� ���� ���� ������� � �������� ���������,\n ����� �������� ��� � �������� ����������\n(��������� 1 ������ = 250 �����)\n1 - ��\n2 - ���" << endl;
						bool miss = false;
						cin >> spendGold;
						if (spendGold == 1) {
							warrior.setGold(warrior.getGold() - 250);
							chance = rand() % 99 + 1;
							if (chance < 20) {
								cout << "�� ������� ��������\n������ �� ������ ���\n��� ���� ���������� �� 20 ������\n";
								warrior.setDamage(warrior.getDamage() + 20);
								cout << "������ ��� ���� ���������� = " << warrior.getDamage() << endl;
							}
							else {
								cout << "�� ������������ ���������\n������� ��� ������� � �����\n";
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
									//���� ���
									cout << endl;
									cout << "��� ������� ���� = " << evil2.getDamage() << endl;
									hitEvil = warrior.getHealth() - evil2.getDamage();
									warrior.setHealth(hitEvil);
									cout << "���� �������� = " << warrior.getHealth() << endl;
									//����� ��
									cout << "�� ������� ���� = " << warrior.getDamage() << endl;
									hitHero = evil2.getHealth() - warrior.getDamage();
									evil2.setHealth(hitHero);
									cout << "�������� ���������� = " << evil2.getHealth() << endl;
									if (warrior.getHealth() <= 0)
									{
										cout << "�� ������� = " << endl;
										fight = false;
									}
									if (evil2.getHealth() <= 0)
									{
										cout << "�� ��������!" << endl;
										cout << "������� ���������?\n1 - ��\n2 - ���";
										int relax;
										cin >> relax;
										if (relax == 1) {
											cout << "�� ���� ��������\n��������� 1 ������ �� ������� �������������� ��������" << endl;
											Sleep(60000);
											warrior.setHealth(50 * warrior.getLvl());
											cout << "���� �������� ��������� �������������� = " << warrior.getHealth() << "hp" << endl;
										}
										else {
											cout << "�� ����������� ����" << endl;
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
