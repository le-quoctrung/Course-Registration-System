#include"Console.h"


void Gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h, c);
}
void ResizeConsole(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void FixConsoleWindow()
{
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void AnTroChuot()
{
    CONSOLE_CURSOR_INFO Info;
    Info.bVisible = FALSE;
    Info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void HienTroChuot()
{
    CONSOLE_CURSOR_INFO Info;
    Info.bVisible = TRUE;
    Info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void SetTextColor(int backgound_color/*default white*/, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}
void full_screen()
{
    HWND hwnd = GetForegroundWindow();
    int cx = GetSystemMetrics(SM_CXSCREEN); /* screen width pixels */
    int cy = GetSystemMetrics(SM_CYSCREEN); /* screen height pixel */

    LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE); /* Get window information */
    /* Set the window information to maximize Cancel the title bar and border */
    SetWindowLong(hwnd, GWL_STYLE, (l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);

    SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
}
void DisableResizeWindow()
{
    HWND hWnd = GetConsoleWindow();
    SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}
void DisableCtrButton(bool Close, bool Min, bool Max)
{
    HWND hWnd = GetConsoleWindow();
    HMENU hMenu = GetSystemMenu(hWnd, false);

    if (Close == 1)
    {
        DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
    }
    if (Min == 1)
    {
        DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
    }
    if (Max == 1)
    {
        DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
    }
}
void ShowScrollbar(bool Show)
{
    HWND hWnd = GetConsoleWindow();
    ShowScrollBar(hWnd, SB_BOTH, Show);
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);

    HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hstdout, &csbi);

    csbi.dwSize.X = csbi.dwMaximumWindowSize.X;
    csbi.dwSize.Y = csbi.dwMaximumWindowSize.Y;
    SetConsoleScreenBufferSize(hstdout, csbi.dwSize);
}
void DisableSelection()
{
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

    SetConsoleMode(hStdin, ~ENABLE_QUICK_EDIT_MODE);
}
void Start()
{
    system("cls"); //clear screen
    SetConsoleTitle(L"portal.ctdb.hcmus.edu.vn");
    full_screen();
    system("color 70"); // change white background for console
    //system("mode 650");	// set console to fullscreen
    DisableResizeWindow();
    DisableCtrButton(0, 1, 1);
    ShowScrollbar(0);

    
    AnTroChuot();
    DisableSelection();   
}
bool CheckCursorClick(short xPos1, short xPos2, short yPos1, short yPos2) // same value with x,y in gotoxy() function
{

    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
    INPUT_RECORD InputRecord;
    DWORD Events;
    COORD coord;
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 25;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hout, &cci);
    SetConsoleMode(hin, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
    
    while (1)
    {
        ReadConsoleInput(hin, &InputRecord, 1, &Events);
        if (InputRecord.EventType == MOUSE_EVENT)
        {
            if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
            {
                coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
                coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
                if (coord.X > xPos1 && coord.X < xPos2 && coord.Y > yPos1 && coord.Y < yPos2)
                    return true;
                else
                    return false;
            }
        }
        FlushConsoleInputBuffer(hin);
    }
}
COORD GetCursorClick()
{
    
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
    INPUT_RECORD InputRecord;
    DWORD Events;
    COORD coord;
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 25;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hout, &cci);
    SetConsoleMode(hin, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);

    while (1)
    {
        ReadConsoleInput(hin, &InputRecord, 1, &Events);
        if (InputRecord.EventType == MOUSE_EVENT)
            if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
            {
                coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
                coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
                return coord;
            }
    }
}