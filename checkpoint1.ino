int valueLDR;
int pinLDR = A0;

int pinLEDGreen = 11;
int pinLEDYellow = 10;
int pinLEDRed = 9;

int pinBuzzer = 8;

void setup() {
  pinMode(pinLDR, INPUT);
  pinMode(pinLEDGreen, OUTPUT);
  pinMode(pinLEDYellow, OUTPUT);
  pinMode(pinLEDRed, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
}

void loop() {
  valueLDR = analogRead(pinLDR);
  
  digitalWrite(pinLEDGreen, LOW);
  digitalWrite(pinLEDYellow, LOW);
  digitalWrite(pinLEDRed, LOW);
  
  if (valueLDR > 115) {
    digitalWrite(pinLEDGreen, HIGH);
    
    digitalWrite(pinBuzzer, LOW);
  }
  else if (valueLDR > 56) {
    digitalWrite(pinLEDYellow, HIGH);
    
    delay(3000);
    digitalWrite(pinBuzzer, HIGH);
    
    delay(3000);
    digitalWrite(pinBuzzer, LOW);
  }
  else {
    digitalWrite(pinLEDRed, HIGH);
    
    digitalWrite(pinBuzzer, HIGH);
  }
}