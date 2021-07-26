#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <fstream>
#include <iomanip>
#include "NumArr.h"
using namespace std;
using namespace Arr;


int main() {
	int size, index;
	double num_to_print;
	//cout << "please enter an array size" << endl;
	cin >> size;
	check_size(size);

	//cout << "please enter the size to find" << endl;
	cin >> index;
	check_index(index, size);

	

	NumArr array_from_user(size, index);
	double* copy_arr_1 = array_from_user.get_copy_arr();
	double* copy_arr_2 = array_from_user.get_copy_arr();
	double* copy_arr_3 = array_from_user.get_copy_arr();
	

	auto start = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);

	num_to_print = insertion_sort(copy_arr_1, array_from_user.get_size(), array_from_user.get_index());// function1

	auto end = chrono::high_resolution_clock::now();
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("Measure.txt"); // The name of the file
	myfile << "Time taken by function <insertion_sort> is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;

	cout << "Insertion sort i'th element: " << fixed << setprecision(4) << num_to_print << endl;
	delete[] copy_arr_1;


	 start = chrono::high_resolution_clock::now();
	
	ios_base::sync_with_stdio(false);

	num_to_print = selection(copy_arr_2, 0, (array_from_user.get_size() - 1), index);// function2

	 end = chrono::high_resolution_clock::now();
	 

	 time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	
	myfile << "Time taken by function <selection> is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;

	cout << "Selection i'th element: " << fixed << setprecision(4) << num_to_print << endl;
	
	delete[] copy_arr_2;




	start = chrono::high_resolution_clock::now();
	
	ios_base::sync_with_stdio(false);

	num_to_print = quintet_algorithm(copy_arr_3, size, index);// function3

	end = chrono::high_resolution_clock::now();
	time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	
	myfile << "Time taken by function <quintet_algorithm> is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;

	myfile.close();


	cout <<"Quintuplet algorithm i'th element: "<< fixed << setprecision(4) << num_to_print << endl;

	delete[] copy_arr_3;

	return 1;
}