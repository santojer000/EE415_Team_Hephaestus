using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IoT_Vibration_Sensor_Database
{
    class MachineProfile
    {
        private string _name;                   // Name of the machine profile
        private List<DataStreamSample> _xAxis;  // List of all X-Axis streams
        private List<DataStreamSample> _yAxis;  // List of all Y-Axis streams      
        private List<DataStreamSample> _zAxis;  // List of all Z-Axis streams

        public MachineProfile(string name)
        {
            _name = name;
            _xAxis = new List<DataStreamSample>();  // Create x-axis list
            _yAxis = new List<DataStreamSample>();  // Create y-axis list
            _zAxis = new List<DataStreamSample>();  // Create z-axis list
        }   // End constructor

        public List<DataStreamSample> XDataStreams
        {
            get { return _xAxis; }
        }   // End property

        public List<DataStreamSample> YDataStreams
        {
            get { return _yAxis; }
        }   // End property

        public List<DataStreamSample> ZDataStreams
        {
            get { return _zAxis; }
        }   // End property

        public void AddXDataStream(DataStreamSample sample)
        {
            _xAxis.Add(sample); // Add data stream sample to list
        }   // End function

        public void AddYDataStream(DataStreamSample sample)
        {
            _yAxis.Add(sample); // Add data stream sample to list
        }   // End function

        public void AddZDataStream(DataStreamSample sample)
        {
            _zAxis.Add(sample); // Add data stream sample to list
        }   // End function
    }   // End class
}
