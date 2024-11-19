#pragma once
#include "sqlite_helper.h"
#include <msclr/marshal_cppstd.h>

namespace studentWA {

    using namespace System;
    using namespace System::Windows::Forms;

    public ref class delstude : public System::Windows::Forms::Form {
    public:
        delstude(void) {
            InitializeComponent();
        }

    protected:
        ~delstude() {
            if (components) {
                delete components;
            }
        }

    private: System::Windows::Forms::TextBox^ textBox1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Button^ button1;
           System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void) {
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(12, 25);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(260, 20);
            this->textBox1->TabIndex = 1;
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(12, 9);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(239, 13);
            this->label2->TabIndex = 2;
            this->label2->Text = L"Введите id студента, которого хотите удалить";
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(12, 52);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(75, 23);
            this->button1->TabIndex = 3;
            this->button1->Text = L"Удалить";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &delstude::del_stud);
            // 
            // allstude
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->ClientSize = System::Drawing::Size(284, 261);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->textBox1);
            this->Name = L"delstude";
            this->Text = L"delstude";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void del_stud(System::Object^ sender, System::EventArgs^ e) {
        SQLiteDel reader("C:/Users/79004/CodeProjects/cppProject/studentWA/db/student_db");
        reader.openDatabase();

        // Получаем ID из текстового поля и преобразуем в строку
        std::string input = msclr::interop::marshal_as<std::string>(textBox1->Text);

        // Проверка на пустой ввод
        if (input.empty()) {
            this->label2->Text = "Введите ID студента.";
            return;
        }

        // Строим параметризованный запрос
        std::string query = "DELETE FROM student WHERE id = ?;";

        // Подготовка запроса
        sqlite3_stmt* stmt;
        int rc = sqlite3_prepare_v2(reader.db, query.c_str(), -1, &stmt, nullptr);

        if (rc != SQLITE_OK) {
            this->label2->Text = "Ошибка подготовки запроса.";
            return;
        }

        // Привязываем параметр (ID студента)
        rc = sqlite3_bind_int(stmt, 1, std::stoi(input));  // преобразуем input в int

        if (rc != SQLITE_OK) {
            this->label2->Text = "Ошибка привязки параметра.";
            sqlite3_finalize(stmt);
            return;
        }

        // Выполняем запрос
        rc = sqlite3_step(stmt);

        if (rc != SQLITE_DONE) {
            MessageBox::Show("Ошибка выполнения запроса.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            
        }
        else {
            MessageBox::Show("Студент удалён успешно.(Или такого id нету)", "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }

        // Завершаем работу с подготовленным выражением
        sqlite3_finalize(stmt);
    }
    };
}