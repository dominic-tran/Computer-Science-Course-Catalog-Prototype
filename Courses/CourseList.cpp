/*
	Team Radiants

	Tran, Dominic
	Hirahara, Allen

	Fall 2022
	CS A250 - C++ 2
	Project: CS Courses
*/

#include "CourseList.h"
#include <iostream>

using namespace std;

// Definition function addCourse
void CourseList::addCourse(const Course& insertCourse)
{
	this->insertInOrder(new Node(insertCourse, nullptr));
}

// Definition function addCourse
void CourseList::addCourse(int courseNumber, const string& courseName,
	int courseUnits, const set<int>& prereqs)
{
	this->CourseList::insertInOrder(new Node(Course
	(courseNumber, courseName, courseUnits, prereqs), nullptr));
}

// Definition function getPrefix
string CourseList::getPrefix() const
{
	return Course::getPrefix();
}

// Definition function getNumberOfCourses
int CourseList::getNumberOfCourses() const
{
	return count;
}

// Definition function isEmpty
bool CourseList::isEmpty() const
{
	return (count == 0);
}

// Definition function searchCourse (courseNumber)
// Assume list is non-empty.
bool CourseList::searchCourse(int courseNumber) const
{
	return (this->getCourseLocation(courseNumber) != nullptr);
}

// Definition function searchCourse (courseNumber, courseName)
// Assume list is non-empty.
bool CourseList::searchCourse(int courseNumber, string& courseName) const
{
	bool isFound = true;
	if (this->getCourseLocation(courseNumber) == nullptr)
	{
		isFound = false;
	}
	else
	{
		courseName = this->getCourseLocation(courseNumber)->
			getCourse().getCourseName();
	}

	return isFound;
}

// Definition function searchCourse(courseNumber, course) 
// Assume list is non-empty.
bool CourseList::searchCourse(int courseNumber, Course& parameterCourse) const
{
	bool isFound = true;
	if (this->getCourseLocation(courseNumber) == nullptr)
	{
		isFound = false;
	}
	else
	{
		parameterCourse = this->getCourseLocation(courseNumber)->getCourse();
	}

	return isFound;
}

// Definitiion deleteCourse
// Assume list is non-empty.
// Assume course is in the list.
void CourseList::deleteCourse(int courseNumber)
{
	Node* deletedNode = this->getCourseLocation(courseNumber);

	if (first == deletedNode)
	{
		Node* temp = first;
		first = first->getNext();
		delete temp;

		temp = nullptr;
	}
	else
	{
		Node* current = first->getNext();
		Node* trailCurrent = first;
		bool isFound = false;

		while (!isFound && current != nullptr)
		{
			if (current == deletedNode)
			{
				trailCurrent->setNext(current->getNext());
				delete current;

				current = nullptr;
				isFound = true;
			}
			else
			{
				trailCurrent = current;
				current = current->getNext();
			}
		}
	}
}

// Definition retrieveAllCourses
// Assume list is non-empty.
void CourseList::retrieveAllCourses(string& collectCourses)
{
	Node* current = first;
	Course currentCourse;
	collectCourses = "";

	while (current != nullptr)
	{
		currentCourse = current->getCourse();

		collectCourses += "CS A" + to_string(currentCourse.getCourseNumber())
			+ " - " + currentCourse.getCourseName() + "\n";

		current = current->getNext();
	}
}

// Definition clearList
void CourseList::clearList()
{
	Node* current = first;
	Node* temp = nullptr;

	while (current != nullptr)
	{
		temp = current->getNext();
		delete current;
		current = temp;
	}

	first = nullptr;
}

// Definition function getCourseLocation
Node* CourseList::getCourseLocation(int courseNumber) const
{
	Node* current = first;
	bool isFound = false;

	while (!isFound && current != nullptr)
	{
		if (current->getCourse().getCourseNumber() == courseNumber)
		{
			isFound = true;
		}
		else
		{
			current = current->getNext();
		}
	}

	if (!isFound)
	{
		current = nullptr;
	}
	return current;
}
