
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
#include "results.h"

//****************************************************************************************************

void getData(int list[], int size, const char filename[]);
void insertionSort(int list[], int size, int & comp, int & cpy);
void selectionSort(int list[], int size, int & comp, int & cpy);
void bubbleSort(int list[], int size, int & comp, int & cpy);
void shellSort(int list[], int size, int & comp, int & cpy);
void heapSort(int list[], int size, int & comp, int & cpy);
void  _siftUp(int list[], int child, int & comp, int & cpy);
void  _siftDown(int list[], int parent, int numValues, int & comp, int & cpy);
void quickSort(int list[], int size, int & comp, int & cpy);
void _quickSort(int list[], int left, int right, int & comp, int & cpy);
void putMedianLeft(int list[], int left, int right, int& comp, int& cpy);
int partition(int list[], int left, int right, int & comp, int & cpy);
void calcResults(Results & result);
void displayResults(Results iResults, Results sResults, Results bResults,
	Results shResults, Results hResults, Results qResults);

//****************************************************************************************************

int main()
{
	int ordered[1000],
		unordered[1000],
		reversed[1000];

	Results	iResults,
		sResults,
		bResults,
		shResults,
		hResults,
		qResults;

	getData(ordered, 1000, "ordered.txt");
	getData(unordered, 1000, "unordered.txt");
	getData(reversed, 1000, "reversed.txt");
	insertionSort(ordered, 1000, iResults.ordCompares, iResults.ordCopies);
	insertionSort(unordered, 1000, iResults.unOrdCompares, iResults.unOrdCopies);
	insertionSort(reversed, 1000, iResults.revOrdCompares, iResults.revOrdCopies);
	calcResults(iResults);

//****************************************************************************************************

	getData(ordered, 1000, "ordered.txt");
	getData(unordered, 1000, "unordered.txt");
	getData(reversed, 1000, "reversed.txt");
	selectionSort(ordered, 1000, sResults.ordCompares, sResults.ordCopies);
	selectionSort(unordered, 1000, sResults.unOrdCompares, sResults.unOrdCopies);
	selectionSort(reversed, 1000, sResults.revOrdCompares, sResults.revOrdCopies);
	calcResults(sResults);

//****************************************************************************************************

	getData(ordered, 1000, "ordered.txt");
	getData(unordered, 1000, "unordered.txt");
	getData(reversed, 1000, "reversed.txt");
	bubbleSort(ordered, 1000, bResults.ordCompares, bResults.ordCopies);
	bubbleSort(unordered, 1000, bResults.unOrdCompares, bResults.unOrdCopies);
	bubbleSort(reversed, 1000, bResults.revOrdCompares, bResults.revOrdCopies);
	calcResults(bResults);

//****************************************************************************************************

	getData(ordered, 1000, "ordered.txt");
	getData(unordered, 1000, "unordered.txt");
	getData(reversed, 1000, "reversed.txt");
	shellSort(ordered, 1000, shResults.ordCompares, shResults.ordCopies);
	shellSort(unordered, 1000, shResults.unOrdCompares, shResults.unOrdCopies);
	shellSort(reversed, 1000, shResults.revOrdCompares, shResults.revOrdCopies);
	calcResults(shResults);

//****************************************************************************************************

	getData(ordered, 1000, "ordered.txt");
	getData(unordered, 1000, "unordered.txt");
	getData(reversed, 1000, "reversed.txt");
	heapSort(ordered, 1000, hResults.ordCompares, hResults.ordCopies);
	heapSort(unordered, 1000, hResults.unOrdCompares, hResults.unOrdCopies);
	heapSort(reversed, 1000, hResults.revOrdCompares, hResults.revOrdCopies);
	calcResults(hResults);

//****************************************************************************************************

	getData(ordered, 1000, "ordered.txt");
	getData(unordered, 1000, "unordered.txt");
	getData(reversed, 1000, "reversed.txt");
	quickSort(ordered, 1000,  qResults.ordCompares, qResults.ordCopies);
	quickSort(unordered, 1000, qResults.unOrdCompares, qResults.unOrdCopies);
	quickSort(reversed, 1000, qResults.revOrdCompares, qResults.revOrdCopies);
	calcResults(qResults);

//****************************************************************************************************

	displayResults(iResults, sResults, bResults, shResults, hResults, qResults);

	return 0;
}

//****************************************************************************************************

void getData(int list[], int size, const char filename[])
{

	int number = 0;

	ifstream myFile;
	myFile.open(filename);

	while ((number < size) && (myFile >> list[number]))
	{
		number++;
	}

	myFile.close();
}

//****************************************************************************************************

