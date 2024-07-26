#include<Windows.h>
#include"resource.h"

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//HIWORD - ������� �����
//LOWORD - ������� �����

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	//hInstance - ��� *.exe-������ ����� ���������
	//hPrevInst - ���� �������� ������������� � ��������������� ���� IA-16/IA-32 (Win98)
	//			  �� ������� �� ��������.
	//lpCmdLine - LongPointer to Command prompt, ��� ��������� ������ ���������� � ������� WinMain ��� ������� ���������.
	//			  lpCmdLine ������������ ����� ������ �����, ������� ��������� �������� ������ �������� ������ ���� � *.exe-�����.

	/*MessageBox(NULL, "HelloWorld!\n��� ���� ���������, �����", "Hello WinAPI", MB_ABORTRETRYIGNORE | MB_ICONSTOP | MB_DEFBUTTON3 | MB_HELP | MB_TOPMOST);
	std::cout << typeid(char).name() << std::endl;
	std::cout << typeid(wchar_t).name() << std::endl;
	WndProc*/

	int a = 2;
	{
		int a = 3;
	}

	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc, 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//hwnd - Handler to Window (���������� ����)
	switch (uMsg)
	{
		//WM_ - Windows Message
	case WM_INITDIALOG:	//������������ ������ ���� ���, ��� �������� ����
		//H - Handler (����������, ����������)
	{
		HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON_BTC));
		SendMessage(hwnd, WM_SETICON, 0, (LPARAM)hIcon);
	}
	break;
	case WM_COMMAND:	//����� �������������� ������� �� ������, ���� ������, � ����� ��������� ��������� ����.
		switch (LOWORD(wParam))
		{
		case IDOK:		MessageBox(hwnd, "���� ������ ������ OK", "Info", MB_OK | MB_ICONINFORMATION); break;
		case IDCANCEL:	EndDialog(hwnd, 0);
		}
		break;
	case WM_CLOSE:		//������������ ��� ������� �� ������ X (�������)
		EndDialog(hwnd, 0);
		break;
	}
	return FALSE;
}