#include <iostream>
using namespace std;
void mergesort(int arr[], int s, int e);
void Merge(int arr[], int l, int m, int r);
int main()
{
    // 5
    // 4 1 3 9 7
    int arr[5] = {4, 1, 3, 9, 7};
    for (int i = 0; i < 5; i++)
    {
        /* code */
        cout << arr[i] << " ";
    }
    cout << endl;
    mergesort(arr, 0, 5);
    for (int i = 0; i < 5; i++)
    {

        cout << arr[i] << " ";
    }
    return 0;
}
void mergesort(int arr[], int s, int e)
{
    if (s >= e)
        return;
    if (s < e)
    {
        // cout << "mergesort is called" << endl;
        // cout << "arr:" << arr << "s:" << s << "e:" << e << endl;
        int mid = (s + (e - s)) / 2;
        mergesort(arr, s, mid);
        mergesort(arr, mid + 1, e);
        Merge(arr, s, mid, e);
    }
}
void Merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int *a = new int[n1];
    int *b = new int[n2];

    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[m + 1 + i];
    }
    int i, j, k;
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            arr[k] = a[i];
            i++;
            k++;
        }
        else
        {
            a[k] = b[j];
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        arr[k] = a[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = b[j];
        j++;
        k++;
    }
}