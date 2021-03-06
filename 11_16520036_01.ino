const int pingPin = 7;			// pin Arduino yang akan membaca output sensor

void setup()
{
  Serial.begin(9600);			// memulai port serial
}

void loop()
{
  long duration, cm;			// variabel untuk simpan nilai durasi dan jarak (cm)
  
  pinMode(pingPin, LOW);		// atur pin sebagai OUTPUT
  digitalWrite(pingPin, LOW);	// beri sinyal awal LOW
  delayMicroseconds(2);			// jeda 2 microseconds
  digitalWrite(pingPin, HIGH);	// trigger sensor dengan sinyal
  delayMicroseconds(5);			// trigger sensor selama 5 microseconds
  digitalWrite(pingPin, LOW);	// beri sinyal LOW
  
  pinMode(pingPin,INPUT);					// atur pin sebagai INPUT
  duration = pulseIn(pingPin, HIGH);		// sinyal HIGH untuk dapat durasi (dalam microseconds)
  cm = microsecondsToCentimeters(duration);	// konversi microseconds ke cm
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100); 
}

long microsecondsToCentimeters(long microseconds) {
	// kecepatan suara 340 m/s atau 29 microseconds/cm
  	// dibagi dua untuk mencari jarak sensor-objek
  return microseconds / 29 / 2;
}