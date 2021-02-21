/*
 * Example of a basic FreeRTOS queue
 * https://www.freertos.org/Embedded-RTOS-Queues.html
 */

// Include Arduino FreeRTOS library
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <queue.h>
#include <semphr.h>
#include <timers.h>

#include "Encoders.h"

#define FORWARD HIGH
#define REVERSE LOW

#define MIN_SPEED 140
#define MAX_POWER 255

#define NUM_ECNODERS 4
#define ENC_UPDATE_PERIOD (pdMS_TO_TICKS(20))

int E1 = 10; //M1 Speed Control
int E2 = 11; //M2 Speed Control
int M1 = 12; //M1 Direction Control
int M2 = 13; //M2 Direction Control
//Rear motors
int E3 = 6; //M1
int E4= 5; //M2
int M3= 8; //M1
int M4= 7; //M2

uint8_t pins[NUM_ECNODERS] = {A0, A1, A2, A3};
const TickType_t delay_100ms = pdMS_TO_TICKS(100);


// Define a Array
//int pinReadArray[8];

//Function Declaration
void TaskBlink(void*);
void TaskSerial(void*);
void TaskEncodersReadAll(TimerHandle_t);
void TaskSpinMotors(void*);

typedef int TaskProfiler;

TaskProfiler    Encoder_prof;
TaskProfiler    UC;
TaskProfiler    Filter;
TaskProfiler    Serial_prof;



SemaphoreHandle_t encoder_mutex;
int i;


Encoders::Wheel w1(A0, 30);
Encoders::Wheel w2(A1, 13);
Encoders::Wheel w3(A2, 32);
Encoders::Wheel w4(A3, 45);

TimerHandle_t enc_timer;

void setup() {

  // Init Arduino serial
  Serial.begin(9600);

  // Wait for serial port to connect. Needed for native USB, on LEONARDO, MICRO, YUN, and other 32u4 based boards.
  while (!Serial) {
    vTaskDelay(1);
  }

  BaseType_t  xEncStarted;
  encoder_mutex = xSemaphoreCreateMutex();
  if(encoder_mutex!=NULL){

    // Create task that consumes the queue if it was created.
    xTaskCreate(TaskSerial,// Task function
                "PrintSerial",// Task name
                128,// Stack size
                NULL,
                2,// Priority
                NULL);

//    xTaskCreate(TaskEncodersReadAll,// Task function
//                "AnalogRead4",// Task name
//                128,// Stack size
//                (void*)pin_ptr,
//                1,// Priority
//                NULL);

  enc_timer = xTimerCreate("EncodersTask",
                           ENC_UPDATE_PERIOD,
                           pdTRUE,
                           nullptr,
                           TaskEncodersReadAll);

    if(enc_timer != NULL)
    {
      xEncStarted  = xTimerStart(enc_timer,0);

      while((xEncStarted != pdPASS)) {Serial.println("Uanble to start timer");}
    }

  }


  xTaskCreate(TaskSpinMotors,// Task function
              "Motors",// Task name
              128,// Stack size
              NULL,
              1,// Priority
              NULL);

}

void loop() {}


/**
 * Serial task.
 * Prints the received items from the queue to the serial monitor.
 */
void TaskSerial(void *pvParameters){
  (void) pvParameters;

  for (;;){
    //TODO: receive values from encoder counts
//    if (xSemaphoreTake(encoder_mutex, portMAX_DELAY)==pdPASS)
    {
      Serial.print("PIN_");
      Serial.print(A0);
      Serial.print(":");
      Serial.print(w1.GetDistanceTurned());
      Serial.print("\t");
      Serial.print("PIN_");
      Serial.print(A1);
      Serial.print(":");
      Serial.print(w2.GetDistanceTurned());
      Serial.print("\t");
      Serial.print("PIN_");
      Serial.print(A2);
      Serial.print(":");
      Serial.print(w3.GetDistanceTurned());
      Serial.print("\t");
      Serial.print("PIN_");
      Serial.print(A3);
      Serial.print(":");
      Serial.print(w4.GetDistanceTurned());
      Serial.print("\n");
//      xSemaphoreGive(encoder_mutex);
      vTaskDelay(delay_100ms);
    }
  }
}


/*
 * Blink task.
 * See Blink_AnalogRead example.
 */
void TaskBlink(void *pvParameters){
  (void) pvParameters;
  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);
  for (;;){
    digitalWrite(LED_BUILTIN,HIGH);
    vTaskDelay(250/portTICK_PERIOD_MS);
    digitalWrite(LED_BUILTIN,LOW);
    vTaskDelay(250/portTICK_PERIOD_MS);
  }
}

void TaskEncodersReadAll(TimerHandle_t timer){

  //TODO: Read all and determine wheel spins and then send the current wheel rotations to this serial functions
    xSemaphoreTake(encoder_mutex, portMAX_DELAY);
    w1.Update(FORWARD);
    w2.Update(FORWARD);
    w3.Update(FORWARD);
    w4.Update(FORWARD);
    xSemaphoreGive(encoder_mutex);
}

void TaskSpinMotors(void* pvParameters)
{

  for (;;) {

    analogWrite (E1,MIN_SPEED);
    digitalWrite(M1,FORWARD);
    analogWrite (E2,MIN_SPEED);
    digitalWrite(M2,FORWARD);
    analogWrite (E3,MIN_SPEED);
    digitalWrite(M3,FORWARD);
    analogWrite (E4,MIN_SPEED);
    digitalWrite(M4,FORWARD);
    vTaskDelay(delay_100ms);
  }


}