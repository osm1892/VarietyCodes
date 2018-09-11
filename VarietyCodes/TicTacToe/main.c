#include "head.h"

int main(void)
{
	char board[3][3] = { 0 };
	int x = 0, y = 0, check = 0, count = 0;

	while (!BoardCheck(board) && count < 9)
	{
		system("cls");
		PrintTictactoe(board);
		do
		{
			printf("O�� ���� �����Դϴ�. ��ġ�� �Է��Ͽ� �ֽʽÿ�. (x y) : ");
			scanf("%d %d", &x, &y);
			getchar();
		} while (SaveTictactoe(board, x, y, 1));
		count++;

		if (BoardCheck(board) || count >= 9)
			break;

		system("cls");
		PrintTictactoe(board);
		do
		{
			printf("X�� ���� �����Դϴ�. ��ġ�� �Է��Ͽ� �ֽʽÿ�. (x y) : ");
			scanf("%d %d", &x, &y);
			getchar();
		} while (SaveTictactoe(board, x, y, 0));
	}
	switch (BoardCheck(board))
	{
	case 1:
		puts("O �� �¸��Ͽ����ϴ�!");
		break;
	case 2:
		puts("X �� �¸��Ͽ����ϴ�!");
		break;
	default:
		puts("�����ϴ�.");
		break;
	}

	system("pause");
	return 0;
}