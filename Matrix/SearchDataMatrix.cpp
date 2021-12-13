#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int rowend = matrix.size() - 1;
    int colend = matrix[0].size() - 1;
    if (rowend == 0 && colend == 0)
    {
        cout<<"rowend == 0 && colend == 0";
        if (matrix[0][0] == target)
            return true;

        return false;
    }
    for (int i = 0; i < rowend; i++)
    {
        for (int j = 0; j < colend; j++)
        {
            cout<<matrix[i][j]<<" ";
            if (matrix[i][j] == target)
                return true;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> arr{};
    arr[0][0]=1;
    cout<<searchMatrix(arr,1);
    return 0;
}