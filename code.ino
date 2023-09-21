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
  
  Serial.begin(9600);
}

void loop() {
  valueLDR = analogRead(pinLDR);
  
  Serial.println(valueLDR);
  
  digitalWrite(pinLEDGreen, LOW);
  digitalWrite(pinLEDYellow, LOW);
  digitalWrite(pinLEDRed, LOW);
  
  if (valueLDR < 900) {
    digitalWrite(pinLEDGreen, HIGH);
    
    noTone(pinBuzzer);
  }
  else if (valueLDR < 970) {
    digitalWrite(pinLEDYellow, HIGH);
    
    noTone(pinBuzzer);
    delay(3000);
    tone(pinBuzzer, 1500);
    delay(3000);
  }
  else {
    digitalWrite(pinLEDRed, HIGH);
    
    tone(pinBuzzer, 1500);
  }
}
