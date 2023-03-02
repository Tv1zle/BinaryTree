#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray
{
	T* arr;
	int count;
public:
	MyArray();
	MyArray(int size);
	MyArray(const MyArray<T>& mas);

	void Input();
	void Print();
	~MyArray();


	MyArray<T>& operator++();
	MyArray<T>& operator--();
	MyArray<T> operator++(int);
	MyArray<T> operator--(int);

	MyArray<T> operator+(int n);
	MyArray<T> operator+(const MyArray<T>& obj);
	MyArray<T> operator-(int n);

	MyArray<T>& operator=(const MyArray<T>& obj);
};

template<class T>
MyArray<T>::MyArray()
{
	arr = nullptr;
	count = 0;
}

template<class T>
MyArray<T>::MyArray(int size)
{
	count = size;
	arr = new T[count];
}

template<class T>
MyArray<T>::MyArray(const MyArray<T>& obj2)
{
	count = obj2.count;
	arr = new T[count];
	for (int i = 0; i < count; i++)
	{
		arr[i] = obj2.arr[i];
	}
}

template<class T>
void MyArray<T>::Input()
{
	for (int i = 0; i < count; i++)
	{
		arr[i] = rand() % 100 * 2.5;
	}
}

template<class T>
void MyArray<T>::Print()
{
	for (int i = 0; i < count; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

template<class T>
MyArray<T>::~MyArray()
{
	delete[]arr;
	count = 0;
}


template<class T>
MyArray<T>& MyArray<T>::operator++()
{
	T* tmp = new T[++count];
	for (int i = 0; i < count - 1; i++)
	{
		tmp[i] = arr[i];
	}
	tmp[count - 1] = 0;

	delete[] arr;
	arr = tmp;

	return *this;
}

template<class T>
MyArray<T>& MyArray<T>::operator--()
{
	T* tmp = new T[--count];
	for (int i = 0; i < count; i++)
	{
		tmp[i] = arr[i];
	}

	delete[] arr;
	arr = tmp;

	return *this;
}

template<class T>
MyArray<T> MyArray<T>::operator++(int)
{
	MyArray obj(*this);

	T* tmp = new T[++count];
	for (int i = 0; i < count - 1; i++)
	{
		tmp[i] = arr[i];
	}
	tmp[count - 1] = 0;

	delete[] arr;
	arr = tmp;

	return obj;
}

template<class T>
MyArray<T> MyArray<T>::operator--(int)
{
	MyArray obj(*this);

	T* tmp = new T[--count];
	for (int i = 0; i < count; i++)
	{
		tmp[i] = arr[i];
	}

	delete[] arr;
	arr = tmp;

	return obj;
}

template<class T>
MyArray<T> MyArray<T>::operator+(int n)
{
	MyArray<T> obj(count + n);

	for (int i = 0; i < count; i++)
	{
		obj.arr[i] = arr[i];
	}
	for (int i = count; i < obj.count; i++)
	{
		obj.arr[i] = 0;
	}
	return obj;
}

template<class T>
MyArray<T> MyArray<T>::operator+(const MyArray<T>& right)
{
	MyArray<T> obj(count + right.count);

	for (int i = 0; i < count; i++)
	{
		obj.arr[i] = arr[i];
	}
	for (int i = count, j = 0; i < obj.count; i++, j++)
	{
		obj.arr[i] = right.arr[j];
	}
	return obj;
}

template<class T>
MyArray<T> MyArray<T>::operator-(int n)
{
	if (count - n < 1)
		return MyArray<T>();

	MyArray<T> obj(count - n);

	for (int i = 0; i < obj.count; i++)
	{
		obj.arr[i] = arr[i];
	}
	return obj;
}

template<class T>
MyArray<T>& MyArray<T>::operator=(const MyArray<T>& obj)
{
	if (&obj != this)
	{
		if (arr != nullptr)
			delete[] arr;

		count = obj.count;
		arr = new T[count];
		for (int i = 0; i < count; i++)
		{
			arr[i] = obj.arr[i];
		}
		for (int i = count; i < count; i++)
		{
			arr[i] = 0;
		}
		cout << "\n";
	}
	return *this;
}