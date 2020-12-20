#include <PID_v1.h>
 
#define PIN_INPUT 0 //pin A0 analog input
#define PIN_OUTPUT 8 // pin 8 PWM ouput 
 
//Define Variables we'll be connecting to
double Setpoint, Input, Output, temperature;
 
//Specify the links and initial tuning parameters
double Kp=2, Ki=5, Kd=1;
PID temp_control(&temperature, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
 
void setup()
{
 Serial.begin(9600); //to print values to test and graph
 Input = analogRead(PIN_INPUT);// read the input value
 Setpoint = 40; //in c
 //turn the PID on
 temp_control.SetMode(AUTOMATIC);
}
 
void loop()
{
 Input = analogRead(PIN_INPUT);
 float voltage = Input*5/1024;
 //temperature in C
 temperature=(voltage-0.5)*100;
 temp_control.Compute();
 analogWrite(PIN_OUTPUT, Output);
 Serial.print("\n Temperature: ");
 Serial.print(temperature);
}
