int ledRot = 9;
int ledGruen = 10;
int ledBlau = 11;
float Temperatur;
float Spannung;
int SensorWert;

void setup() {
  // put your setup code here, to run once:
pinMode(ledRot, OUTPUT);
pinMode(ledGruen, OUTPUT);
pinMode(ledBlau, OUTPUT);
Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  SensorWert= analogRead(A2);
  Spannung = (5.0 / 1023)  * SensorWert;
  Temperatur = 100 * Spannung;
  if (Temperatur >= 27 ){
    digitalWrite(ledRot, HIGH);
    digitalWrite(ledGruen, LOW);
    digitalWrite(ledBlau, LOW);
    delay(500);
  }
  if ((Temperatur >= 26)&&(Temperatur < 27)){
    digitalWrite(ledRot, LOW);
    digitalWrite(ledGruen, HIGH);
    digitalWrite(ledBlau, LOW);
    delay(500);
  }
  if ((Temperatur >= 10)&&(Temperatur < 26)){
    digitalWrite(ledRot, LOW);
    digitalWrite(ledGruen, LOW);
    digitalWrite(ledBlau, HIGH);
    delay(500);
  }
  Serial.println(Temperatur);
  delay(1000);
  
}
