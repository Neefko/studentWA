#include "main.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args){
	Application::SetCompatibleTextRenderingDefault(false); //Коректный текст
	Application::EnableVisualStyles(); //Подлючение Виз. стилей
	studentWA::main form;
	Application::Run(% form); //процент для передачи обьекта 
}
