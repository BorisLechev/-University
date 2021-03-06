#include "pch.h"
#include <iostream>
#include<string>
#include<vector>

using namespace std;

class Student
{
protected:
	string name;

	vector<int> grades;

	string facultyNumber;

public:
	Student(string studentNameParam, string facultyNuymberParam)
	{
		name = studentNameParam;
		facultyNumber = facultyNuymberParam;
	}

	string GetName()
	{
		return name;
	}

	void SetName(string studentNameParam)
	{
		name = studentNameParam;
	}

	string GetFacultyNumber()
	{
		return facultyNumber;
	}

	void SetFacultyNumber(string facultyNumberParam)
	{
		facultyNumber = facultyNumberParam;
	}

	double GetAverageGrade()
	{
		int gradesCount = grades.size();
		double sum = 0;

		for (int i = 0; i < gradesCount; i++)
		{
			sum = sum + grades[i];
		}

		return sum / gradesCount;
	}

	vector<int> GetGrades()
	{
		return grades;
	}

	void AddGrade(int grade)
	{
		grades.push_back(grade);
	}
};

class Course
{
protected:
	string courseName;

	vector<Student> students;

public:
	Course(string courseNameParam)
	{
		courseName = courseNameParam;
	}

	string GetName()
	{
		return courseName;
	}

	void SetName(string courseNameParam)
	{
		courseName = courseNameParam;
	}

	void AddGrade(string facultyNumber, int grade) {
		for (int i = 0; i < students.size(); i++) {
			if (students[i].GetFacultyNumber() == facultyNumber) {
				students[i].AddGrade(grade);
			}
		}
	}

	void AddGrades(string facultyNumber, vector<int> studentGrades)
	{
		for (int i = 0; i < students.size(); i++)
		{
			if (students[i].GetFacultyNumber() == facultyNumber)
			{
				for (int j = 0; j < studentGrades.size(); j++)
				{
					students[i].AddGrade(studentGrades[j]);
				}
			}
		}
	}

	void DisplayGrades()
	{
		for (int i = 0; i < students.size(); i++)
		{
			cout << students[i].GetFacultyNumber() << " ";

			vector<int> currentStudentGrades = students[i].GetGrades();
			cout << students[i].GetName() << "'s grades: ";

			for (int j = 0; j < currentStudentGrades.size(); j++)
			{
				cout << currentStudentGrades[j] << " ";
			}

			cout << "Average grade: " << students[i].GetAverageGrade() << endl;
		}
	}

	void MakeStudent(string studentName, string facultyNumber)
	{
		Student newStudent(studentName, facultyNumber);
		students.push_back(newStudent);
	}
};

void main()
{
	Course course("C++ OOP BASICS");

	course.MakeStudent("Boris", "17621337");
	course.MakeStudent("Stamat", "17621322");
	course.MakeStudent("Ignat", "17621311");
	course.MakeStudent("Kirilcho", "17621388");

	course.AddGrades("17621337", { 6,6,6 });

	course.AddGrades("17621322", { 3,5,6 });

	course.AddGrades("17621311", { 2,2,4 });

	course.AddGrade("17621388", 5);
	course.AddGrade("17621388", 6);
	course.AddGrade("17621388", 6);

	course.DisplayGrades();
}