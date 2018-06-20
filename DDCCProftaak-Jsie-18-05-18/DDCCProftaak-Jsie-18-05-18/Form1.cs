using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

//SerialPorts
using System.Diagnostics;
using System.IO.Ports;

namespace DDCCProftaak_Jsie_18_05_18
{
    public partial class Form1 : Form
    {

        string[] portsJsie;
        SerialPort portJsie;
        bool isConnected;
        byte CommandNumberJsie = 0;
        bool A1 = true;
        bool A2 = true;
        bool A3 = true;
        bool B1 = true;
        bool B2 = true;
        bool B3 = true;
        bool C1 = true;
        bool C2 = true;
        bool C3 = true;

        public Form1()
        {
            InitializeComponent();
            getAvailableComPorts();

            foreach (string portJsie in portsJsie)
            {
                cmbComPortsJsie.Items.Add(portJsie);
                Console.WriteLine(portJsie);
                if (portsJsie[0] != null)
                {
                    cmbComPortsJsie.SelectedItem = portsJsie[0];
                }
            }
        }

        private void btnZeroPosJsie_Click(object sender, EventArgs e)
        {
            CommandNumberJsie = 4;
            if (!isConnected)
            {
                connectToArduino();
                CommandNumberJsie = 0;
            }
            else
            {
                CommandNumberJsie = 0;
            }

        }

        private void Form1_Load(object sender, EventArgs e)
        {
           
            if (A1 == true)
            {
                lblA1Jsie.Text = "In Stock";
                lblDelA1Jsie.Text = "Unavailable";
                btnDelA1Jsie.Enabled = true;
            }
            else if (A1 == false)
            {
                lblA1Jsie.Text = "Out of Stock";
                lblDelA1Jsie.Text = "Available";
                btnDelA1Jsie.Enabled = false;
            }
            if (A2 == true)
            {
                lblA2Jsie.Text = "In Stock";
                lblDelA2Jsie.Text = "Unavailable";
                btnDelA2Jsie.Enabled = true;
            }
            else if (A2 == false)
            {
                lblA2Jsie.Text = "Out of Stock";
                lblDelA2Jsie.Text = "Available";
                btnDelA2Jsie.Enabled = false;
            }
            if (A3 == true)
            {
                lblA3Jsie.Text = "In Stock";
                lblDelA3Jsie.Text = "Unavailable";
            }
            else if (A3 == false)
            {
                lblA3Jsie.Text = "Out of Stock";
                lblDelA3Jsie.Text = "Available";
            }
            if (B1 == true)
            {
                lblB1Jsie.Text = "In Stock";
                lblDelB1Jsie.Text = "Unavailable";
            }
            else if (B1 == false)
            {
                lblB1Jsie.Text = "Out of Stock";
                lblDelB1Jsie.Text = "Available";
            }
            if (B2 == true)
            {
                lblB2Jsie.Text = "In Stock";
                lblDelB2Jsie.Text = "Unavailable";
            }
            else if (B2 == false)
            {
                lblB2Jsie.Text = "Out of Stock";
                lblDelB2Jsie.Text = "Available";
            }
            if (B3 == true)
            {
                lblB3Jsie.Text = "In Stock";
                lblDelB3Jsie.Text = "Unavailable";
            }
            else if (B3 == false)
            {
                lblB3Jsie.Text = "Out of Stock";
                lblDelB3Jsie.Text = "Available";
            }
            if (C1 == true)
            {
                lblC1Jsie.Text = "In Stock";
                lblDelC1Jsie.Text = "Unavailable";
            }
            else if (C1 == false)
            {
                lblC1Jsie.Text = "Out of Stock";
                lblDelC1Jsie.Text = "available";
            }
            if (C2 == true)
            {
                lblC2Jsie.Text = "In Stock";
                lblDelC2Jsie.Text = "Unavailable";
            }
            else if (C2 == false)
            {
                lblC2Jsie.Text = "Out of Stock";
                lblDelC2Jsie.Text = "Available";
            }
            if (C3 == true)
            {
                lblC3Jsie.Text = "In Stock";
                lblDelC3Jsie.Text = "Unavailable";
            }
            else if (C3 == false)
            {
                lblC3Jsie.Text = "Out of Stock";
                lblDelC3Jsie.Text = "Available";
            }
        }

