namespace WindowsFormsApp1
{
    partial class FormChkRadioGroup
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
            this.button1 = new System.Windows.Forms.Button();
            this.chkBox1 = new System.Windows.Forms.CheckBox();
            this.rbSmall = new System.Windows.Forms.RadioButton();
            this.rbMedium = new System.Windows.Forms.RadioButton();
            this.rbLarge = new System.Windows.Forms.RadioButton();
            this.btRadio = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.rbThin = new System.Windows.Forms.RadioButton();
            this.rbThick = new System.Windows.Forms.RadioButton();
            this.gbBox2 = new System.Windows.Forms.GroupBox();
            this.groupBox1.SuspendLayout();
            this.gbBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Enabled = false;
            this.button1.Location = new System.Drawing.Point(121, 191);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(181, 73);
            this.button1.TabIndex = 0;
            this.button1.Text = "button1";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // chkBox1
            // 
            this.chkBox1.AutoSize = true;
            this.chkBox1.Location = new System.Drawing.Point(121, 94);
            this.chkBox1.Name = "chkBox1";
            this.chkBox1.Size = new System.Drawing.Size(95, 20);
            this.chkBox1.TabIndex = 1;
            this.chkBox1.Text = "checkBox1";
            this.chkBox1.UseVisualStyleBackColor = true;
            this.chkBox1.CheckedChanged += new System.EventHandler(this.chkBox1_CheckedChanged);
            // 
            // rbSmall
            // 
            this.rbSmall.AutoSize = true;
            this.rbSmall.Location = new System.Drawing.Point(446, 133);
            this.rbSmall.Name = "rbSmall";
            this.rbSmall.Size = new System.Drawing.Size(62, 20);
            this.rbSmall.TabIndex = 2;
            this.rbSmall.TabStop = true;
            this.rbSmall.Text = "Small";
            this.rbSmall.UseVisualStyleBackColor = true;
            // 
            // rbMedium
            // 
            this.rbMedium.AutoSize = true;
            this.rbMedium.Location = new System.Drawing.Point(15, 30);
            this.rbMedium.Name = "rbMedium";
            this.rbMedium.Size = new System.Drawing.Size(76, 20);
            this.rbMedium.TabIndex = 2;
            this.rbMedium.TabStop = true;
            this.rbMedium.Text = "Medium";
            this.rbMedium.UseVisualStyleBackColor = true;
            // 
            // rbLarge
            // 
            this.rbLarge.AutoSize = true;
            this.rbLarge.Location = new System.Drawing.Point(15, 65);
            this.rbLarge.Name = "rbLarge";
            this.rbLarge.Size = new System.Drawing.Size(63, 20);
            this.rbLarge.TabIndex = 2;
            this.rbLarge.TabStop = true;
            this.rbLarge.Text = "Large";
            this.rbLarge.UseVisualStyleBackColor = true;
            // 
            // btRadio
            // 
            this.btRadio.Location = new System.Drawing.Point(406, 279);
            this.btRadio.Name = "btRadio";
            this.btRadio.Size = new System.Drawing.Size(181, 73);
            this.btRadio.TabIndex = 0;
            this.btRadio.Text = "Button Radio Box";
            this.btRadio.UseVisualStyleBackColor = true;
            this.btRadio.Click += new System.EventHandler(this.btRadio_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.rbThin);
            this.groupBox1.Controls.Add(this.rbThick);
            this.groupBox1.Location = new System.Drawing.Point(577, 124);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(200, 100);
            this.groupBox1.TabIndex = 3;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Crust";
            // 
            // rbThin
            // 
            this.rbThin.AutoSize = true;
            this.rbThin.Location = new System.Drawing.Point(18, 30);
            this.rbThin.Name = "rbThin";
            this.rbThin.Size = new System.Drawing.Size(54, 20);
            this.rbThin.TabIndex = 2;
            this.rbThin.TabStop = true;
            this.rbThin.Text = "Thin";
            this.rbThin.UseVisualStyleBackColor = true;
            this.rbThin.CheckedChanged += new System.EventHandler(this.radioButton1_CheckedChanged);
            // 
            // rbThick
            // 
            this.rbThick.AutoSize = true;
            this.rbThick.Location = new System.Drawing.Point(18, 65);
            this.rbThick.Name = "rbThick";
            this.rbThick.Size = new System.Drawing.Size(61, 20);
            this.rbThick.TabIndex = 2;
            this.rbThick.TabStop = true;
            this.rbThick.Text = "Thick";
            this.rbThick.UseVisualStyleBackColor = true;
            this.rbThick.CheckedChanged += new System.EventHandler(this.radioButton1_CheckedChanged);
            // 
            // gbBox2
            // 
            this.gbBox2.Controls.Add(this.rbMedium);
            this.gbBox2.Controls.Add(this.rbLarge);
            this.gbBox2.Location = new System.Drawing.Point(356, 53);
            this.gbBox2.Name = "gbBox2";
            this.gbBox2.Size = new System.Drawing.Size(200, 100);
            this.gbBox2.TabIndex = 4;
            this.gbBox2.TabStop = false;
            this.gbBox2.Text = "Pizza Size";
            // 
            // FormChkRadioGroup
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.gbBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.rbSmall);
            this.Controls.Add(this.chkBox1);
            this.Controls.Add(this.btRadio);
            this.Controls.Add(this.button1);
            this.Name = "FormChkRadioGroup";
            this.Text = "FormChkRadioGroup";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.gbBox2.ResumeLayout(false);
            this.gbBox2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.CheckBox chkBox1;
        private System.Windows.Forms.RadioButton rbSmall;
        private System.Windows.Forms.RadioButton rbMedium;
        private System.Windows.Forms.RadioButton rbLarge;
        private System.Windows.Forms.Button btRadio;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RadioButton rbThin;
        private System.Windows.Forms.RadioButton rbThick;
        private System.Windows.Forms.GroupBox gbBox2;
    }
}