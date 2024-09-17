/*

#include <Arduino.h>
#include <WiFi.h>

#include "config.h" // Inclui informações sobre as credenciais do wifi
                    // #define WIFI_SSID "xxxx"
                    // #define WIFI_PASS "xxxx"

#define WIFI_TIMEOUT 20000

void keepWifiAlive(void *parameters) {
  for (;;) {
    if (WiFi.status() == WL_CONNECTED) {
      Serial.println("WiFi connected");
      vTaskDelay(10000 /
                 portTICK_PERIOD_MS); // 10 sec delay if wifi is connected
      continue; // Continue to the next iteration of the loop
    }

    Serial.println("WiFi not connected, trying to connect");
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASS);

    unsigned long start = millis();

    while (WiFi.status() != WL_CONNECTED && millis() - start < WIFI_TIMEOUT) {
      if (WiFi.status() == WL_CONNECT_FAILED) {
        Serial.println("[WiFi] failed");
        vTaskDelay(20000 / portTICK_PERIOD_MS); // 20 sec delay if wifi failed
        continue; // Continue to the next iteration of the loop
      }
    }
    Serial.println("[WiFi] connected " + WiFi.localIP());
  }
}

void setup() {
  Serial.begin(9600);
  xTaskCreatePinnedToCore(keepWifiAlive,     // Função que será executada
                          "Keep Wifi Alive", // Nome da tarefa
                          5000,              // Tamanho da pilha
                          NULL,              // Parâmetros da função
                          1,                 // Prioridade
                          NULL,              // Handle
                          CONFIG_ARDUINO_RUNNING_CORE // Core
  );
}

void loop() {}
*/