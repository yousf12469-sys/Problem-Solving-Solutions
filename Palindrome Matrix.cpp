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

int IsPalindromeNumber(int Matrix1[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols / 2; j++)
		{
			if (Matrix1[i][j] != Matrix1[i][Cols - 1 - j])
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	int Matrix1[3][3] = { {9,78,9},{53,53,53},{18,43,18} };

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	if (IsPalindromeNumber(Matrix1, 3, 3))
	{
		cout << "\nyes: matrix is palindrome \n";
	}
	else
		cout << "\nno: matrix is not palindrome \n";

	system("pause>0");
}