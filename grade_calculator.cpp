#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class Class
{
private:
	string className;
	double score;
	string grade;
public:
	Class(string cn, double sc, string gr) : className{ cn }, score{ sc }, grade{ gr } {}

	string getGrade()
	{
		return grade;
	}
	double getScore()
	{
		return score;
	}

	static double getTotalScore(vector<Class> v)
	{
		double total = 0;
		for (int i{ 0 }; i < v.size(); i++)
		{
			if (v[i].getGrade() != "P")
				total += v[i].score;
		}
		return total;
	}
};

int main()
{
	vector<Class> v;

	for (int i{ 0 }; i < 20; i++)
	{
		string className;
		double score;
		string grade;

		cin >> className >> score >> grade;
		v.emplace_back(className, score, grade);
	}

	double balance = 0;

	for (int i{ 0 }; i < v.size(); i++)
	{
		if (v[i].getGrade() == "A+")
		{
			balance += v[i].getScore() * 4.5;
		}
		else if (v[i].getGrade() == "A0")
		{
			balance += v[i].getScore() * 4.0;
		}
		else if (v[i].getGrade() == "B+")
		{
			balance += v[i].getScore() * 3.5;
		}
		else if (v[i].getGrade() == "B0")
		{
			balance += v[i].getScore() * 3.0;
		}
		else if (v[i].getGrade() == "C+")
		{
			balance += v[i].getScore() * 2.5;
		}
		else if (v[i].getGrade() == "C0")
		{
			balance += v[i].getScore() * 2.0;
		}
		else if (v[i].getGrade() == "D+")
		{
			balance += v[i].getScore() * 1.5;
		}
		else if (v[i].getGrade() == "D0")
		{
			balance += v[i].getScore() * 1.0;
		}
		else if (v[i].getGrade() == "F")
		{
			balance += v[i].getScore() * 0.0;
		}
	}
	cout << fixed << setprecision(6) << balance / Class::getTotalScore(v);
}
