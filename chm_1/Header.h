#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
//#include <ctime>
//#include <cstdlib>

using namespace std;
const int SIZE = 10;
const int pInd = 7;

void generateMatrix(vector<double>& p, vector<double>& f, vector<double>& down, vector<double>& up, vector<double>& center/*, int& _SIZE, int& _pInd*/);
void readMatrixFromFile(const string& filename, vector<double>& p, vector<double>& f, vector<double>& down, vector<double>& up, vector<double>& center);
void printMatrix(vector<double> p, vector<double> f, vector<double> down, vector<double> up, vector<double> center);
void first(vector<double>& p, vector<double>& f, vector<double>& down, vector<double>& up, vector<double>& center);
void second(vector<double>& p, vector<double>& f, vector<double>& down, vector<double>& up, vector<double>& center);
void third(vector<double>& p, vector<double>& f, vector<double>& down, vector<double>& up, vector<double>& center);
void forth(vector<double>& p, vector<double>& f, vector<double>& down, vector<double>& up, vector<double>& center);
void fifth(vector<double>& p, vector<double>& f, vector<double>& down, vector<double>& up, vector<double>& center);
void generateF(vector<double> p, vector<double>& f, vector<double> down, vector<double> up, vector<double> center);
void diagonalizeMatrix(vector<double> p, vector<double> f, vector<double> down, vector<double> up, vector<double> center);
void error_rate(vector<double> f_new);
void err(vector<double> p, vector<double> f, vector<double> down, vector<double> up, vector<double> center);
void random_error_rate(vector<double> p, vector<double> f, vector<double> down, vector<double> up, vector<double> center);
