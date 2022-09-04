#include "back.hpp"

#define UNICODE

class bar
{
public:
    HWND hwndBar;

    void create(HWND hwnd, LPCSTR name, int posX, int posY, int sizeX, int sizeY, int ID, LPCSTR type)
    {
        hwndBar = CreateWindow(
            type,                                // Predefined class
            name,                                // Button text
            WS_VISIBLE | WS_CHILD | WS_DLGFRAME, // Styles
            posX,                                // x position
            posY,                                // y position
            sizeX,                               // Button width
            sizeY,                               // Button height
            hwnd,                                // Parent window
            (HMENU)ID,                           // Object ID
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL); // Pointer not needed
    }
};

class text
{
public:
    HWND hwndButton;

    void create(HWND hwnd, LPCSTR name, int posX, int posY, int sizeX, int sizeY, int ID, LPCSTR type)
    {
        hwndButton = CreateWindow(
            type,                                             // Predefined class
            name,                                             // Button text
            SS_RIGHT | WS_VISIBLE | WS_CHILD | WS_THICKFRAME, // Styles
            posX,                                             // x position
            posY,                                             // y position
            sizeX,                                            // Button width
            sizeY,                                            // Button height
            hwnd,                                             // Parent window
            (HMENU)ID,                                        // Object ID
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL); // Pointer not needed
    }
};

// Window Process, recebimento de mensagens.-------------------------------------------------------
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    // Switch para lidar (handle) com cada mensagem.
    switch (uMsg)
    {
    case WM_CLOSE:
        if (MessageBox(hWnd, "Certeza que deseja sair?", "Sair", MB_OKCANCEL | MB_ICONINFORMATION) == IDOK)
            PostQuitMessage(0);
        return 0;
        break;
    case WM_COMMAND:
        do_op(LOWORD(wParam), hWnd);
        break;
    case WM_KEYDOWN:
        // Para quando receber mensagens do teclado
        key_input(LOWORD(wParam), hWnd);
        break;
    }

    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

// Win Main, declaração da janela e criação dos botões. ---------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
    // Fechar o console:
    PostMessage(GetConsoleWindow(), WM_QUIT, 0, 0);

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
    cWindow.hIcon = LoadIcon(NULL, IDI_QUESTION);
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
                          300, 394, HWND_DESKTOP, NULL, hInstance, NULL);

    // Criando os Botões e o texto.
    bar button;
    text rectangle;

    button.create(hWnd, "0", 5, 105, 190, 50, 10, "BUTTON");  // 0
    button.create(hWnd, "1", 5, 290, 60, 60, 1, "BUTTON");    // 1
    button.create(hWnd, "2", 70, 290, 60, 60, 2, "BUTTON");   // 2
    button.create(hWnd, "3", 135, 290, 60, 60, 3, "BUTTON");  // 3
    button.create(hWnd, "4", 5, 225, 60, 60, 4, "BUTTON");    // 4
    button.create(hWnd, "5", 70, 225, 60, 60, 5, "BUTTON");   // 5
    button.create(hWnd, "6", 135, 225, 60, 60, 6, "BUTTON");  // 6
    button.create(hWnd, "7", 5, 160, 60, 60, 7, "BUTTON");    // 7
    button.create(hWnd, "8", 70, 160, 60, 60, 8, "BUTTON");   // 8
    button.create(hWnd, "9", 135, 160, 60, 60, 9, "BUTTON");  // 9
    button.create(hWnd, "CE", 135, 70, 60, 30, 21, "BUTTON"); // CE
    button.create(hWnd, "C", 70, 70, 60, 30, 22, "BUTTON");   // C
    button.create(hWnd, ".X", 5, 70, 60, 30, 31, "BUTTON");   // .
    button.create(hWnd, "+", 200, 70, 37, 150, 32, "BUTTON"); // +
    button.create(hWnd, "-", 242, 70, 37, 150, 33, "BUTTON"); // -
    button.create(hWnd, "X", 200, 225, 37, 60, 34, "BUTTON"); // X
    button.create(hWnd, "/", 242, 225, 37, 60, 35, "BUTTON"); // /
    button.create(hWnd, "=", 200, 290, 78, 60, 36, "BUTTON"); // =

    rectangle.create(hWnd, "", 5, 5, 274, 50, 24, "STATIC");
    HWND showNum = CreateWindow("STATIC", "0.00", WS_VISIBLE | WS_CHILD | SS_RIGHT, 5, 22,
                                270, 15, hWnd, (HMENU)20, (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);

    showNumPtr = &showNum;

    // Ciclo de mensagens entre o SO e a janela
    while (GetMessage(&Msg, NULL, NULL, NULL))
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    DestroyWindow(hWnd);
    return 0;
}