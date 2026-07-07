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
short CountNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols)
{
	short NumberCount = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] == Number)
			{
				NumberCount++;
			};
		}

	}
	return NumberCount;
}
bool IsNumberInMatrix(int Matrix1[3][3], int Number,short Rows, short Cols)
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
int main()
{
	int Matrix1[3][3] = { {9,78,6},{53,90,3},{18,43,84} };
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);
	int Number;
	cout << "\nPlease enter the number to look for in the matrix? ";
	cin >> Number;

	//using count is slwer method
	if (CountNumberInMatrix(Matrix1, Number, 3, 3) > 0)
		cout << "\nYes: it is there\n";
	else
		cout << "\nNo: it is Not there\n";

	//using count is faster method
	if (IsNumberInMatrix(Matrix1, Number,3, 3))
		cout << "\nYes: it is there\n";
	else
		cout << "\nNo: it is Not there\n";
	system("pause>0");
}