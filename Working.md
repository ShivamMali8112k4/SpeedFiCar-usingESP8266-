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
