#define PIN_INPUT 0
#define PIN_OUTPUT 8

double Kp = 2;
double Ki = 5;

unsigned long currentTime, previusTime;
double elapsedTime;
double error;
double input, output, setPoint, temperature;
double cumError;

void setup(){
  setPoint = 40;
  Serial.begin(9600);
}

void loop(){
  input = analogRead(PIN_INPUT);
  float voltage = input*5/1024;
  //temperature in C
  temperature=(voltage-0.5)*100;
  output = computePI(temperature);
  delay(10);
  analogWrite(PIN_OUTPUT, output);

 Serial.print("\n Temperature: ");
 Serial.print(temperature);
 
}
double computePI(double inp){
  currentTime = millis();
  elapsedTime = (double)(currentTime - previusTime);

  error = setPoint - inp;
  cumError += error*elapsedTime;

  double out = Kp*error + Ki*cumError;

  previusTime = currentTime;
  return out;
  
}
