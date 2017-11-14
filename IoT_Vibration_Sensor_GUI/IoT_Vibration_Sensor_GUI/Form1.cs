using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *  Programmer:  Team Hephaestus                                             *
 *  Team:        - Chris Johnson (Communications Liaison)                    *
 *               - Ryan Epperson                                             *
 *               - Aron Galvan                                               *
 *               - Jerome Santos                                             *
 *  Date:        10/19/2017                                                  *
 *  Course:      EE415--Design Project Management                            *
 *  Term:        Fall 2017                                                   *
 *  Project:     Vibration IoT Sensor Monitor Software                       *
 *  Description: Software that provides various statistics based upon the    *
 *               raw data sent from the vibration sensor.                    *
  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

namespace IoT_Vibration_Sensor_GUI
{
    public partial class IoTVibrationSensorGUI : Form
    {
        public IoTVibrationSensorGUI()
        {
            InitializeComponent();
        }   // End constructor

        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
         *  Event:       exitToolStripMenuItem_Click                         *
         *  Input:       object, EventArgs                                   *
         *  Output:      void                                                *
         *  See Funcs:   N/A                                                 *
         *  Description: An event that closes the WinForms application.      *
         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit(); // Exit the program
        }   // End event

        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
         *  Event:       aboutVibrationSensorMonitorToolStripMenuItem_Click  *
         *  Input:       object, EventArgs                                   *
         *  Output:      void                                                *
         *  See Funcs:   N/A                                                 *
         *  Description: An event that pulls up the about page for the       *
         *               VSM software.                                       *
         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
        private void aboutVibrationSensorMonitorToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // Pull up about page
        }   // End event

        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
         *  Event:       graphTestButton_Click                               *
         *  Input:       object, EventArgs                                   *
         *  Output:      void                                                *
         *  See Funcs:   N/A                                                 *
         *  Description: An event that uses the random class to generate     *
         *               random data points to plot onto the graph.          *
         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
        private void graphTestButton_Click(object sender, EventArgs e)
        {
            // Clear current points on the graph
            xAxisGraphChart.Series["graphTest"].Points.Clear();

            // Clear current points in the textbox
            xPointsTextBox.Clear();

            Random rand = new Random();     // Random generator
            for (int i = 0; i < 20; i++)
            {
                double y = rand.NextDouble();   // Generate random Y-Value
                // Generate point and plot it on the graph
                xAxisGraphChart.Series["graphTest"].Points.AddXY(i, y);

                // Add generate point onto the table
                xPointsTextBox.AppendText((i + 1).ToString() + ". " +
                    "( " + i.ToString() + ", " + String.Format("{0:0.##}", y) + " )\n");
            }
        }   // End event

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }   // End event

        public static void systemLoad()
        {
            //OpenFileDialog ofd = new OpenFileDialog();
            //if (ofd.ShowDialog() == DialogResult.OK)
            //{
            //    Stream loadFileStream = new FileStream(ofd.FileName,
            //        FileMode.Open, FileAccess.Read);
            //    wsuSystem.loadFromXML(loadFileStream);
            //    loadFileStream.Dispose();   // Dispose
            //}
            Stream loadFileStream = new FileStream(@"C:\Users\Nani Quichocho\Documents\Visual Studio 2017\Projects\CPTS422_HW4\CPTS422_HW4\VibDataStream.xml",
                    FileMode.Open, FileAccess.Read);
            //wsuSystem.loadFromXML(loadFileStream);
            loadFileStream.Dispose();   // Dispose
        }   // End function
    }   // End class
}   // End namespace
