#include <iostream>
#include <conio.h>
#include <sstream>
#include <windows.h>
using namespace std;

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_CLOSE:
        if (MessageBox(hWnd, "Certeza que deseja sair?", "Sair", MB_OKCANCEL | MB_ICONINFORMATION) == IDOK)
            PostQuitMessage(0);
        return 0;
        break;

    }
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
    WNDCLASSEX cWindow;
    HWND hWnd;
    MSG Msg;

    // Definindo todas as propriedades da janela.
    cWindow.cbSize = sizeof(WNDCLASSEX);
    cWindow.lpszClassName = "cls";
    cWindow.lpfnWndProc = WndProc;
    cWindow.lpszMenuName = NULL;
    cWindow.hInstance = hInstance;
    cWindow.style = CS_OWNDC;
    cWindow.hIcon = LoadIcon(NULL, IDI_HAND);
    cWindow.hIconSm = LoadIcon(NULL, IDI_QUESTION);
    cWindow.hCursor = LoadCursor(NULL, IDC_ARROW);
    cWindow.hbrBackground = (HBRUSH)1;
    cWindow.cbClsExtra = 0;
    cWindow.cbWndExtra = 0;

    // Se não for possível criar a janela:
    if (!RegisterClassEx(&cWindow))
        MessageBox(NULL, "Error registring window class!", "Fatal error", MB_OK | MB_ICONERROR);


    // Criando a janela em si.
    hWnd = CreateWindowEx(0, "cls", "Calculadora", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT,
                          300, 200, HWND_DESKTOP, NULL, hInstance, NULL);

    HWND Rebar  = CreateWindowEx(0, "LISTBOX", "teste",  WS_VISIBLE | WS_CHILD, 5, 22,
                                200, 25, hWnd, (HMENU)20, (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);

    // Ciclo de mensagens entre o SO e a janela
    while (GetMessage(&Msg, NULL, NULL, NULL))
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }


    DestroyWindow(hWnd);
    return 0;
}
