#include "stdafx.h"
#include <memory>
#include "../Lab7 - CMyArray/MyArray.h"

using namespace std;

struct DefaultConstructorCMyArrayIntegerType
{
	CMyArray<int> myArray;
};

BOOST_FIXTURE_TEST_SUITE(myArray, DefaultConstructorCMyArrayIntegerType)
	BOOST_AUTO_TEST_CASE(returns_the_array_size_equeal_zero)
	{
		BOOST_CHECK_EQUAL(myArray.GetSize(), 0);
	}
	BOOST_AUTO_TEST_CASE(at_the_end_of_the_array_must_be_a_terminating_null_character)
	{
		BOOST_CHECK_NO_THROW(myArray.PushBack(23));
	}
	BOOST_AUTO_TEST_CASE(can_clear_empty_string)
	{
		BOOST_CHECK_NO_THROW(myArray.Clear());
	}
	BOOST_AUTO_TEST_CASE(calling_SubString_then_empty_str_returns_empty_value)
	{
		//BOOST_CHECK_EQUAL(myArray.Resize(10, 12));
	}
BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(TestMethodGetSize)
	BOOST_AUTO_TEST_CASE(getSize)
	{
		CMyArray<int> myArray1 = {0,2,3,4,5,1};
		CMyArray<int> myArray2(myArray1);
		BOOST_CHECK_EQUAL(myArray1.GetSize(), 6);
		BOOST_CHECK_EQUAL(myArray2.GetSize(), 6);
	}
BOOST_AUTO_TEST_SUITE_END()




//
//template <class T>
//void VerifyMyArray(const CMyArray<T> & lhs, const CMyArray<T> & rhs)
//{
//	for (size_t i = 0; i < lhs.GetSize(); i++)
//	{
//		BOOST_CHECK_EQUAL(lhs[i], rhs[i]);
//	}
//}
//
//
//BOOST_AUTO_TEST_SUITE(CopyConstructor)
//	BOOST_AUTO_TEST_CASE(can_copy_array1_in_array2)
//	{
//		CMyArray<int> myArray1 = {0,2,3,4,5,1};
//		CMyArray<int> myArray2;
//		BOOST_CHECK_EQUAL(myArray1.GetSize(), 6);
////		BOOST_CHECK_EQUAL(myArray2.GetSize(), 6);
//	}
//BOOST_AUTO_TEST_SUITE_END()
//
//
//BOOST_AUTO_TEST_SUITE(MovingConstructor)
//	BOOST_AUTO_TEST_CASE(can_move_the_array1_in_array2_to_become_empty)
//	{
//		/*CMyArray<int> myArray1 = { 0,2,3,4,5,1 };
//		CMyArray<int> myArray2;
//		CMyString str("heyMoving");
//		CMyString str1(move(str));
//		BOOST_CHECK_EQUAL(str.GetLength(), 0);
//		BOOST_CHECK_EQUAL(str.GetStringData(), "");
//		BOOST_CHECK_EQUAL(str1.GetLength(), 9);
//		BOOST_CHECK_EQUAL(str1.GetStringData(), "heyMoving");*/
//
//	}
//BOOST_AUTO_TEST_SUITE_END()


BOOST_FIXTURE_TEST_SUITE(Array_tests, DefaultConstructorCMyArrayIntegerType)

BOOST_AUTO_TEST_CASE(push_item_widthout_exception)
{
	BOOST_CHECK_NO_THROW(myArray.PushBack(0));
	BOOST_CHECK_NO_THROW(myArray.PushBack(0));
}

BOOST_AUTO_TEST_CASE(get_size_tests)
{
	BOOST_CHECK_EQUAL(myArray.GetSize(), 0);
	myArray.PushBack(0);
	BOOST_CHECK_EQUAL(myArray.GetSize(), 1);
	myArray.PushBack(0);
	BOOST_CHECK_EQUAL(myArray.GetSize(), 2);
	myArray.PushBack(0);
	BOOST_CHECK_EQUAL(myArray.GetSize(), 3);
}

BOOST_AUTO_TEST_CASE(get_item_by_index)
{
	myArray.PushBack(213);
	myArray.PushBack(312);
	myArray.PushBack(123);
	BOOST_CHECK_EQUAL(myArray[0], 213);
	BOOST_CHECK_EQUAL(myArray[1], 312);
	BOOST_CHECK_EQUAL(myArray[2], 123);
	BOOST_CHECK_THROW(myArray[3], std::out_of_range);
}

BOOST_AUTO_TEST_CASE(resize_array_width_start_item)
{
	myArray.Resize(10);
	BOOST_CHECK_EQUAL(myArray.GetSize(), 10);
	myArray.Resize(2);
	BOOST_CHECK_EQUAL(myArray.GetSize(), 2);
}

BOOST_AUTO_TEST_CASE(clear_array)
{
	myArray.Resize(10);
	myArray.Clear();
	BOOST_CHECK_EQUAL(myArray.GetSize(), 0);
	BOOST_CHECK_THROW(myArray[0], std::out_of_range);
}

BOOST_AUTO_TEST_CASE(initializer_list)
{
	CMyArray<int> arr1 = { 0, 1, 2 };
	BOOST_CHECK_EQUAL(arr1.GetSize(), 3);
	BOOST_CHECK_EQUAL(arr1[2], 2);
}

BOOST_AUTO_TEST_CASE(copy_constructor)
{
	CMyArray<int> arr1 = { 0, 1, 2 };
	CMyArray<int> arr2(arr1);
	BOOST_CHECK_EQUAL(arr1.GetSize(), arr2.GetSize());
}

BOOST_AUTO_TEST_CASE(move_constructor)
{
	CMyArray<int> arr1(CMyArray<int>({ 0, 1, 2, 3 }));
	BOOST_CHECK_EQUAL(arr1.GetSize(), 4);
}

BOOST_AUTO_TEST_CASE(can_move_the_arr1_in_arr2_to_become_empty)
{
	CMyArray<int> arr = { 12 };
	CMyArray<int> arr1(move(arr));
	BOOST_CHECK_EQUAL(arr.GetSize(), 0);
	BOOST_CHECK_EQUAL(arr1.GetSize(), 1);
	CMyArray<int> arr3 = arr1;
	BOOST_CHECK_EQUAL(arr3.GetSize(), 1);
}

BOOST_AUTO_TEST_CASE(iterator_tests)
{
	BOOST_CHECK(true);
	CMyArray<int> myArray = CMyArray<int>({ 0, 1, 2, 3 });
	size_t i = 0;
	/*
	for (auto it : myArray)
	{
	it == 0;
	++i;
	}*/
}

BOOST_AUTO_TEST_SUITE_END()