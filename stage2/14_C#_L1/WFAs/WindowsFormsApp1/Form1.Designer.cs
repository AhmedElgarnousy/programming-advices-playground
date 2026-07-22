namespace WindowsFormsApp1
{
    partial class Form1
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
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.btnCloseForm1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(25, 115);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(199, 22);
            this.textBox1.TabIndex = 0;
            this.textBox1.Text = "dq";
            this.textBox1.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // textBox2
            // 
            this.textBox2.Enabled = false;
            this.textBox2.Location = new System.Drawing.Point(585, 115);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(199, 22);
            this.textBox2.TabIndex = 0;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(585, 270);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(199, 59);
            this.button1.TabIndex = 5;
            this.button1.Text = "Copy";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(25, 270);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(199, 59);
            this.button2.TabIndex = 1;
            this.button2.Text = "Copy By Hover";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.MouseHover += new System.EventHandler(this.MouseHover);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(305, 270);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(199, 59);
            this.button3.TabIndex = 3;
            this.button3.Text = "Disable Text1";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click_1);
            this.button3.MouseHover += new System.EventHandler(this.MouseHover);
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(305, 361);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(199, 59);
            this.button4.TabIndex = 4;
            this.button4.Text = "Enable Text1";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click_1);
            this.button4.MouseHover += new System.EventHandler(this.MouseHover);
            // 
            // button5
            // 
            this.button5.Location = new System.Drawing.Point(25, 361);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(199, 59);
            this.button5.TabIndex = 2;
            this.button5.Text = "Copy By Hover";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.button5_Click);
            this.button5.MouseHover += new System.EventHandler(this.MouseHover);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.label1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.label1.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.label1.Font = new System.Drawing.Font("Mistral", 19.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.label1.Location = new System.Drawing.Point(237, 30);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(308, 43);
            this.label1.TabIndex = 3;
            this.label1.Text = "This is a practice project";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // btnCloseForm1
            // 
            this.btnCloseForm1.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Yellow;
            this.btnCloseForm1.FlatAppearance.MouseOverBackColor = System.Drawing.SystemColors.Desktop;
            this.btnCloseForm1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnCloseForm1.ForeColor = System.Drawing.SystemColors.ActiveCaption;
            this.btnCloseForm1.Location = new System.Drawing.Point(585, 361);
            this.btnCloseForm1.Name = "btnCloseForm1";
            this.btnCloseForm1.Size = new System.Drawing.Size(199, 59);
            this.btnCloseForm1.TabIndex = 6;
            this.btnCloseForm1.Text = "close";
            this.btnCloseForm1.UseVisualStyleBackColor = true;
            this.btnCloseForm1.Click += new System.EventHandler(this.button6_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(852, 495);
            this.Controls.Add(this.btnCloseForm1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button5);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.textBox1);
            this.Name = "Form1";
            this.Text = "WF APP1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnCloseForm1;
    }
}

