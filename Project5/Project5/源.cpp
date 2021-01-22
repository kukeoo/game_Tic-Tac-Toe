#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

void bubble_sort(int v[], int length)
{
    for (int i = length; i > 1; --i)
    {
        int flag = 1;
        for (int j = 0; j < i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                int temp = 0;
                temp = v[j + 1];
                v[j + 1] = v[j];
                v[j] = temp;
                flag = 0;
            }
        }
        if (flag == 1)
        {
            break;
        }

    }
}


int main()
{
    int arr[] = { 1,5,3,8,6,7,4 };
    const int length = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, length);
    for (int k = 0; k < 7; k++)
    {
        cout << arr[k] << endl;
    }
    return 0;
}