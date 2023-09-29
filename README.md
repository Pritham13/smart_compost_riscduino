# smart_compost_riscduino
The smart compost system automates the composting process by monitoring moisture and temperature levels. It ensures ideal conditions for decomposition, adding water when it's too dry and adjusting temperature as needed. This system promotes efficient composting, logs data, and can be controlled remotely, offering a convenient and sustainable approach to compost management.
The servo acts as a gateway for the water; the shaft opens up when the temperature exceeds 30 degrees and the soil moisture level is less than 30 percent. This also turns on 
the motor which starts churning once the water is added.
The temperature Values are updated on the mobile app every 5 minutes

NodeMCU and Riscduino communicate via the UART protocol via the RX and TX pins in the node MCU and pins D0 and D1 for RX and TX respectively in Arduino UNO and pins digital_io[6] and digital_io[7] for RX and TX respectively in Riscduino UNO

# Arduino UNO compilation output

![image](https://github.com/Pritham13/smart_compost_riscduino/assets/143584964/b2db2d93-1001-494c-8b14-84908890d536)

# Riscduino UNO compilation output

![image](https://github.com/Pritham13/smart_compost_riscduino/assets/143584964/a4445a9a-8f83-46cd-8dce-93140235e384)

# NodeMCU compilation output

![image](https://github.com/Pritham13/smart_compost_riscduino/assets/143584964/a17afeb4-c91d-4155-a8f5-bac18ffc1993)

