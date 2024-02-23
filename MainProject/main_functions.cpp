#include <iostream>
#include <vector>
#include <Windows.h>
#include <ctime>
#include <random>
#include <math.h>
#include <algorithm>
#include <chrono>

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

	std::cout
		<< termcolor::reset
		<< "\t\t\t    ---------------�������---------------\n\n\t";

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

void set_color(Colors& color)
{
	switch (color)
	{
	case(Colors::BLUE):			 std::cout << termcolor::blue; break;
	case(Colors::BRIGHT_BLUE):   std::cout << termcolor::bright_blue; break;
	case(Colors::YELLOW):		 std::cout << termcolor::yellow; break;
	case(Colors::BRIGHT_YELLOW): std::cout << termcolor::bright_yellow; break;
	case(Colors::MAGENTA):		 std::cout << termcolor::magenta; break;
	case(Colors::CYAN):			 std::cout << termcolor::cyan; break;
	case(Colors::DEFAULT):		 std::cout << termcolor::reset; break;

	}
}

void print_matrix(std::vector<int>& main_vector, int len, int index)
{

	
		std::cout << termcolor::reset << "\t\t\t    ---------------�������---------------\n\n\t";
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

void greetings()
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

}

void loading(int time) 
{
	std::cout << "� ��������, ��������";
	Sleep(time/4);
	system("cls");

	std::cout << "� ��������, ��������.";
	Sleep(time/4);
	system("cls");

	std::cout << "� ��������, ��������..";
	Sleep(time/4);
	system("cls");

	std::cout << "� ��������, ��������...";
	Sleep(time/4);
	system("cls");
}

int increm_search(std::vector<int> const &main_vector,int element)
{
	for (int index{ 0 }; index < main_vector.size(); index++)
	{
		if (main_vector.at(index) == element)
			return index;
		else
			return -1;
	}
}

int jump_search(std::vector<int> const &main_vector, int element)
{
	int step = sqrt(main_vector.size()) ;
	int last_step{ 0 };

	while (main_vector.at(min(step, main_vector.size())) < element)
	{
		last_step = step;
		step += sqrt(main_vector.size());
		if (last_step >= main_vector.size())
			return -1;
	}
	while (main_vector.at(last_step) < element)
	{
		last_step++;
		if (last_step == min(step, main_vector.size()))
			return -1;
	}
	if (main_vector.at(last_step) == element)
		return last_step;
}

int binary_search(std::vector<int> const &main_vector, int element) //�����������
{
	int left{ 0 };
	int right= (main_vector.size() - 1) ;
	int middle{0};
	int step{ 0 };
	bool flag{ false };

	while (left <= right)
	{
		step++;
		middle = (left + right) / 2;
		if (element == main_vector.at(middle))
		{
			flag = true;
			return middle;
		}
		if (element < main_vector.at(middle))
			right = middle - 1;
		else
			left = middle + 1;
	}
}

int binary_search(std::vector<int> const& main_vector, int element, int left, int right,int &step)
{
	step++;
	int middle{ (left + right) / 2 };
	if (left > right)  
		return -1;
	if (element == main_vector.at(middle)) 
		return middle;
	if (element < main_vector.at(middle))    
		return   binary_search(main_vector,element, left, middle - 1,step);
	else           
		return   binary_search(main_vector, element, left, middle + 1, step);
}

