#include <Servo.h>

Servo myservo;  // Crea un objeto Servo

const int trigPin = 9;  // Pin del sensor ultrasónico TRIG
const int echoPin = 8; // Pin del sensor ultrasónico ECHO
int distance = 0; // Variable para almacenar la distancia medida

void setup() {
  myservo.attach(7);  // Attache el servo al pin 8
  pinMode(trigPin, OUTPUT);  // Configura el pin TRIG como salida
  pinMode(echoPin, INPUT);   // Configura el pin ECHO como entrada
  myservo.write(90);  // Mueve el servo a la posición inicial (90 grados)
  Serial.begin(9600);  // Inicia la comunicación serial para ver las lecturas del sensor
}

void loop() {
  // Genera un pulso ultrasónico como murcielago para medir la distancia
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Mide el tiempo que tarda en recibir el eco
  distance = pulseIn(echoPin, HIGH) / 58.0;  // Convierte el tiempo en distancia en cm

  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Si la distancia es menor o igual a 60 cm, mueve el servo
  if (distance <= 60) {
    myservo.write(130);  // Mueve el servo a la posición 0 grados
  } else {
    myservo.write(0);  // Vuelve el servo a la posición inicial (90 grados)
  }

  delay(250);  // Espera un segundo antes de la siguiente lectura
}


