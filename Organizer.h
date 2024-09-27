#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Job {
	string Name;
	int Priority;
	string Solution;
	string JobDoneDate;
};

class Organizer
{
public:
	string fileName;
	Organizer(string FileName) : fileName{ FileName } {}
	~Organizer()
	{
		if (!Jobs.empty()) Jobs.clear();
	}
	void EnterJobs(int count)
	{
		for (size_t i = 0; i < count; i++)
		{
			Jobs.push_back(EnterJob());
		}
	}
	void PrintJobs()
	{
		if (Jobs.empty())
		{
			cout << "Sorry job`s list is empty...";
		}
		else
		{
			for (size_t i = 0; i < Jobs.size(); i++)
			{
				PrintOneJob(Jobs[i]);
			}
		}
	}
	void PrintJob(int index)
	{
		if (isIndex(index))
		{
			cout << "Index out of range!!!" << endl;
		}
		else
		{
			PrintOneJob(Jobs[index]);
		}
	}
	void SaveToFile()
	{
		if (fileName.length() < 5 || Jobs.empty())
		{
			cout << "Not correct fileName or no data in Jobs!!!";
		}
		else
		{
			ofstream out(fileName);
			for (size_t i = 0; i < Jobs.size(); i++)
			{
				out << Jobs[i].Name << endl;
				out << Jobs[i].Priority << endl;
				out << Jobs[i].Solution << endl;
				out << Jobs[i].JobDoneDate << endl;
			}
			out.close();
		}
	}
	void LoadFromFile()
	{
		if (!Jobs.empty()) Jobs.clear();
		ifstream input;
		input.open(fileName);
		if (input)
		{
			Job job;
			input >> job.Name;
			input >> job.Priority;
			input >> job.Solution;
			input >> job.JobDoneDate;
			Jobs.push_back(job);
		}
		else
		{
			cout << "File " << fileName << " not found" << endl;
		}
	}
	Job getJob(int index)
	{
		if (isIndex(index))
		{
			cout << "Index not range in Jobs"<<endl;
		}
		else
		{
			return Jobs[index];
		}
	}
	void DeleteJob(int index)
	{
		if (isIndex(index))
		{
			cout << "Index not range in Jobs" << endl;
		}
		else
		{
			Jobs.erase(Jobs.begin() + index);
		}
	}
	void EditJob(int index)
	{
		if (isIndex(index))
		{
			cout << "Index not range in Jobs" << endl;
		}
		else
		{
			Jobs[index] = EnterJob();
		}
	}
	void SearchByName(string jobName)
	{
		if (jobName.length() > 0)
		{
			int count = 0;
			for (size_t i = 0; i < Jobs.size(); i++)
			{
				if (Jobs[i].Name == jobName)
				{
					PrintOneJob(Jobs[i]);
					count++;
				}
			}
			if (count == 0) cout << "Not found Jobs " << endl; else cout << "Founded " << count << " jobs" << endl;
		}
		else
		{
			cout << "Job Name not correct!!!" << endl;
		}
	}
	void SearchByPriority(int priority)
	{
		int count = 0;
		for (size_t i = 0; i < Jobs.size(); i++)
		{
			if (Jobs[i].Priority == priority)
			{
				PrintOneJob(Jobs[i]);
				count++;
			}
		}
		if (count == 0) cout << "Not found Jobs " << endl; else cout << "Founded " << count << " jobs" << endl;
	}

private:
	vector<Job> Jobs;
	Job EnterJob()
	{
		Job job;
		cout << "Enter job`s name: "; cin >> job.Name;
		cout << "Enter job`s priority: "; cin >> job.Priority;
		cout << "Enter job`s solution: "; cin >> job.Solution;
		cout << "Enter job`s done date: "; cin >> job.JobDoneDate;
		return job;
	}
	bool isIndex(int index)
	{
		if (index > Jobs.size() || index < 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void PrintOneJob(Job job)
	{
		cout << "-----------------------------------------------------------------" << endl;
		cout << job.Name << "\t" << job.Priority << "\t" << job.Solution << "\t" << job.JobDoneDate << endl;
		cout << "-----------------------------------------------------------------" << endl;
	}
};

