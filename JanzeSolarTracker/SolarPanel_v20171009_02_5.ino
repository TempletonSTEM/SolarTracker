/* Servo global variables   */
#include <Servo.h>
int scanServoPin = 10;
int loopCount = 0;
int currentState = 0;  //[TK]
int previousState = 0;  //[TK]
int timer = 250;
int sweepDelay = 600;
int sweepScanDelay = 30;
int positionScanServo = 0;


// create servo object to control our servo
// a maximum of eight servo objects can be created 
Servo myScanServo;


void setup() {
  // put your setup code here, to run once:
  //pinMode(ledPin, OUTPUT); // declare LED as output
  //pinMode(scanServoPin, INPUT); // declare pushbutton as input

  // set up serial at 9600 baud   
  Serial.begin(9600);
    
  /* Servos setup*/
  // attaches the servo on pin 9 to the servo object 
  myScanServo.attach(scanServoPin);
}
void loop() {
  // put your main code here, to run repeatedly: 


// Scan loop  
if (loopCount == 10){
  currentState = 1;
}
else {
  loopCount = loopCount + 1;
  Serial.print("count = ");
  Serial.println(loopCount);
}

if (currentState == 1){
  loopCount = 0;
  currentState = 0;
  /* myScanServo.write(0);
  delay(sweepDelay);
  myScanServo.write(180);
  //delay(1000); */
    for (int i=1; i <= 36; i++){
    if (i <= 18) {
      positionScanServo = ((i * 10) - 1);
    }
    else {
      positionScanServo = ((36 - i) * 10);
    }
    //Serial.print("ServPos = ");
    //Serial.println(i);
    myScanServo.write(positionScanServo);
    Serial.print("ServPos = ");
    Serial.println(positionScanServo);
    
    delay(sweepScanDelay);
   }
  Serial.println("Start over");
}

  delay(timer);
}
