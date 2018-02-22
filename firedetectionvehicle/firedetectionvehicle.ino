// Kode program Voice-Controlled Fire Detection Vehicle

// Deklarasi Variabel
String voice;
const int Motor1 = 3;
const int Motor2 = 5;
const int pinapi = 0;
const int buzzer = 9;
int val = 0; // Penampung nilai dari sensor api

void setup() {
  // Inisialisasi Serial
  Serial.begin(9600);
  // Inisialisasi Pin
  pinMode(Motor1, OUTPUT);
  pinMode(Motor2, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

// Prosedur Kendaraan Berhenti
void berhenti() {
  delay(10);
  digitalWrite(Motor1, LOW);
  digitalWrite(Motor2, LOW);
}

// Prosedur Kendaraan Maju
void maju() {
  delay(10);
  digitalWrite(Motor1, HIGH);
  digitalWrite(Motor2, HIGH);
}

// Prosedur Kendaraan Belok Kiri
void belokkiri() {
  delay(10);
  digitalWrite(Motor1, HIGH);
  digitalWrite(Motor2, LOW);
}

// Prosedur Kendaraan Belok Kanan
void belokkanan() {
  delay(10);
  digitalWrite(Motor1, LOW);
  digitalWrite(Motor2, HIGH);
} 

// Prosedur memproses data sensor api dan mengaktuasi buzzer
void sensorapi() {
  val = analogRead(pinapi); // Simpan nilai dari sensor
  // Logika aktuasi
  if (val >= 625) {
      tone(buzzer, 1000); 
      delay(1000);        
  }
  else
  {
      noTone(buzzer);     
      delay(1000);        
  }
}

void loop() {
  // Pengecekan Teks
  while (Serial.available()) {
    delay(10);
    char inChar = Serial.read();
    if (inChar == '#') {
      break;
    }
    voice += inChar;
  }
  Serial.println(voice);
  delay(500);
  // Kendali Kendaraan
  if (voice == "*stop") {
    berhenti();
  } else if (voice == "*maju") {
    maju();
  } else if (voice == "*belok kiri") {
    belokkiri();
  } else if (voice == "*belok kanan") {
    belokkanan();
  }
  voice ="";
  // Pengecekan Api
  sensorapi();
}
