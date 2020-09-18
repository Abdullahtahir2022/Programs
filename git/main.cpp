#include <windows.h>
#include <iostream>
#include<fstream>
#include<stdio.h>
using namespace std;

LRESULT CALLBACK WindowProcedure(HWND,UINT,WPARAM,LPARAM);
void AddControls(HWND);

HWND hName,hAge,hOut;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
    WNDCLASSW wc ={0};
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance= hInst;
    wc.lpszClassName= L"mywindowclass";
    wc.lpfnWndProc = WindowProcedure;
    if(!RegisterClassW(&wc))
        return -1;
    CreateWindowW(L"mywindowclass",L"My Window",WS_OVERLAPPEDWINDOW | WS_VISIBLE,100,100,500,500,
                  NULL,NULL,NULL,NULL);
    MSG msg ={0};


    while(GetMessage(&msg,NULL,NULL,NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

    }

    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp)
{
    switch (msg)
    {




    case WM_CREATE:
        AddControls(hWnd);
        break;





    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProcW(hWnd,msg,wp,lp);
    }
}


void AddControls(HWND hWnd)
{

    hName=CreateWindowW(L"static", L"Name" , WS_VISIBLE | WS_CHILD, 200,150,98,38,hWnd, NULL,NULL,NULL);
    hName=CreateWindowW(L"Edit", L"..." , WS_VISIBLE | WS_CHILD, 300,150,98,38,hWnd, NULL,NULL,NULL);
    hName=CreateWindowW(L"static", L"ID" , WS_VISIBLE | WS_CHILD, 200,350,98,38,hWnd, NULL,NULL,NULL);
    hName=CreateWindowW(L"Edit", L"..." , WS_VISIBLE | WS_CHILD, 300,350,98,38,hWnd, NULL,NULL,NULL);
    hName=CreateWindowW(L"Button", L"DONE" , WS_VISIBLE | WS_CHILD, 300,400,98,38,hWnd, NULL,NULL,NULL);

}



















