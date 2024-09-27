#include<iostream>
#include"Organizer.h"
#include <cstdlib>;
#include <windows.h>;
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Organizer organizer("data.txå");
	//organizer.EnterJobs(3);
	organizer.LoadFromFile();
	organizer.PrintJobs();
	//organizer.SaveToFile();
	return 0;
}