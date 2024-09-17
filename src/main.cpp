#include <Arduino.h>

int cont1 = 0;
int cont2 = 0;

void task1(void *parameters) {
  for (;;) {
    Serial.print("Task 1: ");
    Serial.println(cont1);
    cont1++;
    // função de delay do FreeRTOS
    vTaskDelay(1000 / portTICK_PERIOD_MS); // daleu de 1 segundo
  }
}

void task2(void *parameters) {
  for (;;) {
    Serial.print("Task 2 ");
    Serial.println(cont2);
    cont2++;
    // função de delay do FreeRTOS
    vTaskDelay(1000 / portTICK_PERIOD_MS); // daleu de 1 segundo
  }
}

void setup() {
  Serial.begin(9600);
  xTaskCreate(task1,    // function name
              "Task 1", // task name
              1000,     // stack size
              NULL,     // parameters
              1,        // priority
              NULL      // task handle
  );

  xTaskCreate(task2,    // function name
              "Task 2", // task name
              1000,     // stack size
              NULL,     // parameters
              1,        // priority
              NULL      // task handle
  );
}

void loop() {}
