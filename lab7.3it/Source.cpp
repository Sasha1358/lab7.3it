#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>
using namespace std;

void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
void localmin(int** a, const int n);
int Sum(int** a, const int n);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 65;
	int n;
	cout << "n = "; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	Create(a, n, Low, High);
	cout << "Масив:" << endl;
	Print(a, n);
	int sum = Sum(a, n);
	cout << "Сума модулів елементів вище головної діагоналі: " << sum << endl;

	cout << "К-сть локальних мінімумів = ";
	localmin(a, n);
	
	for (int i = 0; i < n; i++)
	delete [] a[i];
	delete [] a;
	return 0;
}
void Create(int** a, const int n, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

int Sum(int** a, const int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			sum += abs(a[i][j]);
		}
	}
	return sum;
}
void localmin(int** a, const int n)
{
	int count = 0;
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-1; j++) {
			if (a[i][j] < a[i - 1][j] && a[i][j] < a[i + 1][j] && 
				a[i][j] < a[i][j-1] && a[i][j] < a[i][j+1])
			{
				count++;
			}
		}
	}
	cout << count;
}