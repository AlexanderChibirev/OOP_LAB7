#pragma once

template < typename T, typename Less>
bool FindMax(std::vector<T> const& arr, T& maxValue, Less const& less)
{
	if (arr.empty())
	{
		return false;
	}
	T localMaxNumber = arr.front();
	for (auto &it: arr)
	{
		if(less(localMaxNumber, it))
		{
			localMaxNumber = it;
		}
	}
	maxValue = localMaxNumber;
	return true;
}