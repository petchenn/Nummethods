/*                              F
1   0 0 0 0 * 0 0 0 0 0 * *     *
2   0 0 0 0 * 0 0 0 0 * * *     *
3   0 0 0 0 * 0 0 0 * * * 0     *
4   0 0 0 0 * 0 0 * * * 0 0     *
5   0 0 0 0 * 0 * * * 0 0 0     *
6   0 0 0 0 * * * * 0 0 0 0     *
7   0 0 0 0 * * * 0 0 0 0 0     *
8   0 0 0 * * * 0 0 0 0 0 0     *
9   0 0 * * * 0 0 0 0 0 0 0     *
10  0 * * * * 0 0 0 0 0 0 0     *
11  * * * 0 * 0 0 0 0 0 0 0     *
12  * * 0 0 * 0 0 0 0 0 0 0     *
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "Header.h"


int main()
{
	
	vector<double> center;
    vector<double> up;
    vector<double> down;
    vector<double> f;
    vector<double> p;
    vector<double> x;
    srand(time(0));
    // Считываем матрицу из файла
    //readMatrixFromFile("matrix.txt", p, f, down, up, center);
    //cout << "matrix:" << endl;

    //printMatrix(p, f, down, up, center);
    //cout << '\n' << "NORMAL: ----------------------------- \n\n";


    ////generateMatrix(p, f, down, up, center);
    //diagonalizeMatrix(p, f, down, up, center);
    ////generateF(p, f, down, up, center);
    //cout << '\n' << "NORMAL ERROR: -------------------------------- \n\n";
    //err(p, f, down, up, center);

    //cout << '\n' << "RANDOM ERROR: -------------------------------- \n \n";
    //random_error_rate(p, f, down, up, center);

    generateMatrix(p, f, down, up, center);

    cout << "RANDOM matrix:" << endl;

    printMatrix(p, f, down, up, center);

    cout << '\n' << "RANDOM NORMAL ERROR: -------------------------------- \n\n";
    err(p, f, down, up, center);

    printMatrix(p, f, down, up, center);

    cout << '\n' << "RANDOM RANDOM ERROR: -------------------------------- \n \n";
    random_error_rate(p, f, down, up, center);

    return 0;
}