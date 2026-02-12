#include <Windows.h>
#include "resource.h"

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM IParam);

INT WINAPI WinMain(HINSTANCE hInsance, HINSTANCE hPrevInst, LPSTR IpCmdLine, INT nCmdShow)
{
	DialogBoxParam(hInsance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc, 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM IParam)
{
	switch (uMsg)
	{
	    case WM_INITDIALOG:
			break;
		case WM_COMMAND:
			switch (LOWORD(wParam))
			{
			case IDOK:
				MessageBox(hwnd, "Была нажата кнопка ОК", "info", MB_OK | MB_ICONINFORMATION);
				break;
			case IDCANCEL:EndDialog(hwnd, 0);
			}
		case WM_CLOSE:
			EndDialog(hwnd, 0);
	}
	return FALSE;
}