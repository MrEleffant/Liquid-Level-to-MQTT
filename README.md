![LogoPolytech](https://www.polytech-reseau.org/wp-content/uploads/2021/03/cropped-logo_reseau_Polytech.png)
# Liquid Level to MQTT
Polytech electronic project, aquire analog data and send it to MQTT BROKER

The "Liquid Level to MQTT" project is a system for measuring the level of a liquid and sending it to an MQTT broker. It is developed using the ESP8266MOD board and the Arduino platform.

## Features

- Measures the level of a liquid using a water level sensor.
- Sends the level data to an MQTT broker every 5 minutes.
- Connects to a WiFi network to communicate with the MQTT broker.

## Configuration

To configure the "Liquid Level to MQTT" project, you need to:

1. Download and install the Arduino IDE.
2. Download and install the necessary libraries (ESP8266WiFi, PubSubClient, etc.).
3. Connect the ESP8266MOD board to your computer via a USB cable.
4. Open the "Liquid_Level_to_MQTT.ino" file in the Arduino IDE.
5. Configure the WiFi network, MQTT brokern, MQTT client, MQTT topic and water level sensor in the "Liquid_Level_to_MQTT.ino" file.
6. Compile and upload the code to the ESP8266MOD board.

## Usage

After configuring the "Liquid Level to MQTT" project, you can:

1. Set up the water level sensor and connect it to the ESP8266MOD board.
2. Turn on the ESP8266MOD board and connect it to the WiFi network.
3. Verify the connection to the MQTT broker.
4. View the real-time level data on an MQTT client.