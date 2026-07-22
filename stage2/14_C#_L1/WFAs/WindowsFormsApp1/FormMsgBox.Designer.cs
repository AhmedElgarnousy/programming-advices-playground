namespace WindowsFormsApp1
{
    partial class FormMsgBox
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
            this.btnShowMsgBox = new System.Windows.Forms.Button();
            this.btnShowMsgWithTitle = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.btnMsgBoxWithIconalso = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnShowMsgBox
            // 
            this.btnShowMsgBox.Location = new System.Drawing.Point(96, 41);
            this.btnShowMsgBox.Name = "btnShowMsgBox";
            this.btnShowMsgBox.Size = new System.Drawing.Size(160, 84);
            this.btnShowMsgBox.TabIndex = 0;
            this.btnShowMsgBox.Text = "Show Msg Box";
            this.btnShowMsgBox.UseVisualStyleBackColor = true;
            this.btnShowMsgBox.Click += new System.EventHandler(this.button1_Click);
            // 
            // btnShowMsgWithTitle
            // 
            this.btnShowMsgWithTitle.Location = new System.Drawing.Point(96, 143);
            this.btnShowMsgWithTitle.Name = "btnShowMsgWithTitle";
            this.btnShowMsgWithTitle.Size = new System.Drawing.Size(160, 84);
            this.btnShowMsgWithTitle.TabIndex = 1;
            this.btnShowMsgWithTitle.Text = "Show MsgBox with Title";
            this.btnShowMsgWithTitle.UseVisualStyleBackColor = true;
            this.btnShowMsgWithTitle.Click += new System.EventHandler(this.button1_Click_1);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(96, 272);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(160, 84);
            this.button1.TabIndex = 2;
            this.button1.Text = "Add Btn Cancel to MsgBox";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click_2);
            // 
            // btnMsgBoxWithIconalso
            // 
            this.btnMsgBoxWithIconalso.Cursor = System.Windows.Forms.Cursors.No;
            this.btnMsgBoxWithIconalso.Location = new System.Drawing.Point(321, 41);
            this.btnMsgBoxWithIconalso.Name = "btnMsgBoxWithIconalso";
            this.btnMsgBoxWithIconalso.Size = new System.Drawing.Size(160, 84);
            this.btnMsgBoxWithIconalso.TabIndex = 2;
            this.btnMsgBoxWithIconalso.Text = "Add Btn Cancel to MsgBox and icon";
            this.btnMsgBoxWithIconalso.UseVisualStyleBackColor = true;
            this.btnMsgBoxWithIconalso.Click += new System.EventHandler(this.btnMsgBoxWithIconalso_Click);
            // 
            // FormMsgBox
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnMsgBoxWithIconalso);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.btnShowMsgWithTitle);
            this.Controls.Add(this.btnShowMsgBox);
            this.Name = "FormMsgBox";
            this.Text = "Form Test MsgBox Control";
            this.Load += new System.EventHandler(this.FormMsgBox_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnShowMsgBox;
        private System.Windows.Forms.Button btnShowMsgWithTitle;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button btnMsgBoxWithIconalso;
    }
}