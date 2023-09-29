# smart_compost_riscduino
The smart compost system automates the composting process by monitoring moisture and temperature levels. It ensures ideal conditions for decomposition, adding water when it's too dry and adjusting temperature as needed. This system promotes efficient composting, logs data, and can be controlled remotely, offering a convenient and sustainable approach to compost management.
The servo acts as a gateway for the water; the shaft opens up when the temperature exceeds 30 degrees and the soil moisture level is less than 30 percent. This also turns on 
the motor which starts churning once the water is added.
The temperature Values are updated on the mobile app every 5 minutes

NodeMCU and Riscduino communicate via the UART protocol via the RX and TX pins in the node MCU and pins D0 and D1 for RX and TX respectively in Arduino UNO and pins digital_io[6] and digital_io[7] for RX and TX respectively in Riscduino UNO

# BOM

| Component name  | Quantity Required | Unit price | Total Price (Unit price*Quantity) |                  
|-----------------|-----------------|-----------------|-----------------|
| Ultrasonic Sensor    | 1       | Rs. 220          | Rs. 220           |
| DC motor             | 1       | Rs. 300          | Rs. 300           |
| Moisture Sensor      | 1       | Rs. 100          | Rs. 100           |
| Servo                | 1       | Rs. 175          | Rs. 175           |
| L293D Motor Driver   | 1       | Rs. 120          | Rs. 120           |
| NODEMCU ESP8266         | 1       | Rs. 230          | Rs. 230           |



# Arduino UNO compilation output

![Screenshot (333)](https://github.com/Pritham13/smart_compost_riscduino/assets/137704414/95eb9dd9-dd26-4883-8f8a-a1f1bbb4c5ad)

# Riscduino UNO compilation output

![Screenshot (334)](https://github.com/Pritham13/smart_compost_riscduino/assets/137704414/49009814-6d80-409f-a7f4-efa7e41ac837)

# NodeMCU compilation output

![image](https://github.com/Pritham13/smart_compost_riscduino/assets/143584964/a17afeb4-c91d-4155-a8f5-bac18ffc1993)


