#pragma once
#include <typeinfo>
#include <math.h> 
#include <iomanip>
#include "NumArr.h"




namespace Arr {
	NumArr::NumArr(int size, int i_index)
	{
		if (size < 1) {
			cout << "worng input";
			exit(-1);
		}
		if (i_index<1 || i_index>size) {
			cout << "worng input";
			exit(-1);
		}
		SizeOfArr = size;
		index = i_index - 1;
		arr = new double[size];
		int i;
		double tempNum;
		//cout << "please enter the numbers" << endl;
		for (i = 0; i < SizeOfArr; ++i) {
			
			//add check!!!!!!!!!!!!!!!
			tempNum = check_input();
			arr[i] = tempNum;
			
		}
		
	}

	NumArr::~NumArr()
	{
		delete[] arr;
	}

	double NumArr::check_input() {
		double tempNum;
		if (cin >> tempNum) {
			return tempNum;
		}
		else {
			cout << "wrong input";
			exit(-1);
		}
	}

	double* NumArr::get_copy_arr() {
		int i;
		double* copy_arr = new double[SizeOfArr];

		for (i = 0; i < SizeOfArr; ++i) {
			copy_arr[i] = arr[i];
		}
		return copy_arr;
	}

	void check_size(int size) {
		if (size < 1) {
			cout << "wrong input";
			exit(-1);
		}
	}

	void check_index(int i_index, int size) {
		if (i_index<1 || i_index>size) {
			cout << "wrong input";
			exit(-1);
		}
	}

	void MYswap(double& num1, double& num2) {
		double temp = num1;
		num1 = num2;
		num2 = temp;
	}

	double insertion_sort(double* Arr, int size, int index_to_print) {
		int i, j;
		double CurrNumFromOriArr;


		for (i = 0; i < size; ++i) {
			CurrNumFromOriArr = Arr[i];
			if (i == 0) {
				Arr[i] = CurrNumFromOriArr;
			}

			else {
				j = i - 1;
				while (j >= 0 && (Arr[j] > CurrNumFromOriArr)) {
					Arr[j + 1] = Arr[j];
					--j;
				}
				Arr[j + 1] = CurrNumFromOriArr;
			}
		}
		//cout << fixed << setprecision(4) << Arr[index_to_print] << endl;
		double retVal = Arr[index_to_print];
		delete[] Arr;
		return retVal;
	}

	//int Partition(double* ArrForPart, int left, int right) {
	//	int i, temp_index_to_change, pivot = left;
	//	int num_to_check = right;



	//	while (num_to_check != pivot) {
	//		if (ArrForPart[num_to_check] < ArrForPart[pivot]) {
	//			if (pivot < num_to_check) {
	//				MYswap(ArrForPart[num_to_check], ArrForPart[pivot]);
	//				temp_index_to_change = num_to_check;
	//				num_to_check = pivot + 1;
	//				pivot = temp_index_to_change;
	//			}
	//			else {
	//				num_to_check++;
	//			}
	//		}
	//		else {
	//			if (pivot > num_to_check) {
	//				MYswap(ArrForPart[num_to_check], ArrForPart[pivot]);
	//				temp_index_to_change = num_to_check;
	//				num_to_check = pivot - 1;
	//				pivot = temp_index_to_change;
	//			}
	//			else {
	//				num_to_check--;
	//			}
	//		}
	//	}
	//	/*	for (i = 0; i <= right-left; i++)
	//			cout << ArrForPart[i] << ",";
	//		cout << endl;*/

	//	return pivot;
	//}

	int Partition(double* ArrForPart, int left, int right, int PivotIndex)
	{
		double pivot = ArrForPart[PivotIndex];
		MYswap(ArrForPart[PivotIndex], ArrForPart[right]);
		PivotIndex = left;

		for (int i = left; i < right; i++)
		{
			if (ArrForPart[i] <= pivot)
			{
				MYswap(ArrForPart[i], ArrForPart[PivotIndex]);
				PivotIndex++;
			}
		}

		
		MYswap(ArrForPart[PivotIndex], ArrForPart[right]);

		return PivotIndex;
	}



