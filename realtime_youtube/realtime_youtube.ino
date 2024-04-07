#include "ThreadHandler.h"

SET_THREAD_HANDLER_TICK(1000)
THREAD_HANDLER(InterruptTimer::getInstance())

void funcao1()
{
  Serial.println("LedVermelho");
  digitalWrite(6,HIGH);
  delay(1000);
  digitalWrite(6, LOW);
  delay(1000);
}
void funcao2()
{
  Serial.println("LedVerde");
  digitalWrite(7,HIGH);
  delay(100);
  digitalWrite(7, LOW);
  delay(100);
}
Thread* thread1 = createThread(0,6000,1000*(2/10), funcao1);
Thread* thread2 = createThread(1,6000,1000*(2/10), funcao2);

void setup() {
  ThreadHandler::getInstance()->enableThreadExecution();
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}
