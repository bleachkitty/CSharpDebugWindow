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

using System;
using System.Windows.Forms;

namespace DebugWindow
{
    public static class Exports
    {
        private static DebugWindow s_debugWindow = null;

        //-------------------------------------------------------------------------------------------------------------
        // This function shows the debug window.  It should be called when you want to show the debug window.  To 
        // close the window, just close it as normal.
        //-------------------------------------------------------------------------------------------------------------
        public static void ShowDebugWindow()
        {
            s_debugWindow = new DebugWindow();
            s_debugWindow.Show();
        }

        //-------------------------------------------------------------------------------------------------------------
        // Called by C++ to add a character to the static label.  This shows the process of sending data from the 
        // C++ game layer down to the C# form.
        //      -character: The character that was sent.
        //-------------------------------------------------------------------------------------------------------------
        public static void AddChar(char character)
        {
            if (s_debugWindow == null)
            {
                MessageBox.Show("Debug window is not active.", "Error", MessageBoxButtons.OK);
                return;
            }

            Control label = s_debugWindow.Controls["m_label"] as Label;
            if (label == null)
            {
                MessageBox.Show("Couldn't find label.", "Error", MessageBoxButtons.OK);
                return;
            }

            label.Text += character;
        }

        //-------------------------------------------------------------------------------------------------------------
        // Sets the C++ callback function, which is called whenever the button is clicked.  This is how the C# debug 
        // window can communicate with the game layer.
        // 
        // Note the IntPtr type.  This is an "internal pointer", which is how raw unmanaged pointers can be 
        // represented in C#.  This comes directly from C++.  See here for details on how IntPtr works:
        // https://docs.microsoft.com/en-us/dotnet/api/system.intptr?view=netframework-4.7.2
        //      -funcPtr:   The C++ function pointer callback, in the form of f(string).
        //-------------------------------------------------------------------------------------------------------------
        public static void SetButtonCallback(IntPtr funcPtr)
        {
            if (s_debugWindow == null)
            {
                MessageBox.Show("Debug window is not active.", "Error", MessageBoxButtons.OK);
                return;
            }

            s_debugWindow.SetButtonCallback(funcPtr);
        }
    }
}
