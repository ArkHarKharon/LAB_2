#include <iostream>
#include <vector>
#include <Windows.h>
#include <ctime>
#include <random>

#include "enums.h"
#include "termcolor.hpp"
#include "prototypes.h"



int random(int min, int max)
{
	int number = min + rand() % (max - min + 1);
	return number;
}

void print_matrix(std::vector<int> &main_vector,int len)
{
	std::cout << "\t\t\t    ---------------�������---------------\n\n\t";
	int counter{ 0 };
	for (auto element : main_vector)
	{
		if (counter == len)
		{
			std::cout << "\n\n\t";
			counter = 0;
		}

		if (element > 99)
			std::cout << element << "\t";
		else if (element > 9 and element < 100)
			std::cout << element << " \t";
		else if (element < 10)
			std::cout << " " << element << " \t";
		counter++;
	}
	std::cout << "\n\n\t\t\t    ---------------�������---------------\n\n\n\n";
}

void print_show(std::vector<int>& main_vector, int len, int index)
{
		std::cout << "\t\t\t    ---------------�������---------------\n\n\t";
		int counter{ 0 };
		for (auto element : main_vector)
		{
			if (main_vector.at(index) == element)
				std::cout << termcolor::green;

			if (counter == len)
			{
				std::cout << "\n\n\t";
				counter = 0;
			}

			if (element > 99)
				std::cout << element << "\t";
			else if (element > 9 and element < 100)
				std::cout << element << " \t";
			else if (element < 10)
				std::cout << " " << element << " \t";
			std::cout << termcolor::reset;
			counter++;
		}
		std::cout << "\n\n\t\t\t    ---------------�������---------------\n\n\n\n";
}


void random_set(std::vector<int> &main_vector, int min, int max)
{
	for (int index{ 0 }; index < main_vector.size(); index++)
		main_vector.at(index) = random(min,max);
}

void main_menu(std::vector<int>&main_vector)
{
	std::cout
		<< "\t� ���� ���� �� �� ������� �� ��������, ��, ���� ��, ������� ������������ ��������.\n"
		<< "�� ������ ��������,���, ������ ���� �� �� ������� ����� ����������\n"
		<< "����� ����, �� ������ ����(-a): ������� ��� ����\n"
		<< "�� ���� ���� ��: �� ������� ���(-___-), � ����� ��-�������, ����� �� �������)))";
	Sleep(7000);
	system("cls");

	std::cout << "\t� ���� ��, � ���������: ����� ���� �������)))";
	Sleep(3000);
	system("cls");

	std::cout
		<< "��� ������ ����� ���������� � ���������� ��������\n"
		<< "�� ������, ���������� ���������� ������� �� �������� ������, ��� �������� �����";
	Sleep(4000);
	system("cls");
	
	std::cout
		<< "�� ������ �������� � ���� ���������� ��� ������ -- � �� ���� ������������ ����\n"
		<< "�� �� ������(-��) �������� -- ���� ���������� � ����� �������� (��������) ��� �����\n"
		<< "����� ��������, ��������� �������� ��� ������������� ��������";
	Sleep(6000);
	system("cls");

	std::cout
		<< "�� �����,������ ���������� � ��������\n"
		<< "����� ����� � ������� ������� ����� ������ (���������� 10�10): ";

	int len, width;
	std::cin >> len >> width;
	system("cls");

	int volume{ len * width };
	main_vector.resize(volume);

	std::cout
		<< "������� " << len << "x" << width << " ���� ������!\n"
		<< "�� ������� �������� �� �����, �� ����� �� �������������� � ����!";
	Sleep(5000);
	system("cls");

	std::cout << "����, �������� ���������, ����� ��������))";
	Sleep(2000);
	system("cls");

		
	random_set(main_vector, 1, 999);
	int answer{};
	do
	{
		print_matrix(main_vector, len);

		std::cout
			<< "\t\t\t    ----------------����----------------\n"
			<< "1) ���� ������ ��������\n"
			<< "2) ���������\n"
			<< "3) �����\n";
	} while (1);
}