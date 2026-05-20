#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class SmartDevice
{
protected:
    string deviceID;
    string deviceName;
    string location;
    bool isOn;
    int powerConsumption;

public:
    SmartDevice(string id, string name, string loc, int power)
    {
        deviceID = id;
        deviceName = name;
        location = loc;
        powerConsumption = power;
        isOn = false;
    }

    virtual ~SmartDevice() {}

    string getID() const
    {
        return deviceID;
    }

    string getName() const
    {
        return deviceName;
    }

    string getLocation() const
    {
        return location;
    }

    bool getStatus() const
    {
        return isOn;
    }

    int getPowerConsumption() const
    {
        return powerConsumption;
    }

    void setLocation(string loc)
    {
        location = loc;
    }

    void setPowerConsumption(int power)
    {
        powerConsumption = power;
    }

    virtual void turnOn()
    {
        isOn = true;
        cout << deviceName << " is now ON." << endl;
    }

    virtual void turnOff()
    {
        isOn = false;
        cout << deviceName << " is now OFF." << endl;
    }

    virtual void displayStatus() const = 0;
    virtual string getDeviceType() const = 0;
};

class LightingDevice : public SmartDevice
{
private:
    int brightness;
    string color;

public:
    LightingDevice(string id, string name, string loc, int power)
        : SmartDevice(id, name, loc, power)
    {
        brightness = 100;
        color = "White";
    }

    void setBrightness(int level)
    {
        if(level >= 0 && level <= 100)
        {
            brightness = level;
        }
        else
        {
            cout << "Invalid brightness level!" << endl;
        }
    }

    void setColor(string c)
    {
        color = c;
    }

    void displayStatus() const override
    {
        cout << "\n========== LIGHTING DEVICE ==========" << endl;
        cout << "Device ID: " << deviceID << endl;
        cout << "Device Name: " << deviceName << endl;
        cout << "Location: " << location << endl;
        cout << "Power Consumption: " << powerConsumption << "W" << endl;
        cout << "Status: " << (isOn ? "ON" : "OFF") << endl;
        cout << "Brightness: " << brightness << "%" << endl;
        cout << "Color: " << color << endl;
    }

    string getDeviceType() const override
    {
        return "Lighting Device";
    }
};

class ClimateDevice : public SmartDevice
{
private:
    float currentTemperature;
    float targetTemperature;
    string mode;

public:
    ClimateDevice(string id, string name, string loc, int power)
        : SmartDevice(id, name, loc, power)
    {
        currentTemperature = 22.0;
        targetTemperature = 22.0;
        mode = "Cooling";
    }

    void setTargetTemperature(float temp)
    {
        targetTemperature = temp;
    }

    void setMode(string m)
    {
        mode = m;
    }

    void displayStatus() const override
    {
        cout << "\n========== CLIMATE DEVICE ==========" << endl;
        cout << "Device ID: " << deviceID << endl;
        cout << "Device Name: " << deviceName << endl;
        cout << "Location: " << location << endl;
        cout << "Power Consumption: " << powerConsumption << "W" << endl;
        cout << "Status: " << (isOn ? "ON" : "OFF") << endl;
        cout << "Current Temperature: " << currentTemperature << " C" << endl;
        cout << "Target Temperature: " << targetTemperature << " C" << endl;
        cout << "Mode: " << mode << endl;
    }

    string getDeviceType() const override
    {
        return "Climate Device";
    }
};

int main()
{
    vector<shared_ptr<SmartDevice>> devices;

    int choice;

    do
    {
        cout << "\n===================================" << endl;
        cout << "     SMART HOME MANAGEMENT SYSTEM" << endl;
        cout << "===================================" << endl;

        cout << "1. Add Lighting Device" << endl;
        cout << "2. Add Climate Device" << endl;
        cout << "3. Display All Devices" << endl;
        cout << "4. Turn ON Device" << endl;
        cout << "5. Turn OFF Device" << endl;
        cout << "6. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        if(choice == 1)
        {
            string id, name, location;
            int power;

            cin.ignore();

            cout << "\nEnter Device ID: ";
            getline(cin, id);

            cout << "Enter Device Name: ";
            getline(cin, name);

            cout << "Enter Device Location: ";
            getline(cin, location);

            cout << "Enter Power Consumption (W): ";
            cin >> power;

            shared_ptr<LightingDevice> light =
                make_shared<LightingDevice>(id, name, location, power);

            int brightness;
            string color;

            cout << "Enter Brightness Level (0 - 100): ";
            cin >> brightness;

            cin.ignore();

            cout << "Enter Light Color: ";
            getline(cin, color);

            light->setBrightness(brightness);
            light->setColor(color);

            devices.push_back(light);

            cout << "\nLighting Device Added Successfully!" << endl;
        }

        else if(choice == 2)
        {
            string id, name, location;
            int power;

            cin.ignore();

            cout << "\nEnter Device ID: ";
            getline(cin, id);

            cout << "Enter Device Name: ";
            getline(cin, name);

            cout << "Enter Device Location: ";
            getline(cin, location);

            cout << "Enter Power Consumption (W): ";
            cin >> power;

            shared_ptr<ClimateDevice> climate =
                make_shared<ClimateDevice>(id, name, location, power);

            float temp;
            string mode;

            cout << "Enter Target Temperature: ";
            cin >> temp;

            cin.ignore();

            cout << "Enter Mode (Cooling/Heating/Fan): ";
            getline(cin, mode);

            climate->setTargetTemperature(temp);
            climate->setMode(mode);

            devices.push_back(climate);

            cout << "\nClimate Device Added Successfully!" << endl;
        }

        else if(choice == 3)
        {
            if(devices.empty())
            {
                cout << "\nNo devices available." << endl;
            }
            else
            {
                cout << "\n========== DEVICE LIST ==========" << endl;

                for(auto device : devices)
                {
                    device->displayStatus();
                }
            }
        }

        else if(choice == 4)
        {
            string id;

            cin.ignore();

            cout << "\nEnter Device ID to Turn ON: ";
            getline(cin, id);

            bool found = false;

            for(auto device : devices)
            {
                if(device->getID() == id)
                {
                    device->turnOn();
                    found = true;
                }
            }

            if(!found)
            {
                cout << "Device not found!" << endl;
            }
        }

        else if(choice == 5)
        {
            string id;

            cin.ignore();

            cout << "\nEnter Device ID to Turn OFF: ";
            getline(cin, id);

            bool found = false;

            for(auto device : devices)
            {
                if(device->getID() == id)
                {
                    device->turnOff();
                    found = true;
                }
            }

            if(!found)
            {
                cout << "Device not found!" << endl;
            }
        }

        else if(choice == 6)
        {
            cout << "\nExiting Smart Home System..." << endl;
        }

        else
        {
            cout << "\nInvalid choice! Please try again." << endl;
        }

    } while(choice != 6);

    return 0;
}




