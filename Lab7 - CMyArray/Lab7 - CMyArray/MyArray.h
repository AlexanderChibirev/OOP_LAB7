#pragma once
#include <cstdlib> 
#include <boost/format.hpp> 
template<class T>
class CMyArray
{
public:
	CMyArray(); // constructor  
	CMyArray(const CMyArray &a); // copy constructor  
	~CMyArray(); // distructor  
	CMyArray& operator = (const CMyArray &a); // assignment operator  

	T& operator [] (size_t index); // get array item  
	void Add(const T &item); // Add item to the end of array  

	unsigned int GetSize(); // get size of array (elements) 
	void Resize(unsigned int newsize); // set size of array (elements) 
	void Clear(); // clear array 
	void Delete(unsigned int pos); // delete array item  
private:
	T *array; // pointer for array's memory  
	unsigned int m_size; // size of array (elemets) 
	unsigned int m_realsize; // actual size of allocated memory   

	const static int dyn_array_step = 128; // initial size of array memory (elements) 
	const static int dyn_array_mult = 2; // multiplier (enlarge array memory  
										 // dyn_array_mult times  ) 
};

////////////////////////////////////////////////////////////////////// 

template <class T>
CMyArray<T>::CMyArray()
{
	m_realsize = dyn_array_step; // First, allocate step  
								 // for dyn_array_step items 
	m_size = 0;
	array = (T *)malloc(m_realsize*sizeof(T));

	if (array == NULL)
		throw std::bad_alloc();
}


template <class T>
CMyArray<T>::~CMyArray()
{
	if (array)
	{
		free(array); // Freeing memory  
		array = NULL;
	}
}


template <class T>
CMyArray<T>::CMyArray(const CMyArray &a)
{
	array = (T *)malloc(sizeof(T)*a.m_realsize);
	if (array == NULL)
		throw std::bad_alloc();

	memcpy(array, a.array, sizeof(T)*a.m_realsize);
	// memcpy call -- coping memory contents  
	m_realsize = a.m_realsize;
	m_size = a.m_size;
}


template <class T>
CMyArray<T>& CMyArray<T>::operator = (const CMyArray &a)
{
	if (this == &a) // in case somebody tries assign array to itself  
		return *this;

	if (a.m_size == 0) // is other array is empty -- clear this array  
		Clear();

	Resize(a.m_size); // set size  

	memcpy(array, a.array, sizeof(T)*a.m_size);

	return *this;
}

template <class T>
unsigned int CMyArray<T>::GetSize()
{
	return m_size; // simply return size 
}


template <class T>
void CMyArray<T>::Resize(unsigned int newsize)
{
	m_size = newsize;

	if (m_size != 0)
	{
		// change array memory size  
		// if new size is larger than current  
		// or new size is less then half of the current  
		if ((m_size > m_realsize) || (m_size < m_realsize / 2))
		{
			m_realsize = m_size;
			array = (T *)realloc(array, sizeof(T)*m_size);

			if (array == NULL)
				throw  std::bad_alloc();
		}
	}
	else
		Clear();
}

template <class T>
void CMyArray<T>::Delete(unsigned int pos)
{
	if (m_size == 1) // If array has only one element  
		Clear(); // than we clear it, since it will be deleted  
	else
	{
		// otherwise, shift array elements  
		for (unsigned int i = pos; i<m_size - 1; i++)
			array[i] = array[i + 1];

		// decrease array size 
		m_size--;
	}
}

template <class T>
void CMyArray<T>::Clear() // clear array memory  
{
	m_size = 0;
	array = (T *)realloc(array, sizeof(T)*dyn_array_step);
	// set initial memory size again  
	m_realsize = dyn_array_step;
}

template <class T>
T& CMyArray<T>::operator [] (size_t index)
{
	if (index > m_realsize) 
	{
		throw  std::out_of_range("index out of range");
	}
	return array[index]; // return array element  
}

template <class T>
void CMyArray<T>::Add(const T &item)
{
	m_size++;

	if (m_size > m_realsize)
	{
		m_realsize *= dyn_array_mult;

		array = (T *)realloc(array, sizeof(T)*m_realsize);

		if (array == NULL)
			throw  std::bad_alloc();
	}

	array[m_size - 1] = item;
}