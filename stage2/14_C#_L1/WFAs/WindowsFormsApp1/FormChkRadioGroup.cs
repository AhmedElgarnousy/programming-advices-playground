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
    public partial class FormChkRadioGroup : Form
    {
        public FormChkRadioGroup()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
           MessageBox.Show( chkBox1.Checked.ToString() );
        }

        private void chkBox1_CheckedChanged(object sender, EventArgs e)
        {
            button1.Enabled = chkBox1.Checked;
        }

        private void btRadio_Click(object sender, EventArgs e)
        {
            if(rbSmall.Checked)
            {
                MessageBox.Show(rbSmall.Text);
            }
            else if(rbMedium.Checked)
            {
                MessageBox.Show("Medium");
            }
            else if(rbLarge.Checked)
            {
                MessageBox.Show("Large");
            }
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }
    }
}
