/*
	Team Radiants

	Tran, Dominic
	Hirahara, Allen

	Fall 2022
	CS A250 - C++ 2
	Project: CS Courses
*/

#include "CourseList.h"

void CourseList::insertInOrder(Node* insertCourse)
{
	int insertCourseNumber = insertCourse->getCourse().getCourseNumber();

	if (count == 0)
	{
		first = insertCourse;
		first->setNext(nullptr);
		last = first;
	}
	else if (insertCourseNumber < first->getCourse().getCourseNumber())
	{
		insertCourse->setNext(first);
		first = insertCourse;
	} // if new course number is smaller than first node
	else if (insertCourseNumber > last->getCourse().getCourseNumber())
	{
		insertCourse->setNext(nullptr);
		last->setNext(insertCourse);
		last = last->getNext();
	} // if new course number is larger than last node
	else
	{
		Node* current = first->getNext();
		Node* trailCurrent = first;
		bool isLarger = false;

		while (!isLarger && trailCurrent != last)
		{
			if (insertCourseNumber > trailCurrent->getCourse().getCourseNumber()
				&& insertCourseNumber < current->getCourse().getCourseNumber())
			{
				insertCourse->setNext(current);
				trailCurrent->setNext(insertCourse);
				isLarger = true;
			}
			else
			{
				trailCurrent = current;
				current = current->getNext();
			}

		}
	}

	++count;
}
