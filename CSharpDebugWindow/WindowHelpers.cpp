//=====================================================================================================================
// MIT License
//
// Copyright(c) 2019 David "Rez" Graham
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//=====================================================================================================================

#include "WindowHelpers.h"
#include <tchar.h>

//---------------------------------------------------------------------------------------------------------------------
// This file doesn't contain anything interesting, it's boiler-plate code for the Win32 app.  The interesting stuff 
// in this project is all in Game.cpp.
//---------------------------------------------------------------------------------------------------------------------

HWND g_hwnd = nullptr;

namespace WindowHelpers {

constexpr const char* kAppName = "Game Window";
constexpr auto kWindowStyle = (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE);
constexpr int kWindowX = 50;
constexpr int kWindowY = 50;
constexpr int kWindowWidth = 800;
constexpr int kWindowHeight = 600;

//---------------------------------------------------------------------------------------------------------------------
// Creates the window.
//---------------------------------------------------------------------------------------------------------------------
bool CreateGameWindow(HINSTANCE hinstance, WNDPROC pWinProc)
{
    WNDCLASSEX wc;
    memset(&wc, 0, sizeof(wc));

    // fill in the window class structure
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = (CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW);
    wc.lpfnWndProc = pWinProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hinstance;
    wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);  //load large icon
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);  //background color
    wc.lpszMenuName = nullptr;   //load the menu
    wc.lpszClassName = kAppName;
    wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);  //load small icon

    // register the window class
    if (!RegisterClassEx(&wc))
    {
        MessageBox(nullptr, _T("RegisterClass() failed!"), _T("Critical Windows Error"), MB_OK);
        return false;
    }

    // create the window
    HWND g_hwnd = CreateWindowEx(0,  // extended Windows stuff
        kAppName, kAppName,  // application title
        kWindowStyle,
        kWindowX, kWindowY, kWindowWidth, kWindowHeight,  // initial position & size
        nullptr, nullptr,  // handle to parent & menu
        hinstance,  // instance of this application
        nullptr);  // extra creation params

    // make sure the handle is valid
    if (!g_hwnd)
    {
        MessageBox(nullptr, _T("CreateWindowEx() failed!"), _T("Critical Windows Error"), MB_OK);
        return false;
    }

    return true;
}

//---------------------------------------------------------------------------------------------------------------------
// Runs the main message pump.
//---------------------------------------------------------------------------------------------------------------------
int RunMessagePump()
{
    // main loop
    MSG msg;
    memset(&msg, 0, sizeof(msg));
    while (true)
    {
        const BOOL result = GetMessage(&msg, nullptr, 0, 0);

        if (result > 0)  // result > 0 means we have a message
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else if (result < 0)  // result < 0 means there was an error
        {
            MessageBox(g_hwnd, _T("Error processing message pump."), _T("Error"), MB_OK);
            return 0;
        }
        else  // result == 0 means exit program
        {
            break;
        }
    }

    return (int)msg.wParam;
}

}  // end namespace WindowHelpers

