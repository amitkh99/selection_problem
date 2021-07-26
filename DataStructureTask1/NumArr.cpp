#pragma once
#include <typeinfo>
#include <math.h> 
#include <iomanip>
#include "NumArr.h"




namespace Arr {
	NumArr::NumArr(int size, int i_index)
	{
		SizeOfArr = size;
		index = i_index - 1;
		arr = new double[size];
		int i;
		double tempNum;
		check_input();
	}

	NumArr::~NumArr()
	{
		delete[] arr;
	}



	double NumArr::check_input() {
		int i;
		char temp;
		double num;
		int beforeDot = 0;
		double afterDot = 0;
		int count = 0;
		int countFromBeg = 0;
		int negative = 0;
		getchar();
		for (i = 0; i < SizeOfArr; i++) {//getting the characters that are the number constructed, after checking creates a double
			while (1)
			{//check before dot
				temp = getchar();
				if (temp <= '9' && temp >= '0') {
					beforeDot = 1;
					if (count != 0) {
						num = num * 10 + (temp - '0');
					}
					else {
						num = (temp - '0');
					}
					count++;
				}
				else if (temp == '.') {
					count = 0;
					break;
				}
				else if (!beforeDot && temp == '-') {
					negative = 1;
				}
				else {
					cout << "wrong input";
					exit(-1);
				}

			}
			while (1) 
			{//check after dot
				temp = getchar();
				if (temp <= '9' && temp >= '0' && beforeDot && count <= 4) {
					if (count != 0) {
						afterDot = afterDot * 10 + (temp - '0');
					}
					else {
						afterDot = (temp - '0');
					}

					count++;
				}
				else if (count > 0 && count <= 4 && (temp == ' ' || temp == '\n')) {
					break;
				}
				else {
					cout << "wrong input";
					exit(-1);
				}
			}
			afterDot = afterDot / pow(10, count);
			num += afterDot;
			if (negative) {
				arr[i] = -1 * num;
			}
			else {
				arr[i] = num;
			}
			count = num = beforeDot = negative = 0;

		}
		if (temp != '\n')
		{
			cout << "wrong input";
			exit(-1);
		}
	
	}

	double* NumArr::get_copy_arr() const {
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

	double insertion_sort(double* Arr, int size, int index_to_find) {
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
		
		return Arr[index_to_find]; 
	}

	int myPartition(double* ArrForPart, int left, int right, int PivotIndex)
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
		int PivotIndex = myPartition(ArrForSelect, left, right,left);//executing partition, the left number of the array pivot 
		int left_part = PivotIndex - left + 1;
		if (num_to_find == left_part) {
			return ArrForSelect[PivotIndex];
		}
		if (num_to_find < left_part) {
			return selection(ArrForSelect, left, PivotIndex - 1, num_to_find);
		}
		else {
			return selection(ArrForSelect, PivotIndex + 1, right, num_to_find - left_part);
		}

	}

	

	double quintet_algorithm(double* Arr, int size, int num_to_find) {
		int i, j, k;
		if (size < 6) {
			Bubble_Sort(Arr, size);
			return  Arr[num_to_find - 1];
		}
		else {
			j = 0;
			double* Arr_median = new double[int(ceil(size / double(5)))];
			for (i = 0; i < size; i = i + 5) {
				/*sends arrays of size 5 to bubble sort(or less if the size of the original array is not divisible by 5) and inserts the median of each sub array into a new array*/
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

			double median = quintet_algorithm(Arr_median, ceil(size / double(5)), ceil((size / double(10))));//find and return the median value of the median 

			j = 0;
			for (i = 0; i < size; i = i + 5) {//finds the index of the median in the original array that will be used as a pivot in the partition
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
			 k = myPartition(Arr, 0, size - 1,i);

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