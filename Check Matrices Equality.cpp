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
int SumofMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	int Sum = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Sum += Matrix1[i][j];
		}
	}
	return Sum;
}
bool AreEqualMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	return (SumofMatrix(Matrix1, Rows, Cols) == SumofMatrix(Matrix2, Rows, Cols));
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

	if (AreEqualMatrices(Matrix1, Matrix2, 3, 3))
		cout << "\nYes: both martices are equal.";
	else
		cout << "\nNo: martices are not equal.";
	
	system("pause>0");
}