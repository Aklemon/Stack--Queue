#include<iostream>
using namespace std;
#include<vector>
#include<assert.h>
template <class T>
struct Trituple
{
	Trituple()
	{}
	Trituple(size_t row, size_t col, const T& value)
		:_row(row)
		, _col(col)
		, _value(value)
	{}

	size_t _row;
	size_t _col;
	T _value;
};


template <typename T>
class SparseMatrix
{
public:
	SparseMatrix()
	{}
	SparseMatrix(int *arr, size_t row, size_t col, T invalid)
		:_row(row)
		, _col(col)
		, _invalid(invalid)
	{
		assert(arr);
		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < col; j++)
			{
				if (arr[i*col + j] != invalid)
				{
					_matrix.push_back(Trituple<T>(i, j, arr[i*col + j]));
				}
			}
		}
	}

	//矩阵逆置
	SparseMatrix<T> Transport()
	{
		SparseMatrix<T> s;
		s._row = _col;
		s._col = _row;
		s._invalid = _invalid;
		for (size_t i = 0; i < _col; i++)
		{
			//找原矩阵的一列中有多少个有效元素，即转置后的矩阵中每行有多少元素
			size_t iIdx = 0;
			while (iIdx < _matrix.size())
			{
				//例如列等于1 就是转置后矩阵中第一行的元素
				if (_matrix[iIdx]._col == i)
				{
					s._matrix.push_back( Trituple<T>(i, _matrix[iIdx]._row, _matrix[iIdx]._value));
				}
				iIdx++;
			}
		}
		return s;
	}

	friend ostream &operator<<(ostream& _cout, const  SparseMatrix<T>& s)
	{
		size_t iIdx = 0;
		for (int i = 0; i <s._row; i++)
		{
			for (int j = 0; j < s._col; j++)
			{
				if (iIdx < s._matrix.size() && s._matrix[iIdx]._row == i&&s._matrix[iIdx]._col == j)
				{
					_cout << s._matrix[iIdx++]._value << "";
				}
				else
					_cout << s._invalid << "";
			}
			_cout << endl;
		}
		return _cout;
	}


private:
	vector<Trituple<T> > _matrix;
	size_t _row;
	size_t _col;
	T _invalid;
};


int main()
{
	int arr[6][5] = {
		{ 1, 0, 2, 0, 3, },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 1, 0, 2, 0, 3 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
	};

	SparseMatrix<int> s((int*)arr, 6, 5, 0);
	
	cout << s << endl;
	s.Transport();
	cout <<  s.Transport() << endl;
	return 0;
}