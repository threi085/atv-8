const int redLedPin = 13;
const int blueLedPin = 12;
const int redButtonPin = 11;
const int resetButtonPin = 10;
const int blueButtonPin = 9;

bool redLedState = false;
bool blueLedState = false;
bool redButtonPressed = false;
bool blueButtonPressed = false;

void setup()
{
  pinMode(redLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(redButtonPin, INPUT_PULLUP);
  pinMode(resetButtonPin, INPUT_PULLUP);
  pinMode(blueButtonPin, INPUT_PULLUP);
  
  digitalWrite(redLedPin, LOW);
  digitalWrite(blueLedPin, LOW);
}

void loop()
{
  if(digitalRead(redButtonPin) == LOW & !blueButtonPressed)
  {
   	redButtonPressed = true; 
    blueButtonPressed = false;
    
    redLedState = true;
    digitalWrite(redLedPin, redLedState);
    digitalWrite(blueLedPin, LOW);
  }
  
  if(digitalRead(blueButtonPin) == LOW & !redButtonPressed)
  {
   	blueButtonPressed = true; 
    redButtonPressed = false;
    
    blueLedState = true;
    digitalWrite(blueLedPin, blueLedState);
    digitalWrite(redLedPin, LOW);
  }
  
  if(digitalRead(resetButtonPin) == LOW)
  {
   	digitalWrite(redLedPin, LOW);
    digitalWrite(blueLedPin, LOW);
    
    redButtonPressed = false;
    blueButtonPressed = false;
  }
}