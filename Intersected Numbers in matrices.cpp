#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			//printf(" %0*d   ", 2, arr[i][j]);
			cout << setw(3) << arr[i][j] << "      ";
		}
		cout << "\n";
	}
}
bool IsNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols)
{
	short NumberCount = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] == Number)
			{
				return true;
			};
		}

	}
	return false;
}
void PrintIntersectedNumbers(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	int Number;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Number = Matrix1[i][j];

			if (IsNumberInMatrix(Matrix2, Number, Rows, Cols))
			{
				cout << setw(3) << Number << "      ";
			}
		}
	}
}
int main()
{
	int Matrix1[3][3] = { {9,78,6},{53,90,3},{18,43,84} };
	int Matrix2[3][3] = { {119,76,69},{53,70,9},{19,4,8} };
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);
	
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix2, 3, 3);
	
	cout << "\nIntersected numbers are: \n\n";
	PrintIntersectedNumbers(Matrix1, Matrix2, 3, 3);

	system("pause>0");
}