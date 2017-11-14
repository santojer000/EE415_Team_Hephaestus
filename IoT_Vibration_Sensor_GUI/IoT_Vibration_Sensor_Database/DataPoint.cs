using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IoT_Vibration_Sensor_Database
{
    class DataPoint
    {
        private double _x;      // Value of the x coordinate
        private double _y;      // Value of the y coordinate
        private double _z;      // Value of the z coordinate

        public DataPoint(double x, double y, double z)
        {
            _x = x;
            _y = y;
            _z = z;
        }   // End constructor

        public double X
        {
            get { return _x; }
        }   // End property

        public double Y
        {
            get { return _y; }
        }   // End property

        public double Z
        {
            get { return _z; }
        }   // End property
    }   // End class
}
