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

//#include "Encoders.h"
#include "Motors.h"

#define FORWARD HIGH
#define REVERSE LOW

#define MIN_SPEED 140
//#define MAX_POWER 255
//
//#define NUM_ECNODERS 4
#define ENC_UPDATE_PERIOD (pdMS_TO_TICKS(20))
#define DIR_CHANGE_PERIOD (pdMS_TO_TICKS(5000))

int E1 = 10; //M1 Speed Control
int E2 = 11; //M2 Speed Control
int M1 = 12; //M1 Direction Control
int M2 = 13; //M2 Direction Control
//Rear motors
int E3 = 6; //M1
int E4= 5; //M2
int M3= 8; //M1
int M4= 7; //M2

bool DIRECTION;

Motor::Motor m1(M1,E1,A0,30);
Motor::Motor m2(M2,E2,A1,13);
Motor::Motor m3(M3,E3,A2,32);
Motor::Motor m4(M4,E4,A3,34);


//uint8_t pins[NUM_ECNODERS] = {A0, A1, A2, A3};
const TickType_t delay_100ms = pdMS_TO_TICKS(100);
const TickType_t delay_2s = pdMS_TO_TICKS(2000);


//Function Declaration
void TaskSerial(void*);
void TaskEncodersReadAll(TimerHandle_t);
void ChangeDirection(TimerHandle_t);
void TaskSpinMotors(void*);

//typedef int TaskProfiler;

//TaskProfiler    Encoder_prof;
//TaskProfiler    UC;
//TaskProfiler    Filter;
//TaskProfiler    Serial_prof;

SemaphoreHandle_t encoder_mutex;
int i;
int cd_motors;

TimerHandle_t enc_timer;
TimerHandle_t dir_timer;

void setup() {

  // Init Arduino serial
  Serial.begin(9600);

  cd_motors = 2;

  // Wait for serial port to connect. Needed for native USB, on LEONARDO, MICRO, YUN, and other 32u4 based boards.
  while (!Serial) {
    vTaskDelay(1);
  }

  BaseType_t  xEncStarted, xDirStarted;
  encoder_mutex = xSemaphoreCreateMutex();
  if(encoder_mutex!=nullptr){

    // Create task that consumes the queue if it was created.
    xTaskCreate(TaskSerial,// Task function
                "PrintSerial",// Task name
                128,// Stack size
                nullptr,
                2,// Priority
                nullptr);


  enc_timer = xTimerCreate("EncodersTask",
                           ENC_UPDATE_PERIOD,
                           pdTRUE,
                           nullptr,
                           TaskEncodersReadAll);

  dir_timer = xTimerCreate("DirectionTimer",
                           DIR_CHANGE_PERIOD,
                           pdTRUE,
                           nullptr,
                           ChangeDirection);

    if(enc_timer != nullptr)
    {
      xEncStarted  = xTimerStart(enc_timer,0);
      while((xEncStarted != pdPASS)) {Serial.println("Uanble to start timer encoder");}
    }

    if(dir_timer != nullptr)
    {
      xDirStarted  = xTimerStart(dir_timer,0);
      while((xDirStarted != pdPASS)) {Serial.println("Uanble to start timer direction");}
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
    if (xSemaphoreTake(encoder_mutex, portMAX_DELAY)==pdPASS)
    {
      Serial.print("PIN_");
      Serial.print(A0);
      Serial.print(":");
      Serial.print(m1.GetDistanceTurned());
      Serial.print("\t");
      Serial.print("PIN_");
      Serial.print(A1);
      Serial.print(":");
      Serial.print(m2.GetDistanceTurned());
      Serial.print("\t");
      Serial.print("PIN_");
      Serial.print(A2);
      Serial.print(":");
      Serial.print(m3.GetDistanceTurned());
      Serial.print("\t");
      Serial.print("PIN_");
      Serial.print(A3);
      Serial.print(":");
      Serial.print(m4.GetDistanceTurned());
      Serial.print("\n");
      xSemaphoreGive(encoder_mutex);
      vTaskDelay(delay_100ms);
    }
  }
}

void TaskEncodersReadAll(TimerHandle_t timer){

  //TODO: Read all and determine wheel spins and then send the current wheel rotations to this serial functions
    xSemaphoreTake(encoder_mutex, portMAX_DELAY);
//    w1.Update(FORWARD);
//    w2.Update(FORWARD);
//    w3.Update(FORWARD);
//    w4.Update(FORWARD);
      m1.UpdateEncoder();
      m2.UpdateEncoder();
      m3.UpdateEncoder();
      m4.UpdateEncoder();
    xSemaphoreGive(encoder_mutex);
}

void TaskSpinMotors(void* pvParameters)
{
  for (;;) {
    if (xSemaphoreTake(encoder_mutex, portMAX_DELAY)==pdPASS && cd_motors == 0) {
      m1.TurnWheel(DIRECTION, MAX_POWER);
      m2.TurnWheel(DIRECTION, MAX_POWER);
      m3.TurnWheel(DIRECTION, MAX_POWER);
      m4.TurnWheel(DIRECTION, MAX_POWER);

    }
    xSemaphoreGive(encoder_mutex);
    vTaskDelay(delay_100ms);
  }
}

void ChangeDirection(TimerHandle_t timer)
{
  if(cd_motors > 0){
    cd_motors --;
  }
  DIRECTION = DIRECTION ? REVERSE : FORWARD;
}
