#include <WiFi.h>

#define SSID "NSA Stakeout Van"
#define PASSWORD "idontknow"

#define LOCAL_IP_FOURTH_OCTET 150

IPAddress local_IP(192, 168, 1, LOCAL_IP_FOURTH_OCTET);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 0, 0);

void initWiFi()
{
    if (!WiFi.config(local_IP, gateway, subnet)) {
        Serial.println("STA Failed to configure");
    }

    WiFi.mode(WIFI_STA);
    WiFi.begin(SSID, PASSWORD);
    Serial.print("Connecting to WiFi..");

    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print('.');
        delay(1000);
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

}

void checkIfConnected() {
    // if WiFi is down, try reconnecting
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("Reconnecting to WiFi...");
        WiFi.disconnect();
        WiFi.reconnect();
    }
    
}