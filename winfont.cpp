// Source: http://forum.ubuntu.org.cn/viewtopic.php?f=121&t=291611

#include <windows.h>
#include <stdio.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int PASCAL WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
    char szAppName[] = "字型測試";
    HWND hwnd;
    MSG msg;
    WNDCLASS wndclass;

    if (!hPrevInstance)
    {
        wndclass.style = CS_VREDRAW;
        wndclass.lpfnWndProc = WndProc;
        wndclass.cbClsExtra = 0;
        wndclass.cbWndExtra = 0;
        wndclass.hInstance = hInstance;
        wndclass.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
        wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
        wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
        wndclass.lpszMenuName = NULL;
        wndclass.lpszClassName = szAppName;

        if (!RegisterClass(&wndclass))
            return FALSE;
    }

    hwnd = CreateWindow(
               szAppName,
               "字型測試",
               WS_OVERLAPPEDWINDOW,
               CW_USEDEFAULT, CW_USEDEFAULT,
               CW_USEDEFAULT, CW_USEDEFAULT,
               NULL,
               NULL,
               hInstance,
               NULL );

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while ( GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    int wmId, wmEvent;
    PAINTSTRUCT ps;
    HDC hdc;
    switch (message)
    {

    case WM_PAINT:
    {
        RECT rect;
        HBRUSH hBrush;
        HFONT hFont;
        hdc = BeginPaint(hWnd, &ps);

        // Tahoma, ANSI_CHARSET
        hFont = CreateFont(48,0,0,0,FW_DONTCARE,FALSE,TRUE,FALSE,ANSI_CHARSET,OUT_OUTLINE_PRECIS,
                           CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY, VARIABLE_PITCH,TEXT("Tahoma"));
        SelectObject(hdc, hFont);
        SetRect(&rect, 100, 50, 700, 200);
        SetTextColor(hdc, RGB(255,0,0));
        DrawText(hdc, TEXT("這是中文 This is English, Tahoma, ANSI"), -1,&rect, DT_NOCLIP);

        // Thahoma, DEFAULT_CHARSET
        hFont = CreateFont(48,0,0,0,FW_DONTCARE,FALSE,TRUE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
                           CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY, VARIABLE_PITCH,TEXT("Tahoma"));
        SelectObject(hdc, hFont);
        SetRect(&rect, 100, 100,700,200);
        SetTextColor(hdc, RGB(255,0,0));
        DrawText(hdc, TEXT("這是中文 This is English, Tahoma, DEFAULT"), -1,&rect, DT_NOCLIP);

#if 0
        // Times New Roman, DEFAULT_CHARSET
        hFont = CreateFont(48,0,0,0,FW_DONTCARE,FALSE,TRUE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
                           CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY, VARIABLE_PITCH,TEXT("Times New Roman"));
        SelectObject(hdc, hFont);
        SetRect(&rect, 100, 150,700,200);
        SetTextColor(hdc, RGB(255,0,0));
        DrawText(hdc, TEXT("這是中文 This is English"), -1,&rect, DT_NOCLIP);

        // Courier, DEFAULT_CHARSET
        hFont = CreateFont(48,0,0,0,FW_DONTCARE,FALSE,TRUE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
                           CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY, VARIABLE_PITCH, TEXT("Courier"));
        SelectObject(hdc, hFont);
        SetRect(&rect, 100, 200, 700,200);
        SetTextColor(hdc, RGB(255,0,0));
        DrawText(hdc, TEXT("這是中文 This is English"), -1,&rect, DT_NOCLIP);
#endif

        // PMingLiU (Traditional Chinese), DEFAULT_CHARSET
        hFont = CreateFont(48,0,0,0,FW_DONTCARE,FALSE,TRUE,FALSE, DEFAULT_CHARSET, 
                OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY, VARIABLE_PITCH,TEXT("PMingLiu"));
        SelectObject(hdc, hFont);
        SetRect(&rect, 100, 250, 700, 200);
        SetTextColor(hdc, RGB(255,0,0));
        DrawText(hdc, TEXT("這是中文 This is English, DEFAULT_CHARSET"), -1, &rect, DT_NOCLIP);

        // PMingLiU (Traditional Chinese), ANSI_CHARSET
        hFont = CreateFont(48,0,0,0,FW_DONTCARE,FALSE,TRUE,FALSE, ANSI_CHARSET, 
                OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY, VARIABLE_PITCH,TEXT("PMingLiu"));
        SelectObject(hdc, hFont);
        SetRect(&rect, 100, 300, 700, 200);
        SetTextColor(hdc, RGB(255,0,0));
        DrawText(hdc, TEXT("這是中文 This is English, ANSI_CHARSET"), -1, &rect, DT_NOCLIP);

        DeleteObject(hFont);

        EndPaint(hWnd, &ps);
        break;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
