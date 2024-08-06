# -LSSE-Linux-System-Security-Enhancer
![Licence](https://img.shields.io/badge/License-MIT-blue.svg)
![ReadMe](https://img.shields.io/badge/ReadMe-018EF5?logo=readme&logoColor=fff&style=flat-square)

- [installation](#installation) 
- [Usage](#usage)
- [Description](#Description)
    - [Key Features](#key-features)
    - [How the Tool Operates](#how-the-tool-operates)
    - [Results and Effectiveness](#results-and-effectiveness)


# installation

**Clone th repository**
```bash
    git clone git@github.com:ahlyel-amine/-LSSE-Linux-System-Security-Enhancer.git LSSE
```

**Install in the system**
after the installation in the system you can run the tool by running the command `lsse`
```bash
   cd LSSE
   bash install
   cd ..
   rm -rf LSSE
```

**For simple use**

For simple use just enter to the repository folder and run the executable located on `./bin/lsse`


# Usage

after updating the config file located on `$(HOME)/.lsse/lsse.conf` you can run the command `lsse`

```bash
    lsse
```

if you're using the executable or you want to move the config file to other location you can pass the config file to the command:

```bash
    lsse -c /path/to/conf/file/lsse.conf
```
or
```bash
    ./path/to/repository/bin/lsse -c /path/to/conf/file/lsse.conf
```

for help you can run the command and discover the command options :

```bash
    lsse -h
```


# Description

`LSSE` is a tool in C that enhances the security of a Linux system by monitoring for suspicious activities and potential intrusions.

The `LSSE` tool addresses the issue of intrusion detection by monitoring system logs and network activity for patterns that indicate potential security breaches. It provides real-time alerts and logs detailed information about suspicious activities.

---
#### **Key Features:**

- Real-time Monitoring: Continuously monitors system logs and network traffic for predefined suspicious patterns.
- Intrusion Detection: Utilizes a set of rules to detect common intrusion attempts, such as unauthorized access, unusual user activities, and malware signatures.
- Alert System: Sends real-time alerts via email and logs details about detected intrusions.
- Network Traffic Analysis: Analyzes incoming and outgoing network packets to identify potential threats.
- Report Generation: Generates detailed reports of security incidents for further analysis.


#### **How the Tool Operates:**
- Initialization: On startup, LSSE reads configuration files to load the rules and thresholds for detecting suspicious activities.
- Log Monitoring: Continuously monitors system logs (e.g., /var/log/auth.log, /var/log/syslog) for suspicious entries.
- Network Traffic Analysis: Captures network packets using a packet sniffing library and analyzes them for known malicious patterns.
- Detection: When a suspicious activity or pattern is detected, LSSE logs the event and triggers an alert.
- Alert System: Sends an email alert to the system administrator with details of the detected threat and logs the event in a specified log file.
- Report Generation: Periodically generates comprehensive reports of all detected intrusions and suspicious activities for review.


#### **Results and Effectiveness:**
- Deployment: Deployed LSSE on a test server to monitor its effectiveness in detecting real-world security threats.
- Detection Rate: Successfully identified multiple intrusion attempts during the testing phase, including unauthorized SSH access attempts and malware traffic.
- Performance: Demonstrated low resource usage, ensuring that the tool does not significantly impact system performance.
- Usability: Provided clear and actionable alerts and reports, enabling quick response to potential threats.
