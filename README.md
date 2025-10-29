# 🔥 Smart Fire Safety System for Cattle

## 🐄 Project Overview
In many rural areas, cattle are often tied with ropes connected to **metal rods**.  
During fire incidents, these animals are unable to escape because they remain bound to the rods.  

The **Smart Fire Safety System for Cattle** is an **automation and safety project** that detects fire and automatically **frees the animal** while activating multiple safety measures.  

This system helps protect animals during fire accidents by using sensors, actuators, and smart control logic.

---

## ⚙️ Components Used
| Component | Function |
|------------|-----------|
| 🔥 Flame Sensor | Detects fire or high temperature |
| 🧠 Arduino / NodeMCU | Processes data and controls output actions |
| ⚙️ Servo Motor | Moves down the metal rod to release the animal |
| 💧 Water Pump | Automatically turns on to control the fire |
| 🔴 Red LED | Visual alert indicating fire |
| 🔊 Buzzer | Audible alert during fire |
| 🔋 Power Supply | Provides power to all components |

---

## 🧠 Working Principle
1. The **Flame Sensor** continuously measures infrared light levels.  
2. When the sensor value is **below the threshold (200)**, the system identifies a fire.  
3. The **Servo Motor** moves down, lowering the metal rod so the animal is freed.  
4. Simultaneously, the **Buzzer**, **Red LED**, and **Water Pump** turn ON to alert and control the fire.  
5. Once the flame is no longer detected, the system resets automatically.

---

## 💻 Source Code
The complete source code is available here:  
👉 [test.c](https://github.com/suthargoutam/Smart-Fire-Safety-System-For-Cattle/blob/main/test.c)

---

## ⚡ Circuit Diagram
Below is the circuit connection used in this project:
👉 [project circut diagram.png](https://github.com/suthargoutam/Smart-Fire-Safety-System-For-Cattle/blob/main/project/project circut diagram.png)

---

## 🧰 Setup Instructions
1. Connect all components as per your circuit diagram.  
2. Upload the code to **Arduino** or **NodeMCU** using **Arduino IDE** or **VS Code**.  
3. Adjust the **flame sensor threshold value** if needed.  
4. Power the circuit and test it by showing a flame near the sensor.  

---

## 🚀 Future Improvements
- Add **IoT connectivity** for remote fire alerts (e.g., Blynk or Firebase).  
- Add **temperature sensor** for extra safety.  
- Integrate **automatic water sprinklers**.  
- Include **battery backup** and **SMS/mobile notifications**.  

---

## 👨‍💻 Author
**Goutam Suthar**  
B.E. Electronics and Communication Engineering  
📧 goutamsuthar5095@gmail.com  
💼 GitHub: [github.com/suthargoutam](https://github.com/suthargoutam)

--- 

⭐ *If you find this project helpful, please give it a star on GitHub!*