#pragma once

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
	private: System::Windows::Forms::Button^ count_student;
	private: System::Windows::Forms::Label^ test_label;

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
			this->count_student = (gcnew System::Windows::Forms::Button());
			this->test_label = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// count_student
			// 
			this->count_student->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->count_student->Location = System::Drawing::Point(12, 12);
			this->count_student->Name = L"count_student";
			this->count_student->Size = System::Drawing::Size(97, 36);
			this->count_student->TabIndex = 0;
			this->count_student->Text = L"Сколько всего студентов";
			this->count_student->UseVisualStyleBackColor = true;
			this->count_student->Click += gcnew System::EventHandler(this, &main::count_student_Click);
			// 
			// test_label
			// 
			this->test_label->AutoSize = true;
			this->test_label->Location = System::Drawing::Point(147, 12);
			this->test_label->Name = L"test_label";
			this->test_label->Size = System::Drawing::Size(31, 13);
			this->test_label->TabIndex = 1;
			this->test_label->Text = L"Тест";
			// 
			// main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->ClientSize = System::Drawing::Size(345, 300);
			this->Controls->Add(this->test_label);
			this->Controls->Add(this->count_student);
			this->Name = L"main";
			this->Text = L"Приложение для подсчёта студентов";
			this->Load += gcnew System::EventHandler(this, &main::main_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void main_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void count_student_Click(System::Object^ sender, System::EventArgs^ e) {
		this->test_label->Text = "Тест удался";
	}
	};
}
