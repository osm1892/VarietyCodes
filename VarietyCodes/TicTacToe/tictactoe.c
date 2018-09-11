#include "head.h"

int SaveTictactoe(char board[3][3], int x, int y, int isO)
{
	if (x < 0 || 2 < x || y < 0 || 2 < y)
	{
		puts("�߸��� �����Դϴ�.");
		return 1;
	}

	if (isO && board[x][y] == 0)
	{
		board[y][x] = 'O';
		return 0;
	}
	if (!isO && board[x][y] == 0)
	{
		board[y][x] = 'X';
		return 0;
	}
	puts("�̹� �����ϴ� �ڸ��Դϴ�.");
	return 1;
}

void PrintTictactoe(char board[3][3])
{
	puts("-|-|-");
	printf("%c|%c|%c\n", board[0][0], board[0][1], board[0][2]);
	puts("-|-|-");
	printf("%c|%c|%c\n", board[1][0], board[1][1], board[1][2]);
	puts("-|-|-");
	printf("%c|%c|%c\n", board[2][0], board[2][1], board[2][2]);
	puts("-|-|-");
	return;
}

int BoardCheck(char board[3][3])
{
	int i = 0, j = 0, oCount = 0, xCount = 0;

	for (i = 0; i < 3; i++) // ���� ���� üũ
	{
		oCount = 0;
		xCount = 0;
		for (j = 0; j < 3; j++)
		{
			switch (board[i][j])
			{
			case 'O':
				oCount++;
				break;
			case 'X':
				xCount++;
				break;
			default:
				break;
			}
			if (oCount == 3)
				return 1;
			if (xCount == 3)
				return 2;
		}
	}

	for (i = 0; i < 3; i++) // ���� ���� üũ
	{
		oCount = 0;
		xCount = 0;
		for (j = 0; j < 3; j++)
		{
			switch (board[j][i])
			{
			case 'O':
				oCount++;
				break;
			case 'X':
				xCount++;
			default:
				break;
			}
			if (oCount == 3)
				return 1;
			if (xCount == 3)
				return 2;
		}
	}

	oCount = 0;
	xCount = 0;
	for (i = 0; i < 3; i++) // �������� ���� �缱 üũ
	{
		switch (board[i][i])
		{
		case 'O':
			oCount++;
			break;
		case 'X':
			xCount++;
			break;
		default:
			break;
		}
		if (oCount == 3)
			return 1;
		if (xCount == 3)
			return 2;
	}

	oCount = 0;
	xCount = 0;
	for (i = 0; i < 3; i++)
	{
		switch (board[i][2 - i])
		{
		case 'O':
			oCount++;
			break;
		case 'X':
			xCount++;
			break;
		default:
			break;
		}
		if (oCount == 3)
			return 1;
		if (xCount == 3)
			return 2;
	}

	return 0;
}