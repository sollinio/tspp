// im.cpp: определяет точку входа для консольного приложения.
//
//Преобразование: 1D → 2D. Одномерный массив из 25 вещественных чисел необходимо
//разложить по двумерной сетке 5х5 слева направо и сверху вниз, но первый элемент на
//каждой строке должен содержать сумму остальных четырех.
//Инициализация: заполнить массив числами x[n] = n ∙ sin(πn/25), n – индекс элемента.
//Вывод на экран: на каждый элемент массива отвести 10 позиций.
#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;
//git com
void initializeArray(int* arr, size_t n)
{
	if (n > 0)
	{
		*arr = 1.0;
	}
	if (n > 1)
	{
		*(arr + 1) = 1.0;
	}
	for (size_t i = 2; i < n; ++i)
	{
		arr[i] = i * sin((3.14*i)/25);
	}
}
void printArray1D(int* arr1D, size_t LN)
{
	cout<<"1D array"<<endl;
	
	for(size_t i=0; i<LN; i++)
	{
		cout<<arr1D[i]<<" ";
	}
	cout<<endl;
}

int** makeArray2D(int* arr1D, size_t rows, size_t cols)
{
	int** arr2D = new int* [rows]; // выделяем память под выходной массив
	for (size_t i = 0; i < rows; ++i) // и еще под каждый ряд массива в отдельности
	{
		*(arr2D + i) = new int [cols];
	}
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < cols; ++j)
		{
			arr2D[i][j] = arr1D[i*cols + j];
		}
	}
	return arr2D; // возвращаем указатель на выделенную память под 2-мерный массив
}
void printArray2D(int** arr, size_t n, size_t m)
{
	cout<<"2D array"<<endl;
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
           if (arr[i][j] % 10  == arr[i][j]) cout << "    ";
           else if (arr[i][j] % 100  == arr[i][j]) cout << "   ";
           else if (arr[i][j] % 1000 == arr[i][j]) cout << "  ";
		   else if (arr[i][j] % 10000 == arr[i][j]) cout << " ";
            cout << arr[i][j];
        }
        cout << endl;
    }
}
// comment one vans
int main()
{
const size_t LEN = 25; // задаем все параметры
const size_t N = 5;
const size_t M = 5;
int* arr = new int [LEN]; // выделяем память под входной массив
int sum[N] = {0}; //сумма элементов строк
initializeArray(arr, LEN); // инициализируем массив (по варианту)
printArray1D(arr, LEN); // выводим на консоль массив
// конвертируем 1-мерный массив в 2-мерный (по варианту)
int** arr2D = makeArray2D(arr, N, M);

for(int i = 0; i < N; i++)
{
	for(int j = 0; j < M; j++)
	{
		sum[i] += arr2D[i][j];
	}
}
for(int i = 0; i < N; i++)
{
	for(int j = 0; j < M; j++)
	{
		cout.width(3);
		cout << arr2D[i][j];
	}
	cout << "  mumm: " << sum[i] << endl;
}
for (size_t i = 0; i < N; ++i)
{
		for (size_t j = 0; j < M; ++j)
		{
			if(arr2D[i][j] == arr2D[0][0])
			{
				arr2D[i][j] = sum[0];
			}
			if(arr2D[i][j] == arr2D[1][0])
			{
				arr2D[i][j] = sum[1];
			}
			if(arr2D[i][j] == arr2D[2][0])
			{
				arr2D[i][j] = sum[2];
			}
			if(arr2D[i][j] == arr2D[3][0])
			{
				arr2D[i][j] = sum[3];
			}
			if(arr2D[i][j] == arr2D[4][0])
			{
				arr2D[i][j] = sum[4];
			}
		}
}

printArray2D(arr2D, N, M); // выводим на консоль 2-мерный массив-результат
system("pause");
return 0;
}