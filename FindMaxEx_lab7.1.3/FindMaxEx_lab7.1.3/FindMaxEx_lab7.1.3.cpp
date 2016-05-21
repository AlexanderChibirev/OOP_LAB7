// FindMaxEx_lab7.1.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FindMaxEx.h"
#include <fstream>
#include <boost/lexical_cast.hpp>

using namespace std;

struct Athlete
{
	string fullName;
	double weight;
	double growth;
};
enum class ErrorCode
{
	CANT_OPEN_INPUT_FILE,
	INCORRECT_PROPERTIES
};

vector<Athlete> GetInformationAboutAthletesFromFile(const string &inputFileName, ErrorCode &errorCode)
{
	ifstream inputFile;
	inputFile.open(inputFileName);
	vector<Athlete> arr;
	if (!inputFile.is_open())
	{
		errorCode = ErrorCode::CANT_OPEN_INPUT_FILE;
		return arr;
	}
	while (!inputFile.eof())
	{
		Athlete athlete;
		string name;
		inputFile >> name;
		athlete.fullName = name;
		inputFile >> name;
		athlete.fullName += " " + name;
		inputFile >> name;
		athlete.fullName += " " + name;
		string growth;
		inputFile >> growth;
		string weight;
		inputFile >> weight;
		try
		{
			athlete.growth = boost::lexical_cast<double>(growth);
			athlete.weight = boost::lexical_cast<double>(weight);
		}
		catch(boost::bad_lexical_cast)
		{
			errorCode = ErrorCode::INCORRECT_PROPERTIES;
			return arr;
		}
		arr.push_back(athlete);
	}
	return arr;
}

void PrintResult(vector<Athlete> strongestAndTallestAthletes)
{
	for (auto &it : strongestAndTallestAthletes)
	{
		cout << it.fullName << " " << it.growth << " " << it.weight << endl;
	}
}
vector<Athlete> GetStrongestAndTallestAthletes(const vector<Athlete> &athletes)
{
	vector<Athlete> strongestAndTallestAthletes;
	Athlete bestAthlete;
	if (FindMax(athletes, bestAthlete, [](Athlete lhs, Athlete rhs) {return lhs.growth < rhs.growth; }))
	{
		strongestAndTallestAthletes.push_back(bestAthlete);
	};
	if (FindMax(athletes, bestAthlete, [](Athlete lhs, Athlete rhs) {return lhs.weight < rhs.weight; }))
	{
		strongestAndTallestAthletes.push_back(bestAthlete);
	}
	return strongestAndTallestAthletes;
}
int main(int argc, char** argv)
{
	if (argc != 2)
	{
		cout << "Wrong amount of arguments was proposed\nEnter a correct arguments amount please, for example:\n' <input file>'";
		return 1;
	}
	string inputFileName = argv[1];
	ErrorCode errorCode;
	vector<Athlete> athletes = GetInformationAboutAthletesFromFile(inputFileName, errorCode);
	switch (errorCode)
	{
	case ErrorCode::CANT_OPEN_INPUT_FILE:
		cout << "Failed to open" << inputFileName << "file for reading\n";
		return 1;
	case ErrorCode::INCORRECT_PROPERTIES:
		cout << "incorrect properties athlete\n";
		return 1;
	}
	PrintResult(GetStrongestAndTallestAthletes(athletes));
	return 0;
}

