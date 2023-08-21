#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int mainArr[N];

void mergeSort(int l, int r);
void merge(int l, int r, int mid);
void printArray(int ar[], int sz);



void mergeSort(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    merge(l, r, mid);
}

void merge(int l, int r, int mid)
{
    int leftSz = mid - l + 1;
    int leftArr[leftSz + 1];

    for (int i = l, j = 0; i <= mid; i++, j++)
    {
        leftArr[j] = mainArr[i];
    }

    int rightSz = r - mid;
    int rightArr[rightSz + 1];

    for (int i = mid + 1, j = 0; i <= r; i++, j++)
    {
        rightArr[j] = mainArr[i];
    }

    leftArr[leftSz] = INT_MIN;
    rightArr[rightSz] = INT_MIN;

    int leftPtr = 0, rightPtr = 0;
    for (int i = l; i <= r; i++)
    {
        if (leftArr[leftPtr] >= rightArr[rightPtr])
        {
            mainArr[i] = leftArr[leftPtr];
            leftPtr++;
        }

        else
        {
            mainArr[i] = rightArr[rightPtr];
            rightPtr++;
        }
    }
}

void printArray(int ar[], int sz)
{
    for (int i = 0; i < sz; i++)
        cout << ar[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> mainArr[i];

    mergeSort(0, n - 1);
    printArray(mainArr, n);

    return 0;
}