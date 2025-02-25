**README.md**  

# 🚗 SpeedFiCar - WiFi Controlled Smart Car  

SpeedFiCar is a **WiFi-controlled smart car** powered by **ESP8266 (NodeMCU)**. It features **speed control, obstacle avoidance, and a horn**. The car can be controlled via a mobile app, making it a fun and interactive IoT project! 🚀  

## 🔥 Features  
- 📡 **WiFi Control** – Control the car via the "ESP8266 WiFi Robot Car" app.  
- 🏎️ **Speed Control** – Adjust motor speed from the app.  
- 🛑 **Obstacle Avoidance** – Automatically stops when an obstacle is too close.  
- 📢 **Horn & Warning Buzzer** – Single buzzer for both horn and warnings.  
- ⚡ **Four-Wheel Drive** – Uses 4 DC motors for smooth movement.  

## 🔧 Components Used  
- 🛠️ **NodeMCU ESP8266**  
- 🏎️ **4 x 150 RPM DC Motors**  
- 🔌 **2 x L298N Motor Driver**  
- 📡 **Ultrasonic Sensor (HC-SR04)**  
- 🔊 **Buzzer (Horn + Warning)**  
- 🔋 **18650 Li-ion Battery Pack**  

## 📲 How to Use?  
1️⃣ **Connect the NodeMCU to WiFi**  
2️⃣ **Use the "ESP8266 WiFi Robot Car" app to control the car**  
3️⃣ **Enjoy driving & testing smart features!**  

## 📜 License  
This project is open-source. Feel free to modify and enhance it! 😃  

---

**NOTE.md**  

# 📝 Project Notes  

- This project is designed for educational and hobbyist purposes. ⚙️  
- Make sure to connect the motor drivers properly to avoid overheating. 🔥  
- Always check your power supply to avoid fluctuations. ⚡  
- Keep your ultrasonic sensor clean for accurate distance measurement. 📏  
- Adjust speed control settings carefully in the app to avoid motor damage. 🚗  

---

**WORKING.md**  

# ⚙️ How SpeedFiCar Works?  

## 🛠️ System Overview  
SpeedFiCar is controlled through a WiFi-based app that sends commands to the **NodeMCU ESP8266**. The ESP8266 processes the signals and drives the motors accordingly using **L298N motor drivers**. An **ultrasonic sensor** is used for obstacle detection, and a **buzzer** serves as a warning/horn.  

## 🚀 Working Mechanism  
1️⃣ **User sends a command from the mobile app** 📡  
2️⃣ **NodeMCU processes the command & controls the motors** ⚙️  
3️⃣ **Motors move forward, backward, left, or right** 🏎️  
4️⃣ **If an obstacle is detected at 5cm, buzzer warns** 🚨  
5️⃣ **If the obstacle is within 2cm, the car stops** ⛔  
6️⃣ **User can control speed & horn from the app** 📢  

## 🔌 Circuit Connection  
- NodeMCU → L298N → DC Motors ⚙️  
- NodeMCU → Ultrasonic Sensor 📏  
- NodeMCU → Buzzer 🔊  
- Power Supply → 18650 Battery 🔋  

This is how **SpeedFiCar** operates efficiently! 🎉🚗  
