namespace DebugWindow
{
    partial class DebugWindow
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.m_label = new System.Windows.Forms.Label();
            this.m_textBox = new System.Windows.Forms.TextBox();
            this.m_button = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // m_label
            // 
            this.m_label.AutoSize = true;
            this.m_label.Font = new System.Drawing.Font("Microsoft Sans Serif", 64F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.m_label.Location = new System.Drawing.Point(12, 9);
            this.m_label.Name = "m_label";
            this.m_label.Size = new System.Drawing.Size(257, 97);
            this.m_label.TabIndex = 0;
            this.m_label.Text = "Test: ";
            // 
            // m_textBox
            // 
            this.m_textBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 64F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.m_textBox.Location = new System.Drawing.Point(12, 119);
            this.m_textBox.Name = "m_textBox";
            this.m_textBox.Size = new System.Drawing.Size(776, 104);
            this.m_textBox.TabIndex = 1;
            // 
            // m_button
            // 
            this.m_button.Font = new System.Drawing.Font("Microsoft Sans Serif", 64F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.m_button.Location = new System.Drawing.Point(12, 247);
            this.m_button.Name = "m_button";
            this.m_button.Size = new System.Drawing.Size(776, 129);
            this.m_button.TabIndex = 2;
            this.m_button.Text = "Call C++";
            this.m_button.UseVisualStyleBackColor = true;
            this.m_button.Click += new System.EventHandler(this.OnButtonClicked);
            // 
            // DebugWindow
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 400);
            this.Controls.Add(this.m_button);
            this.Controls.Add(this.m_textBox);
            this.Controls.Add(this.m_label);
            this.Name = "DebugWindow";
            this.Text = "DebugWindow";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label m_label;
        private System.Windows.Forms.TextBox m_textBox;
        private System.Windows.Forms.Button m_button;
    }
}