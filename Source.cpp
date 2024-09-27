#include<iostream>
#include"Organizer.h"
using namespace std;

int main()
{
	Organizer organizer("data.tx");
	//organizer.EnterJobs(2);
	organizer.LoadFromFile();
	organizer.PrintJobs();
	//organizer.SaveToFile();
	return 0;
}