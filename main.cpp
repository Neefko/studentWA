#include "main.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args){
	Application::SetCompatibleTextRenderingDefault(false); //��������� �����
	Application::EnableVisualStyles(); //���������� ���. ������
	studentWA::main form;
	Application::Run(% form); //������� ��� �������� ������� 
}