        private void getAvailableComPorts()
        {
            portsJsie = SerialPort.GetPortNames();
            
        }

        private void connectToArduino()
        {
                isConnected = true;
                string selectedPort = cmbComPortsJsie.GetItemText(cmbComPortsJsie.SelectedItem);
                portJsie = new SerialPort(selectedPort, 250000, Parity.None, 8, StopBits.One);
                portJsie.Encoding = Encoding.ASCII;
                portJsie.Open();
                portJsie.BaseStream.WriteByte(CommandNumberJsie);
                portJsie.BaseStream.Flush();
                System.Threading.Thread.Sleep(100);
                portJsie.Close();

        }

        private void btnA1Jsie_Click(object sender, EventArgs e)
        {
            if (A1 == true)
            {

                CommandNumberJsie = 13;
                if (!isConnected)
                {
                    connectToArduino();
                    CommandNumberJsie = 0;
                }
                else
                {
                    CommandNumberJsie = 0;
                }
            }
            else if (A1 == false)
            {
                MessageBox.Show("Product Not in stock");
            }
        }

        private void btnA2Jsie_Click(object sender, EventArgs e)
        {
            if (A2 == true)
            {
                CommandNumberJsie = 23;
                if (!isConnected)
                {
                    connectToArduino();
                    CommandNumberJsie = 0;
                }
                else
                {
                    CommandNumberJsie = 0;
                }
            }
            else if (A2 == false)
            {
                MessageBox.Show("Product Not in stock");
            }
        }

        private void btnA3Jsie_Click(object sender, EventArgs e)
        {
            if (A3 == true)
            {
                CommandNumberJsie = 33;
                if (!isConnected)
                {
                    connectToArduino();
                    CommandNumberJsie = 0;
                }
                else
                {
                    CommandNumberJsie = 0;
                }
            }
            else if (A3 == false)
            {
                MessageBox.Show("Product Not in stock");
            }
        }

