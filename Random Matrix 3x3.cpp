#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int RandomNumber (int from, int to)
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

}

