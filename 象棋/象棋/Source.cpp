#include <iostream>
#include<stdio.h>
#include <string>
#include <vector>
#include <sstream>
#include <windows.h>
#include <conio.h>
#include<fstream>
#include"Back.h"
using namespace std;
bool whosTurn = false;//true�O�� false�O��
vector<COORD>path;
vector<Back>back;
//�ѽL���
//�����ܰ�
string screen[24] = { "|---------------------------------------------------------------------------------------|\n",
 "| |-   �� �p �� ��   -|  1    2    3    4    5    6    7    8    9 |------------------| |\n",
 "| |                   |  | -- | -- | -- | -- | -- | -- | -- | -- | |                  | |\n",
 "| |                   |  |    |    |    |  \\ | /  |    |    |    | |                  | |\n",
 "| |                   |  | -- | -- | -- | -- | -- | -- | -- | -- | |                  | |\n",
 "| |                   |  |    |    |    |  / | \\  |    |    |    | |                  | |\n",
 "| |                   |  | -- | -- | -- | -- | -- | -- | -- | -- | |                  | |\n",
 "| |                   |  |    |    |    |    |    |    |    |    | |                  | |\n",
 "| |                   |  | -- | -- | -- | -- | -- | -- | -- | -- | |                  | |\n",
 "| |                   |  |    |    |    |    |    |    |    |    | |                  | |\n",
 "| |                   |  | -- | -- | -- | -- | -- | -- | -- | -- | |                  | |\n",
 "| |                   |  |            ���e          �~��         | |                  | |\n",
 "| |                   |  | -- | -- | -- | -- | -- | -- | -- | -- | |------------------| |\n",
 "| |                   |  |    |    |    |    |    |    |    |    | |��V�䲾��        | |\n",
 "| |                   |  | -- | -- | -- | -- | -- | -- | -- | -- | |enter���w�Ѥl   | |\n",
 "| |                   |  |    |    |    |    |    |    |    |    | |s���x�s�C��       | |\n",
 "| |                   |  | -- | -- | -- | -- | -- | -- | -- | -- | |r�䭫�s�}�l�C��   | |\n",
 "| |                   |  |    |    |    |  \\ | /  |    |    |    | |b�䷴��           | |\n",
 "| |                   |  | -- | -- | -- | -- | -- | -- | -- | -- | |                  | |\n",
 "| |                   |  |    |    |    |  / | \\  |    |    |    | |������   ���ͺ�   | |\n",
 "| |                   |  | -- | -- | -- | -- | -- | -- | -- | -- | |����P   ���L��   | |\n",
 "| |                   | �E   �K   �C   ��   ��   �|   �T   �G   �@ |�s�@              | |\n",
 "| |-------------------|                                            |------------------| |\n",
 "|---------------------------------------------------------------------------------------|\n" };
int map[10][9] = { 4, 5, 3, 2, 1, 2, 3, 5, 4,
   0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 6, 0, 0, 0, 0, 0, 6, 0,
   7, 0, 7, 0, 7, 0, 7, 0, 7,
   0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0,
  14, 0,14, 0,14, 0,14, 0,14,
   0,13, 0, 0, 0, 0, 0,13, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0,
  11,12,10, 9, 8, 9,10,12,11 };
//��X��
//�i�H�ܰ�
string tmp_screen[24];

//�x�s���ʺX�l�����p
vector<string> move_data;

//�T�{�H�Ѫ��W�r
string check_chess(int chess)
{
	string tmp;
	switch (chess)
	{
	case 1:
		tmp = "�N";
		break;
	case 2:
		tmp = "�h";
		break;
	case 3:
		tmp = "�H";
		break;
	case 4:
		tmp = "��";
		break;
	case 5:
		tmp = "��";
		break;
	case 6:
		tmp = "�]";
		break;
	case 7:
		tmp = "��";
		break;
	case 8:
		tmp = "��";
		break;
	case 9:
		tmp = "�h";
		break;
	case 10:
		tmp = "��";
		break;
	case 11:
		tmp = "��";
		break;
	case 12:
		tmp = "�X";
		break;
	case 13:
		tmp = "��";
		break;
	case 14:
		tmp = "�L";
		break;
	default:
		break;
	}
	return tmp;
}

//�T�{�H�ѩҦb���y�Эn�p�����
//�� �E ~ �@
//�� �� ~ ��
string check_chess_location(int location, bool is_red)
{
	string tmp;
	switch (location)
	{
	case 1:
		tmp = (is_red ? "�E" : "��");
		break;
	case 2:
		tmp = (is_red ? "�K" : "��");
		break;
	case 3:
		tmp = (is_red ? "�C" : "��");
		break;
	case 4:
		tmp = (is_red ? "��" : "��");
		break;
	case 5:
		tmp = (is_red ? "��" : "��");
		break;
	case 6:
		tmp = (is_red ? "�|" : "��");
		break;
	case 7:
		tmp = (is_red ? "�T" : "��");
		break;
	case 8:
		tmp = (is_red ? "�G" : "��");
		break;
	case 9:
		tmp = (is_red ? "�@" : "��");
		break;
	default:
		break;
	}
	return tmp;
}

string check_walk(int walk, bool is_red)
{
	string tmp;
	switch (walk)
	{
	case 1:
		tmp = (is_red ? "�@" : "��");
		break;
	case 2:
		tmp = (is_red ? "�G" : "��");
		break;
	case 3:
		tmp = (is_red ? "�T" : "��");
		break;
	case 4:
		tmp = (is_red ? "�|" : "��");
		break;
	case 5:
		tmp = (is_red ? "��" : "��");
		break;
	case 6:
		tmp = (is_red ? "��" : "��");
		break;
	case 7:
		tmp = (is_red ? "�C" : "��");
		break;
	case 8:
		tmp = (is_red ? "�K" : "��");
		break;
	case 9:
		tmp = (is_red ? "�E" : "��");
		break;
	default:
		break;
	}
	return tmp;
}

