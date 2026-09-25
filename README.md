# 🛡️ ESP32 MINI IDS
### Wi-Fi Network Monitoring & Unknown Device Detection

[![Watch Demo on LinkedIn](https://img.shields.io/badge/Watch%20Demo-LinkedIn-blue?logo=linkedin)](https://lnkd.in/p/gjCx_XhW)


![ESP32 Mini IDS](images/ESP32%20Mini%20IDS%20(20).jpeg)

ESP32 MINI IDS is an embedded cybersecurity project designed to monitor a Wi-Fi network and identify potentially unknown or unauthorized devices.

The project uses an ESP32 development board as a lightweight network monitoring device. It collects network-related information and provides a simple web-based dashboard for monitoring the current network status and connected devices.

> 🚧 **Project Status: Currently Developing**
>
> The project is still under development. Some features, improvements, testing, and documentation are currently being completed.

---

## 📌 Project Overview

In modern IoT environments, many devices are connected to the same Wi-Fi network. Identifying unknown devices and monitoring network activity can be useful for basic network security.

The ESP32 MINI IDS project explores how an ESP32 can be used as a simple embedded network monitoring and intrusion-detection concept.

The system focuses on:

- 📡 Wi-Fi network monitoring
- 🌐 Network information monitoring
- 🖥️ Web-based security dashboard
- 📱 Connected device monitoring
- ⚠️ Unknown device detection
- 🔐 Basic security alert concept
- 📊 Real-time network status information

---

## 🎯 Objectives

The main objectives of this project are:

1. Monitor the current Wi-Fi connection.
2. Display network information using ESP32.
3. Monitor devices detected on the network.
4. Identify devices that are not recognized as known devices.
5. Provide a simple security alert mechanism.
6. Create a web-based dashboard for network monitoring.
7. Explore the use of embedded systems in cybersecurity.

---

## 🧠 How It Works

The ESP32 acts as the monitoring device.

              ┌─────────────────┐
              │   Wi-Fi Router  │
              └────────┬────────┘
                       │
          ┌────────────┼────────────┐
          │            │            │
       Laptop       Phone       IoT Device
          │            │            │
          └────────────┼────────────┘
                       │
                 Network Activity
                       │
                 ┌─────▼─────┐
                 │   ESP32   │
                 │  MINI IDS │
                 └─────┬─────┘
                       │
                Web Dashboard
                       │
                 Security Alert
                 
The ESP32 connects to the Wi-Fi network and provides a monitoring interface through a web server.
The dashboard can display information such as:

Wi-Fi connection status
ESP32 IP address
Gateway
Subnet information
Signal strength
Network status
Active/observed devices
Unknown device alerts

🔧 Hardware Requirements
Component
Quantity
ESP32 Development Board- 1
USB Cable- 1
Wi-Fi Router / Hotspot- 1
Laptop / PC- 1
Smartphone / Test Devices- 1+
Breadboard (Optional)
Jumper Wires (Optional)

💻 Software Requirements
Arduino IDE
ESP32 Board Package
C/C++ Arduino Programming
Wi-Fi Library
ESP32 Web Server
Web Browser

⚙️ Main Technologies
ESP32
Wi-Fi
Embedded C/C++
HTTP Web Server
Network Monitoring
Cybersecurity Concepts
IoT Security

🌐 Network Information
During testing, the ESP32 can display network information such as:
WiFi Status : CONNECTED
IP Address  : 10.239.161.66
Gateway     : 10.239.161.159
Subnet Mask : 255.255.255.0
RSSI        : -51 dBm

Web Server  : STARTED
Dashboard   : http://10.239.161.66
⚠️ Network addresses shown above are example/test-network values. They may be different when the project is run on another network.
🖥️ Web Dashboard

The project includes a web-based dashboard designed to provide a simple view of the monitored network.
Dashboard Features
Wi-Fi connection status
Gateway status
Internet status
Active device information
Unknown device detection
Security alert indication
ESP32 network information

Example dashboard concept:
╔══════════════════════════════════════════╗
║             ESP32 MINI IDS              ║
║          NETWORK MONITORING              ║
╠══════════════════════════════════════════╣
║ Wi-Fi       : CONNECTED                  ║
║ Gateway     : ONLINE                     ║
║ Internet    : ONLINE                     ║
║ Active Devices : 05                      ║
╠══════════════════════════════════════════╣
║ Known Devices                            ║
║ ✓ Laptop                                  ║
║ ✓ Smartphone                              ║
║ ✓ IoT Device                              ║
╠══════════════════════════════════════════╣
║ ⚠ UNKNOWN DEVICE                         ║
║ Security Alert Detected                  ║
╚══════════════════════════════════════════╝

🔐 Intrusion Detection Concept
This project demonstrates a basic embedded intrusion-detection concept.
The system can compare observed network devices against a list of recognized/known devices.

Concept:
Device Detected
       │
       ▼
Check Device Information
       │
       ▼
Is Device Known?
   ┌───┴───┐
  YES      NO
   │        │
   ▼        ▼
 TRUSTED   ALERT
 DEVICE    UNKNOWN DEVICE
 
A device that is not recognized can be displayed as an unknown device on the dashboard.
🚦 Security Status
The dashboard uses simple status indicators:
🟢 Trusted Device
A recognized device that belongs to the known-device list.
🔴 Unknown Device
A device that is not recognized by the monitoring system.
🟡 Monitoring
The ESP32 is actively monitoring the network.

📂 Project Structure
ESP32-MINI-IDS/
│
├── code/
│    ├── ESP32-MINI-IDS.ino
│    ├── index.html
├── README.md
│
├── images/
│   ├── project.jpg
│   
│── demo 
│
└── LICENSE

Project files may change as development continues.
🧪 Current Testing

The ESP32 network connection and web dashboard have been tested successfully.
Current test output:
WiFi Status : CONNECTED
IP Address  : 10.239.161.66
Gateway     : 10.239.161.159
Subnet Mask : 255.255.255.0
RSSI        : -51 dBm

Web Server : STARTED
Dashboard  : Available through ESP32 IP address
Further testing is being carried out for device monitoring and unknown-device detection.

🚧 Development Status
Completed / Working
[x] ESP32 Wi-Fi connection
[x] Network information display
[x] IP address detection
[x] Gateway detection
[x] Subnet information
[x] RSSI monitoring
[x] ESP32 web server
[x] Web dashboard
[x] Basic network monitoring concept
Currently Developing
[ ] Improved device detection
[ ] Known-device management
[ ] Unknown-device identification
[ ] Security alert improvements
[ ] Dashboard improvements
[ ] Testing with multiple network devices
[ ] Final documentation
[ ] Performance improvements

🔮 Future Improvements

Possible future improvements include:
📊 Advanced network statistics
🔍 Improved device identification
🔐 MAC-based device recognition
⚠️ Real-time security alerts
📱 Mobile-friendly dashboard
📈 Network activity graphs
💾 Event logging
🗂️ Device history
🔔 Alert notification system
🔑 Secure administrator access
🌐 Remote monitoring
🛡️ Integration with a larger IoT security system
🎓 Learning Outcomes

Through this project, I am exploring:
ESP32 networking
Wi-Fi communication
Web server development
Network monitoring
IP addressing
Gateway and subnet concepts
IoT cybersecurity
Intrusion detection concepts
Embedded systems
Basic network security


🎥 Demo
🚧 Demo video will be added after the current development and testing phase is completed.

👨‍💻 Developer
Sasidu-Tech
BICT Student – Rajarata University of Sri Lanka

Areas of Interest
🌐 Networking
🔐 Cyber Security
💻 Embedded Systems
🤖 Robotics
📡 IoT
🛡️ Ethical Hacking
📚 Project Series

This project is part of my ESP32 Networking & Cybersecurity project series.
01. Wi-Fi Scanner
        ↓
02. Network Status Monitor
        ↓
03. Unauthorized Device Detector
        ↓
04. ESP32 Honeypot
        ↓
05. ESP32 MINI IDS  ← Current Project
        ↓
06. Secure IoT Gateway

⚠️ Disclaimer

This project is created for educational, research, and authorized network-monitoring purposes.
Only monitor networks and devices that you own or have explicit permission to test.
📄 License

This project is licensed under the MIT License.
Copyright © 2026 Sasidu-Tech

