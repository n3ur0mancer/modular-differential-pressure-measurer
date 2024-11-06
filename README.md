# Differential Pressure Measurement and Aerodynamic Modeling IoT Project

This project aims to create a modular system for measuring differential pressure and modeling aerodynamic properties using an **ESP32**, **MPX5010DP** pressure sensor, **analog RC filters**, and additional components like an **OLED display** and **SD card** for data logging. The system will allow for **real-time pressure measurements** and will feature a **hardware switch** to toggle between **low-pass and high-pass filters** for noise reduction in sensor data. The project leverages **FreeRTOS** to manage multiple tasks and ensure efficient data collection and logging.

## Project Phases Overview

### 1. Pressure Patch
- **Design and Testing**:
  - Cutting and gluing tubes into **3D printed parts** to ensure proper airflow for accurate pressure measurements.
  - The pressure patch will be made available on **Printables** for others to use.

### 2. Planning Phase
- **Bill of Materials**:
  - Key components for building the prototype:
    - **Wire Specifications**: 0.52mm² for power and 0.2mm² for signal wires.
    - **Connectors and Components**: DIN connectors, SPDT toggle switch, latching push button, 3mm PET cable braid, etc.
    - **Electronics**:
      - **ESP32**: Central microcontroller for system control and communication.
      - **MPX5010DP**: Differential pressure sensor.
      - **OLED Display (0.91-inch)**: For displaying sensor data and system status.
      - **MicroSD Card Module**: For data storage in CSV format.
      - **RC Filters**: For analog signal filtering.

### 3. Prototyping Phase
- **Data Definition**:
  - Pressure will be measured in **Pascal (Pa)** with two different sampling rates:
    - **200 Hz**: For low-dynamics (steady or slowly changing conditions).
    - **700 Hz**: For high-dynamics (turbulent or rapidly changing conditions).

- **RC Filter Usage**:
  - The system will use **analog low-pass and high-pass RC filters** to filter out unwanted noise from sensor readings.
  - The filter type (low-pass or high-pass) can be toggled using a **hardware switch**.
  - **Low-pass filter** (for steady conditions): Allows low frequencies (e.g., 200 Hz sampling).
  - **High-pass filter** (for turbulent conditions): Allows higher frequencies (e.g., 700 Hz sampling).

- **System Features**:
  - **Data Logging**: The system will log pressure data to an **SD card** in CSV format. Each recording session will be stored in a new directory, with each data entry timestamped:
    ```
    Timestamp, Pressure
    2024-09-24 12:00:00, 101.3
    ```
  - **User Interface**:
    - The **OLED Display** will show:
      - A startup image.
      - The sensor readiness status.
      - The current mode (200 Hz or 700 Hz).
      - Whether a recording session is active or not.

### 4. FreeRTOS Integration
The ESP32 will use **FreeRTOS** to efficiently manage multiple tasks concurrently:
- **Pressure Reading Task**: Reads pressure data from the MPX5010DP sensor at the selected sampling rate (200 Hz or 700 Hz).
- **Data Logging Task**: Handles logging of sensor data to the SD card, creating new files for each recording session, and managing timestamped entries.
- **OLED Display Task**: Updates the OLED display with sensor status and session information.
- **Button Management Task**: Manages input from the toggle switch and latching button for controlling the system's recording state.

### Relevant GitHub Links
- [MPX5010DP Pressure Sensor Code](https://github.com/LeandroLimaPRO/Pressure)
- [ESP32 MicroSD Card Tutorial](https://randomnerdtutorials.com/esp32-microsd-card-arduino/)
- [ESP32 OLED Display Tutorial](https://randomnerdtutorials.com/esp32-ssd1306-oled-display-arduino-ide/)
- [Image2CPP Tool for OLED Images](https://javl.github.io/image2cpp/)

### Circuit Design
- **Circuit Diagram**: Available on **circuit-diagram.org** for reference.

## Project Setup

1. **Hardware**:
   - **ESP32** development board.
   - **MPX5010DP** differential pressure sensor.
   - **0.91-inch OLED display**.
   - **MicroSD card module**.
   - **SPDT Toggle Switch** for changing the filter type (low-pass or high-pass).
   - **Latching Push Button** to start and stop data logging.
   - **RC Filter Components** (Resistors and Capacitors for low-pass and high-pass filters).
   - **Wiring**: Follow the bill of materials for wiring the components.

2. **Software Setup**:
   - Clone this repository to your local machine.
   - Set up the **ESP-IDF** or **Arduino IDE** for ESP32 development.
   - Install the necessary libraries for the MPX5010DP, OLED, SD card, and FreeRTOS.

3. **Build and Upload**:
   - Compile and upload the code using **ESP-IDF** or **Arduino IDE**.
   - Once the ESP32 is powered on, the OLED display will show the startup screen and the system will be ready to begin collecting and logging pressure data.


