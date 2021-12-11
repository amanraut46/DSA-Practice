// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<unordered_map>
using namespace std;
void printCombination(int[], int, int);
void combination(int [], int [], int, int, int, int);
int main()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    int r = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    printCombination(arr, n, r);
    return 0;
}
void printCombination(int arr[],int n,int r) {

    int* data =new int[r];

    combination(arr,data,0,n,0,r);

}
void combination(int arr[], int data[], int index, int n, int i,int r) {

    if (index == r) {
        for (int  j= 0; j < r; j++)
        {
            cout << data[j] << " ";

        }
        cout << endl;
        return;
    }
    if (i >= n) {
        return;
    }

    data[index] = arr[i];

    combination(arr, data, index + 1, n, i + 1, r);
    combination(arr, data, index, n, i + 1, r);
}






