//Brandon Briseno | SID: 1932124 | CPSC 350-01: Data Structures (German)
//Program Description: this program runs four algorthims and sorts numbers from a .txt

#ifndef SORTING_H
#define SORTING_H

using namespace std;

class Sorting
{
private:
    string fileName;
    int eleCount;

    double *insertSortArray;
    double *selectionSortArray;
    double *bubbleSortArray;
    double *quickSortArray;

public:
	Sorting();
	~Sorting();

	bool fValid(string name);
	void fRead();

    void insertionSort(double array[]);
    void selectionSort(double array[], int n);
	void bubbleSort(double array[]);
    void quickSort(double array[], int left, int right);
    int partition(double array[], int left, int right);

    void runAlgorthims();
};
#endif