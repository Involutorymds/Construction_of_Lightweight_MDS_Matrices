
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "matrix.h"
using namespace std;

vector<vector<ROW>>get_per_class(vector<ROW> m) {
	int block_per_num = 1;
	for (int i = 1; i <= BLOCK_ORDER; i++) {
		block_per_num *= i;
	}
	vector<vector<ROW>> matrix_per_class;
	vector<vector<int>> block_per_tab;
	vector<ROW> temp1(SIZE);
	vector<int> temp2(SIZE);
	matrix_per_class.resize(block_per_num * block_per_num, temp1);
	block_per_tab.resize(block_per_num, temp2);

	int per_class_num = 0;
	int per_class[BLOCK_ORDER] = { 0 };
	
	for (int i = 0; i <BLOCK_ORDER; i++) { per_class[i] = i; }
	do
	{
		for (int i = 0; i <BLOCK_ORDER; i++) {
			for (int j = 0; j < SBOX_SIZE; j++) {
				block_per_tab[per_class_num][SBOX_SIZE * i + j] = per_class[i] * SBOX_SIZE + j;
			}
		}
		per_class_num++;
	} while (next_permutation(per_class, per_class +BLOCK_ORDER));


	int num = 0;
	for (int i = 0; i < block_per_tab.size(); i++) {
		for (int j = 0; j < block_per_tab.size(); j++) {
			for (int k = 0; k < m.size(); k++) {
				bitset<SIZE> tmp(0);
				for (int l = 0; l < m.size(); l++) {
					tmp[l] = m[block_per_tab[i][k]][block_per_tab[j][l]];
				}
				matrix_per_class[num][k]=tmp;
			}

			num++;
		}

	}
	return matrix_per_class;
}

vector<vector<ROW>> get_per_class_random(vector<ROW> m) {
	srand((int)time(0));
	vector<vector<ROW>> matrix_per_class;
	vector<vector<int>> block_perP;
	vector<vector<int>> block_perQ;
	vector<int> random_tableP;
	vector<int> random_tableQ;
	vector<ROW> temp1(SIZE);
	vector<int> temp2(SIZE);
	matrix_per_class.resize(random_time * random_time, temp1);
	block_perP.resize(random_time, temp2);
	block_perQ.resize(random_time, temp2);
	random_tableP.resize(random_time);
	random_tableQ.resize(random_time);

	int block_per_num = 1;
	for (int i = 1; i <=BLOCK_ORDER; i++) {
		block_per_num *= i;
	}
	for (int i = 0; i < random_time; i++) {
		random_tableP[i] = rand() % block_per_num;
		random_tableQ[i] = rand() % block_per_num;
	}


	block_per_num = 0;
	int ran_per_numP = 0;
	int ran_per_numQ = 0;
	int per_class[BLOCK_ORDER] = { 0 };
	for (int i = 0; i <BLOCK_ORDER; i++) per_class[i] = i;
	do
	{
		for (int num = 0; num < random_time; num++) {
			if (block_per_num == random_tableP[num]) {
				for (int i = 0; i <BLOCK_ORDER; i++) {
					for (int j = 0; j < SBOX_SIZE; j++) {
						block_perP[ran_per_numP][SBOX_SIZE * i + j] = per_class[i] * SBOX_SIZE + j;
					}
				}
				ran_per_numP++;
			}
			if (block_per_num == random_tableQ[num]) {
				for (int i = 0; i <BLOCK_ORDER; i++) {
					for (int j = 0; j < SBOX_SIZE; j++) {
						block_perQ[ran_per_numQ][SBOX_SIZE * i + j] = per_class[i] * SBOX_SIZE + j;
					}
				}
				ran_per_numQ++;
			}
		}
		block_per_num++;
	} while (next_permutation(per_class, per_class +BLOCK_ORDER));


	int num = 0;
	for (int i = 0; i < random_time; i++) {
		for (int j = 0; j < random_time; j++) {
			for (int k = 0; k < m.size(); k++) {
				bitset<SIZE> tmp(0);
				for (int l = 0; l < m.size(); l++) {
					tmp[l] = m[block_perP[i][k]][block_perQ[j][l]];
				}
				matrix_per_class[num][k] = tmp;
			}

			num++;
		}

	}
	return matrix_per_class;
}








