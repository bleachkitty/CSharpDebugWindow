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

#include <Windows.h>
#include <tchar.h>
#include "WindowHelpers.h"

// Include the marshal header here so we have access to our functions.  Don't forget to link it and ensure that the 
// DLL can be found by the EXE.  The easiest thing to do is to export the DLL directly to the EXE's output folder.
#include "../DebugWindowMarshal/DebugWindowMarshal.h"

//-----------------------------------------------------------------------------------------------------------------------
// globals
//-----------------------------------------------------------------------------------------------------------------------
extern HWND g_hwnd;

//---------------------------------------------------------------------------------------------------------------------
// This is called whenever a key is hit on the keyboard.  It will call into our glue wrapper DLL, which in turn calls 
// into our C# DLL to update the form.
//      -val:   The character that was hit.
//---------------------------------------------------------------------------------------------------------------------
void HandleCharEvent(char val)
{
    DebugWindowMarshal::Marshal::AddChar(val);
}

//---------------------------------------------------------------------------------------------------------------------
// This is the callback function we pass to C#.  C# stores it as a delegate and calls it whenever the button is 
// pressed.
//      -str:   The string passed from C#.
//---------------------------------------------------------------------------------------------------------------------
void OnButtonHit(const char* pMessage)
{
    MessageBox(g_hwnd, _T(pMessage), _T("Message From C#"), MB_OK);
}

//---------------------------------------------------------------------------------------------------------------------
// Main window message callback.  The only interesting thing here is the call to HandleCharEvent() in WM_CHAR, which 
// will call into the C# form.
//---------------------------------------------------------------------------------------------------------------------
LRESULT CALLBACK MainWindowMessageProc(HWND g_hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    switch (msg)
    {
        case WM_DESTROY:
        {
            PostQuitMessage(0);  // kill the application, this sends a WM_QUIT message
            return 0;  // return success
        }

        case WM_CHAR:
        {
            HandleCharEvent((char)wparam);
            return 0;  // success
        }

        default:
        {
            return DefWindowProc(g_hwnd, msg, wparam, lparam);
        }
    }
}

//---------------------------------------------------------------------------------------------------------------------
// WinMain()
//---------------------------------------------------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hprevinstance, LPSTR commandline, int showflags)
{
    if (!WindowHelpers::CreateGameWindow(hinstance, &MainWindowMessageProc))
        return 1;

    // Show the window and send our callback function.
    DebugWindowMarshal::Marshal::ShowDebugWindow();
    DebugWindowMarshal::Marshal::SetButtonCallback(&OnButtonHit);

    return WindowHelpers::RunMessagePump();
}
