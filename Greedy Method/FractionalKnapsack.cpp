#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{

    int value;
    int weight;

    Item(int value, int weight)
    {
        this->value = value;
        this->weight = weight;
    }
};
bool comp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)a.value / (double)a.weight;
    return r1 > r2;
}
int fractionalKnapstack(int W, Item arr[], int n)
{
    sort(arr, arr + n, [&](Item &a, Item &b)
         {
             double d1 = (double) a.value/a.weight;
             double d2 = (double) b.value/b.weight;
             return d1 > d2; });
    double res = 0;
    for (int i = 0; i < n; i++)
    {
        if (W >= arr[i].weight)
        {
            res += arr[i].value;
            W -= arr[i].weight;
        }
        else
        {
            res = res + (double)(arr[i].value * W) / arr[i].weight;
            W = 0;
            break;
        }
    }
    return res;
}
int main()
{

    int w = 50;
    Item arr[] = {
        {60, 10}, {100, 20}, {120, 30}};

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << fractionalKnapstack(w, arr, n);
    return 0;
}

////sort(arr, arr + n, [&](Item &a, Item &b)
////     {
////             double d1 = (double) a.value/a.weight;
////             double d2 = (double) b.value/b.weight;
////             return d1 > d2; });
////double res = 0;
////for (int i = 0; i < n; i++)
////{
////    if (W >= arr[i].weight)
////    {
////        res += arr[i].value;
////        W -= arr[i].weight;
////    }
////    else
////    {
////        res = res + (double)(arr[i].value * W) / arr[i].weight;
////        W = 0;
////        break;
////    }
////}
////return res;