#pragma once

enum Colors		//�� ���� ������������ static_cast � ����
{
	BLUE = 1,
	BRIGHT_BLUE,
	YELLOW,
	BRIGHT_YELLOW,
	MAGENTA,
	CYAN,
	DEFAULT,
};


enum Menu		//�� ���� ������������ static_cast � ����
{
	SEARCHING = 1,
	SETTINGS,
	EXIT,
};

enum Settings	//�� ���� ������������ static_cast � ����
{
	LANGUAGE = 1,
	COLOR,
	GENERATE,
	RESIZE,
	MAIN_MENU
};

enum Searching
{
	INCREM = 1,
	JUMP,
	INDEX,
	BINARY,
	MENU
};