void insertionSort(int list[], int size, int & comp, int & cpy)
{
	int hold,
		j;

	for (int i = 1; i < size; i++)
	{
		hold = list[i];

		for (j = i - 1; (j >= 0) && (++comp) && (list[j] > hold); j--)
		{
			list[j + 1] = list[j];
			cpy++;
		}

		list[j + 1] = hold;
		cpy = cpy + 2;
	}
}

//****************************************************************************************************

void selectionSort(int list[], int size, int & comp, int & cpy)
{
	int min;

	for (int i = 0; i < (size - 1); i++)
	{
		min = i;

		for (int j = i + 1; j < size; j++)
		{
			comp++;

			if (list[j] < list[min])
			{
				min = j;
			}
		}

		swap(list[i], list[min]);
		cpy = cpy + 3;
	}
}

//****************************************************************************************************

void bubbleSort(int list[], int size, int & comp, int & cpy)
{
	bool didSwap = true;

	for (int i = 0; (didSwap) && (i < (size - 1)); i++)
	{
		didSwap = false;

		for (int j = (size - 1); j > i; j--)
		{
			comp++;

			if (list[j] < list[j - 1])
			{
				swap(list[j], list[j - 1]);
				didSwap = true;
				cpy = cpy + 3;
			}
		}
	}
}

//****************************************************************************************************

void shellSort(int list[], int size, int & comp, int & cpy)
{
	int hold,
		j;

	for (int gap = size / 2; gap >= 10; gap = gap / 2)
	{
		if (gap % 2 == 0)
		{
			gap++;
		}

		for (int i = gap; i < size; i++)
		{
			hold = list[i];

			for (j = (i - gap); (j >= 0) && (++comp) && (hold < list[j]); j = j - gap)
			{
				cpy++;
				list[j + gap] = list[j];

			}

			list[j + gap] = hold;
			cpy = cpy + 2;
		}
	}

	insertionSort(list, size, comp, cpy);
}

//****************************************************************************************************

void heapSort(int list[], int size, int & comp, int & cpy)
{
	for (int i = 1; i < size; i++)
	{
		_siftUp(list, i, comp, cpy);
	}

	for (int j = (size - 1); j > 0; j--)
	{
		swap(list[j], list[0]);
		cpy = cpy + 3;
		_siftDown(list, 0, j, comp, cpy);
	}
}

//****************************************************************************************************

void  _siftUp(int list[], int child, int & comp, int & cpy)
{
	int parent;

	if (child > 0)
	{
		parent = (child - 1) / 2;

		comp++;

		if (list[child] > list[parent])
		{
			swap(list[child], list[parent]);
			cpy = cpy + 3;
			_siftUp(list, parent, comp, cpy);
		}
	}
}

//****************************************************************************************************

void  _siftDown(int list[], int parent, int numValues, int & comp, int & cpy)
{
	int child = (2 * parent + 1);

	if (child < numValues)
	{
		if (((child + 1) < numValues) && (++comp) && (list[child + 1] > list[child]))
		{
			child++;
		}

		comp++;

		if (list[parent] < list[child])
		{
			swap(list[parent], list[child]);
			cpy = cpy +3;
			_siftDown(list, child, numValues, comp, cpy);
		}
	}
}

//****************************************************************************************************

void quickSort(int list[], int size, int & comp, int & cpy)
{

	_quickSort(list, 0, (size - 1), comp, cpy);
	insertionSort(list, size, comp, cpy);

}

//****************************************************************************************************

void _quickSort(int list[], int left, int right, int & comp, int & cpy)
{
	int pivotPt;

	if ((right - left + 1) > 10)
	{
		putMedianLeft(list, left, right, comp, cpy);
		pivotPt = partition(list, left, right, comp, cpy);
		_quickSort(list, left, (pivotPt - 1), comp, cpy);
		_quickSort(list, (pivotPt + 1), right, comp, cpy);
	}
}

//****************************************************************************************************

void putMedianLeft(int list[], int left, int right, int & comp, int & cpy)
{
	int center = (left + right) / 2;

	comp++;
	if (list[left] < list[center])
	{
		swap(list[left], list[center]);
		cpy = cpy + 3;
	}

	comp++;
	if (list[center] > list[right])
	{
		swap(list[center], list[right]);
		cpy = cpy + 3;
	}
	
	comp++;
	if (list[right] < list[left])
	{
		swap(list[right], list[left]);
		cpy = cpy + 3;
	}
}

//****************************************************************************************************

int partition(int list[], int left, int right, int & comp, int & cpy)
{
	int lte = left + 1;
	int gt = right;

	while (lte <= gt)
	{
		while ((++comp) && (list[lte] <= list[left]))
		{
			lte++;
		}

		while ((++comp) && (list[gt] > list[left]))
		{
			gt--;
		}

		if (lte < gt)
		{
			swap(list[gt], list[lte]);
			cpy = cpy + 3;
			lte++;
			gt--;
		}
	}

	swap(list[gt], list[left]);
	cpy = cpy + 3;

	return gt;
}

