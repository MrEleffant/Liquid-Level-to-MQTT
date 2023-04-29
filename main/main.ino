#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Définition des constantes du réseau WiFi
const char* SSID = "nom_du_reseau_wifi";
const char* PASSWORD = "mot_de_passe_wifi";

// Définition des constantes du broker MQTT
const char* BROKER_IP = "adresse_ip_du_broker_mqtt";
const int BROKER_PORT = 1883;
const char* TOPIC = "nom_du_topic_mqtt";

// Définition des constantes de la broche analogique
const int PIN_ANALOGIQUE = A0;

// Déclaration des objets WiFiClient et PubSubClient
WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

void setup() {
  // Initialisation de la liaison série
  Serial.begin(115200);

  // Connexion au réseau WiFi
  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connexion au réseau WiFi...");
  }

  // Connexion au broker MQTT
  mqttClient.setServer(BROKER_IP, BROKER_PORT);
  while (!mqttClient.connected()) {
    Serial.println("Connexion au broker MQTT...");
    if (mqttClient.connect("ESP8266MOD")) {
      Serial.println("Connecté au broker MQTT !");
    } else {
      Serial.print("Echec de la connexion au broker MQTT : ");
      Serial.println(mqttClient.state());
      delay(5000);
    }
  }
}

void loop() {
  // Lecture de la valeur analogique
  int valeur_analogique = analogRead(PIN_ANALOGIQUE);
  Serial.print("Valeur analogique : ");
  Serial.println(valeur_analogique);

  // Envoi de la valeur analogique au broker MQTT
  char message[20];
  sprintf(message, "%d", valeur_analogique);
  mqttClient.publish(TOPIC, message);

  // Attente de 5 minutes
  delay(5 * 60 * 1000);
}