	double selection(double* ArrForSelect, int left, int right, int num_to_find) {
		int pivot = Partition(ArrForSelect, left, right,left);
		int left_part = pivot - left + 1;
		if (num_to_find == left_part) {
			//cout << ArrForSelect[pivot]<<endl;
			return pivot;
		}
		if (num_to_find < left_part) {
			return selection(ArrForSelect, left, pivot - 1, num_to_find);
		}
		else {
			return selection(ArrForSelect, pivot + 1, right, num_to_find - left_part);
		}

	}

	//double quintet_algorithm(double* Arr, int size, int index_to_print) {
	//	int i,j,k;
	//	if (size < 6) {
	//		Bubble_Sort(Arr, size);
	//		cout << Arr[index_to_print-1] << endl;
	//		return Arr[index_to_print-1];
	//	}
	//	else {
	//		j = 0;
	//		double* Arr_median = new double[(size / 5)];
	//		for (i = 0; i < size; i = i + 5) {
	//			if (size - i < 5) {
	//				Bubble_Sort(Arr + i, size - i);
	//				Arr_median[j] = (Arr + i)[(size - i)/2];
	//				j++;
	//			}
	//			else {
	//				Bubble_Sort(Arr + i, 5);
	//				Arr_median[j] = (Arr + i)[2];
	//				j++;
	//			}
	//		}
	//		//int median = selection(Arr_median, 0, size / 5, ((size / 5) / 2 + 1));
	//		/*if (2 + (5 * median) < size) {
	//			MYswap(Arr[0], Arr[2 + (5 * median)]);
	//		}
	//		else {
	//			MYswap(Arr[0], Arr[((size - i) / 2) + (5 * median)]);
	//		}*/

	//		int median = quintet_algorithm(Arr_median, size / 5, ((size / 5) / 2 + 1));
	//		
	//		selection(Arr, 0, size - 1, index_to_print);
	//	
	//	}
	//}

	double quintet_algorithm(double* Arr, int size, int num_to_find) {
		int i, j, k;
		if (size < 6) {
			Bubble_Sort(Arr, size);
			/*cout << Arr[num_to_find - 1] << endl;*/
			return  Arr[num_to_find - 1];
		}
		else {
			j = 0;
			double* Arr_median = new double[int(ceil(size / double(5)))];
			for (i = 0; i < size; i = i + 5) {
				if (size - i < 5) {
					Bubble_Sort(Arr + i, size - i);
					Arr_median[j] = (Arr + i)[(size - i) / 2];
					j++;
				}
				else {
					Bubble_Sort(Arr + i, 5);
					Arr_median[j] = (Arr + i)[2];
					j++;
				}
			}

		

			double median = quintet_algorithm(Arr_median, ceil(size / double(5)), ceil((size / double(10))));

			//if (2 + (5 * median) < size) {
			//	MYswap(Arr[0], Arr[2 + (5 * median)]);
			//}
			//else {
			//	MYswap(Arr[0], Arr[((size - i) / 2) + (5 * median)]);///NOT GOODDD VAL
			//}
			j = 0;
			for (i = 0; i < size; i = i + 5) {
				if (size - i < 5) {
					if ((Arr + i)[(size - i) / 2] == median) {
						i = i + (size - i) / 2;
						break;
					}
				}
				else {
					if ((Arr + i)[2] == median) {
						i = i + 2;
						break;
					}
				}
			}

			

			 k = Partition(Arr, 0, size - 1,i);

			 /*for (i = 0; i < size; i++)
				 cout << Arr[i] << ",";
			 cout << endl;*/

			if (k == num_to_find - 1) {

				return Arr[k];
			}
			else if (k > num_to_find - 1) {
				return quintet_algorithm(Arr, k , num_to_find);
			}
			else {
				return quintet_algorithm(Arr + k + 1, size - (k + 1), num_to_find - (k + 1));
			}

		}
	}

	void Bubble_Sort(double* Arr, int size) {
		int i, j;
		for (i = 0; i < size - 1; ++i) {
			for ( j = 0; j < size - i - 1; ++j) {
				if (Arr[j] > Arr[j + 1]) {
					MYswap(Arr[j], Arr[j + 1]);
				}
			}
		}

	}
}