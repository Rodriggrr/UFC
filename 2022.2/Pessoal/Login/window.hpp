#include <windows.h>
#include <iostream>
#include <utility>
#include <windowsx.h>

#define UNICODE


struct bar
{
            HWND hwndBar;
            
            void create(HWND hwnd, LPCSTR name, int posX, int posY, int sizeX, int sizeY, int ID, LPCSTR type){
            hwndBar = CreateWindow( 
            type,         // Predefined class
            name,         // Button text 
            WS_VISIBLE | WS_CHILD | WS_DLGFRAME,  // Styles 
            posX,         // x position 
            posY,         // y position 
            sizeX,        // Button width
            sizeY,        // Button height
            hwnd,         // Parent window
            (HMENU) ID,   // Object ID
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), 
            NULL);        // Pointer not needed
            }
};

struct button
{
            HWND hwndButton;
            
            void create(HWND hwnd, LPCSTR name, int posX, int posY, int sizeX, int sizeY, int ID, LPCSTR type){
            hwndButton = CreateWindow( 
            type,         // Predefined class
            name,         // Button text 
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
            posX,         // x position 
            posY,         // y position 
            sizeX,        // Button width
            sizeY,        // Button height
            hwnd,         // Parent window
            (HMENU) ID,   // Object ID
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), 
            NULL);        // Pointer not needed
        }
};

button butSim, butNao;

//Window Process, recebimento de mensagens.-------------------------------------------------------
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    //Switch para lidar (handle) com cada mensagem.
    switch(uMsg) {
        case WM_CLOSE:
            if(MessageBox(hWnd, "Certeza que deseja sair?", "Sair", MB_OKCANCEL | MB_ICONINFORMATION) == IDOK)
                PostQuitMessage(0);
            return 0;
            break;
        case WM_COMMAND:
                   
                break;
    }

    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

