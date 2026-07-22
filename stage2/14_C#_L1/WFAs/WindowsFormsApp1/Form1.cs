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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }


        private void button1_Click(object sender, EventArgs e)
        {
            textBox2.Text = textBox1.Text;
            //textBox1.Text = "HELLO 1";
            //textBox2.Text = "HELLO 2";

        }



        private void MouseHover(object sender, EventArgs e)
        {
            textBox2.Text = textBox1.Text;
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            textBox2.Text = textBox1.Text;
            label1.Text = textBox1.Text;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            textBox1.Enabled = false;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            textBox1.Enabled = true;

        }

        private void button3_Click_1(object sender, EventArgs e)
        {
            textBox1.Enabled = false;

        }

        private void button4_Click_1(object sender, EventArgs e)
        {
            textBox1.Enabled = true;

        }

        private void button5_Click(object sender, EventArgs e)
        {
            button5.Text = "Control colors";
            this.BackColor = Color.Beige;
            textBox1.BackColor = Color.Magenta;
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button6_Click(object sender, EventArgs e)
        {
            //this.BackColor = Color.Transparent;
            this.Close();
        }
    }
}
