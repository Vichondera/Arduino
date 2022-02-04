int color = 0;

// RGB pins
int red = 6;
int green = 5;
int blue = 7;

// Sound Detector pin
int soundPin = A0;

char received;

void setup()
{

    Serial.begin(9600);     // serial com for bluetooth module
    pinMode(red, OUTPUT);   // Red color pwm pin defined as output
    pinMode(green, OUTPUT); // Green color pwm pin defined as output
    pinMode(blue, OUTPUT);  // Blue color pwm pin defined as output

    // start value ofPWM = 0, this means RGB LEDs off
    analogWrite(red, 0);
    analogWrite(green, 0);
    analogWrite(blue, 0);
}

void loop()
{
    long sum = 0;
  
    for (int i = 0; i < 100; i++)
    {
        sum += analogRead(soundPin);
    }
  
    sum = sum / 100;

    Serial.println(sum);

    sum = map(sum, 50, 1000, 0, 255);

    if (sum <= 50)
    {
        analogWrite(Red_LED, 0);
        analogWrite(Green_LED, 0);
        analogWrite(Blue_LED, sum);
    }
    else if (sum < 100 && sum > 50)
    {
        analogWrite(Red_LED, 0);
        analogWrite(Green_LED, sum);
        analogWrite(Blue_LED, sum);
    }
    else if (sum < 150 && sum > 100)
    {
        analogWrite(Red_LED, 0);
        analogWrite(Green_LED, sum);
        analogWrite(Blue_LED, 0);
    }
    else if (sum < 200 && sum > 150)
    {
        analogWrite(Red_LED, sum);
        analogWrite(Green_LED, sum);
        analogWrite(Blue_LED, 0);
    }
    else if (sum < 250 && sum > 150)
    {
        analogWrite(Red_LED, sum);
        analogWrite(Green_LED, 0);
        analogWrite(Blue_LED, 0);
    }
    delay(10);
}

if (Serial.available() > 0)
{

    // read the bluetoot data and store it
    color = Serial.read();

    char Rec = char(color);

    if (Rec != '0')
    {
        Serial.println(Rec);
    } // This is to visualise the received character on the serial monitor
}

// LEDs off
if (color == 'n')
{
    analogWrite(red, 0);
    analogWrite(green, 0);
    analogWrite(blue, 0);
}

// White
if (color == 'w')
{
    analogWrite(red, 255);
    analogWrite(green, 255);
    analogWrite(blue, 255);
}

// Red
if (color == 'r')
{
    analogWrite(red, 255);
    analogWrite(green, 0);
    analogWrite(blue, 0);
}

// Green
if (color == 'g')
{
    analogWrite(red, 0);
    analogWrite(green, 255);
    analogWrite(blue, 0);
}

// Blue
if (color == 'b')
{
    analogWrite(red, 0);
    analogWrite(green, 0);
    analogWrite(blue, 255);
}

// Orange
if (color == 'o')
{
    analogWrite(red, 255);
    analogWrite(green, 153);
    analogWrite(blue, 0);
}

// Violet
if (color == 'v')
{
    analogWrite(red, 102);
    analogWrite(green, 0);
    analogWrite(blue, 153);
}

// Cyan
if (color == 'c')
{
    analogWrite(red, 0);
    analogWrite(green, 255);
    analogWrite(blue, 255);
}

// Yellow
if (color == 'y')
{
    analogWrite(red, 255);
    analogWrite(green, 204);
    analogWrite(blue, 0);
}

}
