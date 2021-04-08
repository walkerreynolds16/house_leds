#include <Arduino.h>
#include <ESPAsyncWebServer.h>
// #include <AsyncJson.h>
#include <ArduinoJson.h>
#include <AsyncJson.h>
#include "Network.h"

AsyncWebServer server(80);

static unsigned long previousWifiCheck = 0;
unsigned long wifiCheckInterval = 20000;

void startServer()
{

    initWiFi();

    server.on("/get-message", HTTP_GET, [](AsyncWebServerRequest *request) {
        StaticJsonDocument<100> data;

        if (request->hasParam("message")) {
            data["message"] = request->getParam("message")->value();
        }
        else {
            data["message"] = "No message parameter";
        }

        String response;
        serializeJson(data, response);
        request->send(200, "application/json", response);
    });

    AsyncCallbackJsonWebHandler *handler = new AsyncCallbackJsonWebHandler("/post-message", 
        [](AsyncWebServerRequest *request, JsonVariant &json) {
            
        StaticJsonDocument<200> data;
        if (json.is<JsonArray>()) {
            data = json.as<JsonArray>();
        }
        else if (json.is<JsonObject>()) {
            data = json.as<JsonObject>();
        }
        
        String response;
        serializeJson(data, response);
        request->send(200, "application/json", response);
        Serial.println(response);
    });

    server.addHandler(handler);

    server.begin();
}

void loopServer()
{
    unsigned long currentMillis = millis();
    if (currentMillis - previousWifiCheck >= wifiCheckInterval)
    {
        previousWifiCheck = currentMillis;
        checkIfConnected();
    }
}

void notFound(AsyncWebServerRequest *request)
{
    request->send(404, "application/json", "{\"message\":\"Not found\"}");
}
