#include <windows.h>

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR IpCmdLine, INT nCmsShow)
{
	MessageBox(NULL, "Привет Windows", "Hello", MB_YESNOCANCEL | MB_HELP | MB_ICONINFORMATION); // Окно сообщения
	return 0;
}