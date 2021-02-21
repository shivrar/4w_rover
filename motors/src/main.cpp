#include <Arduino.h>
/* To control the Rover, copy and paste the code below into the Arduino software. Ensure the motors are connected to the correct pins. The
code does not factor in encoders at this time*/
//Front motors
int E1 = 10; //M1 Speed Control
int E2 = 11; //M2 Speed Control
int M1 = 12; //M1 Direction Control
int M2 = 13; //M2 Direction Control
//Rear motors
int E3 = 6; //M1
int E4= 5; //M2
int M3= 8; //M1
int M4= 7; //M2

#define FORWARD HIGH
#define REVERSE LOW

void establishContact(void);
void forward(char,char);
void reverse(char,char);
void left(char,char);
void right(char,char);
void ccw(char,char);
void cw(char,char);
void stop(void);

void setup(void)
{
  int i;
  for(i=3;i<=13;i++)
    pinMode(i, OUTPUT);
  Serial.begin(9600);

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  establishContact();  // send a byte to establish contact until receiver responds
}
void loop(void)
{
  while (Serial.available() < 1) {Serial.println("Waiting");} // Wait until a character is received
  char val = Serial.read();
  int leftspeed = 120; //255 is maximum speed
  int rightspeed = 120;
  switch(val) // Perform an action depending on the command
  {
    case 'w'://Move Forward
      forward (leftspeed,rightspeed);
      break;
    case 's'://Move Backwards
      reverse (leftspeed,rightspeed);
      break;
    case 'a'://Turn Left
      left (leftspeed,rightspeed);
      break;
    case 'd'://Turn Right
      right (leftspeed,rightspeed);
      break;
    case 'q'://Turn Right
      ccw (leftspeed,rightspeed);
      break;
    case 'e'://Turn Right
      cw (leftspeed,rightspeed);
      break;
    default:
      stop();
      break;
  }
}
void stop(void) //Stop
{
  analogWrite (E1,0);
  digitalWrite(M1,FORWARD);
  analogWrite (E2,0);
  digitalWrite(M2,FORWARD);
  analogWrite (E3,0);
  digitalWrite(M3,FORWARD);
  analogWrite (E4,0);
  digitalWrite(M4,FORWARD);
  Serial.println("Stop");
}
void forward(char a,char b)
{
  analogWrite (E1,a);
  digitalWrite(M1,FORWARD);
  analogWrite (E2,b);
  digitalWrite(M2,FORWARD);
  analogWrite (E3,a);
  digitalWrite(M3,FORWARD);
  analogWrite (E4,b);
  digitalWrite(M4,FORWARD);
  Serial.println("Forward");
}
void reverse (char a,char b)
{
  analogWrite (E1,a);
  digitalWrite(M1,REVERSE);
  analogWrite (E2,b);
  digitalWrite(M2,REVERSE);
  analogWrite (E3,a);
  digitalWrite(M3,REVERSE);
  analogWrite (E4,b);
  digitalWrite(M4,REVERSE);
  Serial.println("Reverse");
}
void ccw (char a,char b)
{
  analogWrite (E1,a);
  digitalWrite(M1,HIGH);
  analogWrite (E2,b);
  digitalWrite(M2,HIGH);
  analogWrite (E3,a);
  digitalWrite(M3,HIGH);
  analogWrite (E4,b);
  digitalWrite(M4,LOW);
  Serial.println("CCW");
}
void cw (char a,char b)
{
  analogWrite (E1,a);
  digitalWrite(M1,LOW);
  analogWrite (E2,b);
  digitalWrite(M2,LOW);
  analogWrite (E3,a);
  digitalWrite(M3,LOW);
  analogWrite (E4,b);
  digitalWrite(M4,HIGH);
  Serial.println("CW");
}
void left (char a,char b)
{
  analogWrite (E1,a);
  digitalWrite(M1,LOW);
  analogWrite (E2,b);
  digitalWrite(M2,LOW);
  analogWrite (E3,a);
  digitalWrite(M3,HIGH);
  analogWrite (E4,b);
  digitalWrite(M4,LOW);
  Serial.println("Left");
}
void right (char a,char b)
{
  analogWrite (E1,a);
  digitalWrite(M1,HIGH);
  analogWrite (E2,b);
  digitalWrite(M2,HIGH);
  analogWrite (E3,a);
  digitalWrite(M3,LOW);
  analogWrite (E4,b);
  digitalWrite(M4,HIGH);
  Serial.println("Right");
}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.print('A');   // send a capital A
    delay(300);
  }
}