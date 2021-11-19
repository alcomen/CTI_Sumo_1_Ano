
#include <HCSR04.h>

#define sensorIR_R  11
#define sensorIR_L  11//13
#define pontH_A0    9
#define pontH_A1    10
#define pontH_B0    5
#define pontH_B1    6
#define trigger     4
#define eco         3

//Debug
#define ultrassom 0
#define IR_R      1
#define IR_L      1

boolean aux = 0;

UltraSonicDistanceSensor distanceSensor(trigger, eco);  
// Initialize sensor that uses digital pins 13 and 12.

void check_infra(void)
{
  while(!(digitalRead(sensorIR_R) || digitalRead(sensorIR_L)))
  {
    tras();
    Serial.println("IR Detect");
    delay(300);
  }
}

void frente(void)
{
  Serial.println("Frente");
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
  Serial.println("Parar");
  digitalWrite(pontH_A0, 0);
  digitalWrite(pontH_A1, 0);
  digitalWrite(pontH_B0, 0);
  digitalWrite(pontH_B1, 0);
}

void direita(void)
{
  Serial.println("Direita");
  digitalWrite(pontH_A0, 1);
  digitalWrite(pontH_A1, 0);
  digitalWrite(pontH_B0, 0);
  digitalWrite(pontH_B1, 1);
}

void esquerda(void)
{
  Serial.println("Esquerda");
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

if(ultrassom)
{
 while(distanceSensor.measureDistanceCm() > 0 && distanceSensor.measureDistanceCm() < 25)
 {
  if(!aux)
  {
    esquerda();
    delay(200);
    aux = 1;
  }
  Serial.println("Ultrassom");
  check_infra();
  frente();
  delay(50);
 }
}
 direita();
 aux = 0;
 if(IR_R || IR_L) check_infra();
}
