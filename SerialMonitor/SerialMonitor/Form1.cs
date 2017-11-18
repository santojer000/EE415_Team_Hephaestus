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

namespace SerialMonitor
{
    public partial class Form1 : Form
    {
        SerialPort myport = new SerialPort();
        public Form1()
        {
            InitializeComponent();
            getavaliableports();
            CloseButton.Enabled = false;
            ClearPlotButton.Enabled = false;
            SerialPlot.Anchor = AnchorStyles.Bottom;
            SerialPlot.ChartAreas[0].AxisX.ScaleView.Zoomable = true;
        }
        private void getavaliableports()
        {
            PortComboBox.Items.AddRange(SerialPort.GetPortNames());
        }
        private void OpenButton_Click(object sender, EventArgs e)
        {
          
                myport.BaudRate = Convert.ToInt32(BaudRateComboBox.Text);
                myport.PortName = PortComboBox.Text;
                myport.DataBits = Convert.ToInt32(FrameSizeComboBox.Text);
                myport.Parity = Parity.None;
                myport.StopBits = StopBits.One;
                myport.Open();

                CloseButton.Enabled = true;
                OpenButton.Enabled = false;
                ClearPlotButton.Enabled = true;
                timer1.Enabled = true;
           
        }

        private void updateplot()
        {
            byte[] temp_data = new byte[4];
            int[] x_data_set = new int[1024];
            float[] x_data_set_float = new float[1024];

            SerialPlot.Invoke(new Action(() =>
            {
                foreach (var series in SerialPlot.Series)
                {
                    series.Points.Clear();
                }

            }));

            for (int i = 0; i < 1024; i++)
            {
               for(int j = 0; j < 4; j++)
                {
                    temp_data[j] = (byte)myport.ReadByte();
                }
                x_data_set_float[i] = (float)(int)((temp_data[0] << 24) | (temp_data[1] << 16) | (temp_data[2] << 8) | (temp_data[3]));
                x_data_set_float[i] = x_data_set_float[i] / 100000;
            }
            float x = -1000;
            float inc = 2000 / 1024;
            for(int k = 0 ; k < 1024; k++)
            {

                SerialPlot.Invoke(new Action(() =>
                {
                    SerialPlot.Series["X_Data"].Points.AddXY(x, x_data_set_float[k]);

                }));
                x = x + (inc);
            }
            x = -1000;

        }
        private void CloseButton_Click(object sender, EventArgs e)
        {
            myport.Close();
            BaudRateComboBox.ResetText();
            FrameSizeComboBox.ResetText();
            PortComboBox.ResetText();
            OpenButton.Enabled = true;
            CloseButton.Enabled = false;
            ClearPlotButton.Enabled = false;
            timer1.Enabled = false;
        }

        private void ClearPlotButton_Click(object sender, EventArgs e)
        {
            ClearPlot();
        }
        private void ClearPlot()
        {
            SerialPlot.Invoke(new Action(() =>
            {
                foreach (var series in SerialPlot.Series)
                {
                    series.Points.Clear();
                }

            }));
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            timer1.Enabled = false;
            updateplot();
            timer1.Enabled = true;
        }
    }
}
