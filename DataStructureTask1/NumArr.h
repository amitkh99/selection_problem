#pragma once
#include <iostream>

using namespace std;

namespace Arr {

	class NumArr
	{
	public:
		NumArr(int size, int i_index);
		~NumArr();
		
		double* get_copy_arr();
		int get_size() { return SizeOfArr; }
		int get_index() { return index; }
		double check_input();


		
	private:
		double* arr;
		int index;
		int SizeOfArr;
	};

	void MYswap(double& num1, double& num2);

	double insertion_sort(double* Arr, int size, int index_to_print);
	double selection(double* ArrForSelect, int left, int right, int num_to_find);
	//int Partition(double* ArrForPart, int left, int right);
	int Partition(double* ArrForPart, int left, int right, int PivotIndex);
	double quintet_algorithm(double* Arr, int size, int index_to_print);
	void Bubble_Sort(double* Arr, int size);
	//int find_median(double* Arr, int size);
	void check_size(int size);
	void check_index(int i_index, int size);



}