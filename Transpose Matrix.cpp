#include <iostream>
#include <string>
using namespace std;
void FillMatrixWithOrderNumbers(int arr[3][3], short Rows, short Cols)
{
	short Counter = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Counter++;
			arr[i][j] = Counter;
		}
	}
}
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << arr[i][j] << "    ";
		}
		cout << "\n";
	}
}
void TransposeMatrix(int arr[3][3], int arrTransposed[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arrTransposed[i][j] = arr[j][i];
		}
	}
}
int main()
{
	int arr[3][3], arrTransposed[3][3];
	FillMatrixWithOrderNumbers(arr, 3, 3);
	cout << "\nThe following is a 3x3 order matrix: \n";
	PrintMatrix(arr, 3, 3);
	TransposeMatrix(arr, arrTransposed, 3, 3);
	cout << "\n\n the following is the transposed matrix: \n";
	cout << endl;
	PrintMatrix(arrTransposed, 3, 3);
	system("pause>0");
}