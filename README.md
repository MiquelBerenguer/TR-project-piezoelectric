# EcoTraffic: Smart Piezoelectric Energy Harvesting for Barcelona 🚦🔋

## 📖 The Story
This project was developed during my 2nd year of Batxillerat (Research Project) to solve a real-world urban challenge: **How can we make Barcelona's public lighting self-sufficient?**

Our solution proposes implementing piezoelectric sensors in high-traffic areas like crosswalks, metro entrances, and crowded streets (e.g., Fontanella St. with 18,000 daily pedestrians) to capture kinetic energy from footsteps. 

## 🛠️ The Simulation
We built a functional mock-up to demonstrate this concept:
- **Energy Capture:** 8 piezoelectric micro-plates connected to a central control unit. 
- **Storage:** A 3.7V Lithium battery representing the "Self-Sufficiency" reservoir. 
- **Grid Integration:** A 9V battery simulating Barcelona's municipal electrical grid. 
- **Smart Control (Arduino):** A relay-based system that manages power sources based on real-time battery levels. 

## ⚙️ Logic & Intelligence
The system is programmed to prioritize renewable energy but ensure service continuity:
1. **Eco-Mode:** The traffic light runs on piezoelectric energy.
2. **Grid-Switch:** If the eco-battery drops below **40%**, the system triggers a relay to draw power from the public grid. 
3. **Recovery:** Once the piezoelectric system recharges to **70-80%**, it automatically switches back to self-sufficient mode.

## 🚦 Traffic Light Cycle
To mirror real-world conditions, the simulation follows a standard cycle:
- **Red:** 10 seconds 
- **Amber:** 5 seconds 
- **Green:** 5 seconds 

## 📂 Repository Structure
- `/src`: Arduino C++ source code.
- `/assets`: Mock-up photographs and circuit diagrams.
