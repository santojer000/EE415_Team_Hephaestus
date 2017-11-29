using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Serial_Accelerometer
{
    public partial class AboutSerialAccel : Form
    {
        public AboutSerialAccel()
        {
            InitializeComponent();
        }   // End constructor

        private void AboutSerialAccel_Load(object sender, EventArgs e)
        {
            // Make the default button the close button
            this.AcceptButton = closeButton;
        }   // End event

        private void closeButton_Click(object sender, EventArgs e)
        {
            this.Dispose(); // Dispose of the form after you hit close
        }   // End event
    }   // End class
}   // End program
