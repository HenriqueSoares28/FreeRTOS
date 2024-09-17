/*
#include <Arduino.h>

int cont1 = 0;
int cont2 = 0;

TaskHandle_t task1Handle = NULL;

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

void importantTask(void *parameters) {
  vTaskSuspendAll(); // Suspende todas as tarefas
  Serial.println("Task 3");
  xTaskResumeAll(); // Resume todas as tarefas
}

void setup() {
  Serial.begin(9600);
  xTaskCreate(task1,       // function name
              "Task 1",    // task name
              1000,        // stack size
              NULL,        // parameters
              1,           // priority
              &task1Handle // task handle
  );

  xTaskCreate(task2,    // function name
              "Task 2", // task name
              1000,     // stack size
              NULL,     // parameters
              1,        // priority
              NULL      // task handle
  );
}

void loop() {
  if (cont1 == 3 &&
      task1Handle != NULL) { // Verifica se task1Handle é diferente de NULL para
                             // evitar que o Loop seja suspendido
    vTaskSuspend(task1Handle);
  }
  if (cont2 == 5 && task1Handle != NULL) {
    vTaskResume(task1Handle);
  }
  if (cont1 == 10 && task1Handle != NULL) {
    vTaskDelete(task1Handle);
    task1Handle = NULL;
  }
}

*/
