#include<stack>
#include<iostream>
using namespace std;
class Solution
{
public:
	void push(int data) 
	{
		stack1.push(data);
	}

	int pop()
	{
		if (stack2.empty())
		{
			stack2.push(stack1.top());
		}
		else
		{
			stack1.pop();
			stack2.push(stack1.top());
		}
		int ret = stack2.top();
		stack2.pop();
		return ret;
	}
private:
	stack<int> stack1;
	stack<int> stack2;
};
