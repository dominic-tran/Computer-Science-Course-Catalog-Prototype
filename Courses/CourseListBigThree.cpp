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

// Copy constructor
CourseList::CourseList(const CourseList& otherCourseList)
{
	count = otherCourseList.count;

	if (count != 0)
	{
		first = new Node(otherCourseList.first->getCourse(), nullptr);

		auto tracker = first;
		auto otherTracker = otherCourseList.first->getNext();

		while (otherTracker != nullptr)
		{
			tracker->setNext(new Node(otherTracker->getCourse(), nullptr));

			if (tracker->getNext() == nullptr)
			{
				last = tracker;
			}

			tracker = tracker->getNext();
			otherTracker = otherTracker->getNext();
		}
	}
	else
	{
		first = nullptr;
		last = nullptr;
	}
}

// Definition overloaded assignment operator
CourseList& CourseList::operator=(const CourseList& otherCourseList)
{
	if (&otherCourseList == this)
	{
		cerr << "Attempted assignment to itself." << endl;
	}
	else
	{
		int otherCourseCount = otherCourseList.count;

		if (otherCourseCount == 0)
		{
			this->clearList();
		}
		else if (count == 0)
		{
			this->copyCallingObjIsEmpty(otherCourseList);
		}
		else if (count == otherCourseCount)
		{
			this->copyObjectsSameLength(otherCourseList);
		}
		else if (count > otherCourseCount)
		{
			this->copyCallingObjLonger(otherCourseList);
		}
		else if (count < otherCourseCount)
		{
			this->copyCallingObjShorter(otherCourseList);
		}
	}
	return *this;
}


// Definition function copyCallingObjIsEmpty
void CourseList::copyCallingObjIsEmpty(const CourseList& otherCourseList)
{
	// Making a for loop so that the pointer will iterate through the otherCourseList
	// and copy it into the calling CourseList
	for (auto i = otherCourseList.first; i != nullptr; i = i->getNext())
	{
		Node* newNode = new Node(i->getCourse(), nullptr);
		last->setNext(newNode);
		last = newNode;
	}
	count = otherCourseList.count;
}

// Definition function copyObjectsSameLength
void CourseList::copyObjectsSameLength(const CourseList& otherCourseList)
{
	// Creating tracker pointers with auto
	auto tracker = first;
	auto otherTracker = otherCourseList.first;

	// Creating a for loop to reset values from otherCourseList into CourseList
	for (int i = 0; i < count; ++i)
	{
		tracker->setCourse(otherTracker->getCourse());
		tracker = tracker->getNext();
		otherTracker = otherTracker->getNext();
	}
}

// Definition function copyCallingObjLonger
void CourseList::copyCallingObjLonger(const CourseList& otherCourseList)
{
	// Creating tracker pointers with auto
	auto tracker = first;
	auto otherTracker = otherCourseList.first;

	// Creating while loop to reset values from param to calling list
	while (otherTracker != nullptr)
	{
		tracker->setCourse(otherTracker->getCourse());
		otherTracker = otherTracker->getNext();
		if (otherTracker == nullptr)
		{
			Node* temp = tracker;
			tracker = tracker->getNext();
			temp->setNext(nullptr);
		} // tracker points to nullptr if otherTracker hits nullptr
		else
		{
			tracker = tracker->getNext();
		}
	}

	// Delete the rest of the other values in the calling CourseList
	auto deleteNode = tracker;
	while (tracker != nullptr)
	{
		tracker = tracker->getNext();
		delete deleteNode;
		deleteNode = nullptr;
		deleteNode = tracker;

	}

	count = otherCourseList.count;
}

// Definition function copyCallingObjShorter
void CourseList::copyCallingObjShorter(const CourseList& otherCourseList)
{
	// Creating tracker pointers with auto
	auto tracker = first;
	auto otherTracker = otherCourseList.first;

	// Creating a for loop to reset values from otherCourseList into CourseList
	for (int i = 0; i < count; ++i)
	{
		tracker->setCourse(otherTracker->getCourse());
		tracker = tracker->getNext();
		otherTracker = otherTracker->getNext();
	}

	// Add the rest of the nodes from the otherCourseList into CourseList
	for (int i = count; i < otherCourseList.count; ++i)
	{
		Node* newNode = new Node(otherTracker->getCourse(), nullptr);
		last->setNext(newNode);
		last = newNode;
		otherTracker = otherTracker->getNext();
	}

	count = otherCourseList.count;
}

// Destructor
CourseList::~CourseList()
{
	if (count != 0)
	{
		this->clearList();
	}
}
