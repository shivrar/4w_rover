/*
 * Example of a basic FreeRTOS queue
 * https://www.freertos.org/Embedded-RTOS-Queues.html
 */

// Include Arduino FreeRTOS library
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <queue.h>
#include <semphr.h>

#define PPM_PIN 2
#define NUM_ECNODERS 4

uint8_t pins[NUM_ECNODERS] = {A0, A1, A2, A3};
const TickType_t delay_100ms = pdMS_TO_TICKS(100);


// Define a Array
uint16_t pinReadArray[8]={0,0,0,0,0,0,0,0};
uint16_t a,b,c, ch[8];
const uint8_t *pin_ptr = pins;


//Function Declaration
void TaskBlink(void*);
void TaskSerial(void*);
void TaskFilterRC(void*);
void TaskUpdateCommands(void*);
void TaskEncodersReadAll(void*);

typedef int TaskProfiler;

TaskProfiler    Encoder_prof;
TaskProfiler    UC;
TaskProfiler    Filter;
TaskProfiler    Serial_prof;


/* 
 * Declaring a global variable of type QueueHandle_t 
 * 
 */
QueueHandle_t arrayQueue;
SemaphoreHandle_t ch_mutex;
int i;


void setup() {

  // Init Arduino serial
  Serial.begin(9600);

  // Wait for serial port to connect. Needed for native USB, on LEONARDO, MICRO, YUN, and other 32u4 based boards.
  while (!Serial) {
    vTaskDelay(1);
  }

  ch_mutex = xSemaphoreCreateBinary();
  pinMode(PPM_PIN, INPUT_PULLUP);
  if (ch_mutex != NULL) {
    //if the semaphore was successful attach the interrupt
    cli();
    //  EICRA = (EICRA & ~((1 << ISC00) | (1 << ISC01))) | (FALLING << ISC00);
    EICRA = 0b00000010; // set the INT0 to trigger an external inttrupt
    EIMSK |= (1 << INT0); // set INT0 bit in interrupt flag
    // enabling interrupt at pin 2
    sei();
    xTaskCreate(TaskFilterRC, // Task function
                "FilterRC", // Task name
                128, // Stack size
                NULL,
                1, // Priority
                NULL );

    xTaskCreate(TaskUpdateCommands, // Task function
                "UpdateCommands", // Task name
                128, // Stack size
                NULL,
                1, // Priority
                NULL );
  }


  arrayQueue=xQueueCreate(4, //Queue length
                          sizeof(uint16_t)); //Queue item size
  if(arrayQueue!=NULL){

    // Create task that consumes the queue if it was created.
    xTaskCreate(TaskSerial,// Task function
                "PrintSerial",// Task name
                128,// Stack size
                NULL,
                2,// Priority
                NULL);

    xTaskCreate(TaskEncodersReadAll,// Task function
                "AnalogRead4",// Task name
                128,// Stack size
                (void*)pin_ptr,
                1,// Priority
                NULL);
  }


}

void loop() {}


/**
 * Serial task.
 * Prints the received items from the queue to the serial monitor.
 */
void TaskSerial(void *pvParameters){
  (void) pvParameters;

  for (;;){
    if(xQueueReceive(arrayQueue,&pinReadArray,portMAX_DELAY) == pdPASS ){
//      Serial.print("PIN_");
//      Serial.print(pinReadArray[0]);
//      Serial.print(":");
//      Serial.print(pinReadArray[1]);
//      Serial.print("\t");
//      Serial.print("PIN_");
//      Serial.print(pinReadArray[2]);
//      Serial.print(":");
//      Serial.print(pinReadArray[3]);
//      Serial.print("\t");
//      Serial.print("PIN_");
//      Serial.print(pinReadArray[4]);
//      Serial.print(":");
//      Serial.print(pinReadArray[5]);
//      Serial.print("\t");
//      Serial.print("PIN_");
//      Serial.print(pinReadArray[6]);
//      Serial.print(":");
//      Serial.print(pinReadArray[7]);
//      Serial.print("\n");

//      if (xSemaphoreTake(ch_mutex, portMAX_DELAY) == pdPASS) {
//        Serial.print("ch_1:");
//        Serial.print(ch[0]);
//        Serial.print("\t");
//        Serial.print("ch_2:");
//        Serial.print(ch[1]);
//        Serial.print("\t");
//        Serial.print("ch_3:");
//        Serial.print(ch[2]);
//        Serial.print("\t");
//        Serial.print("ch_4:");
//        Serial.print(ch[3]);
//        Serial.print("\t");
//        Serial.print("ch_5:");
//        Serial.print(ch[4]);
//        Serial.print("\t");
//        Serial.print("ch_6:");
//        Serial.print(ch[5]);
//        Serial.print("\t");
//        Serial.print("ch_7:");
//        Serial.print(ch[6]);
//        Serial.print("\t");
//        Serial.print("ch_8:");
//        Serial.print(ch[7]);
//        Serial.print("\n");
//        vTaskDelay(delay_100ms);
//      }
      Serial_prof++;
      Serial.print("Serial Run Time : ");
      Serial.println(Serial_prof);
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

ISR(INT0_vect){
  a=micros(); //store time value a when pin value falling
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

void TaskUpdateCommands(void *pvParameters)
{
  for(;;) {
    if (xSemaphoreTake(ch_mutex, portMAX_DELAY) == pdPASS) {
//      Serial.print("ch_1:");
//      Serial.print(ch[0]);
//      Serial.print("\t");
//      Serial.print("ch_2:");
//      Serial.print(ch[1]);
//      Serial.print("\t");
//      Serial.print("ch_3:");
//      Serial.print(ch[2]);
//      Serial.print("\t");
//      Serial.print("ch_4:");
//      Serial.print(ch[3]);
//      Serial.print("\t");
//      Serial.print("ch_5:");
//      Serial.print(ch[4]);
//      Serial.print("\t");
//      Serial.print("ch_6:");
//      Serial.print(ch[5]);
//      Serial.print("\t");
//      Serial.print("ch_7:");
//      Serial.print(ch[6]);
//      Serial.print("\t");
//      Serial.print("ch_8:");
//      Serial.print(ch[7]);
//      Serial.print("\n");
      Serial.print("ISR occirance : ");
      Serial.println(i);
      UC++;
      Serial.print("Updater Run time : ");
      Serial.println(UC);
      vTaskDelay(delay_100ms);
    }
  }
}

void TaskFilterRC(void *pvParameters)
{
  for(;;) {
    if (xSemaphoreTake(ch_mutex, portMAX_DELAY) == pdPASS) {
      for (int g = 0; g < 8; g++) {
        ch[g] = max(min(2000, ch[g]), 900);
      }
    }
    Filter++;
    Serial.print("Filter Run Time : ");
    Serial.println(Filter);
  }
}

void TaskEncodersReadAll(void *pvParameters){
  uint8_t * pin = (uint8_t *) pvParameters;

  for (;;)
  {
    pinReadArray[0] = *pin;
    pinReadArray[1] = analogRead(*pin);
    pinReadArray[2] = *(pin+1);
    pinReadArray[3] = analogRead(*(pin+1));
    pinReadArray[4] = *(pin+2);
    pinReadArray[5] = analogRead(*(pin+2));
    pinReadArray[6] = *(pin+3);
    pinReadArray[7] = analogRead(*(pin+3));
//    pinReadArray[2*(e->access_order)+1] = analogRead(e->pin);
    Encoder_prof++;
    Serial.print("Encoder Run Time : ");
    Serial.println(Encoder_prof);
    xQueueSend(arrayQueue,&pinReadArray,portMAX_DELAY);
  }
}