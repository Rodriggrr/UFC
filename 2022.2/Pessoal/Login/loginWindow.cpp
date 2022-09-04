#include "window.hpp"

//Win Main, declaração da janela e criação dos botões. ---------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow) {
    //Fechar o console:
    PostMessage(GetConsoleWindow(),WM_QUIT,0,0);

    WNDCLASSEX cWindow;
    HWND hWnd;
    MSG Msg;

    //Definindo todas as propriedades da janela.
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

    //Se não for possível criar a janela:
    if(!RegisterClassEx(&cWindow))
        MessageBox(NULL, "Error registring window class!", "Fatal error", MB_OK | MB_ICONERROR);

    
    //Criando a janela em si.
    hWnd = CreateWindowEx(0, "cls", "Login", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT,
                          300, 200, HWND_DESKTOP, NULL, hInstance, NULL);

    //Criando os Botões e o texto.
    bar textLogin, textPassword;
    
    
    textPassword.create(hWnd, "", 10, 50, 240, 25, 1, "EDIT");
    textLogin.create(hWnd, "", 10, 100, 240, 25, 1, "EDIT");

    //Ciclo de mensagens entre o SO e a janela
    while(GetMessage(&Msg, NULL, NULL, NULL)) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    DestroyWindow(hWnd);
    return 0;
}
