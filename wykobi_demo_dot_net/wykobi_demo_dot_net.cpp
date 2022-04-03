#include "stdafx.h"
#include "WykobiGUIForm.h"

using namespace wykobi_demo_dot_net;

[STAThreadAttribute]
int main(array<System::String ^> ^/*args*/)
{
   // Enabling Windows XP visual effects before any controls are created
   Application::EnableVisualStyles();
   Application::SetCompatibleTextRenderingDefault(false);

   // Create the main window and run it
   Application::Run(gcnew WykobiGUIForm());
   return 0;
}
