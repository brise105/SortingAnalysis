//Brandon Briseno | SID: 1932124 | CPSC 350-01: Data Structures (German)
//Program Description: this program runs four algorthims and sorts numbers from a .txt

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "Sorting.h"

using namespace std;

Sorting::Sorting(){};

Sorting::~Sorting()
{
    delete [] insertSortArray;
    delete [] selectionSortArray;	
	delete [] bubbleSortArray;
    delete [] quickSortArray;
}

bool Sorting::fValid(string fName)
{
	ifstream fileCheck;
	fileCheck.open(fName.c_str());

	if (fileCheck.is_open()) {
		cout << fName.c_str() << " has been opened!" << endl;
		fileCheck.close();
		fileName = fName;

		return true;
	} else {
		return false;
	}
}

void Sorting::fRead()
{
    ifstream fileIn;
    fileIn.open(fileName.c_str());

    string eleCountStr;
    string line;
    double num;
    int lineCount = 1;

    getline(fileIn, eleCountStr);
    eleCount = stoi(eleCountStr);

    insertSortArray = new double[eleCount];
    selectionSortArray = new double[eleCount];
    bubbleSortArray = new double[eleCount];
    quickSortArray = new double[eleCount];

    //iteratively count lines and fill arrays w/ elements
    for (int i = 0; i < eleCount; ++i) {
        lineCount++;
        getline(fileIn, line);
        num = stod(line); // parse to double

        insertSortArray[i] = num;
        selectionSortArray[i] = num;
        bubbleSortArray[i] = num;
        quickSortArray[i] = num;
    }
    fileIn.close();
    runAlgorthims();
}

void Sorting::insertionSort(double array[])
{
    for (int j = 1; j < eleCount; ++j) {
        double temp = array[j]; //dupe ele at curr
        int k = j; //set flagged ele equal to curr
        while (k > 0 && array[k-1] >= temp) { //while element to left of k is greater than curr
            array[k] = array[k-1]; //shift
            --k;
        }
        array[k] = temp; //set flagged equal to dupe
    }
}

void Sorting::selectionSort(double array[], int n)
{
	int i;
	int j;
	int minIndex;
	double temp;
	for (i = 0; i < n; ++i) {
		minIndex = i;
		for (j = i; j < n; ++j) {
			if (array[j] < array[minIndex]) {
				minIndex = j;
			}
			if (minIndex != i) {
				temp = array[i];
				array[i] = array[minIndex];
				array[minIndex] = temp;
			}
		}
	}
}

void Sorting::bubbleSort(double array[])
{
    for(int i = 0; i < eleCount-1; ++i) {
        int temp = 0;
        for (int j = 0; j < eleCount - 1 - i; ++j) {
            if(array[j] > array[j+1]) {
                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }
}

void Sorting::quickSort(double array[], int left, int right)
{
    int index = partition(array, left, right);

    //sort left
    if (left < index - 1) {
        quickSort(array, left, index - 1);
    }

    //sort right
    if (index < right) {
        quickSort(array, index, right);
    }
}

int Sorting::partition(double array[], int left, int right)
{
    //split array at marker
    int marker = array[(left + right) / 2];

    while (left <= right) {
        //move elements on left side to the right
        while (array[left] < marker) {
            left++;
        }
        //move elements on right side to the left
        while (array[right] > marker) {
            right--;
        }
        //temp swap and shift sides
        if (left <= right) {
            double temp = array[left];
    		array[left] = array[right];
    		array[right] = temp;

            left++;
            right--;
        }
    }

    return left;
}

void Sorting::runAlgorthims()
{
    cout << "The algorthims have begun to sort!\nPLEASE BE PATIENT!\r\n";

    clock_t beginT;
    clock_t endT;

    //begin insertion sort
    beginT = clock();
    insertionSort(insertSortArray);
    endT = clock();
    printf("\nIt took InsertionSort %.2fms to sort %d elements.\n", (float(endT - beginT)/CLOCKS_PER_SEC) * 1000, eleCount);

    //begin selection sort
    beginT = clock();
    selectionSort(selectionSortArray, eleCount);
    endT = clock();
    printf("\nIt took SelectionSort %.2fms to sort %d elements.\n", (float(endT - beginT)/CLOCKS_PER_SEC) * 1000, eleCount);
    //begin bubble sort
    beginT = clock();
    bubbleSort(bubbleSortArray);
    endT = clock();
    printf("\nIt took BubbleSort %.2fms to sort %d elements.\n", (float(endT - beginT)/CLOCKS_PER_SEC) * 1000, eleCount);

    //begin quick sort
    beginT = clock();
    quickSort(quickSortArray, 0, eleCount - 1);
    endT = clock();
    printf("\nIt took QuickSort %.2fms to sort %d elements.\n", (float(endT - beginT)/CLOCKS_PER_SEC) * 1000, eleCount);
}