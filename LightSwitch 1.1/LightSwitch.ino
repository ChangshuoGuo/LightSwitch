/*
 * 增加蓝牙功能，可通过手机APP控制
 */
#include <SoftwareSerial.h>
#include <Servo.h>
#include <IRremote.h>

#define   OFF_ANGLE   60
#define   ON_ANGLE    120

SoftwareSerial JDYSerial(2, 3);   //蓝牙模块TX->2,RX->3
Servo SG90;
IRrecv irrecv(11);
decode_results results;

void turnOn(void);
void turnOff(void);
char light;

void setup() {
  Serial.begin(9600);
  JDYSerial.begin(9600);

  pinMode(13, OUTPUT);    //13引脚输出高电平做IRrecv VCC
  digitalWrite(13, HIGH);

  SG90.attach(5);
  SG90.write(90);

  irrecv.enableIRIn(); // Start the receiver
}

void loop() 
{
  //  if (JDYSerial.available()) {
  //    Serial.println(JDYSerial.read());
  //  }
  //  if (Serial.available()) {
  //    JDYSerial.println(Serial.read());
  //  }
  if (JDYSerial.available()) 
  {
    light = JDYSerial.read();

    if (light == '1')
    {
      turnOn();
    }
    else if (light == '0')
    {
      turnOff();
    }
  }

  if (irrecv.decode(&results)) //检查是否接收到红外遥控信号
  {
    Serial.println(results.value, HEX);

    if ( results.value == 0xFFA25D || results.value == 0xE318261B )
    {
      turnOn();
    }
    if ( results.value == 0xFF22DD || results.value == 0x52A3D41F )
    {
      turnOff();
    }

    irrecv.resume(); //接收下一指令
  }

  delay(100);
}

void turnOn() {
  SG90.write(ON_ANGLE);
  delay(500);
  SG90.write(90);
}

void turnOff() {
  SG90.write(OFF_ANGLE);
  delay(500);
  SG90.write(90);
}
