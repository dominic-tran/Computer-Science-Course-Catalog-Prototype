#pragma once

#include "CourseList.h"

namespace Courses {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Text;
	using namespace System::Drawing;

	public ref class frmSearchCourseName : public System::Windows::Forms::Form
	{
	public:
		frmSearchCourseName(void)
		{
			InitializeComponent();
		}

		frmSearchCourseName(CourseList* list)
		{
			InitializeComponent();

			this->courseList = list;
		}

	protected:
		~frmSearchCourseName()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Label^ lblTitle;
	private: System::Windows::Forms::Label^ lblKeyWord;
	private: System::Windows::Forms::TextBox^ txtSearch;
	private: System::Windows::Forms::Button^ btnSearch;

	private: System::Windows::Forms::Button^ btnReset;
	private: System::Windows::Forms::Button^ btnExit;
	private: System::Windows::Forms::Label^ label1;






		   CourseList* courseList;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->lblKeyWord = (gcnew System::Windows::Forms::Label());
			this->txtSearch = (gcnew System::Windows::Forms::TextBox());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->btnReset = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->Location = System::Drawing::Point(74, 24);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(174, 13);
			this->lblTitle->TabIndex = 1;
			this->lblTitle->Text = L"Please Enter a Key Word or Phrase";
			// 
			// lblKeyWord
			// 
			this->lblKeyWord->AutoSize = true;
			this->lblKeyWord->Location = System::Drawing::Point(8, 73);
			this->lblKeyWord->Name = L"lblKeyWord";
			this->lblKeyWord->Size = System::Drawing::Size(96, 13);
			this->lblKeyWord->TabIndex = 2;
			this->lblKeyWord->Text = L"Enter Key Word(s):";
			// 
			// txtSearch
			// 
			this->txtSearch->Location = System::Drawing::Point(106, 70);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(219, 20);
			this->txtSearch->TabIndex = 3;
			// 
			// btnSearch
			// 
			this->btnSearch->Location = System::Drawing::Point(67, 106);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(75, 23);
			this->btnSearch->TabIndex = 4;
			this->btnSearch->Text = L"Search";
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->Click += gcnew System::EventHandler(this, &frmSearchCourseName::btnSearch_Click);
			// 
			// btnReset
			// 
			this->btnReset->Location = System::Drawing::Point(184, 106);
			this->btnReset->Name = L"btnReset";
			this->btnReset->Size = System::Drawing::Size(75, 23);
			this->btnReset->TabIndex = 6;
			this->btnReset->Text = L"Reset Word";
			this->btnReset->UseVisualStyleBackColor = true;
			this->btnReset->Click += gcnew System::EventHandler(this, &frmSearchCourseName::btnReset_Click);
			// 
			// btnExit
			// 
			this->btnExit->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnExit->Location = System::Drawing::Point(250, 158);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(75, 23);
			this->btnExit->TabIndex = 7;
			this->btnExit->Text = L"Exit";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &frmSearchCourseName::btnExit_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(81, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(159, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"(ex. C++, Java, CS A150, ect...) ";
			// 
			// frmSearchCourseName
			// 
			this->AcceptButton = this->btnSearch;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(337, 193);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnReset);
			this->Controls->Add(this->btnSearch);
			this->Controls->Add(this->txtSearch);
			this->Controls->Add(this->lblKeyWord);
			this->Controls->Add(this->lblTitle);
			this->Name = L"frmSearchCourseName";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Search CS Course by Key Word/Phrase";
			this->Load += gcnew System::EventHandler(this, &frmSearchCourseName::frmSearchCourseName_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		// Load
		System::Void frmSearchCourseName::frmSearchCourseName_Load(
			System::Object^ sender, System::EventArgs^ e);

		// Exit btn
		System::Void frmSearchCourseName::btnExit_Click(
			System::Object^ sender, System::EventArgs^ e);

		// Search btn
		System::Void frmSearchCourseName::btnSearch_Click(
			System::Object^ sender, System::EventArgs^ e);
		
		// Clear btn
		System::Void frmSearchCourseName::btnReset_Click(
			System::Object^ sender, System::EventArgs^ e);

		// Validator: Text is present
	private: bool IsPresent(TextBox^ textBox, String^ name)
	{
		if (textBox->Text == "")
		{
			MessageBox::Show(name + " is a required field.", "Entry Error");
			textBox->Focus();
			return false;
		}
		return true;
	}
};
}
