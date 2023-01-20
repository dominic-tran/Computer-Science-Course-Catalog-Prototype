/*
	Team Radiants
	
	Tran, Dominic
	Hirahara, Allen
	
	Fall 2022
	CS A250 - C++ 2
	Project: CS Courses
*/

#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <set>

class Course
{
public:

	// Constructors
	Course() : courseNumber(0), courseUnits(0),
		courseName("N/A") {}
	// Default constructor

	Course(int newCourseNumber, const std::string& newCourseName,
		int newNumberOfUnits, const std::set<int>& newPrerequisites);
	// Overloaded constructor

	// Accessor functions
	const std::string& getCourseName() const;
	int getCourseNumber() const;
	int getCourseUnits() const;
	const std::set<int>& getCoursePrereqs() const;
	const Course& getCourse() const;
	static std::string getPrefix();

	// Mutator functions
	void setCourseName(const std::string& newCourseName);
	void setCourseNumber(int newCourseNumber);
	void setCourseUnits(int newNumberOfUnits);
	void setPrereqs(const int newPrerequisites[], int lengthOfArray);

	// Destructor
	~Course() {};

private:
	int courseNumber;
	std::string courseName;
	int courseUnits;
	std::set<int> prereqs;
	static const std::string PREFIX;
};
#endif
