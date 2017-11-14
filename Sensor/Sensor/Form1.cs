using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace Sensor
{
    public partial class Form1 : Form
    {
        private SerialPort myport = new SerialPort();
        public Form1()
        {
            InitializeComponent();
            string[] ports = SerialPort.GetPortNames();
            comboBox1.Items.AddRange(ports);
            button1.Enabled = true;
            button2.Enabled = false;
            button3.Enabled = false;

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(comboBox1.Text == "" | comboBox1.Text == "" | comboBox1.Text == "")
            {
                textBox1.Text = "Error please select configuration for com port.";
            }
            else
            {
                myport.PortName = comboBox1.Text;
                myport.DataBits = Convert.ToInt32(comboBox2.Text);
                myport.BaudRate = Convert.ToInt32(comboBox3.Text);
                myport.StopBits = StopBits.One;
                myport.Parity = Parity.None;
                myport.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);
                myport.Open();
                button1.Enabled = false;
                button2.Enabled = true;
                button3.Enabled = true;
            }
            
        }
        delegate void SetTextCallback(string text);

        private void SetText(string text)
        {
            // InvokeRequired required compares the thread ID of the
            // calling thread to the thread ID of the creating thread.
            // If these threads are different, it returns true.
            if (this.textBox1.InvokeRequired)
            {
                SetTextCallback d = new SetTextCallback(SetText);
                this.Invoke(d, new object[] { text });
            }
            else
            {
                this.textBox1.AppendText(text);
            }
        }

        private void DataReceivedHandler(object sender, EventArgs e)
        {
            int data = myport.ReadByte();
            SetText(Convert.ToString(Convert.ToChar(data)));
        }

        private void button2_Click(object sender, EventArgs e)
        {
            myport.Close();
            button1.Enabled = true;
            button2.Enabled = false;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            textBox1.Clear();
        }
    }
}
