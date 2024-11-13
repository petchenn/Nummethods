#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "Header.h"
using namespace std;

void generateMatrix(vector<double>& p, vector<double>& f, vector<double>& down, vector<double>& up, vector<double>& center /*, int & _SIZE, int & _pInd*/) {
    //( rand() % 101 - 50 ) / 10.0
    //_SIZE = 5 + rand() % 10;
    //_pInd = 3 + rand() % (_SIZE - 4);

    center.resize(SIZE);
    up.resize(SIZE - 1);
    down.resize(SIZE - 1);
    f.resize(SIZE);
    p.resize(SIZE);

    for(int i = 0; i < SIZE; i++) {
        p[i] = (rand() % 100001 - 50) / 10.0;
        f[i] = (rand() % 100001 - 50) / 10.0;
        center[i] = (rand() % 100001 - 50) / 10.0;
        if (i != SIZE - 1) {
            up[i] = (rand() % 100001 - 50) / 10.0;
            down[i] = (rand() % 100001 - 50) / 10.0;
        }
    }

    center[SIZE - pInd] = p[SIZE - pInd];
    down[SIZE - pInd] = p[SIZE - pInd + 1];
    up[SIZE - pInd - 1] = p[SIZE - pInd - 1];

    printMatrix(p, f, down, up, center);
}

void readMatrixFromFile(const string& filename, vector<double>& p, vector<double>& f, vector<double>& down, vector<double>& up, vector<double>& center) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "file didn't open" << endl;
        return;
    }

    center.resize(SIZE);
    up.resize(SIZE-1);
    down.resize(SIZE - 1);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE + 1; j++) {
            double c;
            file >> c;

            if (j == pInd - 1) {
                p.push_back(c);
            }
            if (j == SIZE) {
                f.push_back(c);
            }

            if (j == SIZE - 2 - i && i < SIZE - 1) {
                up[i] = c;
            } 
            else if (j == SIZE - 1 - i  && i > 0 && i <= SIZE ) {
                center[i] = c;
            }
            else if (i > 0 && j == SIZE - i) {
                down[i - 1] = c;
            }
            if (i == 0 && j == SIZE - 1) {
                center[0] = c;
            }

        }
    }

    //считывать в 1массив, забирать оттуда 5 элемент, i, i+1, i+2 - так дл€ всех строчек, кроме первой и последней. Ќачинать с n-3 элемента, заканчивать 0.



    file.close();
}

// ‘ункци€ дл€ вывода матрицы на экран
void printMatrix(vector<double> p, vector<double> f, vector<double> down, vector<double> up, vector<double> center) {
    cout << "p:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << p[i] << ' ';
    }
    cout << endl;
    cout << "centr:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << center[i] << ' ';
    }
    cout << endl;
    cout << "f:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << f[i] << ' ';
    }
    cout << endl;
    cout << "up:\n";
    for (int i = 0; i < SIZE-1; i++) {
        cout << up[i] << ' ';
    }
    cout << endl;
    cout << "down:\n";
    for (int i = 0; i < SIZE-1; i++) {
        cout << down[i] << ' ';
    }
    cout << endl;
    cout << endl;
}

void first(vector<double>& p, vector<double>& f, vector<double>& down, vector<double>& up, vector<double>& center) { //права€ нижн€€ часть диагонали
    for (int i = 0; i < SIZE - pInd; i++) {
        double curCenter = center[i];
        center[i] = 1;
        p[i] = p[i] / curCenter;
        up[i] = up[i] / curCenter;
        f[i] = f[i] / curCenter;
        p[i + 1] -= p[i] * down[i];
        f[i + 1] -= f[i] * down[i];
        center[i + 1] -= up[i] * down[i];
        down[i] = 0;
    }
    printMatrix(p, f, down, up, center);
}

void third(vector<double>& p, vector<double>& f, vector<double>& down, vector<double>& up, vector<double>& center) { //лева€ нижн€€ часть диагонали
    for (int i = SIZE - pInd + 1; i < SIZE - 1; i++) {
        double curCenter = center[i];
        center[i] = 1;
        p[i] = p[i] / curCenter;
        up[i] = up[i] / curCenter;
        f[i] = f[i] / curCenter;
        p[i + 1] -= p[i] * down[i];
        f[i + 1] -= f[i] * down[i];
        center[i + 1] -= up[i] * down[i];
        down[i] = 0;
    }
    p[SIZE - 1] /= center[SIZE - 1];
    f[SIZE - 1] /= center[SIZE - 1];
    center[SIZE - 1] = 1;
    printMatrix(p, f, down, up, center);
}

void second(vector<double>& p, vector<double>& f, vector<double>& down, vector<double>& up, vector<double>& center) { // права€ верзн€€ часть
    for (int i = SIZE - pInd - 1; i > 0; i--) {
        p[i - 1] -= p[i] * up[i - 1];
        f[i - 1] -= f[i] * up[i - 1];
        up[i - 1] = 0;
    }
    printMatrix(p, f, down, up, center);
}

