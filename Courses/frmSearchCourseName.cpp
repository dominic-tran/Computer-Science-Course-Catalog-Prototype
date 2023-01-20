/*
	Team Radiants

	Tran, Dominic
	Hirahara, Allen

	Fall 2022
	CS A250 - C++ 2
	Project: CS Courses
*/

#include "frmSearchCourseName.h"
#include <msclr\marshal_cppstd.h> // from Microsoft C++ support library
#include <string>
#include <algorithm> // used for .find() method
#include <vector>

// Load
System::Void Courses::frmSearchCourseName::frmSearchCourseName_Load(
	System::Object^ sender, System::EventArgs^ e)
{
	this->txtSearch->Text = "";
}

// Exit btn
System::Void Courses::frmSearchCourseName::btnExit_Click(
	System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}

// Search btn
System::Void Courses::frmSearchCourseName::btnSearch_Click(
	System::Object^ sender, System::EventArgs^ e)
{
	if (IsPresent(txtSearch, "Key word(s)"))
	{
		std::string str;
		courseList->retrieveAllCourses(str);
		int strLen = static_cast<int>(str.length() + 1);

		// Converts input text and retrieveAllCourses to all upper-case.
		// Allows for input to not be case-sensitive.
		std::string strUpper = str;
		std::transform(strUpper.begin(), strUpper.end(),
			strUpper.begin(), ::toupper);
		std::string inputUpper = msclr::interop::marshal_as<std::string>
			(txtSearch->Text->ToUpper());
			// Uses the Microsoft C++ support library to convert Text to string

		std::vector<int> newLineLocations;
		newLineLocations.push_back(0);
		for (int i = 0; i < strLen; ++i)
		{
			if (str[i] == '\n')
			{
				newLineLocations.push_back(i);
			}
		} // Vector containing all occurences of '\n' in str

		int j = 0;
		int found = 0;
		int endLineFound = 0;
		int lineLocationLen = static_cast<int>(newLineLocations.size());
		int counter = 0;
		int courseCounter = 0;
		std::string resultString;
		std::string addToResult;
		bool initialEndLine = false;

		while (counter < lineLocationLen)
		{
			found = static_cast<int>(strUpper.find(inputUpper,
				newLineLocations[counter]));

			if (found != std::string::npos)
			{
				j = 0;
				initialEndLine = false;

				while (!initialEndLine)
				{
					if (str.substr(found - j, 4) == "CS A")
					{
						initialEndLine = true;
					}
					else
					{
						++j;
					}
				} // Traverses backwards from found pos until reaches '\n' or npos

				endLineFound = static_cast<int>(str.find('\n', found));
				addToResult = str.substr(found - j, endLineFound - found + j)
					+ "\n";

				if (resultString.find(addToResult) == -1)
				{
					resultString += addToResult;
					++courseCounter;
				} // Concatenates resultString with matching non-repeating courses
			}
			++counter;
		} // Iterates through each line of retrieveAllCourses str

		if (resultString == "")
		{
			MessageBox::Show("No courses matches your input." + 
					"\nTry inputting different words.", "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}
		else
		{
			if (courseCounter != 1)
			{
				resultString = std::to_string(courseCounter) + " Courses matching key word(s):\n\n" + resultString;
			}
			else
			{
				resultString = std::to_string(courseCounter) + " Course matching key word(s):\n\n" + resultString;
			}

			String^ result = gcnew String(resultString.c_str());
			MessageBox::Show(result, "CS Courses");
		}

	}
}

// Clear btn
System::Void Courses::frmSearchCourseName::btnReset_Click(
	System::Object^ sender, System::EventArgs^ e)
{
	txtSearch->Clear();
	txtSearch->Focus();
}
