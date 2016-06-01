#pragma once
#include <memory>
#include <iostream>
#include <iterator>
#include <initializer_list>

template <typename T>
class CMyArray
{
public:
	CMyArray();
	CMyArray(std::initializer_list<T> list);
	CMyArray(const CMyArray<T> & other);
	CMyArray(CMyArray<T> && other);

	void PushBack(const T & item);
	size_t GetSize() const;
	T & operator [](size_t index);
	const T & operator [] (size_t index) const;
	void Resize(size_t newSize);
	void Resize(size_t newSize, T item);
	void Clear();
	CMyArray & operator = (const CMyArray &rhs); 
	CMyArray& operator = (CMyArray &&rhs);
private:
	size_t m_size = 0;
	std::unique_ptr<T[]> m_array;
};

template <typename T>
CMyArray<T>::CMyArray()
{

}

template <typename T>
CMyArray<T>::CMyArray(CMyArray<T> && other)
	: m_size(other.m_size)
{
	m_array.swap(other.m_array);
	other.m_size = 0;
}

template <typename T>
CMyArray<T>::CMyArray(std::initializer_list<T> list)
	: m_size(list.size())
	, m_array(std::make_unique<T[]>(m_size))
{
	size_t i = 0;
	for (auto it : list)
	{
		//PushBack(it);
		m_array[i] = it;
		++i;
	}
}

template <typename T>
CMyArray<T>::CMyArray(const CMyArray<T> & other) 
	: m_size(other.m_size)
	, m_array(std::make_unique<T[]>(m_size))
{
	memcpy(m_array.get(), other.m_array.get(), m_size * sizeof(m_size));
}

template <typename T>
void CMyArray<T>::Clear()
{
	m_size = 0;
	m_array.reset();
}

template <typename T>
void CMyArray<T>::Resize(size_t newSize)
{
	if (m_size > newSize)
	{
		m_size = newSize;
		return;
	}
	if ((m_size < newSize) || (m_size > newSize / 2) && newSize != 0)
	{
			
			std::unique_ptr<T[]> buffer;
			m_array.swap(buffer);
			m_array = std::make_unique<T[]>(newSize);
			memcpy(m_array.get(), buffer.get(), (m_size) * sizeof(T));
			m_size = newSize;
	}
	else 
	{
		Clear();
	}
}

template <typename T>
void CMyArray<T>::Resize(size_t newSize, T item)
{
	if (m_size > newSize)
	{
		m_size = newSize;
		return;
	}
	if ((m_size < newSize) || (m_size > newSize / 2) && newSize != 0)
	{

			std::unique_ptr<T[]> buffer;
			m_array.swap(buffer);
			m_array = std::make_unique<T[]>(newSize);
			memcpy(m_array.get(), buffer.get(), (m_size) * sizeof(T));
			for (size_t i = m_size; i < newSize; ++i)
			{
				m_array[i] = item;
			}
			m_size = newSize;
	}
	else
	{
		Clear();
	}

}

template <typename T>
T & CMyArray<T>::operator[](size_t index)
{
	if (index < 0 || index >= m_size)
	{
		throw std::out_of_range("incorrect index");
	}
	return m_array[index];
}

template <class T>
const T& CMyArray<T>::operator [] (size_t index) const
{
	if (index < 0 || index >= m_size)
	{
		throw  std::out_of_range("index out of range");
	}
	return m_array[index];
}

template <typename T>
size_t CMyArray<T>::GetSize() const
{
	return m_size;
}

template <typename T>
void CMyArray<T>::PushBack(const T & item)
{
	++m_size;
	std::unique_ptr<T[]> buffer;
	m_array.swap(buffer);
	m_array = std::make_unique<T[]>(m_size);
	memcpy(m_array.get(), buffer.get(), (m_size - 1) * sizeof(T));
	m_array[m_size - 1] = item;
}


template <class T>
CMyArray<T>& CMyArray<T>::operator=(CMyArray const &rhs)
{
	if (this != &rhs)
	{
		CMyArray copy(rhs);
		swap(m_array, copy.m_array);
		swap(m_size, copy.m_size);
	}
	return *this;
}

template <class T>
CMyArray<T>& CMyArray<T>::operator=(CMyArray &&rhs)
{
	if (this != &rhs)
	{
		swap(m_array, rhs.m_array);
		swap(m_size, rhs.m_size);
		rhs.m_size = 0;
	}
	return *this;
}