//****************************************************************************************************

void calcResults(Results & result)
{
	result.avgCompares = (result.ordCompares + result.unOrdCompares + result.revOrdCompares) / 3;

	result.avgCopies = (result.ordCopies + result.unOrdCopies + result.revOrdCopies) / 3;
}

//****************************************************************************************************

void displayResults(Results iResults, Results sResults, Results bResults,
	Results shResults, Results hResults, Results qResults)
{

	cout << "                                        Compares / Copies                       " << endl;
	cout << "                   Ordered  " << "               UnOrdered       "
		 << "      Reversed  " 
	     << "                  Average " << endl;

	cout << " Insertion :   " << right << setw(5) << setw(5) << left << setw(5) << iResults.ordCompares << " / "
		<< right << setw(5) << iResults.ordCopies << "          " << left << setw(5) << iResults.unOrdCompares << " / "
		<< right << setw(5) << iResults.unOrdCopies << "          " << left << setw(5) << iResults.revOrdCompares << " / "
		<< right << setw(5) << iResults.revOrdCopies << "          " << left << setw(10) << iResults.avgCompares << " / "
		<< right << setw(5) << iResults.avgCopies << endl;

	cout << " Selection:   " << right << setw(5) << setw(5) << left << setw(5) << sResults.ordCompares << " / "
		<< right << setw(5) << sResults.ordCopies << "          " << left << setw(5) << sResults.unOrdCompares << " / "
		<< right << setw(5) << sResults.unOrdCopies << "          " << left << setw(5) << sResults.revOrdCompares << " / "
		<< right << setw(5) << sResults.revOrdCopies << "          " << left << setw(5) << sResults.avgCompares << " / "
		<< right << setw(5) << sResults.avgCopies << endl;

	cout << " Bubble :       " << right << setw(5) << setw(5) << left << setw(5) << bResults.ordCompares << " / "
		<< right << setw(5) << bResults.ordCopies << "          " << left << setw(5) << bResults.unOrdCompares << " / "
		<< right << setw(5) << bResults.unOrdCopies << "          " << left << setw(5) << bResults.revOrdCompares << " / "
		<< right << setw(5) << bResults.revOrdCopies << "          " << left << setw(5) << bResults.avgCompares << " / "
		<< right << setw(5) << bResults.avgCopies << endl;

	cout << " Shell :       " << right << setw(5) << setw(5) << left << setw(5) << shResults.ordCompares << " / "
		<< right << setw(5) << shResults.ordCopies << "          " << left << setw(5) << shResults.unOrdCompares << " / "
		<< right << setw(5) << shResults.unOrdCopies << "          " << left << setw(5) << shResults.revOrdCompares << " / "
		<< right << setw(5) << shResults.revOrdCopies << "          " << left << setw(5) << shResults.avgCompares << " / "
		<< right << setw(5) << shResults.avgCopies << endl;

	cout << " Heap :        " << right << setw(5) << setw(5) << left << setw(5) << hResults.ordCompares << " / "
		<< right << setw(5) << hResults.ordCopies << "          " << left << setw(5) << hResults.unOrdCompares << " / "
		<< right << setw(5) << hResults.unOrdCopies << "          " << left << setw(5) << hResults.revOrdCompares << " / "
		<< right << setw(5) << hResults.revOrdCopies << "          " << left << setw(5) << hResults.avgCompares << " / "
		<< right << setw(5) << hResults.avgCopies << endl;

	cout << " Quick :         " << right << setw(5) << setw(5) << left << setw(5) << qResults.ordCompares << " / "
		<< right << setw(5) << qResults.ordCopies << "          " << left << setw(5) << qResults.unOrdCompares << " / "
		<< right << setw(5) << qResults.unOrdCopies << "          " << left << setw(5) << qResults.revOrdCompares << " / "
		<< right << setw(5) << qResults.revOrdCopies << "          " << left << setw(5) << qResults.avgCompares << " / "
		<< right << setw(5) << qResults.avgCopies << endl;
}

//****************************************************************************************************
//							Program Output
//****************************************************************************************************

/*

	                                        Compares / Copies
                   Ordered                 UnOrdered             Reversed                    Average
 Insertion :   999   /  1998          257314 / 258317          499500 / 501498          252604     / 253937
 Selection:   499500 /  2997          499500 /  2997          499500 /  2997          499500 /  2997
 Bubble :       999   /     0          499065 / 768957          499500 / 1498500          333188 / 755819
 Shell :       6013  / 12026          20949 / 27513          13781 / 20780          13581 / 20106
 Heap :        22462 / 47922          17194 / 28575          15965 / 24948          18540 / 33815
 Quick :         8387  /  2760          10983 /  9179          8387  /  4260          9252  /  5399


*/