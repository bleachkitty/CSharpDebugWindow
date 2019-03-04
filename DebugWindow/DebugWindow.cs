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
using System.Runtime.InteropServices;

namespace DebugWindow
{
    // Stylistic note: The fonts in this window are massive because it was originally a live presentation at GDC, so 
    // I wanted people to be able to read everything.
    public partial class DebugWindow : Form
    {
        //-------------------------------------------------------------------------------------------------------------
        // In C#, the C++ call is stored as a delegate.  See SetButtonCallback() below and Exports.SetButtonCallback()
        // for details on how this works.
        //-------------------------------------------------------------------------------------------------------------
        private delegate void ButtonCallback(string str);
        private ButtonCallback m_buttonCallback = null;

        //-------------------------------------------------------------------------------------------------------------
        // Constructor.
        //-------------------------------------------------------------------------------------------------------------
        public DebugWindow()
        {
            InitializeComponent();
        }

        //-------------------------------------------------------------------------------------------------------------
        // Sets the button callback.  See Exports.cs for details.
        //      -funcPtr:   The C++ function pointer.
        //-------------------------------------------------------------------------------------------------------------
        public void SetButtonCallback(IntPtr funcPtr)
        {
            // The call to GetDelegateForFunctionPointer() will effectively cast the raw C++ function pointer to the 
            // delegate type declared above.  See here for details on how this works:
            // https://docs.microsoft.com/en-us/dotnet/api/system.runtime.interopservices.marshal.getdelegateforfunctionpointer?view=netframework-4.7.2
            m_buttonCallback = Marshal.GetDelegateForFunctionPointer<ButtonCallback>(funcPtr);
        }

        //-------------------------------------------------------------------------------------------------------------
        // Called when the button is clicked.
        //-------------------------------------------------------------------------------------------------------------
        private void OnButtonClicked(object sender, EventArgs e)
        {
            // The hard work was done in SetButtonCallback(), so from this function's point of view, the C++ callback 
            // is just a delegate.  We can call it like any other delegate.
            if (m_buttonCallback != null)
                m_buttonCallback(m_textBox.Text);
            else
                MessageBox.Show("No button callback", "Error", MessageBoxButtons.OKCancel);
        }
    }
}
