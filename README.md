# RFID-Based-Attendance-System
RFID-based attendance system using ATmega328P, MFRC522 RFID reader and I²C LCD

**Project Overview**

The RFID-Based Attendance System is a microcontroller-based system designed to automate the process of recording attendance using Radio Frequency Identification (RFID) technology.

The system uses an ATmega328P microcontroller to process the RFID data received from an MFRC522 RFID reader. When a registered RFID card or tag is scanned, the system identifies the user and displays the attendance status on an I²C LCD.

The project also includes a custom PCB designed using Altium Designer, integrating the required components into a compact hardware system.

**Objectives**

* To develop an automated RFID-based attendance system.
* To identify users using unique RFID card/tag IDs.
* To process RFID data using the ATmega328P microcontroller.
* To display user and attendance information on an I²C LCD.
* To design and develop a custom PCB for the system.

**System Features**

* RFID-based user identification
* Automatic attendance recording
* ATmega328P-based control
* MFRC522 RFID reader interface
* I²C LCD display

**Components Used**

| Component       | Purpose                           |
| --------------- | --------------------------------- |
| ATmega328P      | Main microcontroller              |
| MFRC522         | RFID card/tag reader              |
| RFID Cards/Tags | User identification               |
| I²C LCD         | Displaying attendance information |
| Custom PCB      | Hardware integration              |
| Power Supply    | Provides power to the system      |

**Working Principle**

1. The system is powered on and the ATmega328P initializes the connected peripherals.
2. The MFRC522 RFID reader waits for an RFID card or tag to be placed near the reader.
3. When an RFID card/tag is detected, the MFRC522 reads its unique identification data.
4. The ATmega328P receives and processes the RFID data.
5. The scanned RFID ID is compared with the registered user information.
6. The corresponding attendance status is displayed on the I²C LCD.
7. The attendance information is recorded according to the implemented system logic.

**System Architecture**

```text
                    ┌─────────────────┐
                    │   RFID Card /   │
                    │       Tag       │
                    └────────┬────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │     MFRC522     │
                    │   RFID Reader   │
                    └────────┬────────┘
                             │
                         SPI Data
                             │
                             ▼
                    ┌─────────────────┐
                    │    ATmega328P   │
                    │  Microcontroller│
                    └────────┬────────┘
                             │
                           I²C
                             │
                             ▼
                    ┌─────────────────┐
                    │     I²C LCD     │
                    │     Display     │
                    └─────────────────┘
```

---

**Communication Interfaces**

MFRC522 - ATmega328P

The MFRC522 RFID reader communicates with the ATmega328P using the **SPI (Serial Peripheral Interface)** protocol.

I²C LCD - ATmega328P

The LCD is interfaced with the ATmega328P using the **I²C (Inter-Integrated Circuit)** communication protocol.

**Software**

The ATmega328P firmware is developed using **C programming**.

The firmware is responsible for:

* Initializing the ATmega328P and peripherals
* Initializing the MFRC522 RFID reader
* Detecting RFID cards/tags
* Reading RFID identification data
* Identifying registered users
* Processing attendance
* Displaying information on the I²C LCD

**Project Images**

**Circuit Diagram**
A custom PCB was designed using **Altium Designer** to integrate the ATmega328P, MFRC522 interface, I²C LCD interface, power supply and other required circuitry.

Schematic from altium
<img width="1264" height="816" alt="WhatsApp Image 2026-02-25 at 20 47 21" src="https://github.com/user-attachments/assets/3084697e-f4b7-4a55-8543-38f1c5f13f46" />


**PCB Design**

3D layout
<img width="659" height="576" alt="WhatsApp Image 2026-02-26 at 12 48 30 (1)" src="https://github.com/user-attachments/assets/dfcf67d1-7401-4316-8e8b-7bf102caed30" />

2D layout
<img width="712" height="674" alt="WhatsApp Image 2026-02-26 at 06 29 48" src="https://github.com/user-attachments/assets/1bffb43f-a042-4ec5-b8af-5766773e1c33" />



**Hardware Prototype**

<img width="960" height="1280" alt="WhatsApp Image 2026-05-24 at 12 00 36" src="https://github.com/user-attachments/assets/86aab4ba-6ccb-42fe-855e-b32eb3a72a11" />


**Applications**

The RFID-based attendance system can be used in:

* Colleges and educational institutions
* Schools
* Laboratories
* Offices
* Training centers
* Small-scale attendance monitoring systems

**Future Improvements**

The system can be further enhanced by adding:

* Real-time attendance monitoring
* RTC-based date and time stamping
* Database storage for attendance records
* Wi-Fi or Bluetooth connectivity
* Web or mobile-based attendance monitoring
* Automatic attendance report generation

**Technologies & Tools**

* **Microcontroller:** ATmega328P
* **RFID Reader:** MFRC522
* **Display:** I²C LCD
* **Programming Language:** C
* **PCB Design:** Altium Designer
* **Communication Protocols:** SPI, I²C

**Project Team**

**Developed by:**
* Maleeha Nasseer
* Krishnapriya S
* Siya Sherif
* Ayush A

---

Custom PCB design
Compact embedded hardware implementation
