#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <bitset>
#include <iostream>


using namespace std;

#define MULTI_THREAD_FLAG 1
#define THREAD_NUM 4


#define SIZE 16
#define SBOX_SIZE 4
#define BLOCK_ORDER 4
#define random_time 5
#define FILENAME "COST.txt"




typedef bitset<SIZE> ROW;

vector<vector<ROW>> get_per_class(vector<ROW> m);
vector<vector<ROW>> get_per_class_random(vector<ROW> m);

typedef struct{
    int src;
    int dst;
    bool flag;
}xpair;

typedef struct
{
    vector<xpair> seq;
    int gap;
    int start;
    int len;
}thread_data;

vector<ROW> get_matrix();


#endif
