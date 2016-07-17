#include<stack>
#include<iostream>
using namespace std;
class solution
{
	stack<int> StackData;
	stack<int>StackMin;
	void Push(int data)
	{
		StackData.push(data);
		if (StackMin.empty())
		{
			StackMin.push(data);
		}
		else
		{
			if (data<StackData.top())
			{
				StackMin.push(data);
			}
			else
			{
				StackMin.push(StackMin.top);
			}
		}
	}
	void Pop()
	{
		StackData.pop();
		StackMin.pop();
	}
	int top()
	{
		return StackData.top();
	}
	int MinData()
	{
		return StackData.top();
	}
};