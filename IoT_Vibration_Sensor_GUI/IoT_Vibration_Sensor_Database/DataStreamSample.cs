using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IoT_Vibration_Sensor_Database
{
    class DataStreamSample
    {
        private string _axis;                   // Axis the sample belongs to
        private List<DataPoint> _dataPoints;    // List of data points on specific axis

        public DataStreamSample(string axis)
        {
            _axis = axis;
            _dataPoints = new List<DataPoint>();
        }   // End constructor

        public string Axis
        {
            get { return _axis; }
        }   // End property

        public List<DataPoint> DataPoints
        {
            get { return _dataPoints; }
        }   // End property

        public void addDataPoint(int x, int y, int z)
        {
            // Create new point
            DataPoint newPoint = new DataPoint(x, y, z);

            // Add it to the datapoints list
            _dataPoints.Add(newPoint);
        }   // End function
    }   // End class
}
