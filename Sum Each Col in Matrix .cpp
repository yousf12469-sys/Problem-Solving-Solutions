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
int ColsSum(int arr[3][3], short Rows, short ColNumber)
{
    int sum = 0;
    for (short i = 0; i <= Rows - 1; i++)
    {
        sum += arr[i][ColNumber];
    }
    return sum;
}
void SumMatrixColsInArry(int arr[3][3], int arrSum[3], short Rows, short Cols)
{
    for (short i = 0; i < Cols; i++)
    {
        arrSum[i] = ColsSum(arr, Rows, i);
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
void PrintColsSumArry(int arr[3], short length)
{
    cout << "\n the following are the sum of each row in the matrix \n";
    for (short i = 0; i < length; i++)
    {
        cout << " Cols " << i + 1 << "Sum = " << arr[i] << endl;
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[3][3];
    int arrSum[3];
    FillMatrixWithRandomNumbers(arr, 3, 3);
    cout << "\n the following is a 3x3 random matrix: \n";
    PrintMatrix(arr, 3, 3);
    SumMatrixColsInArry(arr, arrSum, 3, 3);
    PrintColsSumArry(arrSum, 3);
}
