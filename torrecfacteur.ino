int relayBlue = 9;
int relayPurple = 10;
int incomingByte = 0;
int targetTemp = 20;
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relayBlue,OUTPUT);
  pinMode(relayPurple,OUTPUT);
  digitalWrite(relayBlue,HIGH);
  digitalWrite(relayPurple,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A5);
  float voltageThermo = sensorValue * (5.0/1023.0);
  float thermoTemp = 7.30 * exp(0.54 * voltageThermo);
  Serial.print("temperature : ");
  Serial.print(thermoTemp);
  Serial.println();
  Serial.print("target temperature : ");
  Serial.print(targetTemp);
  Serial.println();
  delay(1000);
  if (Serial.available() > 0) {
    incomingByte = Serial.parseInt();
    if (incomingByte > 0) {
      targetTemp = incomingByte;};
      Serial.print("Updated target temp to : ");
      Serial.print(targetTemp);
      Serial.println();
  }
  delay(1000);
  if(targetTemp > thermoTemp){
      Serial.print("heating");
      Serial.println();
      digitalWrite(relayPurple,HIGH);
    }else{
      Serial.print("cooling");
      Serial.println();
      digitalWrite(relayPurple,LOW);
    }
//  digitalWrite(relayPurple,LOW);
//  digitalWrite(relayBlue,HIGH);
//  delay(500);
//  digitalWrite(relayPurple,HIGH);
//  digitalWrite(relayBlue,LOW);
}
