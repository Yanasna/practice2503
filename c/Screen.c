#include<windows.h>

static int g_nScreenIndex;
static HANDLE g_hScreen[2];

void ScreenInit()
{
	CONSOLE_CURSOR_INFO cci;

	g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	cci.dwSize = 1;
	cci.bVisible = FALSE;
	setConsoleCursorInfo(g_hScreen[0], &cci);
	setConsoleCursorInfo(g_hScreen[1], &cci);
}

void ScreenFlipping() {
	Sleep(10);
	SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);
	g_nScreenIndex = !g_nScreenIndex;
}

void ScreenClear()
{
	COORD Coor = { 0, 0 };
	DWORD dw;
	FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ', 80 * 25, Coor, &dw);
}

void ScreenRelease()
{
	CloseHandle(g_hScreen[0]);
	CloseHandle(g_hScreen[1]);
}

void ScreenPrint(int x, int y, char* String)
{
	DWORD dw;
	COORD CursorPosition = {x, y};
	SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
	WriteFile(g_hScreen[g_nScreenIndex], string, strlen(string), &dw, NULL);
}

void SetColor(unsigned short color) {
	SetConsoleTextAttribute(g_hScreen[g_nScreenIndex], color);
}
