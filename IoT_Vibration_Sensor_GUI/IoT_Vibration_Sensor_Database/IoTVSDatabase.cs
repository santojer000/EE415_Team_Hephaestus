using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IoT_Vibration_Sensor_Database
{
    class IoTVSDatabase
    {
        private Dictionary<string, MachineProfile> _database;    // Dictionary to hold all stream samples

        public IoTVSDatabase()
        {
            _database = new Dictionary<string, MachineProfile>();    // Create database
        }   // End constructor

        public Dictionary<string, MachineProfile> Database
        {
            get { return _database; }
        }   // End property

        public void AddMachineProfile(string name, MachineProfile profile)
        {
            _database.Add(name, profile);   // Add new machine profile to dictionary
        }   // End function
    }   // End class
}
