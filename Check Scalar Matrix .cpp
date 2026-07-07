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
bool IsScalarMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	int FirstDiagElemement = Matrix1[0][0];
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (i == j && Matrix1[i][j] != FirstDiagElemement)
			{
				return false;
			}
			else if (i != j && Matrix1[i][j] != 0)
			{
				return false;
			}

		}

	}
	return true;
}
int main()
{
	int Matrix1[3][3] = { {4,0,0},{0,4,0},{0,0,4} };
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	if (IsScalarMatrix(Matrix1, 3, 3))
		cout << "\nYes; Matrix is scalar.";
	else
		cout << "\nNo: Matrix is Not scalar.";

	system("pause>0");
}