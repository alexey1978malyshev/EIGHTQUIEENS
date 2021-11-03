#include<iostream>
using namespace std;


const int FIELD = 8;
int board[FIELD][FIELD];			//задаем матрицу поля

bool tryQueen(int i);
void putQueen(int i, int j);
void deleteQueen(int i, int j);


int main()
{
	setlocale(LC_ALL, "rus");	

	for (int i = 0; i < FIELD; i++)		//заполняем поле нулями
		for (int j = 0; j < FIELD; j++)
			board[i][j] = 0;
	tryQueen(0);
	for (int i = 0; i < FIELD; i++) {
		for (int j = 0; j < FIELD; j++)
		{
			if (board[i][j] == 5)
				cout << "| Ф";
				
			else
				cout << "| +";
		}
		cout << endl;
	}
}

bool tryQueen(int i)				//принимает аргументом текущий столбец
{
	bool result = false;
	for (int j = 0; j < FIELD; j++)
	{
		if (board[i][j] == 0)		//если поле свободно
		{
			putQueen(i, j);			// ставим ферзя
			if (i == 7)
				result = true;      //дойдя до конца столбца, возвращаем  тру, выходим из цикла
			else
			{
				if (!(result = tryQueen(i + 1))) 
					deleteQueen(i, j);				//если не удалось поставить следующего ферзя - удаляем предыдущего
			}
		}
		if (result)
			break;
	}
	return result;
}

void putQueen(int i, int j)
{
	for (int k = 0; k < FIELD; k++)
	{
		board[k][j]++;  //заполняем строку единицами
		board[i][k]++;  //заполняем колонку единицами
		int diag;
		diag = j - i + k;				//заполняем диагонали единицами
		if (diag >= 0 && diag < FIELD)
			board[k][diag]++;
		diag = j + i - k;
		if (diag >= 0 && diag < FIELD)
			board[k][diag]++;
	}
	board[i][j] = 5;					//ставим ферзя: 5 -это ферзь

}

void deleteQueen(int i, int j)
{
	for (int k = 0; k < FIELD; k++)
	{
		board[k][j]--;
		board[i][k]--;
		int diag;
		diag = j - i + k;
		if (diag >= 0 && diag < FIELD)
			board[k][diag]--;
		diag = j + i - k;
		if (diag >= 0 && diag < FIELD)
			board[k][diag]--;
	}
	board[i][j] = 0;					//убираем ферзя 

}








/*const int DIAG = 15;
const char QUEEN = 232;


main() {
	int positionQinI[FIELD]; // массив позиций по столбцу i
	int nobodyJ[FIELD] = { 1 }; // в строке j нет ферзя
	int diagPositive[DIAG] = { 1 }; // на диагонали / нет ферзя
	int diagNegative[DIAG] = { 1 }; // на диагонали \ нет ферзя
	int countQ = 0;					// счетчик установленных ферзей
	//int queen = 0;					//

	for (int i = 0; i < FIELD; i++) {
		for (int j = 0; j < FIELD; j++)
		{
			if (nobodyJ[j] == 1 && diagPositive[i + j] == 1 && diagNegative[i - j + 7] == 1)
			{
				nobodyJ[j] = 99; //отмечаем ферзя
				diagPositive[i + j] = 0;
				diagNegative[i - j + 7] = 0;
				
				countQ++; //добавляем в счетчик установленного ферзя
				break;
			}
			else
				break;
		}
	}	
return 0;
}

*/


