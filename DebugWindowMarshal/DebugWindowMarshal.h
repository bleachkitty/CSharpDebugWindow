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

#pragma once

// BUILDING_CLI_WRAPPER is a preprocessor definition defined in the project properties.  This ensures the class is 
// imported or exported as appropriate.  Without this, you'll get "C4273: Inconsistent Linkage" warnings for each 
// of these functions, so if you get those warnings, you have likely forgotten this step.
#ifdef BUILDING_CLI_WRAPPER
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif

namespace DebugWindowMarshal
{
    // Note that Visual Studio automatically generates the class like this:
    // public ref class Class1
    // You could use this for storing C++ references in C#, but it's not really necessary.  In this case, an typical 
    // exported class is easier, as listed below.
    class DLL_EXPORT Marshal
    {
    public:
        static void ShowDebugWindow();
        static void AddChar(char character);
        static void SetButtonCallback(void(*pCallback)(const char*));
    };
}
