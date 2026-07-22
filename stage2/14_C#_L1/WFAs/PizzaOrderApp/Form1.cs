using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.NetworkInformation;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Net.Mime.MediaTypeNames;

namespace PizzaOrderApp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }


        private void rbSmall_CheckedChanged(object sender, EventArgs e)
        {
            if (rbSmall.Checked == true)
            {
                IbTotalPrice.Text = (int.Parse(IbTotalPrice.Text) + 5).ToString();
                lbSize.Text = rbSmall.Text;
            }
            else
            { 
                IbTotalPrice.Text = (int.Parse(IbTotalPrice.Text) - 5).ToString();
            }
        }

        private void rbMedium_CheckedChanged(object sender, EventArgs e)
        {
            if (rbMedium.Checked == true)
            {
                IbTotalPrice.Text = (int.Parse(IbTotalPrice.Text) + 10).ToString();
                lbSize.Text = rbMedium.Text;
            }
            else
            {
                IbTotalPrice.Text = (int.Parse(IbTotalPrice.Text) - 10).ToString();
            }
        }


        private void rbLarge_CheckedChanged(object sender, EventArgs e)
        {
            if (rbLarge.Checked == true)
            {
                IbTotalPrice.Text = (int.Parse(IbTotalPrice.Text) + 15).ToString();
                lbSize.Text = rbLarge.Text;
            }
            else
            {
                IbTotalPrice.Text = (int.Parse(IbTotalPrice.Text) - 15).ToString();
            }
        }

        private void chkExtraChees_CheckedChanged(object sender, EventArgs e)
        {
            if(chkExtraChees.Checked == true)
            {
                IbTotalPrice.Text = (int.Parse(IbTotalPrice.Text) + 5).ToString();
                lbToppings.Text = lbToppings.Text + ", " + chkExtraChees.Text;
            }
            else
            {
                IbTotalPrice.Text = (int.Parse(IbTotalPrice.Text) - 5).ToString();
                    lbToppings.Text = lbToppings.Text.Replace(", " + chkExtraChees.Text, "");
            }
        }

        private void chkMushrooms_CheckedChanged(object sender, EventArgs e)
        {
            if (chkMushrooms.Checked == true)
            {
                IbTotalPrice.Text = (int.Parse(IbTotalPrice.Text) + 5).ToString();
                lbToppings.Text = lbToppings.Text + ", " + chkMushrooms.Text;
            }
            else
            {
                IbTotalPrice.Text = (int.Parse(IbTotalPrice.Text) - 5).ToString();
                lbToppings.Text = lbToppings.Text.Replace(", " + chkMushrooms.Text, "");
            }
        }

        private void chkTomatoes_CheckedChanged(object sender, EventArgs e)
        {

            if (chkTomatoes.Checked == true)
            {
                IbTotalPrice.Text = (int.Parse(IbTotalPrice.Text) + 5).ToString();
                lbToppings.Text = lbToppings.Text + ", " + chkTomatoes.Text;
            }
            else
            {
                IbTotalPrice.Text = (int.Parse(IbTotalPrice.Text) - 5).ToString();
                lbToppings.Text = lbToppings.Text.Replace(", " + chkTomatoes.Text, "");
            }
        }

        private void chkOnion_CheckedChanged(object sender, EventArgs e)
        {
            if (chkOnion.Checked == true)
            {
                IbTotalPrice.Text = (int.Parse(IbTotalPrice.Text) + 5).ToString();
                lbToppings.Text = lbToppings.Text + ", " + chkOnion.Text;
            }
            else
            {
                IbTotalPrice.Text = (int.Parse(IbTotalPrice.Text) - 5).ToString();
                lbToppings.Text = lbToppings.Text.Replace(", " + chkOnion.Text, "");
            }
        }

        private void chkOlives_CheckedChanged(object sender, EventArgs e)
        {
            if (chkOlives.Checked == true)
            {
                IbTotalPrice.Text = (int.Parse(IbTotalPrice.Text) + 5).ToString();
                lbToppings.Text = lbToppings.Text + ", " + chkOlives.Text;
            }
            else
            {
                IbTotalPrice.Text = (int.Parse(IbTotalPrice.Text) - 5).ToString();
                lbToppings.Text = lbToppings.Text.Replace(", " + chkOlives.Text, "");
            }
        }

        private void chkGreenPeppers_CheckedChanged(object sender, EventArgs e)
        {
            if (chkGreenPeppers.Checked == true)
            {
                IbTotalPrice.Text = (int.Parse(IbTotalPrice.Text) + 5).ToString();
                lbToppings.Text = lbToppings.Text + ", " + chkGreenPeppers.Text;
            }
            else
            {
                IbTotalPrice.Text = (int.Parse(IbTotalPrice.Text) - 5).ToString();
                lbToppings.Text = lbToppings.Text.Replace(", " + chkGreenPeppers.Text, "");
            }
        }

        private void rbThin_CheckedChanged(object sender, EventArgs e)
        {
            if (rbThin.Checked == true)
            {
                IbCrustType.Text = rbThin.Text;
            }
            else
            {
                IbCrustType.Text = rbThick.Text;
            }
        }

        private void rbEatIn_CheckedChanged(object sender, EventArgs e)
        {
            if (rbEatIn.Checked == true)
            {
                lbWhereToEat.Text = rbEatIn.Text;
            }
            else
            {
                lbWhereToEat.Text = rbTakeOut.Text;
            }
        }

        private void btnOrderPizza_Click(object sender, EventArgs e)
        {
            gbCrustType.Enabled  = false;
            gbPizzaSzie.Enabled  = false;
            gbToppings.Enabled   = false;
            gbWhereToEat.Enabled = false;

            MessageBox.Show("Are you sure to confirm order? ",
               "Confirm ", MessageBoxButtons.OKCancel,
               MessageBoxIcon.Question,
               MessageBoxDefaultButton.Button1);
        }
        private void Reset_Click(object sender, EventArgs e)
        {
            gbCrustType.Enabled  = true;
            gbPizzaSzie.Enabled  = true;
            gbToppings.Enabled   = true;
            gbWhereToEat.Enabled = true;  
        }

    }
}
