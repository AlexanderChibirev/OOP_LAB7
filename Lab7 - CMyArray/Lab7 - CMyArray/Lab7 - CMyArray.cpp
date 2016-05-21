// Lab7 - CMyArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyArray.h"
#include <array>
using namespace std;


void output_array(CMyArray<int> &array)
{
	for (unsigned int i = 0; i<array.GetSize(); i++)
		cout << array[i] << ", ";

	cout << endl;
}

int main(void)
{
	CMyArray<int> array;

	// setting array size  
	array.Resize(15);
	//array[17];

	// filling array with pseudo-random values  
	for (unsigned int i = 0; i<15; i++)
		array[i] = rand() % 100;

	// lets add some values using Add() 
	array.Add(7);
	array.Add(94);
	array.Add(1);

	// output all array items 
	output_array(array);

	// delete 1-st  and last items  
	array.Delete(0);
	array.Delete(array.GetSize() - 1);

	// output all array items (again) 
	output_array(array);

	// let's sort all array items using extemly ineffective sort 
	for (unsigned int i = 0; i<array.GetSize();)
		if (array[i] > array[i + 1])
		{
			int x = array[i];
			array[i] = array[i + 1];
			array[i + 1] = x;
			i = 0;
			continue;
		}
		else
			i++;

	output_array(array);

	// create another array, based on first  
	CMyArray<int> array2(array);
	array2.Clear(); // clear it 

					// check multiple addition 
	for (int i = 0; i<1000000; i++)
		array2.Add(rand());

	// check assigment operator  
	array = array2;

	// output array 
	cout << "array 2 size " << array2.GetSize() << endl;
	cout << "array 1 size " << array.GetSize() << endl;

	// check random element 
	int testel = rand() % 1000000;
	cout << "array 2 element " << testel << " = " << array2[testel] << endl;
	cout << "array 1 element " << testel << " = " << array[testel] << endl;

	// that's all!  
	return 0;
}