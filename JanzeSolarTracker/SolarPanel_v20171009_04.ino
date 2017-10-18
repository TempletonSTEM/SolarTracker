int timer = 250;
int sweepDelay = 600;
int sweepScanDelay = 30;
int loopCount = 0;
int currentState = 0;  //[TK]
int previousState = 0;  //[TK]
long randNumber; // for testing

int photocellPin = A0;
int analogValuePhotocell = 0;
const int photocellSensorMin = 0;
const int photocellSensorMax = 800;

#include <Servo.h>
Servo myScanServo;
int positionScanServo = 0;
int scanServoPin = 10;

Servo mySolarcellServo;
int positionSolarcellServo = 0;
int solarcellServoPin = 9;

void setup()
{
  Serial.begin(9600);

  myScanServo.attach(scanServoPin);
  mySolarcellServo.attach(solarcellServoPin);

  // if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  randomSeed(analogRead(0));  // for testing

  analogValuePhotocell = analogRead(photocellPin);


}

void loop()
{
  if (loopCount == 10){
    currentState = 1;
  }
  else {
    loopCount = loopCount + 1;
//    Serial.print("count = ");
//    Serial.print(loopCount);
//    Serial.print("; ");
  }

  if (currentState == 1){
    loopCount = 0;
    currentState = 0;
    for (int i=1; i <= 36; i++){
      if (i <= 18) {
        positionScanServo = ((i * 10) - 1);
      }
      else {
        positionScanServo = ((36 - i) * 10);
      }

      myScanServo.write(positionScanServo);
      int analogValuePhotocell;
      analogValuePhotocell = analogRead(photocellPin);
//      Serial.print("photocell = ");
//      Serial.print(analogValuePhotocell);
//      Serial.print("; ");
 
//      Serial.print("ServPos = ");
//      Serial.println(positionScanServo);
//      Serial.print(positionScanServo);
//      Serial.print("; ");

      delay(sweepScanDelay);
    }

    // print a random number from 1 to 36, for testing
    randNumber = random(1, 37);
    positionSolarcellServo = randNumber * 5;
    
    mySolarcellServo.write(positionSolarcellServo);  
//    Serial.print("SolarcellServo pos = ");
//    Serial.print(positionSolarcellServo);


    /* Diagnostics via Serial.print*/

    Serial.print("solarcell = ");
    Serial.print(positionSolarcellServo);
    Serial.print("; ");
    Serial.println("Start over");


    // waits for the servo to get there
    delay(250);
  }
}



