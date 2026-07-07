#include <iostream>
#include <string>
using namespace std;
int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}
void FillMatrixWithOrderNumbers(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumber(1, 10);
		}
	}
}
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf(" %0*d   ", 2, arr[i][j]);
		}
		cout << "\n";
	}
}
bool AreTypicallMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] != Matrix2[i][j])
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	srand((unsigned)time(NULL));
	int Matrix1[3][3], Matrix2[3][3];

	FillMatrixWithOrderNumbers(Matrix1, 3, 3);
	cout << "\n matrix1: \n";
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithOrderNumbers(Matrix2, 3, 3);
	cout << "\n matrix2: \n";
	PrintMatrix(Matrix2, 3, 3);

	if (AreTypicallMatrices(Matrix1, Matrix2, 3, 3))
		cout << "\nYes: both martices are typical.";
	else
		cout << "\nNo: martices are not typical.";

	system("pause>0");
}