#include <Servo.h>
#include <IRremote.h>

#define   OFF_ANGLE   60
#define   ON_ANGLE    120

Servo SG90;

IRrecv irrecv(11);
decode_results results;

void setup() {
  Serial.begin(9600);
  SG90.attach(3);
  SG90.write(90);

  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) //检查是否接收到红外遥控信号
  {
    Serial.println(results.value, HEX);

    if (results.value == 0xFFA25D)
    {
      SG90.write(ON_ANGLE);
      delay(500);
      SG90.write(90);
    }

    if (results.value == 0xFF22DD)
    {
      SG90.write(OFF_ANGLE);
      delay(500);
      SG90.write(90);
    }
    
    irrecv.resume(); //接收下一指令
  }
  delay(100);
}