void forth(vector<double>& p, vector<double>& f, vector<double>& down, vector<double>& up, vector<double>& center) { // лева€ верхн€€ часть
    for (int i = SIZE-1; i > SIZE - pInd; i--) {
        p[i - 1] -= p[i] * up[i - 1];
        f[i - 1] -= f[i] * up[i - 1];
        up[i - 1] = 0;
    }
    printMatrix(p, f, down, up, center);
}

void fifth(vector<double>& p, vector<double>& f, vector<double>& down, vector<double>& up, vector<double>& center) { //одна крута€ строчка DIDNT WORK
    double curP = p[SIZE - pInd];
    double curF = f[SIZE - pInd] / curP;
    f[SIZE - pInd] = f[SIZE - pInd] / curP;
    //p[i] = p[pInd];
    for (int i = 0; i < SIZE; i++) {
        if (i != SIZE - pInd) f[i] -= curF * p[i];
        p[i] = 0;
    }
    p[SIZE - pInd] = 1;
    center[SIZE - pInd] = 1;
    down[SIZE - pInd] = 0;
    up[SIZE - pInd - 1] = 0;
    printMatrix(p, f, down, up, center);
}//индексы на побочной диагонали дают в сумме size-1

void generateF(vector<double> p, vector<double>& f_new, vector<double> down, vector<double> up, vector<double> center) { //work!!!!!
    for (int i = 0; i < SIZE; i++) {
        if (i == 0) {
            f_new[i] = center[i] + up[i] + p[i];
        }
        else if(i == SIZE-1){
            f_new[i] = center[i] + down[i - 1] + p[i];
        }
        else if(i == SIZE-pInd || i == SIZE-pInd-1 || i == SIZE-pInd+1){
            f_new[i] = center[i] + down[i - 1] + up[i];
        }
        else {
            f_new[i] = center[i] + down[i - 1] + up[i] + p[i];
        }
    }
    printMatrix(p, f_new, down, up, center);
}

//void unser(vector<double> f, vector<double>& x) {
//    for (int i = 0; i < SIZE; i++) {
//        x[i] = f[SIZE - i - 1];
//    }
//}

void diagonalizeMatrix(vector<double> p, vector<double> f, vector<double> down, vector<double> up, vector<double> center) {
        first( p, f, down, up, center);
        second(p, f, down, up, center);
        third(p, f, down, up, center);
        forth(p, f, down, up, center);
        fifth(p, f, down, up, center);
        cout << "unser:";
        for (int i = SIZE - 1; i > -1; i--) {
            cout << f[i] << ' ';
        }
        cout << endl;
        
        //printMatrix(p, f, down, up, center);
    } 

void err(vector<double> p, vector<double> f, vector<double> down, vector<double> up, vector<double> center) {
    generateF(p, f, down, up, center);
    first(p, f, down, up, center);
    second(p, f, down, up, center);
    third(p, f, down, up, center);
    forth(p, f, down, up, center);
    fifth(p, f, down, up, center);
    error_rate(f);
}


void error_rate(vector<double> f_new) {
    double curmax = 0;
    for (int i = 0; i < f_new.size(); i++) {
        f_new[i] = f_new[i] - 1 ;
        if (abs(f_new[i]) > abs(curmax)) {
            curmax = f_new[i];
        }
    }
    cout << "Error rate: " << curmax;
    cout << '\n';
}

void random_error_rate(vector<double> p, vector<double> f, vector<double> down, vector<double> up, vector<double> center) {
    vector<double> x_gen;
    x_gen.resize(SIZE);
    int testx = SIZE-1;
    cout << endl << "gener X:" << endl;
    for (int i = 0; i < SIZE; i++) {
        x_gen[i] = (rand() % 100001 - 50) / 100.0;
        //x_gen[i] = testx--;
        std::cout << x_gen[i] << ' ';
    }
    std::cout << endl;
    for (int i = 0; i < SIZE; i++) {
        if (i == 0) {
            f[i] = center[i]*x_gen[i] + up[i] * x_gen[i+1] + p[i] * x_gen[SIZE-pInd];
        }
        else if (i == SIZE - 1) {
            f[i] = center[i] * x_gen[i] + down[i - 1] * x_gen[i - 1] + p[i] * x_gen[SIZE - pInd];
        }
        else if (i == SIZE - pInd || i == SIZE - pInd - 1 || i == SIZE - pInd + 1) {
            f[i] = center[i] * x_gen[i] + down[i - 1] * x_gen[i - 1] + up[i] * x_gen[i+1];
        }
        else {
            f[i] = center[i] * x_gen[i] + down[i - 1] * x_gen[i - 1] + up[i] * x_gen[i + 1] + p[i] * x_gen[SIZE - pInd];
        }
    }

    cout << "f:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << f[i] << ' ';
    }
    cout << endl;
    first(p, f, down, up, center);
    second(p, f, down, up, center);
    third(p, f, down, up, center);
    forth(p, f, down, up, center);
    fifth(p, f, down, up, center);

    double curmax = 0;
    for (int i = 0; i < f.size(); i++) {
        f[i] = f[i] - x_gen[i];
        if (abs(f[i]) > abs(curmax)) {
            curmax = f[i];
        }
    };

    std::cout <<"Random error rate: " << curmax;
    std::cout << '\n';
}