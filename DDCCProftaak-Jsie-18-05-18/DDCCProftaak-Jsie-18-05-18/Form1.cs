﻿using System;
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
            if (!isConnected)
            {
                connectToArduino();
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
           // portJsie = new SerialPort(selectedPort, 9600, Parity.None, 8, StopBits.One);
            portJsie = new SerialPort("COM3");
            portJsie.Encoding = Encoding.ASCII;
            portJsie.Open();
            portJsie.BaseStream.WriteByte(4);
            portJsie.BaseStream.Flush();
            System.Threading.Thread.Sleep(100);
            string ab = "";
            while(1==1){
                System.Diagnostics.Debug.Write(ab);
                ab = portJsie.ReadExisting();
            }
            portJsie.Close();
        }
    }
}
