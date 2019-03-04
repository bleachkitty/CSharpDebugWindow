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

#include "stdafx.h"

// This imports the C# functions from the DLL.  If you get an error on this line, it usually means one of two things:
//  1) You are not exporting the C# dll to a place visible by this project.
//  2) Your project dependencies are not set up correctly.  This project depends on the C# DLL being built.
#using "../Debug/DebugWindow.dll"
#include <msclr/auto_gcroot.h>

#include "DebugWindowMarshal.h"

using namespace System::Runtime::InteropServices;

namespace DebugWindowMarshal {

    void Marshal::ShowDebugWindow()
    {
        DebugWindow::Exports::ShowDebugWindow();
    }

    void Marshal::AddChar(char character)
    {
        DebugWindow::Exports::AddChar(character);
    }

    void Marshal::SetButtonCallback(void(*pCallback)(const char*))
    {
        DebugWindow::Exports::SetButtonCallback(System::IntPtr(pCallback));
    }

}  // end namespace DebugWindowMarshal
