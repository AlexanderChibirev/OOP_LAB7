#pragma once
template < typename T, typename Less>
bool FindMax(std::vector<T> const& arr, T& maxValue, Less const& less)
{
	for (auto &it: arr)
	{
		if(less(maxValue, it))
		{
			maxValue = it;
		}
	}
	return !(arr.empty());
}