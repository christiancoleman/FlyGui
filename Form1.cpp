#include "stdafx.h"
#include "Form1.h"
#include "Program.h"
#include "WoW.h"

using namespace std;

WoW program;
int userAction = 0;

// ATTACH
System::Void flyGui::Form1::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	program = WoW();

	switch (program.getBaseAddress())
	{
	case 1:
		MessageBox::Show("FindWindow() Failed.");
		return;
	case 2:
		MessageBox::Show("GetWindowThreadProcessId() Failed.");
		return;
	case 3:
		MessageBox::Show("handleWoW == INVALID_HANDLE_VALUE");
		return;
	case 4:
		MessageBox::Show("Module32First returned FALSE");
		return;
	case 5:
		MessageBox::Show("setDebugPrivilegesEnabled() returned FALSE");
		return;
	}

	if (program.getProgramHandle() == NULL)
	{
		MessageBox::Show("OpenProcess() Failed.");
		return;
	}
	MessageBox::Show("Successfully attached.");
	program.setAttached(true);
}

//// FOV
System::Void flyGui::Form1::button2_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (program.attached == FALSE)
	{
		MessageBox::Show("Please attach to the process first");
		return;
	}

	float newFoV = (float)Convert::ToDouble(this->textBox1->Text);

	bool success = program.changeFoV(newFoV);
	
	if (!success)
	{
		MessageBox::Show("Did not write FOV successfully");
		return;
	}
}

// ZOOM
System::Void flyGui::Form1::button3_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (program.attached == FALSE)
	{
		MessageBox::Show("Please attach to the process first");
		return;
	}

	float newZoom = (float)Convert::ToDouble(this->textBox2->Text);
	
	bool success = program.changeZoom(newZoom);

	if (!success)
	{
		MessageBox::Show("Did not write zoom successfully");
		return;
	}
}

// TERRAIN
System::Void flyGui::Form1::checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (program.attached == FALSE)
	{
		if (userAction == 1)
		{
			userAction = 0;
			checkBox1->Checked = false;
			MessageBox::Show("Please attach to WoW first");
			return;
		}
		userAction = 1;
		return;
	}
//	if (buttonone == 0)
//	{
//		currentRender = currentRender - 0x2;
//		DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
//		int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
//		error = GetLastError();
//		if (isSuccess == 0)
//		{
//			MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error);
//			return;
//		}
//		buttonone = 1;
//	}
//	else
//	{
//		currentRender = currentRender + 0x2;
//		DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
//		int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
//		error = GetLastError();
//		if (isSuccess == 0)
//		{
//			MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error);
//			return;
//		}
//		buttonone = 0;
//	}
}

// M2
System::Void flyGui::Form1::checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (program.attached == FALSE)
	{
		if (userAction == 1)
		{
			userAction = 0;
			checkBox2->Checked = false;
			MessageBox::Show("Please attach to WoW first");
			return;
		}
		userAction = 1;
		return;
	}
//	if (buttontwo == 0)
//	{
//		currentRender = currentRender - 0x1;
//		DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
//		int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
//		error = GetLastError();
//		if (isSuccess == 0)
//		{
//			MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error);
//			return;
//		}
//		buttontwo = 1;
//	}
//	else
//	{
//		currentRender = currentRender + 0x1;
//		DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
//		int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
//		error = GetLastError();
//		if (isSuccess == 0)
//		{
//			MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error);
//			return;
//		}
//		buttontwo = 0;
//	}
}

// WMO
System::Void flyGui::Form1::checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (program.attached == FALSE)
	{
		if (userAction == 1)
		{
			userAction = 0;
			checkBox3->Checked = false;
			MessageBox::Show("Please attach to WoW first");
			return;
		}
		userAction = 1;
		return;
	}
//	if (buttonthree == 0)
//	{
//		currentRender = currentRender - 0x20;
//		DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
//		int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
//		error = GetLastError();
//		if (isSuccess == 0)
//		{
//			MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error);
//			return;
//		}
//		buttonthree = 1;
//	}
//	else
//	{
//		currentRender = currentRender + 0x20;
//		DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
//		int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
//		error = GetLastError();
//		if (isSuccess == 0)
//		{
//			MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error);
//			return;
//		}
//		buttonthree = 0;
//	}
}

// LIQUID
System::Void flyGui::Form1::checkBox4_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (program.attached == FALSE)
	{
		if (userAction == 1)
		{
			userAction = 0;
			checkBox4->Checked = false;
			MessageBox::Show("Please attach to WoW first");
			return;
		}
		userAction = 1;
		return;
	}
//	if (buttonfour == 0)
//	{
//		currentRender = currentRender - 0x200;
//		DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
//		int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
//		error = GetLastError();
//		if (isSuccess == 0)
//		{
//			MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error);
//			return;
//		}
//		buttonfour = 1;
//	}
//	else
//	{
//		currentRender = currentRender + 0x200;
//		DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
//		int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
//		error = GetLastError();
//		if (isSuccess == 0)
//		{
//			MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error);
//			return;
//		}
//		buttonfour = 0;
//	}
}

// WIREFRAME
System::Void flyGui::Form1::checkBox5_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (program.attached == FALSE)
	{
		if (userAction == 1)
		{
			userAction = 0;
			checkBox5->Checked = false;
			MessageBox::Show("Please attach to WoW first");
			return;
		}
		userAction = 1;
		return;
	}
//	if (buttonfive == 0)
//	{
//		currentRender = currentRender + 0x08000000;
//		DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
//		int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
//		error = GetLastError();
//		if (isSuccess == 0)
//		{
//			MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error);
//			return;
//		}
//		buttonfive = 1;
//	}
//	else
//	{
//		currentRender = currentRender - 0x08000000;
//		DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
//		int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
//		error = GetLastError();
//		if (isSuccess == 0)
//		{
//			MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error);
//			return;
//		}
//		buttonfive = 0;
//	}
}

// COLLISION
System::Void flyGui::Form1::checkBox6_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (program.attached == FALSE)
	{
		if (userAction == 1)
		{
			userAction = 0;
			checkBox6->Checked = false;
			MessageBox::Show("Please attach to WoW first");
			return;
		}
		userAction = 1;
		return;
	}
//	if (buttonsix == 0)
//	{
//		currentRender = currentRender + 0x04000000;
//		DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
//		int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
//		error = GetLastError();
//		if (isSuccess == 0)
//		{
//			MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error);
//			return;
//		}
//		buttonsix = 1;
//	}
//	else
//	{
//		currentRender = currentRender - 0x04000000;
//		DWORD WoWbase_PLUS_E2260C = WoWbaseaddress + 14820876; // WoWbase + 0xE2260C
//		int isSuccess = WriteProcessMemory(actualWoWhandle, (void*)WoWbase_PLUS_E2260C, &currentRender, 4, 0);
//		error = GetLastError();
//		if (isSuccess == 0)
//		{
//			MessageBox::Show("Did not write new render successfully. GetLastError() produced: " + error);
//			return;
//		}
//		buttonsix = 0;
//
//	}
}