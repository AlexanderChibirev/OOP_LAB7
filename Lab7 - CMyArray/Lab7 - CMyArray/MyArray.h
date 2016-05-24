#pragma once
#include <cstdlib> 
template<class T>
class CMyArray
{
public:
	CMyArray();
	CMyArray(std::initializer_list< T> list);  
	CMyArray(const CMyArray &a);
	~CMyArray(); 
	//CMyArray& operator = (const CMyArray &a); 
	//CMyArray& operator = (CMyArray &&rhs);
	T& operator [] (size_t index);  
	const T&  operator [] (size_t index) const;
	void Add(const T &item);  
	size_t GetSize(); 
	void Resize(size_t newsize);
	void Clear(); 
	//void Delete(unsigned int pos); 
private:
	T * m_array; 
	size_t m_size;  
};

////////////////////////////////////////////////////////////////////// 

template <class T>
CMyArray<T>::CMyArray()
	: m_size(0)
{

}

template <class T>
void CMyArray<T>::Add(const T & item)
{
	++m_size;
	try
	{
		auto buffer = m_array;
		m_array = new T[sizeof(T)*m_size];
		for (size_t i = 0; i < m_size - 1; ++i)
		{
			m_array[i] = buffer[i];
		}
		m_array[m_size - 1] = item;
		delete [] buffer;
	}
	catch (...)
	{
		throw  std::bad_alloc();
	}
}

template <class T>
CMyArray<T>::CMyArray(std::initializer_list<T> list)
	: m_size(0)
{
	for (auto &it : list)
	{
		Add(it);
	}
}


template <class T>
CMyArray<T>::~CMyArray()
{
	if (m_array)
	{
		//free(m_array); // Freeing memory  
		m_array = nullptr;
	}
}


template <class T>
CMyArray<T>::CMyArray(const CMyArray &a)
{
	try
	{
		m_array = new T[sizeof(T)*a.m_size];
		memcpy(m_array, a.m_array, sizeof(T)*a.m_size);
		m_size = a.m_size;
	//	a.Clear();
	}
	catch(...)
	{
		throw  std::bad_alloc();
	}
}
//
//template <class T>
//CMyArray<T>& CMyArray<T>::operator=(CMyArray const &rhs)//CMyArray rhs
//{
//	if (this != &rhs)
//	{
//		CMyArray copy(rhs);
//		swap(m_array, copy.m_array);
//		swap(m_size, copy.m_size);
//		swap(m_realsize, copy.m_realsize);
//	}
//	return *this;
//}
//
//template <class T>
//CMyArray<T>& CMyArray<T>::operator=(CMyArray &&rhs)
//{
//	if (this != &rhs)
//	{
//		m_array = move(rhs.m_array);
//		m_realsize = rhs.m_length;
//		rhs.Clear();
//	}
//	return *this;
//}
//
//
template <class T>
unsigned int CMyArray<T>::GetSize()
{
	return m_size; // simply return size 
}
//
//
template <class T>
void CMyArray<T>::Resize(size_t newSize)
{
	if (newSize != 0)
	{
		// change array memory size  
		// if new size is larger than current  
		// or new size is less then half of the current  
		if ((m_size < newSize) || (m_size > newSize / 2))
		{
			m_size = newSize;
			m_array = (T *)realloc(m_array, sizeof(T)*m_size);

			if (m_array == nullptr)
				throw  std::bad_alloc();
		}
	}
	else 
	{
		Clear();
	}		
}
//
//template <class T>
//void CMyArray<T>::Delete(unsigned int pos)
//{
//	if (m_size == 1) // If array has only one element  
//		Clear(); // than we clear it, since it will be deleted  
//	else
//	{
//		// otherwise, shift array elements  
//		for (unsigned int i = pos; i<m_size - 1; i++)
//			m_array[i] = m_array[i + 1];
//
//		// decrease array size 
//		m_size--;
//	}
//}
//
template <class T>
void CMyArray<T>::Clear() // clear array memory  
{
	m_size = 0;
	delete[] m_array;
	m_array = nullptr;
}

template <class T>
T& CMyArray<T>::operator [] (size_t index)
{
	if (index > m_size)
	{
		throw  std::out_of_range("index out of range");
	}
	//else if (!m_array)
	//{
	//	m_array = new T(0);
	//	m_array[1] = '\0';
	//}
	return m_array[index];
}

template <class T>
const T& CMyArray<T>::operator [] (size_t index) const
{
	if (index > m_size)
	{
		throw  std::out_of_range("index out of range");
	}
	//else if (!m_array)
	//{
	//	m_array = new T(0);
	//	m_array[1] = '\0';
	//}
	return m_array[index];
}
//
////template <class T>
////T const& CMyArray<T>::operator[] const (size_t index)
////{
////	if (index > m_realsize)
////	{
////		throw  std::out_of_range("index out of range");
////	}
////	return m_array[index];
////}
//






