void main_menu(std::vector<int>& main_vector, Colors& color)
{
	//greetings();

	std::cout
		<< "�� �����,������ ���������� � ��������\n"
		<< "����� ����� � ������� ������� ����� ������ (���������� 10�10): ";

	int len, width;
	std::cin >> len >> width;
	system("cls");

	int volume{ len * width };
	main_vector.resize(volume);

	std::cout
		<< "������� " << len << "x" << width << " ���� �������!\n"
		<< "�� ������� �������� �� �����, �� ����� �� �������������� � ����!";
	Sleep(5000);
	system("cls");

	std::cout << "����, �������� ���������, ����� ��������))";
	Sleep(2000);
	system("cls");


	random_set(main_vector, 1, 999);

	int answer_menu{ 0 };
	int answer_settings{ 0 };
	int answer_color{ 0 };
	int answer_searching{ 0 };

	int new_len{}; int new_width{};
	int& temp_len{ len };
	int& temp_width{ width };
	int& new_volume{ volume };

	int index_increm{};
	int index_jump{};
	int index_binary{};

	int element_increm{};
	int element_jump{};
	int element_binary{};

	std::chrono::steady_clock::time_point start_increm{};
	std::chrono::steady_clock::time_point start_jump{};
	std::chrono::steady_clock::time_point start_binary{};

	std::chrono::steady_clock::time_point finish_increm{};
	std::chrono::steady_clock::time_point finish_jump{};
	std::chrono::steady_clock::time_point finish_binary{};

	std::chrono::duration<double, std::micro> duration_increm{};
	std::chrono::duration<double, std::micro> duration_jump{};
	std::chrono::duration<double, std::micro> duration_binary{};

	do
	{
		system("cls");

		print_matrix(main_vector, len);
		set_color(color);

		std::cout
			<< "1) ���� ������ ��������\n"
			<< "2) ���������\n"
			<< "3) �����\n\n"
			<< "�����: ";
		std::cin >> answer_menu;
		system("cls");

		switch (answer_menu)
		{
		case(SEARCHING):
			system("cls");
			std::cout << "�������� ����������...";
			//std::sort(begin(main_vector),end(main_vector));
			Sleep(2000);
			system("cls");
			loading(4000);
			system("cls");

			do
			{
				std::cout
					<< "\t\t\t    ----------------�����----------------\n"
					<< "1) � ���� ����� �������� � ������� ����������������� ������\n"
					<< "2) � ���� ����� �������� � ������� ������ ��������\n"
					<< "3) � ���� ����� �������� � ������� �������-����������������� ������\n"
					<< "4) � ���� ����� �������� � ������� ��������� ������ \n"
					<< "5) � ���� ��������� � ������� ����\n\n"
					<< "�����: ";

				std::cin >> answer_searching;
				system("cls");
				switch (answer_searching)
				{
				case(INCREM):
					std::cout
						<< "\t\t\t    ----------------���������������� �����----------------\n"
						<< "������� �������: ";
					std::cin >> element_increm;
					system("cls");
					std::cout << "�������� �����...";
					Sleep(2000);
					system("cls");
					loading(4000);

					start_increm = std::chrono::high_resolution_clock::now() ;
					index_increm = increm_search(main_vector,element_increm) ;
					finish_increm = std::chrono::high_resolution_clock::now() ;

					duration_increm = (finish_increm - start_increm);

					if (index_increm != -1)
					{
						print_matrix(main_vector, len, index_increm);
						std::cout
							<< "������� " << main_vector.at(index_increm) << " ��������� �� ������� "
							<< index_increm << ".\n���������������� ����� ����� " << duration_increm.count() << "���";
						break;
					}
					else
					{
						std::cout << "������� " << element_increm << " �� ��� ���������!";
						Sleep(3000);
						system("cls");
						break;
					}

				case(JUMP):
					std::cout
						<< "\t\t\t    ----------------����� ��������----------------\n"
						<< "������� �������: ";
					std::cin >> element_jump;
					system("cls");
					std::cout << "��������� �����...";
					Sleep(2000);
					system("cls");
					loading(4000);

					start_jump = std::chrono::high_resolution_clock::now() ;
					index_jump = jump_search(main_vector,element_jump) ;
					finish_jump = std::chrono::high_resolution_clock::now() ;

					duration_jump = (finish_jump - start_jump);

					if (index_jump != -1)
					{
						print_matrix(main_vector, len, index_jump);
						std::cout
							<< "������� " << main_vector.at(index_jump) << " ��������� �� ������� "
							<< index_jump << ".\n����� �������� ����� " << duration_jump.count() << "���";
						break;
					}
					else
					{
						std::cout << "������� " << element_jump << " �� ��� ���������!";
						Sleep(3000);
						system("cls");
						break;
					}

				case(BINARY):
					std::cout
						<< "\t\t\t    ----------------�������� �����----------------\n"
						<< "������� �������: ";
					std::cin >> element_binary;
					system("cls");
					std::cout << "��������� �����...";
					Sleep(2000);
					system("cls");
					loading(4000);

					start_binary = std::chrono::high_resolution_clock::now();
					index_binary = binary_search(main_vector,element_binary);
					finish_binary = std::chrono::high_resolution_clock::now();

					duration_binary = (finish_binary - start_binary);

					if (index_binary != -1)
					{
						print_matrix(main_vector, len, index_binary);
						std::cout
							<< "������� " << main_vector.at(index_binary) << " ��������� �� ������� "
							<< index_binary << ".\n�������� ����� ����� " << duration_binary.count() << "���";
						Sleep(4000);
						system("cls");
						break;
					}
					else
					{
						std::cout << "������� " << element_binary << " �� ��� ���������!";
						Sleep(3000);
						system("cls");
						break;
					}
				case(INDEX):
					std::cout << "������-���������������� ����� ����(������) � ����������...";
					Sleep(3000);
					system("cls");
						break;
				case(MENU): break;
				}
			}while (answer_searching != MENU);
			break;
		case(SETTINGS):
			do
			{
				std::cout
					<< "\t\t\t    ----------------���������----------------\n"
					<< "1) � ���� �������� ����\n"
					<< "2) � ���� �������� ���� ����\n"
					<< "3) � ���� ������������� ����� �������� ��������� �������\n"
					<< "4) � ���� �������� ������ ������� (�� ���� ����� � ����)\n"
					<< "5) � ���� ��������� � �������� ����\n\n"
					<< "�����: ";

				std::cin >> answer_settings;

				switch (answer_settings)
				{
				case(LANGUAGE):
					system("cls");
					loading(4000);
					std::cout << "�������, ���� ����, � �� ����� �����)))))";
					Sleep(3000);
					system("cls");
					break;

				case(COLOR):
					system("cls");

					std::cout
						<< "\t\t\t    ----------------����� �����----------------\n"
						<< "������ ����� ����:\n"
						<< "1) �����\n"
						<< "2) �������(��)\n"
						<< "3) ������\n"
						<< "4) ������-������\n"
						<< "5) ���������\n"
						<< "6) ��������\n"
						<< "7) ������� ����\n"
						<< "�����: ";

					std::cin >> answer_color;

					switch (answer_color)
						{
					case(BLUE):				 color = BLUE; break;
					case(BRIGHT_BLUE):		 color = BRIGHT_BLUE; break;
					case(YELLOW):			 color = YELLOW; break;
					case(BRIGHT_YELLOW):	 color = BRIGHT_YELLOW; break;
					case(MAGENTA):			 color = MAGENTA; break;
					case(CYAN):				 color = CYAN; break;
					case(DEFAULT):			 color = DEFAULT; break;
					}

					system("cls");
					loading(4000);
					set_color(color);
					std::cout << "������!";
					Sleep(3000);
					system("cls");
					break;

				case(GENERATE):
					system("cls");
					loading(4000);
					random_set(main_vector, 1, 999);
					std::cout << "������!";
					Sleep(3000);
					system("cls");
					break;

				case(RESIZE):
					system("cls");
					std::cout
						<< "\t\t\t    ----------------��������� �������----------------\n"
						<< "�������� ������� ����� ������������!\n"
						<< "����� ����� ����� � ������ ������� ����� ������: ";
					std::cin >> new_len >> new_width;

					temp_len = new_len;
					temp_width = new_width;
					new_volume = new_len * new_width;

					main_vector.resize(new_volume);
					random_set(main_vector, 1, 999);

					system("cls");
					loading(4000);
					std::cout << "������!";
					system("cls");
					break;

				case(MAIN_MENU):
					std::cout << termcolor::green << "�������� ���!" << termcolor::reset;
					break;
				}
			} while (answer_settings != MAIN_MENU);
			
		}
	}while (answer_menu != EXIT);
}