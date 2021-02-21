#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include "timers.h"

#define ONE_SHOT_TIMER_PERIOD     (pdMS_TO_TICKS(500))
#define AUTO_RELOAD_TIMER_PERIOD  (pdMS_TO_TICKS(500))


TimerHandle_t xTimer1, xTimer2;
BaseType_t xTimer1Started, xTimer2Started;

TickType_t prev;

void  prvOneShotTimerCallback(TimerHandle_t xTimer);
void  prvAutoReloadCallback(TimerHandle_t xTimer);

void setup()
{
  Serial.begin(9600);
  xTimer1 =  xTimerCreate("One Shot",
                          ONE_SHOT_TIMER_PERIOD,
                          pdFALSE,
                          nullptr,
                          prvOneShotTimerCallback
  );

  xTimer2  = xTimerCreate("Auto-Reload",
                          AUTO_RELOAD_TIMER_PERIOD,
                          pdTRUE,
                          nullptr,
                          prvAutoReloadCallback
  );

  if((xTimer1 != NULL)&&(xTimer2 !=NULL))
  {
    xTimer1Started  =  xTimerStart(xTimer1,0);
    xTimer2Started =  xTimerStart(xTimer2,0);
  }

  while((xTimer1Started !=pdPASS) &&( xTimer2Started !=pdPASS)){}


}

void prvOneShotTimerCallback(TimerHandle_t xTimer)
{
  static  TickType_t xTimeNow;
  xTimeNow = xTaskGetTickCount();
  Serial.print(" One-shot timer callback execution  : ");
  Serial.println(xTimeNow);
}

void prvAutoReloadCallback(TimerHandle_t xTimer)
{
  static TickType_t xTimeNow;
  xTimeNow = xTaskGetTickCount();
  Serial.print("Auto-reload timer callback execution : ");
  Serial.println((xTimeNow-prev)*(( TickType_t ) 1000U)/(( TickType_t ) configTICK_RATE_HZ));
  prev = xTimeNow;
}


void loop(){}