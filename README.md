# sonoff-zigbee-bridge
Hacking sonoff Zigbee bridge device and reverse engineering its firmware

## specifications
- Model: ZBBridge
- Wireless connections: Wi-Fi IEEE 802.11 b/g/n 2.4GHz - ZigBee 3.0
- Microcontroller: ESP8266EX
- Zigbee SiP: SM-011 V1.0
- Zigbee MCU: EFR32MG21A020F
- Flash memory: FM25Q16A
- EEPROM: BL24C512A
- Serial port: 76800 bauds, 8N1

## ESP8266 Serial connection
| ZBBridge | Adaptor |
|----------|---------|
| ETX      | Rx      |
| ERX      | Tx      |
| IO0      | GND     |
| GND      | GND     |
| 3v3      | 3v3     |

## ToDo
- extract current firmware of ESP8266 and EFR32 controllers
