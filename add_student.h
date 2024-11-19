#pragma once 
#include "sqlite_helper.h"
#include <msclr/marshal_cppstd.h>

namespace studentWA {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class add_student : public System::Windows::Forms::Form
    {
    public:
        add_student(void)
        {
            InitializeComponent();
        }

    protected:
        ~add_student()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::TextBox^ textBoxFamily;
        System::Windows::Forms::TextBox^ textBoxName;
        System::Windows::Forms::ComboBox^ comboBoxPol;
        System::Windows::Forms::TextBox^ textBoxAge;
        System::Windows::Forms::ComboBox^ comboBoxStatus;
        System::Windows::Forms::Button^ buttonAdd;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label5;
           System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->textBoxFamily = (gcnew System::Windows::Forms::TextBox());
            this->textBoxName = (gcnew System::Windows::Forms::TextBox());
            this->comboBoxPol = (gcnew System::Windows::Forms::ComboBox());
            this->textBoxAge = (gcnew System::Windows::Forms::TextBox());
            this->comboBoxStatus = (gcnew System::Windows::Forms::ComboBox());
            this->buttonAdd = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // textBoxFamily
            // 
            this->textBoxFamily->Location = System::Drawing::Point(12, 25);
            this->textBoxFamily->Name = L"textBoxFamily";
            this->textBoxFamily->Size = System::Drawing::Size(260, 20);
            this->textBoxFamily->TabIndex = 0;
            // 
            // textBoxName
            // 
            this->textBoxName->Location = System::Drawing::Point(12, 65);
            this->textBoxName->Name = L"textBoxName";
            this->textBoxName->Size = System::Drawing::Size(260, 20);
            this->textBoxName->TabIndex = 1;
            // 
            // comboBoxPol
            // 
            this->comboBoxPol->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->comboBoxPol->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Мужской", L"Женский" });
            this->comboBoxPol->Location = System::Drawing::Point(12, 105);
            this->comboBoxPol->Name = L"comboBoxPol";
            this->comboBoxPol->Size = System::Drawing::Size(260, 21);
            this->comboBoxPol->TabIndex = 2;
            // 
            // textBoxAge
            // 
            this->textBoxAge->Location = System::Drawing::Point(12, 145);
            this->textBoxAge->Name = L"textBoxAge";
            this->textBoxAge->Size = System::Drawing::Size(260, 20);
            this->textBoxAge->TabIndex = 3;
            // 
            // comboBoxStatus
            // 
            this->comboBoxStatus->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->comboBoxStatus->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Бюджетник", L"Не бюджетник(тупой)" });
            this->comboBoxStatus->Location = System::Drawing::Point(12, 185);
            this->comboBoxStatus->Name = L"comboBoxStatus";
            this->comboBoxStatus->Size = System::Drawing::Size(260, 21);
            this->comboBoxStatus->TabIndex = 4;
            // 
            // buttonAdd
            // 
            this->buttonAdd->Location = System::Drawing::Point(12, 225);
            this->buttonAdd->Name = L"buttonAdd";
            this->buttonAdd->Size = System::Drawing::Size(75, 23);
            this->buttonAdd->TabIndex = 5;
            this->buttonAdd->Text = L"Добавить";
            this->buttonAdd->UseVisualStyleBackColor = true;
            this->buttonAdd->Click += gcnew System::EventHandler(this, &add_student::addStudent);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(13, 6);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(56, 13);
            this->label1->TabIndex = 6;
            this->label1->Text = L"Фамилия";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(13, 49);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(29, 13);
            this->label2->TabIndex = 7;
            this->label2->Text = L"Имя";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(13, 88);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(27, 13);
            this->label3->TabIndex = 8;
            this->label3->Text = L"Пол";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(12, 129);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(49, 13);
            this->label4->TabIndex = 9;
            this->label4->Text = L"Возраст";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(12, 169);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(88, 13);
            this->label5->TabIndex = 10;
            this->label5->Text = L"Бюджет или нет";
            // 
            // add_student
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(284, 261);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->buttonAdd);
            this->Controls->Add(this->comboBoxStatus);
            this->Controls->Add(this->textBoxAge);
            this->Controls->Add(this->comboBoxPol);
            this->Controls->Add(this->textBoxName);
            this->Controls->Add(this->textBoxFamily);
            this->Name = L"add_student";
            this->Text = L"Добавление студента";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        System::Void addStudent(System::Object^ sender, System::EventArgs^ e) {
            // Получаем значения из текстовых полей
            std::string family = msclr::interop::marshal_as<std::string>(textBoxFamily->Text);
            std::string name = msclr::interop::marshal_as<std::string>(textBoxName->Text);
            std::string pol = msclr::interop::marshal_as<std::string>(comboBoxPol->Text);
            std::string age = msclr::interop::marshal_as<std::string>(textBoxAge->Text);
            std::string status = msclr::interop::marshal_as<std::string>(comboBoxStatus->Text);

            // Проверяем, чтобы поля не были пустыми
            if (family.empty() || name.empty() || pol.empty() || age.empty() || status.empty()) {
                MessageBox::Show("Пожалуйста, заполните все поля.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            // Открытие базы данных и подготовка запроса для добавления студента
            SQLiteWriter writer("C:/Users/79004/CodeProjects/cppProject/studentWA/db/student_db");
            writer.openDatabase();

            // Параметризованный запрос для добавления студента
            std::string query = "INSERT INTO student (family, name, pol, age, status) VALUES (?, ?, ?, ?, ?);";
            sqlite3_stmt* stmt;

            // Подготовка запроса
            int rc = sqlite3_prepare_v2(writer.db, query.c_str(), -1, &stmt, nullptr);
            if (rc != SQLITE_OK) {
                MessageBox::Show("Ошибка подготовки запроса.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            // Привязываем параметры
            sqlite3_bind_text(stmt, 1, family.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 2, name.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 3, pol.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_int(stmt, 4, std::stoi(age)); // Преобразуем возраст в int
            sqlite3_bind_text(stmt, 5, status.c_str(), -1, SQLITE_STATIC);

            // Выполняем запрос
            rc = sqlite3_step(stmt);
            if (rc != SQLITE_DONE) {
                MessageBox::Show("Ошибка выполнения запроса.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
            else {
                MessageBox::Show("Студент добавлен успешно.", "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }

            // Завершаем работу с подготовленным выражением
            sqlite3_finalize(stmt);
        }
};
}