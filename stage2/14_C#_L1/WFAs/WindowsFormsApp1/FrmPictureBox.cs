using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WindowsFormsApp1.Properties;

namespace WindowsFormsApp1
{
    public partial class FrmPictureBox : Form
    {
        public FrmPictureBox()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = Resources.Strong;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //pictureBox1.Image = Image.FromFile(@"E:\general_courses\programming-advices\stage2\14_C#_L1\WFAs\PizzaOrderApp\imgs\Weak.jpg");
            pictureBox1.Image = Resources.Weak;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = Image.FromFile
                (@"E:\general_courses\programming-advices\stage2\14_C#_L1\WFAs\PizzaOrderApp\imgs\programmingAdvices.jpg");

        }
    }
}