int read_Chess(int o_x, int o_y)
{
	return map[(o_y - 2) / 2][(o_x - 24) / 5];
}
//�u�n��J�L�b�}�C�����Ӧ�m
//�M�Ჾ�ʨ���ӷs��m
//�|���A��o�ন�H�ѥΪ��y��
//�M��s��move�̭�
void add_Move(int o_x, int o_y, int new_x, int new_y)
{
	Back b;
	b.chessName = read_Chess(o_x, o_y);
	b.ox = (o_x - 24) / 5;
	b.oy = (o_y - 2) / 2;
	b.nx = (new_x - 24) / 5;
	b.ny = (new_y - 2) / 2;
	b.eatenChess = read_Chess(new_x, new_y);
	b.eox = (new_x - 24) / 5;
	b.eoy = (new_y - 2) / 2;

	back.push_back(b);

	int output_x = (o_x - 24) / 5 + 1;

	int chess = map[(o_y - 2) / 2][output_x - 1];
	map[(o_y - 2) / 2][output_x - 1] = 0;
	map[(new_y - 2) / 2][(new_x - 24) / 5] = chess;//���|

	stringstream ss;
	ss << move_data.size() + 1;
	bool is_red;
	if (chess < 8)
	{
		ss << " �� : ";
		is_red = false;
	}
	else
	{
		ss << " �� : ";
		is_red = true;
	}
	ss << check_chess(chess);
	//x 24 y 2

	ss << check_chess_location(output_x, is_red);



	int output_y = (new_y - o_y) / 2;
	if (is_red)
		output_y *= -1;
	if (output_y == 0)
	{
		ss << "��";
		output_x = ((new_x - 24) / 5) + 1;
		ss << check_walk(output_x, is_red);
		move_data.push_back(ss.str());
		return;
	}
	else if (output_y > 0)
		ss << "�i";
	else if (output_y < 0)
	{
		ss << "�h";
		output_y *= -1;
	}
	if (o_x != new_x)
		ss << check_chess_location((new_x - 24) / 5 + 1, is_red);
	else
		ss << check_walk(output_y, is_red);
	ss << " ";
	move_data.push_back(ss.str());

	return;
}

void output_Turn()
{
	int output_x = 71, output_y = 2;
	string who;
	HANDLE hin;
	DWORD WriteWord;
	COORD pos;

	hin = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//��J�ܬ۹�}�C��m
	bool turn = whosTurn;
	if (turn)
	{
		who = "�¦��";
		SetConsoleTextAttribute(hConsole, 11);
	}
	else
	{
		who = "�����";
		SetConsoleTextAttribute(hConsole, 12);
	}
	pos.X = output_x;
	pos.Y = output_y;
	SetConsoleCursorPosition(hin, pos);
	cout << "���� ";
	cout << who;
	turn = !turn;
}



void output_Move()
{
	//�_�l�y��
	int move_y = 2;
	int move_x = 4;

	//�첾�ʸ�ƪ�����
	int move_data_size = move_data.size();
	//�W�L20�����u��J��20��,�qstart_output��X
	int start_output = move_data_size > 20 ? move_data_size - 20 : 0;

	HANDLE hin;
	DWORD WriteWord;
	COORD pos;

	hin = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	//��J�ܬ۹�}�C��m
	bool turn = whosTurn;
	for (int i = move_data_size - 1; i >= start_output; i--)
	{
		if (turn)
			SetConsoleTextAttribute(hConsole, 12);
		else
			SetConsoleTextAttribute(hConsole, 15);

		pos.X = move_x;
		pos.Y = move_y + i - start_output;
		SetConsoleCursorPosition(hin, pos);
		cout << move_data[i];
		turn = !turn;
	}

}

void output_chess()
{
	//x 24 y 2
	int move_y = 2;
	int move_x = 24;
	HANDLE hin;
	DWORD WriteWord;
	COORD pos;

	hin = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (map[j][i] != 0)
			{
				string s = check_chess(map[j][i]);
				if (map[j][i] < 8)
					SetConsoleTextAttribute(hConsole, 7 * 16 + 8);
				else
					SetConsoleTextAttribute(hConsole, 7 * 16 + 12);
				pos.X = move_x + (i * 5);
				pos.Y = move_y + j * 2;
				SetConsoleCursorPosition(hin, pos);
				cout << s[0];
				cout << s[1];
			}

		}
	}
	SetConsoleTextAttribute(hConsole, 7);
}

