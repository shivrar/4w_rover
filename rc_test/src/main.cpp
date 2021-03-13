#include <Arduino_FreeRTOS.h>
#include <Arduino.h>
#include <semphr.h>

#define NO_CMD_CHANNELS 4
#define PPM_PIN 2

#define MAX_LR_VEL 0.5
#define MAX_FORWARD_VEL 0.5
#define MAX_ANG_VEL 0.25

SemaphoreHandle_t ch_mutex;
uint16_t a,b,c, ch[8];
float commands[4];
int i;

const TickType_t _100ms = pdMS_TO_TICKS(100);

float MapCommand(uint16_t x, uint16_t in_min, uint16_t in_max, float out_min, float out_max){
  return static_cast<float>(x - in_min) * (out_max - out_min) / static_cast<float>(in_max - in_min) + out_min;
}

//void filter_rc();
void TaskFilterRC(void*);
void TaskUpdateCommands(void*);
void TaskLed(void*);

void setup() {
  Serial.begin(9600);

  xTaskCreate(TaskLed, // Task function
              "Led", // Task name
              configMINIMAL_STACK_SIZE, // Stack size
              NULL,
              0, // Priority
              NULL );

  xTaskCreate(TaskFilterRC, // Task function
              "FilterRC", // Task name
              configMINIMAL_STACK_SIZE, // Stack size
              NULL,
              0, // Priority
              NULL );

  xTaskCreate(TaskUpdateCommands, // Task function
              "UpdateCommands", // Task name
              configMINIMAL_STACK_SIZE, // Stack size
              NULL,
              0, // Priority
              NULL );

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
  }

  //Other way to configure the intterupt
  //noInterrupts();
  //attachInterrupt(digitalPinToInterrupt(PPM_PIN), read_me, FALLING);
  //interrupts();

}

void loop() {
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
//      commands[0] = static_cast<long>(ch[2]);
//      commands[1] = static_cast<long>(ch[0]);
//      commands[2] = static_cast<long>(ch[1]);
//      commands[3] = static_cast<long>(ch[3]);

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
//      commands[0] = static_cast<long>(ch[2]);
//      commands[1] = static_cast<long>(ch[0]);
//      commands[2] = static_cast<long>(ch[1]);
//      commands[3] = static_cast<long>(ch[3]);

//      commands[0] = static_cast<long>(ch[2]);
      commands[0] = MapCommand(ch[2], 900, 2000, 0.0, 1.0);
      commands[1] = commands[0]*(MapCommand(ch[0], 0, 3000, -1.0, 1.0)*MAX_LR_VEL);
      commands[2] = -commands[0]*(MapCommand(ch[1], 0, 3000, -1.0, 1.0)*MAX_FORWARD_VEL);
      commands[3] = commands[0]*(MapCommand(ch[3], 0, 3000, -1.0, 1.0)*MAX_ANG_VEL);

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

      vTaskDelay(_100ms);
    }
  }
}

void TaskLed(void *pvParameters)
{
  (void) pvParameters;

  pinMode(LED_BUILTIN, OUTPUT);

  for (;;) {

    /**
     * Take the semaphore.
     * https://www.freertos.org/a00122.html
     */
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    vTaskDelay(10);
  }
}

//void filter_rc(){
//  for(int g = 0; g<8;g++){
//    ch[g] = max(min(2000,ch[g]), 900);
//  }
//  // Given the clipping we can now decide a proper way to determine velocity
//  // commands for the vehicle
//
//}

//void read_me()  {
//  a=micros(); //store time value a when pin value falling
//  c=a-b;      //calculating time inbetween two peaks
//  b=a;        //
//  if(c>10000 || i>=8){
//    i = 0;
//    return;
//  }
//  ch[i] = c;
//  i++;
//  xSemaphoreGiveFromISR(ch_mutex, NULL);
//}

//void loop() {
////  filter_rc();
//
////  Serial.print("ch_1:");
////  Serial.print(ch[0]);
////  Serial.print("\t");
////  Serial.print("ch_2:");
////  Serial.print(ch[1]);
////  Serial.print("\t");
////  Serial.print("ch_3:");
////  Serial.print(ch[2]);
////  Serial.print("\t");
////  Serial.print("ch_4:");
////  Serial.print(ch[3]);
////  Serial.print("\t");
////  Serial.print("ch_5:");
////  Serial.print(ch[4]);
////  Serial.print("\t");
////  Serial.print("ch_6:");
////  Serial.print(ch[5]);
////  Serial.print("\t");
////  Serial.print("ch_7:");
////  Serial.print(ch[6]);
////  Serial.print("\t");
////  Serial.print("ch_8:");
////  Serial.print(ch[7]);
////  Serial.print("\n");
//
////  delay(10);
//}