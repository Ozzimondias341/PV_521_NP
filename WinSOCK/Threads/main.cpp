#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using std::cin;
using std::cout;
using std::endl;
using namespace std::chrono_literals;

bool finish = false;
std::mutex mutex;

void Plus()
{

	while (!finish)
	{
		mutex.lock();
		cout << "+ ";
		std::this_thread::sleep_for(10ms);
		mutex.unlock();
	}

}

void Minus()
{

	while (!finish)
	{
		mutex.lock();
		cout << "- ";
		std::this_thread::sleep_for(10ms);
		mutex.unlock();
	}

}

void main()
{
	setlocale(LC_ALL, "");

	//Plus();
	//Minus();

	std::thread plus_thread(Plus);
	std::thread minus_thread(Minus);

	cin.get();
	finish = true;


	if(plus_thread.joinable())plus_thread.join();
	if(minus_thread.joinable())minus_thread.join();

}
