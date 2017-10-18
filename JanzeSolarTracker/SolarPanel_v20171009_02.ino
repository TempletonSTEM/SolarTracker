

/*
 * Title
 * 
 * Description Line 1
 * ...
 * Description Line n
 *
 * The circuit:
 * - Servo Brown pin to ground
 * - Servo Red pin to 5v
 * - Servo Orange pin to digital pin 9
 * - Potentiometer connected to 5v, gnd as a voltage divider
 * - Potentiometer wiper connected to Analog pin 0
 *
 * by janzeteachesit, October 09, 2017>
 *
 * This code is in the public domain.
 *
 * 
 */

/* Photocell global variables   */
// these constants won't change. They are the 
// lowest and highest readings you get from your sensor:
//
// photocell sensor minimum and maximum, discovered through experiment
const int photocellSensorMin = 0;
const int photocellSensorMax = 800;

// the photocell voltage divider pin
int photocellPin = A1;

/* Servo global variables   */
#include <Servo.h>

// the Orange pin for scan servo is connected to digital pin 9
int scanServoPin = 10;
// the Orange pin for solar cell servo is connected to digital pin 9
int solarcellServoPin = 9;
int servoPin = solarcellServoPin;  // transition code; [TK]
// analog pin used to connect the potentiometer
int potPin = A0; 
int inputPin = potPin;  // transition code; [TK]

// create servo object to control our servo
// a maximum of eight servo objects can be created 
Servo myServo; // transition code; [TK]
Servo myScanServo;
Servo mySolarcellServo;


void setup()
{

  // set up serial at 9600 baud   
  Serial.begin(9600);
  
  
  /* Photocell setup   */

  /* Servos setup*/
  // attaches the servo on pin 9 to the servo object 
  myServo.attach(servoPin);
  //myScanServo.attach(scanServoPin);
  //mySolarcellServo.attach(solarcellServoPin);


}

void loop()
{
  /* Photocell loop   */

  int analogValuePhotocell;
  //int range;

  // read our photocell
  analogValuePhotocell = analogRead(photocellPin);

  /* Servo loop*/

  int analogValuePot;
  int position;
  int positionScanServo;
  int loopCount;
 

  // reads the value of the potentiometer (value between 0 and 1023)
  analogValuePot = analogRead(potPin);

  // scale it to use it with the servo (value between 0 and 180)
  positionScanServo = map(analogValuePot, 0, 1023, 0, 179);
  position = positionScanServo;// transition code; [TK]

  // sets the servo position according to the scaled value
  myServo.write(position);// transition code; [TK]
  //myPhotoCellServo.write(positionScanServo);
  
  //myScanServo.write(position)

  /* Diagnostics vi Serial.print*/

  Serial.print("photocell = ");
  Serial.println(analogValuePhotocell);
  Serial.print("pot = ");
  Serial.println(analogValuePot);


  // waits for the servo to get there
  delay(250);

}

