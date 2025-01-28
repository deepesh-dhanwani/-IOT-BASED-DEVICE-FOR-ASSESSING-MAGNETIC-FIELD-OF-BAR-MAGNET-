#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int IR_Sensor1=2;
const int IR_Sensor2=7;
double startMillis; 
double endMillis;
double free_fall_time;
double h = 1.41; 
double m = 0.0115;
double g=9.81;
double v,l;
double e=1.6E-19;
double n=4.7E22;
double a=225;
double B;
int activate=0;
void setup() { 
pinMode(IR_Sensor1,INPUT);
pinMode(IR_Sensor2,INPUT);
lcd.init();
lcd.clear();
lcd.backlight();
lcd.begin(16,2);
lcd.setCursor(0, 0);
lcd.print("T:");
lcd.setCursor(0, 1);
lcd.print("B:");
}
void loop() {
if(digitalRead(IR_Sensor1)==LOW) //Check the sensor output
{
startMillis = millis(); 
activate=0;
}
if(digitalRead(IR_Sensor2)==LOW) //Check the sensor output
if (activate==0){
{
endMillis = millis(); 
free_fall_time = (endMillis-startMillis)/1000;

lcd.setCursor(2, 0);
lcd.print(free_fall_time);
v=(m)*(g)*(h)*(free_fall_time);
l=(e)*(a)*(n);
B=v/l;
lcd.setCursor(1,1);
lcd.print(B,24);
 activate=1;
}
} 
}