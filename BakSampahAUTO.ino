//Simple BAK SAMPAH AUTO OPEN

#include <Servo.h>
Servo myservo;
const int trigPin = 9; // Trig Pin
const int echoPin = 10; // Echo Pin
const int servoPin = 8; // Servo Pin

long duration;
int distance;
int pos = 0;

void setup() {
pinMode(trigPin, OUTPUT); // Output Data
pinMode(echoPin, INPUT); // Input Data
myservo.attach(servoPin); // Menentukan Pin Servo
Serial.begin(9600);
}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// TrigPin ke HIGH untuk mengirimkan  Ultrasound dalam waktu 2 microsecond
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Membaca EchoPin, mengembalikan jarak tempuh ultrasound dalam satuan microsecond
duration = pulseIn(echoPin, HIGH);
// Mengukur Jarak
// Kecepatan  suara 340m/s atau 0,034 cm/microsecond
// Waktu = Jarak/kecepatan -> kecepatan microsecond
// Maka, Jarak = Waktu*0,034/2 -> 2 karena microsecond yang dikirimkan pada saat state HIGH trigPin 

distance= duration*0.034/2;


if(distance>40){
   myservo.write(0); //Jika Tidak Ada Tangan/Benda dengan jarak kurang dari 40cm maka servo berada posisi 0 atau awal
   delay(50);                   
  }
else if(distance<=40){
  myservo.write(90);   //Jika Ada Tangan/Benda dengan jarak kurang dari 40cm maka servo berada pada posisi 90, dimana servo akan membuka tutup bak sampah
  delay(50);          
  }
Serial.print("Distance: "); 
Serial.println(distance); //Cek Jarak Menggunakan Serial Monitor
}
