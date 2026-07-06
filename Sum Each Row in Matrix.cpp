#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int RandomNumber(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}
void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}
int RowSum(int arr[3][3], short RowNumber, short cols)
{
    int sum = 0;
    for (short j = 0; j <= cols - 1; j++)
    {
        sum += arr[RowNumber][j];
    }
    return sum;
}
void PrintEachRowSum(int arr[3][3], short Rows, short Cols)
{
    cout << "\n the sum of arr \n";
    for (short i = 0; i < Rows; i++)
    {
        cout << " Row " << i + 1 << " sum = " << RowSum(arr, i, Cols) << endl;
    }
}
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << arr[i][j] << "     ";
        }
        cout << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[3][3];
    FillMatrixWithRandomNumbers(arr, 3, 3);
    cout << "\n the following is a 3x3 random matrix: \n";
    PrintMatrix(arr, 3, 3);

    PrintEachRowSum(arr, 3, 3);

}

