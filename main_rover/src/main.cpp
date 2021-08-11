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

#define ENC_UPDATE_PERIOD (pdMS_TO_TICKS(20))
#define DIR_CHANGE_PERIOD (pdMS_TO_TICKS(5000))
#define PERIOD_100MS (pdMS_TO_TICKS(100))


#define PPM_PIN 2

#define MAX_LR_VEL 0.5
#define MAX_FORWARD_VEL 0.5
#define MAX_ANG_VEL 0.25

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

uint16_t a,b,c, ch[8];
float commands[4];

Motor::Motor m1(M1,E1,A0,30);
Motor::Motor m2(M2,E2,A1,13);
Motor::Motor m3(M3,E3,A2,32);
Motor::Motor m4(M4,E4,A3,34);


float MapCommand(uint16_t x, uint16_t in_min, uint16_t in_max, float out_min, float out_max){
  return static_cast<float>(x - in_min) * (out_max - out_min) / static_cast<float>(in_max - in_min) + out_min;
}

//Function Declaration
void TaskSerial(void*);
void TaskEncodersReadAll(TimerHandle_t);
void ChangeDirection(TimerHandle_t);
void TaskSpinMotors(void*);
void TaskFilterRC(void*);
void TaskUpdateCommands(void*);

//typedef int TaskProfiler;

//TaskProfiler    Encoder_prof;
//TaskProfiler    UC;
//TaskProfiler    Filter;
//TaskProfiler    Serial_prof;

SemaphoreHandle_t encoder_mutex;
SemaphoreHandle_t ch_mutex;
int i;
int cd_motors;

TimerHandle_t enc_timer;
TimerHandle_t dir_timer;

void setup() {

  // Init Arduino serial
  Serial.begin(9600);
  xTaskGetTickCount();
  cd_motors = 1;

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

//    if(enc_timer != nullptr)
//    {
////      xEncStarted  = xTimerStart(enc_timer,0);
//      while((xEncStarted != pdPASS)) {Serial.println("Uanble to start timer encoder");}
//    }

    if(dir_timer != nullptr)
    {
      xDirStarted  = xTimerStart(dir_timer,0);
      while((xDirStarted != pdPASS)) {Serial.println("Uanble to start timer direction");}
    }

  }


  xTaskCreate(TaskSpinMotors,// Task function
              "Motors",// Task name
              128,// Stack size
              nullptr,
              1,// Priority
              NULL);

  xTaskCreate(TaskFilterRC, // Task function
              "FilterRC", // Task name
              configMINIMAL_STACK_SIZE, // Stack size
              nullptr,
              0, // Priority
              nullptr );

  xTaskCreate(TaskUpdateCommands, // Task function
              "UpdateCommands", // Task name
              configMINIMAL_STACK_SIZE, // Stack size
              nullptr,
              0, // Priority
              nullptr );

  ch_mutex = xSemaphoreCreateBinary();
  pinMode(PPM_PIN, INPUT);
  pinMode(3,OUTPUT);
  digitalWrite(3, HIGH);

  if (ch_mutex != nullptr) {
    //if the semaphore was successful attach the interrupt
    cli();
    //  EICRA = (EICRA & ~((1 << ISC00) | (1 << ISC01))) | (FALLING << ISC00);
    EICRA = 0b00000010; // set the INT0 to trigger an external inttrupt
    EIMSK |= (1 << INT0); // set INT0 bit in interrupt flag
    // enabling interrupt at pin 2
    sei();
  }

}

void loop() {}

ISR(INT0_vect){
  a=micros(); //store time value a when pin value falling //TODO: this will behave erratically so should take them out
  //a = xTaskGetTickCount()/portTICK_PERIOD_MS;
  c=a-b;      //calculating time inbetween two peaks
  b=a;        //
  if(c>10000 || i>=8){
    i = 0;
    return;
  }
  ch[i] = c;
  i++;
  xSemaphoreGiveFromISR(ch_mutex, NULL);
}


/**
 * Serial task.
 * Prints the received items from the queue to the serial monitor.
 */
void TaskSerial(void *pvParameters){
  (void) pvParameters;

  for (;;){
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
      Serial.print("\t");

      Serial.print("throttle:");
      Serial.print(commands[0],4);
      Serial.print("\t");
      Serial.print("Left/Right:");
      Serial.print(commands[1],4);
      Serial.print("\t");
      Serial.print("Forward:");
      Serial.print(commands[2],4);
      Serial.print("\t");
      Serial.print("Yaw:");
      Serial.print(commands[3],4);
      Serial.print("\n");

      Serial.print("\n");
      xSemaphoreGive(encoder_mutex);
      vTaskDelay(PERIOD_100MS);
    }
  }
}

void TaskEncodersReadAll(TimerHandle_t timer){

  //TODO: Read all and determine wheel spins and then send the current wheel rotations to this serial functions
    xSemaphoreTake(encoder_mutex, portMAX_DELAY);
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
      m1.TurnWheel(DIRECTION, MIN_SPEED);
      m2.TurnWheel(DIRECTION, MIN_SPEED);
      m3.TurnWheel(DIRECTION, MIN_SPEED);
      m4.TurnWheel(DIRECTION, MIN_SPEED);
    }
    xSemaphoreGive(encoder_mutex);
    vTaskDelay(PERIOD_100MS);
  }
}

void ChangeDirection(TimerHandle_t timer)
{
  if(cd_motors > 0){
    cd_motors --;
  }

  DIRECTION = DIRECTION ? REVERSE : FORWARD;
}

void TaskFilterRC(void *pvParameters)
{
  for(;;) {
    if (xSemaphoreTake(ch_mutex, portMAX_DELAY) == pdPASS) {
      for (int g = 0; g < 8; g++) {
        ch[g] = max(min(2000, ch[g]), 900);
        /*!
         *
         * ch[0] = roll
         * ch[1] = pitch
         * ch[2] = throttle
         * ch[3] = yaw
         *
         * rest is TBD
         *
         * */
      }
    }
  }
}

void TaskUpdateCommands(void *pvParameters)
{
  for(;;) {
    if (xSemaphoreTake(ch_mutex, portMAX_DELAY) == pdPASS) {
//      commands[0] = static_cast<long>(ch[2]);
      commands[0] = MapCommand(ch[2], 900, 2000, 0.0, 1.0);
      //TODO: If throttle value is too large we can use that as an indicator that we have lost RC comms
      commands[1] = commands[0]*(MapCommand(ch[0], 0, 3000, -1.0, 1.0)*MAX_LR_VEL);
      commands[2] = -commands[0]*(MapCommand(ch[1], 0, 3000, -1.0, 1.0)*MAX_FORWARD_VEL);
      commands[3] = commands[0]*(MapCommand(ch[3], 0, 3000, -1.0, 1.0)*MAX_ANG_VEL);

      vTaskDelay(PERIOD_100MS);
    }
  }
}