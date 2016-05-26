#include "stdafx.h"
#include "../FindMaxEx_lab7.1.3/FindMaxEx.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(FindMaxEx)

BOOST_AUTO_TEST_CASE(retun_false_then_array_empty)
{
	string maxValue;
	BOOST_CHECK(!FindMax(vector<string>(), maxValue, [](string const & lhs, string const &  rhs) {return lhs.length() < rhs.length(); }));
}

BOOST_AUTO_TEST_CASE(can_return_max_value_for_integer_num)
{
	int maxValue = 0;
	vector<int> arr = { 1, 2, -1, 111, 2, 1, 2  };
	BOOST_CHECK(FindMax(arr, maxValue, [](int lhs, int rhs) {return lhs < rhs; }));
	BOOST_CHECK_EQUAL(maxValue, 111);
}

BOOST_AUTO_TEST_CASE(can_return_max_value_for_float_num)
{
	float maxValue = 0;
	vector<float> arr = { 1.f, 2.f, -1.f, 111.f, 2.f, 1.f, 2.f };
	BOOST_CHECK(FindMax(arr, maxValue, [](float lhs, float rhs) {return lhs < rhs; }));
	BOOST_CHECK_EQUAL(maxValue, 111.f);
}

BOOST_AUTO_TEST_CASE(can_return_max_value_for_double_num)
{
	double maxValue = 0;
	vector<double> arr = { 1.23123123123, 2.6785758768, 1.23123123123, 111.234234234, 1.23123123123, 1.23123123123, 3.12312312313};
	BOOST_CHECK(FindMax(arr, maxValue, [](double lhs, double rhs) {return lhs < rhs; }));
	BOOST_CHECK_EQUAL(maxValue, 111.234234234);
}

BOOST_AUTO_TEST_CASE(can_return_max_string_for_string)
{
	string maxLenghtStr;
	vector<string> arr = { "min", "max", "words" };
	BOOST_CHECK(FindMax(arr, maxLenghtStr, [](string const & lhs, string const &  rhs) {return lhs.length() < rhs.length(); }));
	BOOST_CHECK_EQUAL(maxLenghtStr, "words");
}

BOOST_AUTO_TEST_CASE(then_lambda_return_exeption)
{
	int maxValue = 0;
	vector<int> arr = { 1, 2, -1, 1, 2, 1, 222 };
	int x = 0;
	auto less = [&x](int lhs, int rhs) {
		++x;
		if (x == 3) { throw std::invalid_argument("invalid_argument"); }
		return lhs < rhs; };
	BOOST_CHECK_THROW(FindMax(arr, maxValue, less), std::invalid_argument);
	BOOST_CHECK_EQUAL(maxValue, 0);
}

BOOST_AUTO_TEST_SUITE_END()