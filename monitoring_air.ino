// Definisi pin
const int lokasiA = 32;    // Lokasi A
const int lokasiB = 35;    // Lokasi B
const int lokasiC = 34;    // Lokasi C

const int ledMerah = 16;   // LED Merah
const int ledKuning = 17;  // LED Kuning
const int ledHijau = 18;   // LED Hijau

void setup() {
  Serial.begin(115200);

  // Set mode pin
  pinMode(lokasiA, INPUT);
  pinMode(lokasiB, INPUT);
  pinMode(lokasiC, INPUT);

  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledHijau, OUTPUT);
}

void loop() {
  // Baca nilai dari masing-masing lokasi
  int nilaiA = analogRead(lokasiA);
  int nilaiB = analogRead(lokasiB);
  int nilaiC = analogRead(lokasiC);

  // Debug di Serial Monitor
  Serial.print("Lokasi A: "); Serial.println(nilaiA);
  Serial.print("Lokasi B: "); Serial.println(nilaiB);
  Serial.print("Lokasi C: "); Serial.println(nilaiC);

  // Cek kualitas air berdasarkan nilai analog
  cekKualitasAir(nilaiA, "A");
  cekKualitasAir(nilaiB, "B");
  cekKualitasAir(nilaiC, "C");

  delay(2000); // Delay 2 detik sebelum baca lagi
}

void cekKualitasAir(int nilai, String lokasi) {
  if (nilai < 300) {
    // Air bersih/alami
    Serial.println("Lokasi " + lokasi + ": Air BERSIH/ALAMI (LED HIJAU ON)");
    digitalWrite(ledMerah, LOW);
    digitalWrite(ledKuning, LOW);
    digitalWrite(ledHijau, HIGH);
  } 
  else if (nilai >= 300 && nilai < 600) {
    // Sedikit pupuk/sabun
    Serial.println("Lokasi " + lokasi + ": Sedikit PUPUK/SABUN (LED KUNING ON)");
    digitalWrite(ledMerah, LOW);
    digitalWrite(ledKuning, HIGH);
    digitalWrite(ledHijau, LOW);
  } 
  else if (nilai >= 600 && nilai < 1000) {
    // Polusi sedang
    Serial.println("Lokasi " + lokasi + ": Polusi SEDANG (LED MERAH ON)");
    digitalWrite(ledMerah, HIGH);
    digitalWrite(ledKuning, LOW);
    digitalWrite(ledHijau, LOW);
  } 
  else {
    // Polusi tinggi/limbah
    Serial.println("Lokasi " + lokasi + ": Polusi TINGGI/LIMBAH (LED MERAH ON)");
    digitalWrite(ledMerah, HIGH);
    digitalWrite(ledKuning, LOW);
    digitalWrite(ledHijau, LOW);
  }
}
