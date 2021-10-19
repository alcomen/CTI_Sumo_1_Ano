
#include <HCSR04.h>

#define sensorIR_R  11
#define sensorIR_L  13
#define pontH_A0    9
#define pontH_A1    10
#define pontH_B0    5
#define pontH_B1    6
#define trigger     4
#define eco         3

UltraSonicDistanceSensor distanceSensor(trigger, eco);  
// Initialize sensor that uses digital pins 13 and 12.

void frente(void)
{
  digitalWrite(pontH_A0, 1);
  digitalWrite(pontH_A1, 0);
  digitalWrite(pontH_B0, 1);
  digitalWrite(pontH_B1, 0);
}

void tras(void)
{
  digitalWrite(pontH_A0, 0);
  digitalWrite(pontH_A1, 1);
  digitalWrite(pontH_B0, 0);
  digitalWrite(pontH_B1, 1);
}

void parar(void)
{
  digitalWrite(pontH_A0, 0);
  digitalWrite(pontH_A1, 0);
  digitalWrite(pontH_B0, 0);
  digitalWrite(pontH_B1, 0);
}

void direita(void)
{
  digitalWrite(pontH_A0, 1);
  digitalWrite(pontH_A1, 0);
  digitalWrite(pontH_B0, 0);
  digitalWrite(pontH_B1, 1);
}

void esquerda(void)
{
  digitalWrite(pontH_A0, 0);
  digitalWrite(pontH_A1, 1);
  digitalWrite(pontH_B0, 1);
  digitalWrite(pontH_B1, 0);
}

void setup() {

  Serial.begin(9600);
  
  pinMode(pontH_A0, OUTPUT);
  pinMode(pontH_A1, OUTPUT);
  pinMode(pontH_B0, OUTPUT);
  pinMode(pontH_B1, OUTPUT);

  digitalWrite(pontH_A0, 0);
  digitalWrite(pontH_A1, 0);
  digitalWrite(pontH_B0, 0);
  digitalWrite(pontH_B1, 0);
}

void loop() {

 Serial.println(distanceSensor.measureDistanceCm());
 delay(500);

 if(distanceSensor.measureDistanceCm() < 10)
 {
  parar();
  delay(300);
  tras();
  delay(300);
  direita();
  delay(300);
  frente();
 }else

 frente();
}
