#include "stdafx.h"
#include "../Lab7 - CMyArray/MyArray.h"


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
		BOOST_CHECK_NO_THROW(myArray.Add(23));
	}
	BOOST_AUTO_TEST_CASE(can_clear_empty_string)
	{
		BOOST_CHECK_NO_THROW(myArray.Clear());
	}
	//BOOST_AUTO_TEST_CASE(calling_SubString_then_empty_str_returns_empty_value)
	//{
	//	BOOST_CHECK_EQUAL(myString.SubString(0, 0), "");
	//}
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