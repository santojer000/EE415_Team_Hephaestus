using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace IoT_Vibration_Sensor_Logic
{
    class XMLWriter
    {
        public void loadFromXML(Stream loadFile)
        {
            XDocument xmlDoc = XDocument.Load(loadFile);

            // Load all users into the system
            foreach (XElement tag in xmlDoc.Root.Elements("roster").Elements("user"))
            {
                string name = tag.Element("name").Value;
                string uid = tag.Element("userid").Value;
                string pw = tag.Element("password").Value;
                bool isman = Convert.ToBoolean(tag.Element("ismanager").Value);

                if (isman)
                    _roster.Add(uid, new Manager(name, uid, pw));
                else
                    _roster.Add(uid, new Customer(name, uid, pw));
            }
        }   // End function
    }   // End class
}
