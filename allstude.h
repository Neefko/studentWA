#pragma once
#include "sqlite_helper.h"

namespace studentWA {

    using namespace System;
    using namespace System::Windows::Forms;

    public ref class allstude : public System::Windows::Forms::Form {
    public:
        allstude(void) {
            InitializeComponent();
            LoadData();
        }

    protected:
        ~allstude() {
            if (components) {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Label^ label1;
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void) {
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(12, 9);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(0, 13);
            this->label1->TabIndex = 0;
            // 
            // allstude
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->ClientSize = System::Drawing::Size(284, 261);
            this->Controls->Add(this->label1);
            this->Name = L"allstude";
            this->Text = L"allstude";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

        void LoadData() {
            SQLiteReader reader("C:/Users/79004/CodeProjects/cppProject/studentWA/db/student_db");
            reader.openDatabase();
            std::string data = reader.readAllRows("SELECT * FROM student;");
            this->label1->Text = gcnew System::String(data.c_str());
        }
    };
}