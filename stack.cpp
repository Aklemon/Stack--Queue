#include<iostream>
using namespace std;
template <typename T>
class Stack
{
public:
	Stack()
		：_size(0)
		, _capacity(3)
		, _pData(new T[_capacity])
	{
		}
	~Stzck()
	{
		if (_pData != NULL)
			delete[]_pstr;
	}
	void Push(const T&data)
	{
		CheckCapacity();
		_pData[size++] = data;
	}
	void Pop()
	{

	}
	void Top()
	{

	}
private:
	void CheckCapacity()
	{
		if (_size == _capacity)
		{
			T* tmp = new T[_capacity * 2];
			for (int i = 0; i < size; i++)
			{
				tmp[i] = _pData[i];
			}
		}
	}
	private://它决定数据成员在初始化列表的顺序
		size_t _size;
		size_t _capacity;
		T* _pData;
};