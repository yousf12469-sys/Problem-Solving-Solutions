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
int MinNumberInMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	int Min = Matrix1[0][0];

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] < Min)
			{
				Min = Matrix1[i][j];
			}
		}
	}
	return Min;
}

int MaxNumberInMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	int Max = Matrix1[0][0];
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] > Max)
			{
				Max = Matrix1[i][j];
			}
		}
	}
	return Max;
}

int main()
{
	int Matrix1[3][3] = { {9,78,6},{53,90,3},{18,43,84} };

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nMinimum number is: ";
	cout << MinNumberInMatrix(Matrix1, 3, 3);

	cout << "\nMaximum number is: ";
	cout << MaxNumberInMatrix(Matrix1, 3, 3);

	system("pause>0");
}