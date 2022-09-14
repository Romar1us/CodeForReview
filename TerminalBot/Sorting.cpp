#include <iostream>;

using namespace std;

void SortArray(int* arr, int* SortedArray, int size) 
{
	for (int i = 0; i < size; i++)
	{

		int MaxIndex = 0;
		int MaxNumberInArray = arr[MaxIndex];
		for (int n = 1; n < size; n++)
		{
			if (arr[n] > MaxNumberInArray)
			{
				MaxNumberInArray = arr[n];
				MaxIndex = n;	
			}
		}
		arr[MaxIndex] = 0;
		SortedArray[i] = MaxNumberInArray;
	}
}

void FillArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		int n;
		cin >> n;
		arr[i] = n;
	}
}

void PrintArray(int* SortedArray, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << SortedArray[i] << endl;
	}
}
//void main()
//{
//	int ArraySize = 10;
//	int* arr = new int[ArraySize];
//	int* SortedArray = new int[ArraySize];
//
//	FillArray(arr, ArraySize);
//	SortArray(arr, SortedArray, ArraySize);
//	PrintArray(SortedArray, ArraySize);
//
//	delete[]arr;
//	delete[]SortedArray;
//}

