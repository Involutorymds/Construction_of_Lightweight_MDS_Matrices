#include "strategy.h"
#include "matrix.h"
#include "reduce.h"
#include <fstream>


void print_seq(vector<ROW> m, vector<ROW> tmp_m, vector<xpair> seq);
int main()
{
	int counter = 100000;
	

	int num = 0;
	cout<<FILENAME<<endl;



	vector<vector<ROW>> matrix_per_class;
	vector<ROW> m = get_matrix();
	//matrix_per_class = get_per_class_random(m);
	matrix_per_class = get_per_class(m);
	

	
	
		
	for (int i = 0; i < matrix_per_class.size(); i++) {

		vector<xpair> seq = reduce(matrix_per_class[i]);

		vector<ROW> tmp_m = get_reduced_matrix(seq, matrix_per_class[i]);

		cout << "minimal = " << counter << "   current = " << seq.size() << endl << endl;

		if(seq.size() < counter)
		{
			counter = seq.size();
			print_seq(matrix_per_class[i], tmp_m, seq);
			
		}



	}


	return 0;
}

void print_seq(vector<ROW> m, vector<ROW> tmp_m, vector<xpair> seq)
{
	ofstream f;
	f.open(FILENAME);
	f << "Original Matrix:" << endl;
	for(int i = 0; i < m.size(); i++)
		f << m[i] << endl;
	f << endl << endl;
	f << "Reduced Matrix:" << endl;
	for(int i = 0; i < tmp_m.size(); i++)
		f << tmp_m[i] << endl;
	f << endl << endl;


	f << "Xor Count = " << seq.size() << endl;
	
	int tab[SIZE] = {0};
	for(int i = 0; i < tmp_m.size(); i++)
		{
			for(int j = 0; j < tmp_m.size(); j++)
			{
				if(tmp_m[i].test(tmp_m.size() - 1 - j))
				{
					tab[i] = j;
					break;
				}
			}
		}

	for(int i = seq.size() - 1; i >= 0; i--)
		{
			f<<"x["<<tab[seq[i].dst]<<"] = x["<<tab[seq[i].dst]<<"] ^ x["<<tab[seq[i].src]<<"]";
		    tmp_m[seq[i].dst] ^= tmp_m[seq[i].src];
		  	bool flag = false;
		    for(int j = 0; j < m.size(); j++)
		    {
				if(tmp_m[seq[i].dst] == m[j])
				{
					flag = true;
					f<<"    y["<<j<<"]"<<endl;
					break;
				}
			}
			
			if(!flag)
			{
				f<<endl;
			}
		}
		f.close();
}