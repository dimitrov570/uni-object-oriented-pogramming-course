#pragma once


template <class T>
class Matrix
{
public:
	Matrix<T>();
	Matrix<T>(unsigned int x = 2, unsigned int y = 2);
	Matrix<T>(const Matrix & copyFrom);
	Matrix<T> & operator=(const Matrix & copyFrom);
	~Matrix<T>();

	void setAt(unsigned int x, unsigned int y, T element);
	T getAt(unsigned int x, unsigned int y);
	void Transpose();
	void setDefaultValues(unsigned int height, unsigned int width);
	void clearMatrix(); //deletes matrix

private:
	const int DEFAULT_WIDTH = 2;
	const int DEFAULT_HEIGHT = 2;
	
	T** matrix;
	unsigned int height; //Need to store height value in order to properly destruct the object
	unsigned int width; //and for copy constructor and operator=
};

template<class T>
Matrix<T>::Matrix()
{
	height = DEFAULT_HEIGHT;
	width = DEFAULT_WIDTH;
	matrix = new T*[DEFAULT_HEIGHT];
	for (unsigned int i = 0; i < DEFAULT_HEIGHT; i++)
	{
		matrix[i] = new T[DEFAULT_WIDTH];
	}
	setDefaultValues(height, width);
}

template<class T>
inline Matrix<T>::Matrix(unsigned int x, unsigned int y)
{
	height = x;
	width = y;
	matrix = new T*[x];
	for (unsigned int i = 0; i < x; i++)
	{
		matrix[i] = new T[y];
	}
	setDefaultValues(height, width);
}

template<class T>
inline Matrix<T>::Matrix(const Matrix & copyFrom)
{
	height = copyFrom.height;
	width = copyFrom.width;
	matrix = new T*[height];
	for (unsigned int i = 0; i < height; i++)
	{
		matrix[i] = new T[width];
	}
	for (unsigned int i = 0; i < height; i++)
	{
		for (unsigned int j = 0; j < width; j++)
		{
			matrix[i][j] = copyFrom.matrix[i][j];
		}
	}
}

template<class T>
inline Matrix<T> & Matrix<T>::operator=(const Matrix & copyFrom)
{
	if (this != &object)
	{
		clearMatrix();
		
		height = copyFrom.height;
		width = copyFrom.width;
		matrix = new T*[x];
		for (unsigned int i = 0; i < x; i++)
		{
			matrix[i] = new T[y];
		}

		for (unsigned int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				matrix[i][j] = copyFrom.getAt(i + 1, j + 1); //i+1 and j+1 because getAt() takes parameters that start from 1;
			}
		}

	}
	return *this;
}

template<class T>
inline Matrix<T>::~Matrix()
{
	clearMatrix();
}

template<class T>
inline void Matrix<T>::setAt(unsigned int x, unsigned int y, T element)
{
	if (x > height || x <= 0 || y > width || y <= 0)
	{
		std::cout << "Such element does not exist!" << '\n';
		return;
	}
	matrix[x - 1][y - 1] = element; //x-1 and y-1 because user inputs numbers from 1
}

template<class T>
inline T Matrix<T>::getAt(unsigned int x, unsigned int y)
{
	if (x > height || x <= 0 || y > width || y <= 0)
	{
		std::cout << "Such element does not exist!" << '\n';
		return T();
	}
	return matrix[x - 1][y - 1];
}

template<class T>
inline void Matrix<T>::Transpose()
{
	Matrix tmp = *this;
	this->clearMatrix();
	height = tmp.width;
	width = tmp.height;
	matrix = new T*[height];
	for (unsigned int i = 0; i < height; i++)
	{
		matrix[i] = new T[width];
	}

	for (unsigned int i = 0; i < height; i++)
	{
		for (unsigned int j = 0; j < width; j++)
		{
			matrix[i][j] = tmp.getAt(j + 1, i + 1); //j+1 and i+1 because getAt() takes parameters that start from 1
		}
	}
}

template<class T>
inline void Matrix<T>::setDefaultValues(unsigned int height, unsigned int width)
{
	for (unsigned int i = 0; i < height; i++)
	{
		for (unsigned int j = 0; j < width; j++)
		{
			matrix[i][j] = 1;
		}
	}
}

template<class T>
inline void Matrix<T>::clearMatrix()
{
	for (unsigned int i = 0; i < height; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}
