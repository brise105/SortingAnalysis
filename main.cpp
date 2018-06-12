//Brandon Briseno | SID: 1932124 | CPSC 350-01: Data Structures (German)
//Program Description: this program runs four algorthims and sorts numbers from a .txt

#include <iostream>
#include "Sorting.h"

using namespace std;

int main(int argc, char** argv)
{
    Sorting a;
    if (argc != 2)
    {
		cout << "Expected input: <./a.out test.txt>" << endl;
		exit(0);
    }
    else {
        if (a.fValid(argv[1])) {
            a.fRead();
        }
        else {
            cout << "\nERROR: File not found!"<< endl;
        }
    }

    return 0;
}