        private void btnB1Jsie_Click(object sender, EventArgs e)
        {
            if (B1 == true)
            {
                CommandNumberJsie = 12;
                if (!isConnected)
                {
                    connectToArduino();
                    CommandNumberJsie = 0;
                }
                else
                {
                    CommandNumberJsie = 0;
                }
            }
            else if (B1 == false)
            {
                MessageBox.Show("Product Not in stock");
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (B2 == true)
            {
                CommandNumberJsie = 21;
                if (!isConnected)
                {
                    connectToArduino();
                    CommandNumberJsie = 0;
                }
                else
                {
                    CommandNumberJsie = 0;
                }
            }
            else if (B2 == false)
            {
                MessageBox.Show("Product Not in stock");
            }
        }

        private void btnB3Jsie_Click(object sender, EventArgs e)
        {
            if (B3 == true)
            {
                CommandNumberJsie = 32;
                if (!isConnected)
                {
                    connectToArduino();
                    CommandNumberJsie = 0;
                }
                else
                {
                    CommandNumberJsie = 0;
                }
            }
            else if (B3 == false)
            {
                MessageBox.Show("Product Not in stock");
            }
        }

        private void btnC1Jsie_Click(object sender, EventArgs e)
        {
            if (C1 == true)
            {
                CommandNumberJsie = 11;
                if (!isConnected)
                {
                    connectToArduino();
                    CommandNumberJsie = 0;
                }
                else
                {
                    CommandNumberJsie = 0;
                }
            }
            else if (C1 == false)
            {
                MessageBox.Show("Product Not in stock");
            }
        }

        private void btnC2Jsie_Click(object sender, EventArgs e)
        {
            if (C2 == true)
            {
                CommandNumberJsie = 21;
                if (!isConnected)
                {
                    connectToArduino();
                    CommandNumberJsie = 0;
                }
                else
                {
                    CommandNumberJsie = 0;
                }
            }
            else if (C3 == false)
            {
                MessageBox.Show("Product Not in stock");
            }
        }

        private void btnC3Jsie_Click(object sender, EventArgs e)
        {
            if (C3 == true)
            {
                CommandNumberJsie = 31;
                if (!isConnected)
                {
                    connectToArduino();
                    CommandNumberJsie = 0;
                }
                else
                {
                    CommandNumberJsie = 0;
                }
            }
            else if (C3 == false)
            {
                MessageBox.Show("Product Not in stock");
            }
        }

        private void lblDeveloperJsie_Click(object sender, EventArgs e)
        {
            tcbJsie.SelectedTab = tbpDeveloperJsie;
        }

        private void btnDeliver2Jsie_Click(object sender, EventArgs e)
        {
            CommandNumberJsie = 10;
            if (!isConnected)
            {
                connectToArduino();
                CommandNumberJsie = 0;
            }
            else
            {
                CommandNumberJsie = 0;
            }
        }

        private void btnRetrieveJsie_Click(object sender, EventArgs e)
        {
            tcbJsie.SelectedTab = tabRetrieveJsie;
        }

        private void btnDeliverJsie_Click(object sender, EventArgs e)
        {
            tcbJsie.SelectedTab = tabDeliverJsie;
        }

        private void btnDelA1Jsie_Click(object sender, EventArgs e)
        {
            CommandNumberJsie = 41;
            if (!isConnected)
            {
                connectToArduino();
                CommandNumberJsie = 0;
            }
            else
            {
                CommandNumberJsie = 0;
            }
        }

        private void btnDelA2Jsie_Click(object sender, EventArgs e)
        {
            CommandNumberJsie = 42;
            if (!isConnected)
            {
                connectToArduino();
                CommandNumberJsie = 0;
            }
            else
            {
                CommandNumberJsie = 0;
            }
        }

        private void btnDelA3Jsie_Click(object sender, EventArgs e)
        {
            CommandNumberJsie = 43;
            if (!isConnected)
            {
                connectToArduino();
                CommandNumberJsie = 0;
            }
            else
            {
                CommandNumberJsie = 0;
            }
        }

        private void btnDelB3Jsie_Click(object sender, EventArgs e)
        {
            CommandNumberJsie = 51;
            if (!isConnected)
            {
                connectToArduino();
                CommandNumberJsie = 0;
            }
            else
            {
                CommandNumberJsie = 0;
            }
        }

        private void btnDelB2Jsie_Click(object sender, EventArgs e)
        {
            CommandNumberJsie = 52;
            if (!isConnected)
            {
                connectToArduino();
                CommandNumberJsie = 0;
            }
            else
            {
                CommandNumberJsie = 0;
            }
        }

        private void btnDeliB3Jsie_Click(object sender, EventArgs e)
        {
            CommandNumberJsie = 53;
            if (!isConnected)
            {
                connectToArduino();
                CommandNumberJsie = 0;
            }
            else
            {
                CommandNumberJsie = 0;
            }
        }

        private void btnDelC1Jsie_Click(object sender, EventArgs e)
        {
            CommandNumberJsie = 61;
            if (!isConnected)
            {
                connectToArduino();
                CommandNumberJsie = 0;
            }
            else
            {
                CommandNumberJsie = 0;
            }
        }

        private void btnDelC2Jsie_Click(object sender, EventArgs e)
        {
            CommandNumberJsie = 62;
            if (!isConnected)
            {
                connectToArduino();
                CommandNumberJsie = 0;
            }
            else
            {
                CommandNumberJsie = 0;
            }
        }

        private void btnDelC3Jsie_Click(object sender, EventArgs e)
        {
            CommandNumberJsie = 63;
            if (!isConnected)
            {
                connectToArduino();
                CommandNumberJsie = 0;
            }
            else
            {
                CommandNumberJsie = 0;
            }
        }

        private void btnDelMainMenuJsie_Click(object sender, EventArgs e)
        {
            tcbJsie.SelectedTab = tabMainMenuJsie;
        }
    }
}
