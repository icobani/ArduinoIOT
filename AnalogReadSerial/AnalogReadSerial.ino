/*
  Nem Sensör Kontrolü
  Arduino Nano üzerinde 8 tane analog giriş vardır.
  Bizim örneğimizde toprak nem sensörümüzü Analog 0 girişine bağladık
*/

//Long tipinde bir değişken tanımlanıyor.
long tickValue;

// Setup bölümünde program çalışmadan önce gerekli olan ayarlar yapılır.
void setup() {
  // Serial iletişimin hızını belirtir. Default değeri saniyede 9600 bit
  Serial.begin(9600);


  pinMode(2, OUTPUT);// değirmen pervanesi
  pinMode(3, OUTPUT);// kırmızı led ampul
  pinMode(4, OUTPUT);// motor
  pinMode(5, OUTPUT);// düdük
  
  
  // Serial ekranına mesajı yazdır.
  Serial.println("Sistem hazırlanıyor.");




}

// Sürekli dönen bir döngü bu yani sonrasında yine buraya geliyor.:
void loop() {
    Serial.println("Döngü başladı");
    digitalWrite(5, HIGH);
    
    // Analog sıfır portundan değeri oku:
    int sensorValue = analogRead(A0);
    delay(1000);
    
    sensorValue += analogRead(A0);
    delay(1000);
    
    sensorValue += analogRead(A0);
    delay(1000);
    
    sensorValue += analogRead(A0);
    delay(1000);
    
    sensorValue += analogRead(A0);

    //Bir saniye beklemek kaydı ile beş kez veriyi okuyoruz. Ve ortalamasını alıyoruz.
    sensorValue = sensorValue / 5;

    digitalWrite(5, LOW);


    
  
    // Okuduğumuz değeri ekrana yazdır.
    Serial.println(String(tickValue) + " saat, Olcülen Değer :" + String(sensorValue));
  
    if (sensorValue < 512){
      Serial.println("Su olayımız gayet iyi");
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
    }
    else
    {
      if (sensorValue < 900){
        Serial.println("Suyumuz biraz azalmış");
        digitalWrite(2,LOW);
        digitalWrite(3,HIGH);
        digitalWrite(4,LOW);
      }
      else
      {
        Serial.println("suyumuz az, biraz su veriyoruz");
        digitalWrite(2,LOW);
        digitalWrite(3,LOW);
        digitalWrite(4,HIGH);
        
        delay(3000);
        
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        Serial.println("Su vermeyi kestik.");
      }
    }
  
  
  delay(3600000);        // belirtilen zaman kadar bekle 1 saniye 1000 milisaniye.3600 saniye bir saat demek bir saatte bekle demek bu satır.
  //delay(1000);         //Bu bir saniye demek
  //Değeri bir arttırıyoruz.
  tickValue = tickValue + 1;
}
