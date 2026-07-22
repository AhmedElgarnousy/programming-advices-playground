namespace WindowsFormsApp1
{
    partial class mainForm
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
            this.btnShowForm1 = new System.Windows.Forms.Button();
            this.btnShowFrmDialog = new System.Windows.Forms.Button();
            this.bntShowFrmMsgBox = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnShowForm1
            // 
            this.btnShowForm1.Location = new System.Drawing.Point(14, 28);
            this.btnShowForm1.Name = "btnShowForm1";
            this.btnShowForm1.Size = new System.Drawing.Size(248, 116);
            this.btnShowForm1.TabIndex = 0;
            this.btnShowForm1.Text = "Show Form1";
            this.btnShowForm1.UseVisualStyleBackColor = true;
            this.btnShowForm1.Click += new System.EventHandler(this.btnShowForm1_Click);
            // 
            // btnShowFrmDialog
            // 
            this.btnShowFrmDialog.Location = new System.Drawing.Point(12, 190);
            this.btnShowFrmDialog.Name = "btnShowFrmDialog";
            this.btnShowFrmDialog.Size = new System.Drawing.Size(248, 116);
            this.btnShowFrmDialog.TabIndex = 1;
            this.btnShowFrmDialog.Text = "Show Form1 as dialog";
            this.btnShowFrmDialog.UseVisualStyleBackColor = true;
            this.btnShowFrmDialog.Click += new System.EventHandler(this.button1_Click);
            // 
            // bntShowFrmMsgBox
            // 
            this.bntShowFrmMsgBox.Location = new System.Drawing.Point(356, 28);
            this.bntShowFrmMsgBox.Name = "bntShowFrmMsgBox";
            this.bntShowFrmMsgBox.Size = new System.Drawing.Size(248, 116);
            this.bntShowFrmMsgBox.TabIndex = 1;
            this.bntShowFrmMsgBox.Text = "Show Form MsgBox";
            this.bntShowFrmMsgBox.UseVisualStyleBackColor = true;
            this.bntShowFrmMsgBox.Click += new System.EventHandler(this.button1_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(356, 190);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(248, 116);
            this.button1.TabIndex = 1;
            this.button1.Text = "Show Form chkRadioGroupBox";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click_1);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(14, 339);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(248, 116);
            this.button2.TabIndex = 1;
            this.button2.Text = "More About TextBox";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(356, 339);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(248, 116);
            this.button3.TabIndex = 1;
            this.button3.Text = "Test TextBox practice ";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(632, 28);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(248, 116);
            this.button4.TabIndex = 1;
            this.button4.Text = "Test PictureBox";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // mainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(883, 493);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.bntShowFrmMsgBox);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.btnShowFrmDialog);
            this.Controls.Add(this.btnShowForm1);
            this.Name = "mainForm";
            this.Text = "MainForm";
            this.Load += new System.EventHandler(this.mainForm_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnShowForm1;
        private System.Windows.Forms.Button btnShowFrmDialog;
        private System.Windows.Forms.Button bntShowFrmMsgBox;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
    }
}