#pragma once
#include <iostream>	

namespace Algorithms
{
	inline int* BubbleSort(int* Data, size_t Size)
	{
		for (int i = 0; i < Size; i++)
		{
			if (Data[i] > Data[i + 1])
			{

				int j = Data[i];
				Data[i] = Data[i + 1];
				Data[i + 1] = j;

			}

		}
		return Data;
	}

	inline int* InsertionSort(int* Data, size_t Size) {
		for (size_t i = 1; i < Size; ++i) {
			int value = Data[i];
			size_t j = i;

			while (j > 0 && Data[j - 1] > value) {
				Data[j] = Data[j - 1];
				--j;
			}

			Data[j] = value;
		}
		return Data;
	}

inline int* SelectionSort(int* Data, size_t Size)
	{
		return nullptr;
	}


	inline int* HeapSort(int* Data, size_t Size)
	{
		return nullptr;
	}


	inline int* MergeSort(int* Data, size_t Size)
	{
		return nullptr;
	}


	inline int* QuickSort(int* Data, size_t Size)
	{
		return nullptr;
	}


	inline int* BinSort(int* Data, size_t Size)
	{
		return nullptr;
	}


	inline int* LinierSearch(int* Data, size_t Size, int target)
	{
		return nullptr;
	}


	inline int* BinarySearch(int* Data, size_t Size, int target)
	{
		return nullptr;
	}
}

