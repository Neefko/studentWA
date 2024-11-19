#pragma once
#include "add_student.h"
#include "grafic.h"
#include "allstude.h"
#include "delstude.h"
#include "infostude.h"

namespace studentWA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для main
	/// </summary>
	public ref class main : public System::Windows::Forms::Form
	{
	public:
		main(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ add_studentov;
	private: System::Windows::Forms::Button^ all_student;
	private: System::Windows::Forms::Button^ del_student;
	private: System::Windows::Forms::Button^ graf_student;
	private: System::Windows::Forms::Button^ edit_student;





	protected:

	protected:


	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->add_studentov = (gcnew System::Windows::Forms::Button());
			this->all_student = (gcnew System::Windows::Forms::Button());
			this->del_student = (gcnew System::Windows::Forms::Button());
			this->graf_student = (gcnew System::Windows::Forms::Button());
			this->edit_student = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// add_studentov
			// 
			this->add_studentov->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->add_studentov->Location = System::Drawing::Point(12, 12);
			this->add_studentov->Name = L"add_studentov";
			this->add_studentov->Size = System::Drawing::Size(97, 36);
			this->add_studentov->TabIndex = 0;
			this->add_studentov->Text = L"Добавить студента";
			this->add_studentov->UseVisualStyleBackColor = true;
			this->add_studentov->Click += gcnew System::EventHandler(this, &main::add_student_Click);
			// 
			// all_student
			// 
			this->all_student->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->all_student->Location = System::Drawing::Point(115, 12);
			this->all_student->Name = L"all_student";
			this->all_student->Size = System::Drawing::Size(97, 36);
			this->all_student->TabIndex = 1;
			this->all_student->Text = L"Все студенты";
			this->all_student->UseVisualStyleBackColor = true;
			this->all_student->Click += gcnew System::EventHandler(this, &main::all_student_Click);
			// 
			// del_student
			// 
			this->del_student->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->del_student->Location = System::Drawing::Point(218, 12);
			this->del_student->Name = L"del_student";
			this->del_student->Size = System::Drawing::Size(97, 36);
			this->del_student->TabIndex = 2;
			this->del_student->Text = L"Удалить студента";
			this->del_student->UseVisualStyleBackColor = true;
			this->del_student->Click += gcnew System::EventHandler(this, &main::del_student_Click);
			// 
			// graf_student
			// 
			this->graf_student->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->graf_student->Location = System::Drawing::Point(218, 54);
			this->graf_student->Name = L"graf_student";
			this->graf_student->Size = System::Drawing::Size(97, 49);
			this->graf_student->TabIndex = 3;
			this->graf_student->Text = L"График успеваймости";
			this->graf_student->UseVisualStyleBackColor = true;
			this->graf_student->Click += gcnew System::EventHandler(this, &main::grafik);
			// 
			// edit_student
			// 
			this->edit_student->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->edit_student->Location = System::Drawing::Point(12, 54);
			this->edit_student->Name = L"edit_student";
			this->edit_student->Size = System::Drawing::Size(97, 49);
			this->edit_student->TabIndex = 4;
			this->edit_student->Text = L"Изменить ифнормацию о студенте";
			this->edit_student->UseVisualStyleBackColor = true;
			this->edit_student->Click += gcnew System::EventHandler(this, &main::info_student_Click);
			// 
			// main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->ClientSize = System::Drawing::Size(345, 300);
			this->Controls->Add(this->edit_student);
			this->Controls->Add(this->graf_student);
			this->Controls->Add(this->del_student);
			this->Controls->Add(this->all_student);
			this->Controls->Add(this->add_studentov);
			this->Name = L"main";
			this->Text = L"Приложение для подсчёта студентов";
			this->Load += gcnew System::EventHandler(this, &main::main_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void main_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void add_student_Click(System::Object^ sender, System::EventArgs^ e) {
		add_student^ add_students = gcnew add_student();
		add_students->ShowDialog();
	};
	private: System::Void grafik(System::Object^ sender, System::EventArgs^ e) {
		grafic^ grafik = gcnew grafic();
		grafik->ShowDialog();
	};
	private: System::Void all_student_Click(System::Object^ sender, System::EventArgs^ e) {
		allstude^ all_student = gcnew allstude();
		all_student->ShowDialog();
	};
	private: System::Void del_student_Click(System::Object^ sender, System::EventArgs^ e) {
		delstude^ del_students = gcnew delstude();
		del_students->ShowDialog();

	}
	private: System::Void info_student_Click(System::Object^ sender, System::EventArgs^ e) {
		infostude^ infostudents = gcnew infostude();
		infostudents->ShowDialog();
	}
};
}
