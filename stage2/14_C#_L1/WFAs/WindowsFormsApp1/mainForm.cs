using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class mainForm : Form
    {
        public mainForm()
        {
            InitializeComponent();
        }

        private void mainForm_Load(object sender, EventArgs e)
        {

        }

        private void btnShowForm1_Click(object sender, EventArgs e)
        {
            Form frm1 = new Form1();
            frm1.Show();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form frmMsgBox1 = new FormMsgBox();
            frmMsgBox1.ShowDialog();
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            Form frm1 = new FormChkRadioGroup();
            frm1.ShowDialog();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form form1 = new FrmTextBox();
            form1.Show();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Form form1 = new FrmPractice();
            form1.Show();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Form form1 = new FrmPictureBox();
            form1.Show();
        }
    }
}
