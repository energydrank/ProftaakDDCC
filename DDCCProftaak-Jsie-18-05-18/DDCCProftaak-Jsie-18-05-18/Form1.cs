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
        byte WhitePosition = 0;
        byte bluePosition = 0;
        byte redPosition = 0;
        byte emptyBox1 = 0;
        byte emptyBox2 = 0;
        byte emptyBox3 = 0;
        byte emptyBox4 = 0;
        byte emptyBox5 = 0;
        byte emptyBox6 = 0;

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

        private void btnA2Jsie_Click(object sender, EventArgs e)
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

        private void btnA3Jsie_Click(object sender, EventArgs e)
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

        private void btnB1Jsie_Click(object sender, EventArgs e)
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

        private void button1_Click(object sender, EventArgs e)
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

        private void btnB3Jsie_Click(object sender, EventArgs e)
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

        private void btnC1Jsie_Click(object sender, EventArgs e)
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

        private void btnC2Jsie_Click(object sender, EventArgs e)
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

        private void btnC3Jsie_Click(object sender, EventArgs e)
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
    }
}
