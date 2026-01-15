# Linux Network Traffic Analyzer

A Linux-based network traffic analyzer written in **C** using **raw sockets**.  
The tool captures live network packets, parses IP headers, identifies common protocols, and displays real-time traffic statistics.

This project was built to gain hands-on experience with **Linux networking**, **systems-level programming**, and **packet processing fundamentals**.

---

## 🚀 Features

- Captures live Ethernet packets using Linux raw sockets  
- Parses IP headers to extract:
  - Source IP address
  - Destination IP address
  - Protocol type  
- Identifies and counts:
  - TCP traffic
  - UDP traffic
  - ICMP traffic
  - Other protocols  
- Displays real-time protocol statistics  

---

## 🛠️ Technologies Used

- **C**
- **Linux OS**
- **Raw Sockets**
- **GCC**
- **Makefile**

---

## 📂 Project Structure

linux-network-traffic-analyzer/
├── src/
│ └── packet_analyzer.c
├── include/
│ └── headers.h
├── Makefile
├── README.md
└── .gitignore
