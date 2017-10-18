int timer = 1000;
int sweepDelay = 600;
int sweepScanDelay = 30;
int loopCount = 0;
int loopCountValue = 20;
int currentState = 0;  //[TK]
int previousState = 0;  //[TK]
long randNumber; // for testing

int photocellPin = A0;
int analogValuePhotocell;
const int photocellSensorMin = 0;
const int photocellSensorMax = 800;

int positionScanServo = 0;

// added 
// int analogValuePhotocellNew = 0

void setup()
{
  Serial.begin(9600);
}

void loop()
{
//  int analogValuePhotocell = 0;

  if (loopCount == loopCountValue){
    currentState = 1;
    Serial.println("StartScan");
  }
  else {
    loopCount = loopCount + 1;
  }

  if (currentState == 1){
    loopCount = 0;
    currentState = 0;
    int analogValuePhotocell = 0;
    for (int i=1; i <= 36; i++){
      if (i <= 18) {
        positionScanServo = ((i * 10) - 1);
      }
      else {
        positionScanServo = ((36 - i) * 10);
      }

      int analogValuePhotocellNew;  //added
      int positionSolarPanelServo = 0;  //added
      analogValuePhotocellNew = analogRead(photocellPin);  //new
      if (analogValuePhotocellNew > analogValuePhotocell ) {
        analogValuePhotocell = analogValuePhotocellNew;
        positionSolarPanelServo = positionScanServo;
        Serial.print("new=");
        Serial.print(analogValuePhotocellNew);
        Serial.print("; ");
        Serial.println(positionSolarPanelServo);
      }
      else {
//        Serial.print("old=");
//        Serial.print(analogValuePhotocell);        
      }
//      Serial.print(analogValuePhotocell);
//      Serial.print("; ");
 
      delay(sweepScanDelay);
    }
    Serial.println("EndScan");
    delay(timer);
  }
}



