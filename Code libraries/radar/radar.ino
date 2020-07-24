// Includes the Servo library
#include <Servo.h>. 


// defineste pinii Trig and Echo ai senzorului ultrasonic
const int trigPin = 10;
const int echoPin = 11;



// variabile pentru durata si distanta
long duration;
int distance;
Servo myServo; // creaaza un obiect servo pentr a controla servomotorul
void setup() {
  pinMode(trigPin, OUTPUT); // seteaza trigPin ca si Output
  pinMode(echoPin, INPUT); // seteaza echoPin ca si Input
  Serial.begin(9600);
  myServo.attach(12); // defineste pinul in care este atasat servomotorul
}
void loop() {
  // roteste servomotorul de la 0 la 180 de grade
  for(int i=0;i<=180;i++){  
  myServo.write(i);
  delay(35);
  distance = calculateDistance();// foloseste o functie de calculare a distantei masurate de catre senzorul ultrasonic 
  
  Serial.print(i); // trimite gradul curent catre portul Serial
  Serial.print(","); // trimite caracterul aditional langa valoarea anteriaora; necesara in Processing IDE pentru indexare
  Serial.print(distance); // trimite valoarea distantei catre portul Serial 
  Serial.print("."); // trimite caracterul aditional langa valoarea anteriaora; necesara in Processing IDE pentru indexare
  }
  // repeta liniile de cod antecedente incepand cu gradul 180 pana la 0 
  for(int i=180;i>0;i--){  
  myServo.write(i);
  delay(35);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}
// functie pentru calcularea distantei masurate de catre senzorul ultrasonic
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Seteaza trigPin pe pozitia HIGH pentru 10 microsecunde
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // citeste echoPin si returneaza timpul de transmisie ale undelor sonore in microsecunde 
  distance= duration*0.034/2;
  return distance;
}
