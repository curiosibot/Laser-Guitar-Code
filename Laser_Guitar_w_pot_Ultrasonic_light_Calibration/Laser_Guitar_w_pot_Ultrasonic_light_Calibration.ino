int photoPin0 = 4; 
int photoPin1 = 0; 
int photoPin2 = 1; 
int photoPin3 = 5; 
int photoPin4 = 2; 
int photoPin5 = 3;
   
int minLight0;          //Used to calibrate the readings
int maxLight0;          //Used to calibrate the readings
int minLight1;          //Used to calibrate the readings
int maxLight1;          //Used to calibrate the readings
int minLight2;          //Used to calibrate the readings
int maxLight2;          //Used to calibrate the readings
int minLight3;          //Used to calibrate the readings
int maxLight3;          //Used to calibrate the readings
int minLight4;          //Used to calibrate the readings
int maxLight4;          //Used to calibrate the readings
int minLight5;          //Used to calibrate the readings
int maxLight5;          //Used to calibrate the readings
int lightLevel0;
int lightLevel1;
int lightLevel2;
int lightLevel3;
int lightLevel4;
int lightLevel5;
int adjustedLightLevel0;
int adjustedLightLevel1;
int adjustedLightLevel2;
int adjustedLightLevel3;
int adjustedLightLevel4;
int adjustedLightLevel5;

// defines pins numbers
const int trigPin0 = 9;
const int echoPin0 = 8;
// defines variables
long duration0;
int distance0;

void setup() {
pinMode(trigPin0, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin0, INPUT); // Sets the echoPin as an Input

 Serial.begin(9600);
 
 //Setup the starting light level limits
 lightLevel0=analogRead(photoPin0);
 minLight0=lightLevel0-20;
 maxLight0=lightLevel0;
 lightLevel1=analogRead(photoPin1);
 minLight1=lightLevel1-20;
 maxLight1=lightLevel1;
 lightLevel2=analogRead(photoPin2);
 minLight2=lightLevel2-20;
 maxLight2=lightLevel2;
 lightLevel3=analogRead(photoPin3);
 minLight3=lightLevel3-20;
 maxLight3=lightLevel3;
 lightLevel4=analogRead(photoPin4);
 minLight4=lightLevel4-20;
 maxLight4=lightLevel4;
 lightLevel5=analogRead(photoPin5);
 minLight5=lightLevel5-20;
 maxLight5=lightLevel5;
}

void loop(){
  int sensorValue7 = analogRead(A6);
 //auto-adjust the minimum and maximum limits in real time
 lightLevel0=analogRead(photoPin0);
 if(minLight0>lightLevel0){
 minLight0=lightLevel0;
 }
 if(maxLight0<lightLevel0){
 maxLight0=lightLevel0;
 }
  lightLevel1=analogRead(photoPin1);
 if(minLight1>lightLevel1){
 minLight1=lightLevel1;
 }
 if(maxLight1<lightLevel1){
 maxLight1=lightLevel1;
 }
  lightLevel2=analogRead(photoPin2);
 if(minLight2>lightLevel2){
 minLight2=lightLevel2;
 }
 if(maxLight2<lightLevel2){
 maxLight2=lightLevel2;
 }
  lightLevel3=analogRead(photoPin3);
 if(minLight3>lightLevel3){
 minLight3=lightLevel3;
 }
 if(maxLight3<lightLevel3){
 maxLight3=lightLevel3;
 }
  lightLevel4=analogRead(photoPin4);
 if(minLight4>lightLevel4){
 minLight4=lightLevel4;
 }
 if(maxLight4<lightLevel4){
 maxLight4=lightLevel4;
 }
  lightLevel5=analogRead(photoPin5);
 if(minLight5>lightLevel5){
 minLight5=lightLevel5;
 }
 if(maxLight5<lightLevel5){
 maxLight5=lightLevel5;
 }
 
 //Adjust the light level to produce a result between 0 and 100.
 adjustedLightLevel0 = map(lightLevel0, minLight0, maxLight0, 0, 100);
 adjustedLightLevel1 = map(lightLevel1, minLight1, maxLight1, 0, 100);
 adjustedLightLevel2 = map(lightLevel2, minLight2, maxLight2, 0, 100);
 adjustedLightLevel3 = map(lightLevel3, minLight3, maxLight3, 0, 100);
 adjustedLightLevel4 = map(lightLevel4, minLight4, maxLight4, 0, 100);
 adjustedLightLevel5 = map(lightLevel5, minLight5, maxLight5, 0, 100);
 
 //Send the adjusted Light level result to Serial port (processing)
  // Clears the trigPin
digitalWrite(trigPin0, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin0, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin0, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration0 = pulseIn(echoPin0, HIGH);
// Calculating the distance
distance0= duration0*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance0);

Serial.print("String1: ");
Serial.println(adjustedLightLevel0);

Serial.print("String2: ");
Serial.println(adjustedLightLevel1);

Serial.print("String3: ");
Serial.println(adjustedLightLevel2);

Serial.print("String4: ");
Serial.println(adjustedLightLevel3);

Serial.print("String5: ");
Serial.println(adjustedLightLevel4);

Serial.print("String6: ");
Serial.println(adjustedLightLevel5);

Serial.print("Pot1: ");
Serial.println(sensorValue7);

 //slow down the transmission for effective Serial communication.
 delay(100);
}
