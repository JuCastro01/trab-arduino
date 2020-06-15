#include <DS1302.h>
#include <Servo.h>
Time t;
Servo myservo;
int Hour;
int Min;
int Sec;
DS1302 rtc(2, 3, 4);

void setup()
{
pinMode(LED_BUILTIN, 13);
pinMode(12, INPUT_PULLUP);
myservo.attach(9); 
myservo.write(45); 
rtc.halt(false);
rtc.writeProtect(false);
Serial.begin(9200);
rtc.setDOW(SUNDAY);
rtc.setTime(8, 00, 00); 
rtc.setDate(6, 14, 2020); // 
}

void loop()
{
t = rtc.getTime();
Hour = t.hour;
Min = t.min;
Sec = t.sec;

if ((Hour==8 && Min==00 && Sec==5)||(Hour==8 && Min==0 && Sec==20)) {
digitalWrite(LED_BUILTIN, HIGH);
delay (1000);
digitalWrite(LED_BUILTIN, LOW);
delay (300);
myservo.write(180);
delay (500);
myservo.write(-180);
delay (400);
myservo.write(180);
delay (500);
myservo.write(-180);
delay (400);}
if (digitalRead(12) == HIGH){
digitalWrite(LED_BUILTIN, HIGH);
delay (600);
digitalWrite(LED_BUILTIN, LOW);
delay (300);
myservo.write(180);
delay (300);
myservo.write(-180);
delay (300);}
}
