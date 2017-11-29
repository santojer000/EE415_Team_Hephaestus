using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Serial_Accelerometer
{
    public partial class SerialAccelSplashScreen : Form
    {
        public SerialAccelSplashScreen()
        {
            InitializeComponent();
        }   // End constructor

        private void SerialAccelSplashScreen_Load(object sender, EventArgs e)
        {
            ThreadStart splashScreen = new ThreadStart(splashScreenThread);
            Thread splashThread = new Thread(splashScreen);
            splashThread.Start();
        }   // End event

        private void splashScreenThread()
        {
            // Make the progress bar visible
            splashScreenProgressBar.Invoke(new Action(() =>
                splashScreenProgressBar.Visible = true));
            // Set the minimum value
            splashScreenProgressBar.Invoke(new Action(() =>
                splashScreenProgressBar.Minimum = 0));
            // Set the maximum value
            splashScreenProgressBar.Invoke(new Action(() =>
                splashScreenProgressBar.Maximum = 5000));
            // Set the initial value
            splashScreenProgressBar.Invoke(new Action(() =>
                splashScreenProgressBar.Value = 0));
            // Set the step value
            splashScreenProgressBar.Invoke(new Action(() =>
                splashScreenProgressBar.Step = 2));
            for (int i = 0; i < splashScreenProgressBar.Maximum; i++)
            {
                splashScreenProgressBar.Invoke(new Action(() =>
                splashScreenProgressBar.PerformStep()));
            }
            this.Invoke(new Action(() => this.Dispose()));
        }
    }   // End class
}   // End program
