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
using System.Numerics;


namespace Serial_Accelerometer
{
    public partial class Form1 : Form
    {
        SerialPort accelerometer = new SerialPort();
        byte[] temp_data = new byte[6];
        int data_frame = 6;
        int x_data;
        int y_data;
        int z_data;
        int count = 0;

        public Form1()
        {
            InitializeComponent();
            ComboComBox.Items.AddRange(SerialPort.GetPortNames());
            ButtonClose.Enabled = false;
            TimerUpdate.Enabled = false;
            ButtonClear.Enabled = false;
        }

        private void ButtonOpen_Click(object sender, EventArgs e)
        {
            if(ComboComBox.Text == "")
            {
                TextBoxPortStatus.Text = "Failed to open";
            }
            else
            {
                ButtonClose.Enabled = true;
                ButtonOpen.Enabled = false;
                TimerUpdate.Enabled = true;
                ButtonClear.Enabled = true;
                TextBoxPortStatus.Text = "Opened: " + ComboComBox.Text;
                accelerometer.BaudRate = 9600;
                accelerometer.DataBits = 8;
                accelerometer.Parity = Parity.None;
                accelerometer.StopBits = StopBits.One;
                accelerometer.PortName = ComboComBox.Text;
                accelerometer.Open();
            }
        }

        void updateplot()
        {
            for(int i =  0; i < data_frame; i++)
            {
                temp_data[i] = (byte)accelerometer.ReadByte();
            }
            x_data = (int)(short)((temp_data[1] << 8) | temp_data[0]);
            y_data = (int)(short)((temp_data[3] << 8) | temp_data[2]);
            z_data = (int)(short)((temp_data[5] << 8) | temp_data[4]);

            if (count > 100)
            {
                ChartSerialPlot.Invoke(new Action(() =>
                {
                    ChartSerialPlot.Series["X_DATA"].Points.RemoveAt(0);
                    ChartSerialPlot.Series["Y_DATA"].Points.RemoveAt(0);
                    ChartSerialPlot.Series["Z_DATA"].Points.RemoveAt(0);
                    ChartSerialPlot.Series["X_DATA"].Points.AddXY(count, x_data);
                    ChartSerialPlot.Series["Y_DATA"].Points.AddXY(count, y_data);
                    ChartSerialPlot.Series["Z_DATA"].Points.AddXY(count, z_data);
                }));

            }
            else
            {
                ChartSerialPlot.Invoke(new Action(() =>
                { 
                    ChartSerialPlot.Series["X_DATA"].Points.AddXY(count, x_data);
                    ChartSerialPlot.Series["Y_DATA"].Points.AddXY(count, y_data);
                    ChartSerialPlot.Series["Z_DATA"].Points.AddXY(count, z_data);
                }));
            }
            ChartSerialPlot.ResetAutoValues();
            count++;
        }

        private void TimerUpdate_Tick(object sender, EventArgs e)
        {
            TimerUpdate.Enabled = false;
            updateplot();
            TimerUpdate.Enabled = true;
        }

        private void ButtonClose_Click(object sender, EventArgs e)
        {
            accelerometer.Close();
            ButtonClear.Enabled = false;
            ButtonClose.Enabled = false;
            ButtonOpen.Enabled = true;
            TimerUpdate.Enabled = false;
            TextBoxPortStatus.Text = "Closed: " + ComboComBox.Text;
        }

        private void ButtonClear_Click(object sender, EventArgs e)
        {
            count = 0;
            ChartSerialPlot.Invoke(new Action(() =>
            {
                ChartSerialPlot.Series["X_DATA"].Points.Clear();
                ChartSerialPlot.Series["Y_DATA"].Points.Clear();
                ChartSerialPlot.Series["Z_DATA"].Points.Clear();
            }));

        }
    }
}