void output()
{
	system("CLS");
	// �e���_��
	for (int i = 0; i < 24; i++)
		tmp_screen[i] = screen[i];
	//��X�Ԫp
	HANDLE hin;
	DWORD WriteWord;
	COORD pos;

	hin = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 90; j++)
		{

			if (j >= 24 && j <= 66 && i >= 1 && i <= 21)
			{
				SetConsoleTextAttribute(hConsole, 7 * 16);
			}
			else if(j >= 67 && j <= 86 && i >= 1 && i <= 21)
			{
				SetConsoleTextAttribute(hConsole, 15 * 16);
			}
			else if (j >= 67 && j <= 86 && i >= 12 && i <= 21)
			{
				SetConsoleTextAttribute(hConsole, 7);
			}
			else
			{
				SetConsoleTextAttribute(hConsole, 7);
			}
			cout << tmp_screen[i][j];
		}
	}
	//���@��
	output_Turn();
	output_chess();
	int pathSize = path.size();
	for (int i = 0; i < pathSize; i++)
	{
		SetConsoleTextAttribute(hConsole, 23);
		pos.X = path[i].X * 5 + 24;
		pos.Y = path[i].Y * 2 + 2;
		SetConsoleCursorPosition(hin, pos);
		string s = check_chess(map[path[i].Y][path[i].X]);
		if (s != "")
		{
			cout << s[0];
			cout << s[1];
		}
		else
		{
			cout << tmp_screen[pos.Y][pos.X];
			cout << tmp_screen[pos.Y][pos.X + 1];
		}

	}
	SetConsoleTextAttribute(hConsole, 7);
	output_Move();
}
void output_esc() {}
void moveRule(int chess, int x, int y)
{
	x = (x - 24) / 5;
	y = (y - 2) / 2;
	path.clear();
	//���X
	if (chess == 12)
	{
		//�W�k
		if (x + 1 <= 8 && y - 2 >= 0)
		{
			if (map[y - 2][x + 1] == 0 || map[y - 2][x + 1] <= 7)
			{
				if (map[y - 1][x] == 0)
				{
					COORD tmp;
					tmp.X = x + 1;
					tmp.Y = y - 2;
					path.push_back(tmp);
				}
			}
		}
		//�k�W
		if (x + 2 <= 8 && y - 1 >= 0)
		{
			if (map[y - 1][x + 2] == 0 || map[y - 1][x + 2] <= 7) {
				if (map[y][x + 1] == 0)
				{
					COORD tmp;
					tmp.X = x + 2;
					tmp.Y = y - 1;
					path.push_back(tmp);
				}
			}
		}
		//�W��
		if (x - 1 >= 0 && y - 2 >= 0)
		{
			if (map[y - 2][x - 1] == 0 || map[y - 2][x - 1] <= 7) {
				if (map[y - 1][x] == 0)
				{
					COORD tmp;
					tmp.X = x - 1;
					tmp.Y = y - 2;
					path.push_back(tmp);
				}
			}
		}
		//���W
		if (x - 2 >= 0 && y - 1 >= 0)
		{
			if (map[y - 1][x - 2] == 0 || map[y - 1][x - 2] <= 7) {
				if (map[y][x - 1] == 0)
				{
					COORD tmp;
					tmp.X = x - 2;
					tmp.Y = y - 1;
					path.push_back(tmp);
				}
			}
		}
		//���U
		if (x - 2 >= 0 && y + 1 <= 9)
		{
			if (map[y + 1][x - 2] == 0 || map[y + 1][x - 2] <= 7) {
				if (map[y][x - 1] == 0)
				{
					COORD tmp;
					tmp.X = x - 2;
					tmp.Y = y + 1;
					path.push_back(tmp);
				}
			}
		}
		//�U��
		if (x - 1 >= 0 && y + 2 <= 9)
		{
			if (map[y + 2][x - 1] == 0 || map[y + 2][x - 1] <= 7) {
				if (map[y + 1][x] == 0)
				{
					COORD tmp;
					tmp.X = x - 1;
					tmp.Y = y + 2;
					path.push_back(tmp);
				}
			}
		}
		//�U�k
		if (x + 1 <= 8 && y + 2 <= 9)
		{
			if (map[y + 2][x + 1] == 0 || map[y + 2][x + 1] <= 7) {
				if (map[y + 1][x] == 0)
				{
					COORD tmp;
					tmp.X = x + 1;
					tmp.Y = y + 2;
					path.push_back(tmp);
				}
			}
		}
		//�k�U
		if (x + 2 <= 8 && y + 1 <= 9)
		{
			if (map[y + 1][x + 2] == 0 || map[y + 1][x + 2] <= 7) {
				if (map[y][x + 1] == 0)
				{
					COORD tmp;
					tmp.X = x + 2;
					tmp.Y = y + 1;
					path.push_back(tmp);
				}
			}
		}

	}

	//�°�
	else if (chess == 5)
	{
		//�W�k
		if (x + 1 <= 8 && y - 2 >= 0)
		{
			if (map[y - 2][x + 1] == 0)
			{
				if (map[y - 1][x] == 0)
				{
					COORD tmp;
					tmp.X = x + 1;
					tmp.Y = y - 2;
					path.push_back(tmp);
				}
			}
			if (map[y - 2][x + 1] > 7 && map[y - 2][x + 1] <= 14)
			{
				if (map[y - 1][x] == 0)
				{
					COORD tmp;
					tmp.X = x + 1;
					tmp.Y = y - 2;
					path.push_back(tmp);
				}
			}
		}
		//�k�W
		if (x + 2 <= 8 && y - 1 >= 0)
		{
			if (map[y - 1][x + 2] == 0)
			{
				if (map[y][x + 1] == 0)
				{
					COORD tmp;
					tmp.X = x + 2;
					tmp.Y = y - 1;
					path.push_back(tmp);
				}
			}
			if (map[y - 1][x + 2] > 7 && map[y - 1][x + 2] <= 14)
			{
				if (map[y][x + 1] == 0)
				{
					COORD tmp;
					tmp.X = x + 2;
					tmp.Y = y - 1;
					path.push_back(tmp);
				}
			}
		}
		//�W��
		if (x - 1 >= 0 && y - 2 >= 0)
		{
			if (map[y - 2][x - 1] == 0) {
				if (map[y - 1][x] == 0)
				{
					COORD tmp;
					tmp.X = x - 1;
					tmp.Y = y - 2;
					path.push_back(tmp);
				}
			}
			if (map[y - 2][x - 1] <= 14 && map[y - 2][x - 1] > 7)
			{
				if (map[y - 1][x] == 0)
				{
					COORD tmp;
					tmp.X = x - 1;
					tmp.Y = y - 2;
					path.push_back(tmp);
				}
			}
		}
		//���W
		if (x - 2 >= 0 && y - 1 >= 0)
		{
			if (map[y - 1][x - 2] == 0) {
				if (map[y][x - 1] == 0)
				{
					COORD tmp;
					tmp.X = x - 2;
					tmp.Y = y - 1;
					path.push_back(tmp);
				}
			}
			if (map[y - 1][x - 2] <= 14 && map[y - 1][x - 2] > 7)
			{
				if (map[y][x - 1] == 0)
				{
					COORD tmp;
					tmp.X = x - 2;
					tmp.Y = y - 1;
					path.push_back(tmp);
				}
			}
		}
		//���U
		if (x - 2 >= 0 && y + 1 <= 9)
		{
			if (map[y + 1][x - 2] == 0) {
				if (map[y][x - 1] == 0)
				{
					COORD tmp;
					tmp.X = x - 2;
					tmp.Y = y + 1;
					path.push_back(tmp);
				}
			}
			if (map[y + 1][x - 2] <= 14 && map[y + 1][x - 2] > 7)
			{
				if (map[y][x - 1] == 0)
				{
					COORD tmp;
					tmp.X = x - 2;
					tmp.Y = y + 1;
					path.push_back(tmp);
				}
			}
		}
		//�U��
		if (x - 1 >= 0 && y + 2 <= 9)
		{
			if (map[y + 2][x - 1] == 0) {
				if (map[y + 1][x] == 0)
				{
					COORD tmp;
					tmp.X = x - 1;
					tmp.Y = y + 2;
					path.push_back(tmp);
				}
			}
			if (map[y + 2][x - 1] > 7 && map[y + 2][x - 1] <= 14)
			{
				if (map[y + 1][x] == 0)
				{
					COORD tmp;
					tmp.X = x - 1;
					tmp.Y = y + 2;
					path.push_back(tmp);
				}
			}

		}
		//�U�k
		if (x + 1 <= 8 && y + 2 <= 9)
		{
			if (map[y + 2][x + 1] == 0) {
				if (map[y + 1][x] == 0)
				{
					COORD tmp;
					tmp.X = x + 1;
					tmp.Y = y + 2;
					path.push_back(tmp);
				}
			}
			if (map[y + 2][x + 1] > 7 && map[y + 2][x + 1] <= 14)
			{
				if (map[y + 1][x] == 0)
				{
					COORD tmp;
					tmp.X = x + 1;
					tmp.Y = y + 2;
					path.push_back(tmp);
				}
			}
		}
		//�k�U
		if (x + 2 <= 8 && y + 1 <= 9)
		{
			if (map[y + 1][x + 2] == 0) {
				if (map[y][x + 1] == 0)
				{
					COORD tmp;
					tmp.X = x + 2;
					tmp.Y = y + 1;
					path.push_back(tmp);
				}
			}
			if (map[y + 1][x + 2] > 7 && map[y + 1][x + 2] <= 14)
			{
				if (map[y][x + 1] == 0)
				{
					COORD tmp;
					tmp.X = x + 2;
					tmp.Y = y + 1;
					path.push_back(tmp);
				}
			}
		}
	}
	//�¶H
	else if (chess == 3)
	{
		//���W
		if (x - 2 >= 0 && y - 2 >= 0)
		{
			if (map[y - 2][x - 2] == 0)
			{
				if (map[y - 1][x - 1] == 0)
				{
					COORD tmp;
					tmp.X = x - 2;
					tmp.Y = y - 2;
					path.push_back(tmp);
				}
			}
			if (map[y - 2][x - 2] <= 14 && map[y - 2][x - 2] > 7)
			{
				if (map[y - 1][x - 1] == 0)
				{
					COORD tmp;
					tmp.X = x - 2;
					tmp.Y = y - 2;
					path.push_back(tmp);
				}
			}
		}
		//�k�W
		if (x + 2 <= 8 && y - 2 >= 0)
		{
			if (map[y - 2][x + 2] == 0)
			{
				if (map[y - 1][x + 1] == 0)
				{
					COORD tmp;
					tmp.X = x + 2;
					tmp.Y = y - 2;
					path.push_back(tmp);
				}
			}
			if (map[y - 2][x + 2] <= 14 && map[y - 2][x + 2] > 7)
			{
				if (map[y - 1][x + 1] == 0)
				{
					COORD tmp;
					tmp.X = x + 2;
					tmp.Y = y - 2;
					path.push_back(tmp);
				}
			}
		}
		//���U
		if (x - 2 >= 0 && y + 2 <= 4)
		{
			if (map[y + 2][x - 2] == 0)
			{
				if (map[y + 1][x - 1] == 0)
				{
					COORD tmp;
					tmp.X = x - 2;
					tmp.Y = y + 2;
					path.push_back(tmp);
				}
			}
			if (map[y + 2][x - 2] <= 14 && map[y + 2][x - 2] > 7)
			{
				if (map[y + 1][x - 1] == 0)
				{
					COORD tmp;
					tmp.X = x - 2;
					tmp.Y = y + 2;
					path.push_back(tmp);
				}
			}
		}
		//�k�U
		if (x + 2 <= 8 && y + 2 <= 4)
		{
			if (map[y + 2][x + 2] == 0)
			{
				if (map[y + 1][x + 1] == 0)
				{
					COORD tmp;
					tmp.X = x + 2;
					tmp.Y = y + 2;
					path.push_back(tmp);
				}
			}
			if (map[y + 2][x + 2] <= 14 && map[y + 2][x + 2] > 7)
			{
				if (map[y + 1][x + 1] == 0)
				{
					COORD tmp;
					tmp.X = x + 2;
					tmp.Y = y + 2;
					path.push_back(tmp);
				}
			}
		}
	}
	//����
	else if (chess == 10)
	{
		//���W
		if (x - 2 >= 0 && y - 2 >= 5)
		{
			if (map[y - 2][x - 2] == 0 || map[y - 2][x - 2] <= 7) {
				if (map[y - 1][x - 1] == 0)
				{
					COORD tmp;
					tmp.X = x - 2;
					tmp.Y = y - 2;
					path.push_back(tmp);
				}
			}
		}
		//�k�W
		if (x + 2 <= 8 && y - 2 >= 5)
		{
			if (map[y - 2][x + 2] == 0 || map[y - 2][x + 2] <= 7) {
				if (map[y - 1][x + 1] == 0)
				{
					COORD tmp;
					tmp.X = x + 2;
					tmp.Y = y - 2;
					path.push_back(tmp);
				}
			}
		}
		//���U
		if (x - 2 >= 0 && y + 2 <= 9)
		{
			if (map[y + 2][x - 2] == 0 || map[y + 2][x - 2] <= 7) {
				if (map[y + 1][x - 1] == 0)
				{
					COORD tmp;
					tmp.X = x - 2;
					tmp.Y = y + 2;
					path.push_back(tmp);
				}
			}
		}
		//�k�U
		if (x + 2 <= 8 && y + 2 <= 9)
		{
			if (map[y + 2][x + 2] == 0 || map[y + 2][x + 2] <= 7) {
				if (map[y + 1][x + 1] == 0)
				{
					COORD tmp;
					tmp.X = x + 2;
					tmp.Y = y + 2;
					path.push_back(tmp);
				}
			}
		}
	}
	//�±N
	else if (chess == 1)
	{
		//���W
		if (y - 1 >= 0)
		{
			if (map[y - 1][x] == 0 || map[y - 1][x] > 7)
			{
				COORD tmp;
				tmp.X = x;
				tmp.Y = y - 1;
				path.push_back(tmp);
			}
		}
		//���U
		if (y + 1 <= 2)
		{
			if (map[y + 1][x] == 0 || map[y + 1][x] > 7)
			{
				COORD tmp;
				tmp.X = x;
				tmp.Y = y + 1;
				path.push_back(tmp);
			}
		}
		//���k
		if (x + 1 <= 5)
		{
			if (map[y][x + 1] == 0 || map[y][x + 1] > 7)
			{
				COORD tmp;
				tmp.X = x + 1;
				tmp.Y = y;
				path.push_back(tmp);
			}
		}
		//����
		if (x - 1 >= 3)
		{
			if (map[y][x - 1] == 0 || map[y][x - 1] > 7)
			{
				COORD tmp;
				tmp.X = x - 1;
				tmp.Y = y;
				path.push_back(tmp);
			}
		}
		//������誺��
		for (int i = y; i <= 9; i++)
		{
			if (map[i][x] == 8)
			{
				COORD tmp;
				tmp.X = x;
				tmp.Y = i;
				path.push_back(tmp);
				break;
			}
			if (map[i][x] > 1 && map[i][x] <= 14)
			{
				break;
			}
		}
	}
	//����
	else if (chess == 8)
	{
		if (y - 1 >= 7)
		{
			if (map[y - 1][x] == 0)
			{
				COORD tmp;
				tmp.X = x;
				tmp.Y = y - 1;
				path.push_back(tmp);
			}
			if (map[y - 1][x] <= 7 && map[y - 1][x] > 0)
			{
				COORD tmp;
				tmp.X = x;
				tmp.Y = y - 1;
				path.push_back(tmp);
			}

		}
		//���U
		if (y + 1 <= 9)
		{
			if (map[y + 1][x] == 0)
			{
				COORD tmp;
				tmp.X = x;
				tmp.Y = y + 1;
				path.push_back(tmp);
			}
			if (map[y + 1][x] <= 7 && map[y + 1][x] > 0)
			{
				COORD tmp;
				tmp.X = x;
				tmp.Y = y + 1;
				path.push_back(tmp);
			}
		}
		//���k
		if (x + 1 <= 5)
		{
			if (map[y][x + 1] == 0)
			{
				COORD tmp;
				tmp.X = x + 1;
				tmp.Y = y;
				path.push_back(tmp);
			}
			if (map[y][x + 1] <= 7 && map[y][x + 1] > 0)
			{
				COORD tmp;
				tmp.X = x + 1;
				tmp.Y = y;
				path.push_back(tmp);
			}

		}
		//����
		if (x - 1 >= 3)
		{
			if (map[y][x - 1] == 0)
			{
				COORD tmp;
				tmp.X = x - 1;
				tmp.Y = y;
				path.push_back(tmp);
			}
			if (map[y][x - 1] <= 7 && map[y][x - 1] > 0)
			{
				COORD tmp;
				tmp.X = x - 1;
				tmp.Y = y;
				path.push_back(tmp);
			}
		}
		//�ӹ���誺�N�i�H�����Y
		for (int i = y; i >= 0; i--)
		{
			if (map[i][x] == 1)
			{
				COORD tmp;
				tmp.X = x;
				tmp.Y = i;
				path.push_back(tmp);
				break;
			}
			if (map[i][x] > 1 && map[i][x] <= 14)
			{
				if (map[i][x] != 8)
				{
					break;
				}
			}
		}
	}
	//�¤h
	else  if (chess == 2) {
		if (y == 0) {
			if (x == 3) {
				if (map[1][4] == 0 || map[1][4] == 0 >= 8) {
					COORD tmp;
					tmp.X = 4;
					tmp.Y = 1;
					path.push_back(tmp);
				}

			}
			else if (x == 5) {
				if (map[1][4] == 0 || map[1][4] == 0 >= 8) {
					COORD tmp;
					tmp.X = 4;
					tmp.Y = 1;
					path.push_back(tmp);
				}
			}
		}
		else if (y == 1) {
			if (x == 4) {
				if (map[0][3] == 0 || map[0][3] >= 8) {
					COORD tmp;
					tmp.X = 3;
					tmp.Y = 0;
					path.push_back(tmp);
				}
				if (map[0][5] == 0 || map[0][5] >= 8) {
					COORD tmp;
					tmp.X = 5;
					tmp.Y = 0;
					path.push_back(tmp);
				}
				if (map[2][3] == 0 || map[2][3] >= 8) {
					COORD tmp;
					tmp.X = 3;
					tmp.Y = 2;
					path.push_back(tmp);
				}
				if (map[2][5] == 0 || map[2][5] >= 8) {
					COORD tmp;
					tmp.X = 5;
					tmp.Y = 2;
					path.push_back(tmp);
				}

			}
		}

		else if (y == 2) {
			if (x == 3) {
				if (map[1][4] == 0 || map[1][4] == 0 >= 8) {
					COORD tmp;
					tmp.X = 4;
					tmp.Y = 1;
					path.push_back(tmp);
				}
			}
			else if (x == 5) {
				if (map[1][4] == 0 || map[1][4] == 0 >= 8) {
					COORD tmp;
					tmp.X = 4;
					tmp.Y = 1;
					path.push_back(tmp);
				}
			}
		}
	}
	//�¨�
	else if (chess == 4) {
		//���e����
		vector<int>front;
		for (int i = y + 1; i <= 9; i++) {
			if (map[i][x] != 0) {
				if (map[i][x] >= 8) {
					COORD tmp;
					tmp.X = x;
					tmp.Y = i;
					path.push_back(tmp);
					break;
				}
				break;
			}
			else
				front.push_back(i);
		}
		for (int i = 0; i < front.size(); i++) {
			COORD tmp;
			tmp.X = x;
			tmp.Y = front[i];
			path.push_back(tmp);
		}
		//���ᤣ��
		vector<int>back;
		for (int i = y - 1; i >= 0; i--) {
			if (map[i][x] != 0) {
				if (map[i][x] >= 8) {
					COORD tmp;
					tmp.X = x;
					tmp.Y = i;
					path.push_back(tmp);
					break;
				}
				break;
			}
			else
				back.push_back(i);
		}
		for (int i = 0; i < back.size(); i++) {
			COORD tmp;
			tmp.X = x;
			tmp.Y = back[i];
			path.push_back(tmp);
		}
		//���k����
		vector<int>right;
		for (int i = x + 1; i <= 8; i++) {
			if (map[y][i] != 0) {
				if (map[y][i] >= 8) {
					COORD tmp;
					tmp.X = i;
					tmp.Y = y;
					path.push_back(tmp);
					break;
				}
				break;
			}
			else
				right.push_back(i);
		}
		for (int i = 0; i < right.size(); i++) {
			COORD tmp;
			tmp.X = right[i];
			tmp.Y = y;
			path.push_back(tmp);
		}
		//��������
		vector<int>left;
		for (int i = x - 1; i >= 0; i--) {
			if (map[y][i] != 0) {
				if (map[y][i] >= 8) {
					COORD tmp;
					tmp.X = i;
					tmp.Y = y;
					path.push_back(tmp);
					break;
				}
				break;
			}
			else
				left.push_back(i);
		}
		for (int i = 0; i < left.size(); i++) {
			COORD tmp;
			tmp.X = left[i];
			tmp.Y = y;
			path.push_back(tmp);
		}
	}
	//�¥]
	else if (chess == 6) {

		//���e����
		vector<int>front;
		if (y + 1 > 9);
		else {
			int frontIndex = 9999;
			for (int i = y + 1; i <= 9; i++) {
				if (map[i][x] != 0) {
					frontIndex = i;
					break;
				}
				else
					front.push_back(i);
			}
			for (int i = 0; i < front.size(); i++) {
				COORD tmp;
				tmp.X = x;
				tmp.Y = front[i];
				path.push_back(tmp);
			}
			if (frontIndex != 9999) {
				for (int i = frontIndex + 1; i <= 9; i++) {
					if (map[i][x] <= 7 && map[i][x] != 0) {
						break;
					}
					else if (map[i][x] >= 8) {
						COORD tmp;
						tmp.X = x;
						tmp.Y = i;
						path.push_back(tmp);
						break;
					}
				}
			}

		}
		//���ᤣ��
		vector<int>back;
		if (y - 1 < 0);
		else {
			int backIndex = 9999;
			for (int i = y - 1; i >= 0; i--) {
				if (map[i][x] != 0) {
					backIndex = i;
					break;
				}
				else
					back.push_back(i);
			}

			for (int i = 0; i < back.size(); i++) {
				COORD tmp;
				tmp.X = x;
				tmp.Y = back[i];
				path.push_back(tmp);
			}
			if (backIndex != 9999) {
				for (int i = backIndex - 1; i >= 0; i--) {
					if (map[i][x] <= 7 && map[i][x] != 0) {
						break;
					}
					else if (map[i][x] >= 8) {
						COORD tmp;
						tmp.X = x;
						tmp.Y = i;
						path.push_back(tmp);
						break;
					}
				}
			}
		}
		//���k����
		vector<int>right;
		if (x + 1 > 8);
		else {
			int rightIndex = 9999;
			for (int i = x + 1; i <= 8; i++) {
				if (map[y][i] != 0) {
					rightIndex = i;
					break;
				}
				else
					right.push_back(i);
			}
			for (int i = 0; i < right.size(); i++) {
				COORD tmp;
				tmp.X = right[i];
				tmp.Y = y;
				path.push_back(tmp);
			}
			if (rightIndex != 9999) {
				for (int i = rightIndex + 1; i <= 8; i++) {
					if (map[y][i] <= 7 && map[y][i] != 0) {
						break;
					}
					else if (map[y][i] >= 8) {
						COORD tmp;
						tmp.X = i;
						tmp.Y = y;
						path.push_back(tmp);
						break;
					}
				}
			}
		}
		//��������
		vector<int>left;
		if (x - 1 < 0);
		else {
			int leftIndex = 9999;
			for (int i = x - 1; i >= 0; i--) {
				if (map[y][i] != 0) {
					leftIndex = i;
					break;
				}
				else
					left.push_back(i);
			}
			for (int i = 0; i < left.size(); i++) {
				COORD tmp;
				tmp.X = left[i];
				tmp.Y = y;
				path.push_back(tmp);
			}
			if (leftIndex != 9999) {
				for (int i = leftIndex - 1; i >= 0; i--) {
					if (map[y][i] <= 7 && map[y][i] != 0) {
						break;
					}
					else if (map[y][i] >= 8) {
						COORD tmp;
						tmp.X = i;
						tmp.Y = y;
						path.push_back(tmp);
						break;
					}
				}
			}
		}
	}
	//���h
	else if (chess == 9) {
		if (y == 9) {
			if (x == 3) {
				if (map[8][4] == 0 || map[8][4] == 0 <= 7) {
					COORD tmp;
					tmp.X = 4;
					tmp.Y = 8;
					path.push_back(tmp);
				}

			}
			else if (x == 5) {
				if (map[8][4] == 0 || map[8][4] == 0 <= 7) {
					COORD tmp;
					tmp.X = 4;
					tmp.Y = 8;
					path.push_back(tmp);
				}
			}
		}
		else if (y == 8) {
			if (x == 4) {
				if (map[9][3] == 0 || map[9][3] <= 7) {
					COORD tmp;
					tmp.X = 3;
					tmp.Y = 9;
					path.push_back(tmp);
				}
				if (map[9][5] == 0 || map[9][5] <= 7) {
					COORD tmp;
					tmp.X = 5;
					tmp.Y = 9;
					path.push_back(tmp);
				}
				if (map[7][3] == 0 || map[7][3] <= 7) {
					COORD tmp;
					tmp.X = 3;
					tmp.Y = 7;
					path.push_back(tmp);
				}
				if (map[7][5] == 0 || map[7][5] <= 7) {
					COORD tmp;
					tmp.X = 5;
					tmp.Y = 7;
					path.push_back(tmp);
				}

			}
		}
		else if (y == 7) {
			if (x == 3) {
				if (map[8][4] == 0 || map[8][4] == 0 <= 7) {
					COORD tmp;
					tmp.X = 4;
					tmp.Y = 8;
					path.push_back(tmp);
				}
			}
			else if (x == 5) {
				if (map[8][4] == 0 || map[8][4] == 0 <= 7) {
					COORD tmp;
					tmp.X = 4;
					tmp.Y = 8;
					path.push_back(tmp);
				}
			}
		}
	}
	//����
	else if (chess == 11) {
		//���e����
		vector<int>front;
		for (int i = y - 1; i >= 0; i--) {
			if (map[i][x] != 0) {
				if (map[i][x] <= 7) {
					COORD tmp;
					tmp.X = x;
					tmp.Y = i;
					path.push_back(tmp);
					break;
				}
				break;
			}
			else
				front.push_back(i);
		}
		for (int i = 0; i < front.size(); i++) {
			COORD tmp;
			tmp.X = x;
			tmp.Y = front[i];
			path.push_back(tmp);
		}
		//���ᤣ��
		vector<int>back;
		for (int i = y + 1; i <= 9; i++) {
			if (map[i][x] != 0) {
				if (map[i][x] <= 7) {
					COORD tmp;
					tmp.X = x;
					tmp.Y = i;
					path.push_back(tmp);
					break;
				}
				break;
			}
			else
				back.push_back(i);
		}
		for (int i = 0; i < back.size(); i++) {
			COORD tmp;
			tmp.X = x;
			tmp.Y = back[i];
			path.push_back(tmp);
		}
		//���k����
		vector<int>right;
		for (int i = x + 1; i <= 8; i++) {
			if (map[y][i] != 0) {
				if (map[y][i] <= 7) {
					COORD tmp;
					tmp.X = i;
					tmp.Y = y;
					path.push_back(tmp);
					break;
				}
				break;
			}
			else
				right.push_back(i);
		}
		for (int i = 0; i < right.size(); i++) {
			COORD tmp;
			tmp.X = right[i];
			tmp.Y = y;
			path.push_back(tmp);
		}
		//��������
		vector<int>left;
		for (int i = x - 1; i >= 0; i--) {
			if (map[y][i] != 0) {
				if (map[y][i] <= 7) {
					COORD tmp;
					tmp.X = i;
					tmp.Y = y;
					path.push_back(tmp);
					break;
				}
				break;
			}
			else
				left.push_back(i);
		}
		for (int i = 0; i < left.size(); i++) {
			COORD tmp;
			tmp.X = left[i];
			tmp.Y = y;
			path.push_back(tmp);
		}
	}

	//���w
	else if (chess == 13) {
		//���e����
		vector<int>front;
		if (y - 1 < 0);
		else {
			int frontIndex = 9999;
			for (int i = y - 1; i >= 0; i--) {
				if (map[i][x] != 0) {
					frontIndex = i;
					break;
				}
				else
					front.push_back(i);
			}
			for (int i = 0; i < front.size(); i++) {
				COORD tmp;
				tmp.X = x;
				tmp.Y = front[i];
				path.push_back(tmp);
			}
			if (frontIndex != 9999) {
				for (int i = frontIndex - 1; i >= 0; i--) {
					if (map[i][x] >= 8) {
						break;
					}
					else if (map[i][x] <= 7 && map[i][x] != 0) {
						COORD tmp;
						tmp.X = x;
						tmp.Y = i;
						path.push_back(tmp);
						break;
					}
				}
			}
		}
		//���ᤣ��
		vector<int>back;
		if (y + 1 > 9);
		else {
			int backIndex = 9999;
			for (int i = y + 1; i <= 9; i++) {
				if (map[i][x] != 0) {
					backIndex = i;
					break;
				}
				else
					back.push_back(i);
			}
			for (int i = 0; i < back.size(); i++) {
				COORD tmp;
				tmp.X = x;
				tmp.Y = back[i];
				path.push_back(tmp);
			}
			if (backIndex != 9999) {
				for (int i = backIndex + 1; i <= 9; i++) {
					if (map[i][x] >= 8) {
						break;
					}
					else if (map[i][x] <= 7 && map[i][x] != 0) {
						COORD tmp;
						tmp.X = x;
						tmp.Y = i;
						path.push_back(tmp);
						break;
					}
				}
			}
		}
		//���k����
		vector<int>right;
		if (x + 1 > 8);
		else {
			int rightIndex = 9999;
			for (int i = x + 1; i <= 8; i++) {
				if (map[y][i] != 0) {
					rightIndex = i;
					break;
				}
				else
					right.push_back(i);
			}
			for (int i = 0; i < right.size(); i++) {
				COORD tmp;
				tmp.X = right[i];
				tmp.Y = y;
				path.push_back(tmp);
			}
			if (rightIndex != 9999) {
				for (int i = rightIndex + 1; i <= 8; i++) {
					if (map[y][i] >= 8) {
						break;
					}
					else if (map[y][i] <= 7 && map[y][i] != 0) {
						COORD tmp;
						tmp.X = i;
						tmp.Y = y;
						path.push_back(tmp);
						break;
					}
				}
			}
		}
		//��������
		vector<int>left;
		if (x - 1 < 0);
		else {
			int leftIndex = 9999;
			for (int i = x - 1; i >= 0; i--) {
				if (map[y][i] != 0) {
					leftIndex = i;
					break;
				}
				else
					left.push_back(i);
			}
			for (int i = 0; i < left.size(); i++) {
				COORD tmp;
				tmp.X = left[i];
				tmp.Y = y;
				path.push_back(tmp);
			}
			if (leftIndex != 9999) {
				for (int i = leftIndex - 1; i >= 0; i--) {
					if (map[y][i] >= 8) {
						break;
					}
					else if (map[y][i] <= 7 && map[y][i] != 0) {
						COORD tmp;
						tmp.X = i;
						tmp.Y = y;
						path.push_back(tmp);
						break;
					}
				}
			}
		}
	}

	//��
	else if (chess == 7)
	{
		//���L�e
		if (y <= 4) {
			if (map[y + 1][x] == 0 || map[y + 1][x] >= 8) {
				COORD tmp;
				tmp.X = x;
				tmp.Y = y + 1;
				path.push_back(tmp);
			}
		}
		//�L�e
		else {
			//���e�X�k
			if (y + 1 <= 9) {
				if (map[y + 1][x] == 0 || map[y + 1][x] >= 8) {
					COORD tmp;
					tmp.X = x;
					tmp.Y = y + 1;
					path.push_back(tmp);
				}
			}
			//�����X�k
			if (x - 1 >= 0) {
				if (map[y][x - 1] == 0 || map[y][x - 1] >= 8) {
					COORD tmp;
					tmp.X = x - 1;
					tmp.Y = y;
					path.push_back(tmp);
				}
			}
			//���k�X�k
			if (x + 1 <= 8) {
				if (map[y][x + 1] == 0 || map[y][x + 1] >= 8) {
					COORD tmp;
					tmp.X = x + 1;
					tmp.Y = y;
					path.push_back(tmp);
				}
			}
		}
	}
	//�L
	else if (chess == 14) {
		//�w�L�e
		if (y <= 4) {
			//���e
			if (y - 1 >= 0) {
				if (map[y - 1][x] == 0 || map[y - 1][x] <= 7) {
					COORD tmp;
					tmp.X = x;
					tmp.Y = y - 1;
					path.push_back(tmp);
				}
			}
			//���k
			if (x + 1 <= 8) {
				if (map[y][x + 1] == 0 || map[y][x + 1] <= 7) {
					COORD tmp;
					tmp.X = x + 1;
					tmp.Y = y;
					path.push_back(tmp);
				}
			}
			//����
			if (x - 1 >= 0) {
				if (map[y][x - 1] == 0 || map[y][x - 1] <= 7) {
					COORD tmp;
					tmp.X = x - 1;
					tmp.Y = y;
					path.push_back(tmp);
				}
			}
		}
		else {
			//���L�e�N�S����ɰ��D
			if (map[y - 1][x] == 0 || map[y - 1][x] <= 7) {
				COORD tmp;
				tmp.X = x;
				tmp.Y = y - 1;
				path.push_back(tmp);
			}
		}
	}
}
void readFile()
{
	ifstream file;
	int turn;
	file.open("Initial.txt");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			file >> map[i][j];
		}
	}
	file >> turn;
	if (turn == 1)
		whosTurn = false;
	else
		whosTurn = true;
}
void outputFile()
{
	ofstream file;
	int turn;
	file.open("output.txt");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			file << map[i][j] << " ";
		}
		file << "\n";
	}

	if (whosTurn)
		file << 0;
	else
		file << 1;

}
int main()
{
	int r_move_x = 24, r_move_y = 2;
	int b_move_x = 24, b_move_y = 20;

	HANDLE hin;
	DWORD WriteWord;
	COORD pos;
	pos.X = r_move_x, pos.Y = r_move_y;
	hin = GetStdHandle(STD_OUTPUT_HANDLE);
	int c;
	bool can_move = false;
	int first_x = 0, first_y = 0;
	//readFile();
	//outputFile();
	output();
	while (c = _getch())
	{
		if (c == 115)//save files
		{
			_getch();
			outputFile();
			continue;
		}
		if (c == 114)//read files
		{
			readFile();
			move_data.clear();
			path.clear();
			back.clear();
			output();
			_getch();
			continue;
		}
		if (c == 98)
		{
			if (back.size() == 0)
			{
				continue;
			}
			Back b = back[back.size() - 1];
			map[b.ny][b.nx] = 0;
			map[b.oy][b.ox] = b.chessName;
			map[b.eoy][b.eox] = b.eatenChess;
			move_data.pop_back();
			back.pop_back();
			whosTurn = !whosTurn;
			output();
			SetConsoleCursorPosition(hin, pos);
			_getch();
			continue;
		}
		if (c == 13 && !can_move)
		{
			_getch();
			if ((whosTurn && read_Chess(pos.X, pos.Y) <= 7) || (!whosTurn && read_Chess(pos.X, pos.Y) >= 8))
			{
				if (read_Chess(pos.X, pos.Y) != 0)
				{
					can_move = true;
					first_x = pos.X;
					first_y = pos.Y;
					moveRule(read_Chess(pos.X, pos.Y), first_x, first_y);
					output();
				}
				else
					can_move = false;
			}
		}
		else if (c == 13 && can_move)
		{
			_getch();
			if (first_x == pos.X && first_y == pos.Y)
			{
				can_move = false;
				path.clear();
				output();
				continue;
			}
			bool moveIsValid = false;
			for (size_t i = 0; i < path.size(); i++)
			{
				if (path[i].X == (pos.X - 24) / 5 && path[i].Y == (pos.Y - 2) / 2)
				{
					moveIsValid = true;
				}
			}
			if (moveIsValid == false)
			{
				continue;
			}
			if (read_Chess(pos.X, pos.Y) != 0)
			{
				int tmp = (read_Chess(pos.X, pos.Y) - 8)*(read_Chess(first_x, first_y) - 8);
				if ((read_Chess(pos.X, pos.Y) - 8) == 0 && (read_Chess(first_x, first_y) - 8) < 0)
					tmp = -1;
				if (tmp >= 0)
				{
					continue;
				}
			}
			int chess_tmp = read_Chess(pos.X, pos.Y) - 7;
			add_Move(first_x, first_y, pos.X, pos.Y);
			int lose = 0;
			if (chess_tmp == 1)//�C������
			{
				lose = 1;

				move_data.push_back(to_string(move_data.size() + 1) + " �¤����");
			}
			else if (chess_tmp == -6)
			{
				lose = 2;
				move_data.push_back(to_string(move_data.size() + 1) + " �������");
			}
			path.clear();
			whosTurn = !whosTurn;
			output();
			if (lose == 1 || lose == 2)
				break;
			can_move = false;
		}

		if (c == 72 && pos.Y > 2)
			pos.Y -= 2;
		if (c == 80 && pos.Y < 20)
			pos.Y += 2;
		if (c == 75 && pos.X > 24)
			pos.X -= 5;
		if (c == 77 && pos.X < 64)
			pos.X += 5;
		SetConsoleCursorPosition(hin, pos);
	}

	pos.X = 0;
	pos.Y = 25;
	SetConsoleCursorPosition(hin, pos);
	system("pause");
}

