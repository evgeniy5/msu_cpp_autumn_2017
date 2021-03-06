#include <chrono>
#include <iostream>
using namespace std;


class Timer
{
public:
	Timer()
		: start_(std::chrono::high_resolution_clock::now())
	{
	}

	~Timer()
	{
		const auto finish = std::chrono::high_resolution_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::microseconds>(finish - start_).count() << " us = ";
		std::cout << std::chrono::duration_cast<std::chrono::microseconds>(finish - start_).count()/1.0e6 << " s" << std::endl;
	}

private:
	const std::chrono::high_resolution_clock::time_point start_;
};


int main()
{
	int N = 10000;
	volatile int sum = 0;

	int** data = new int*[N];
	for (int i = 0; i < N; i++) {
		data[i] = new int[N]; 
	}

	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			data[i][j] = i + j;

	Timer t;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			sum += data[j][i];
	return 0;
}