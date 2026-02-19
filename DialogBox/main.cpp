#include <Windows.h>
#include "resource.h"

CONST CHAR h_sz_INVITE[] = "Введите имя пользователя";
// g - Global (глобальная переменная или константа)
//sz_ - String Zero (строка, заканчивающайся нулем - NULL Terminatel Line)

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM IParam);

INT WINAPI WinMain(HINSTANCE hInsance, HINSTANCE hPrevInst, LPSTR IpCmdLine, INT nCmdShow)
{
	DialogBoxParam(hInsance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc, 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM IParam)
{
	//HWND - Handler to Window. Это указатель, при помощи, которого можно обратиться
	// к окну ( указатель, на, который модно отправить сообщение - SendMEssage)
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
		SendMessage(hwnd, WM_SETICON, 0, (LPARAM)hIcon);
		
		HWND hEditLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
		SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)g_sz_INVITE);
	}
	break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_EDIT_LOGIN:
		{
			//WPARAM - это DWORD
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE] = {};
			HWND hEditLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
			SendMessage(hEditLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
			if (HIWORD(wParam) == EN_SETFOCUS && strcmp(sz_buffer, g_sz_INVITE) == 0)
			    SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)"");
			if(HIWORD(wParam) == EN_KILLFOCUS && strcmp(sz_buffer, "") == 0)
				SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)g_sz_INVITE);
		}
		break;
		case IDC_BUTTON_COPY:
		{
			CONST INT SIZE = 256; // Размер буфера в 256 байт
			CHAR sz_buffer[SIZE] = {}; // Текстовый буфер
			// Поулчаем текстовые поля, чтобы к ним можно было обращаться
			HWND hEditLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
			HWND hEditPassword = GetDlgItem(hwnd, IDC_EDIT_PASSWORD);
			// Для того, чтобы обратиться к какому-либо элементу окна,
			// ему нужно отправить сообщение
			SendMessage(hEditLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer); // Считываем текст из поля 'Login'
			SendMessage(hEditPassword, WM_SETTEXT, 0, (LPARAM)sz_buffer); // Загружаем
		}
		break;
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