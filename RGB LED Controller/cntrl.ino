/*
  Bluetooth RGB LED Controller & Visualizer
*/

// Pin that the KY-037 is attached to
const int soundDetector = A0;
int sensor_value = 0;

// Enter Your threshold value here
int threshold = 613;
int abs_value = 0;

// the number of LEDs(Red,Gree,Blue)
const int ledCount = 3;

// array of pin to which LEDs
int ledPins[] = { 10, 11, 12 };


/*
Define RGB Pins
*/
int color = 0;
 
int red = 10;
int green = 11;
int blue = 12;
char received;


void setup() {

  // setup serial
  Serial.begin(9600);
  pinMode(red, OUTPUT);   //Red color pwm pin defined as output
  pinMode(green, OUTPUT); //Green color pwm pin defined as output
  pinMode(blue, OUTPUT);  //Blue color pwm pin defined as output

 // start value of PWM = 0, this means RGB LEDs off
  analogWrite(red,0);
  analogWrite(green,0);
  analogWrite(blue,0);
  
//   Define LED pins OUTPUT
  for (int i = 0; i < ledCount; i++)
  {
    pinMode(ledPins[i], OUTPUT);
  }

  for (int i = 0; i < 9; i++)
  {
    digitalWrite(i, LOW);
  }

}

void loop() {

  Serial.println(analogRead(A0));
  sensor_value = analogRead(A0);
  
  abs_value = abs(sensor_value - threshold);
  int ledLevel = map(abs_value, 0, (1024 - threshold), 0, ledCount);

  for (int i = 0; i < ledCount; i++) {
    // if arr element's idx is > ledLevel,turn pin for this element on:

    if (i < ledLevel) {
      digitalWrite(ledPins[i], HIGH);
      Serial.println(i);
    } else {
      digitalWrite(ledPins[i], LOW); // turn off all pins higher than the ledLevel:
    }
    
  long sum = 0;
  for (int i = 0; i < 100; i++){
    sum += analogRead(soundDetector);
  }
  
  sum = sum / 100;
  Serial.println(sum);
  sum = map(sum, 50, 1000, 0, 255);

  if (sum <= 50) {
    analogWrite(red, 0);
    analogWrite(green, 0);
    analogWrite(blue, sum);
  } else if (sum < 100 && sum > 50) {
    analogWrite(red, 0);
    analogWrite(green, sum);
    analogWrite(blue, sum);
  } else if (sum < 150 && sum > 100) {
     analogWrite(red, 0);
     analogWrite(green, sum);
     analogWrite(blue, 0);
  } else if (sum < 200 && sum > 150) {
    analogWrite(red, sum);
    analogWrite(green, sum);
    analogWrite(blue, 0);
  } else if (sum < 250 && sum > 150) {
    analogWrite(red, sum);
    analogWrite(green, 0);
    analogWrite(blue, 0);
  }
    delay(100);
  }
  
  if(Serial.available() > 0){
    // read the bluetoot data and store it
    color = Serial.read();
    char Rec = char(color);
    if (Rec != '0')
    {
    Serial.println(Rec); //This is to visualise the received character on the serial monitor
    }  
  }
 
  //LEDs off
  if (color == 'n')
  {
    analogWrite(red,0);
    analogWrite(green,0);
    analogWrite(blue,0);
  }
  //White
  if (color == 'w')
  {
    analogWrite(red,255);
    analogWrite(green,255);
    analogWrite(blue,255);
  }
  //Red
  if (color == 'r')
  {
    analogWrite(red,255);
    analogWrite(green,0);
    analogWrite(blue,0);
  }
  //Green
  if (color == 'g')
  {
    analogWrite(red,0);
    analogWrite(green,255);
    analogWrite(blue,0);
  }
  //Blue
  if (color == 'b')
  {
    analogWrite(red,0);
    analogWrite(green,0);
    analogWrite(blue,255);
  }
  //Orange
  if (color == 'o')
  {
    analogWrite(red,255);
    analogWrite(green,153);
    analogWrite(blue,0);
  }
  //Violet
  if (color == 'v')
  {
    analogWrite(red,102);
    analogWrite(green,0);
    analogWrite(blue,153);
  }
  //Cyan
  if (color == 'c')
  {
    analogWrite(red,0);
    analogWrite(green,255);
    analogWrite(blue,255);
  }
  //Yellow 
  if (color == 'y')
  {
    analogWrite(red,255);
    analogWrite(green,204);
    analogWrite(blue,0);
  }  
}
