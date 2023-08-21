#include <DHT.h>

#define DHTPIN 0        // 連接到 DHT11 的引腳
#define DHTTYPE DHT11   // 使用 DHT11 溫度傳感器

#define RELAY_PIN_1 3   // 第一個繼電器的控制引腳
#define RELAY_PIN_2 4   // 第二個繼電器的控制引腳

#define lowest 28.0
#define medium 30.0
#define highest 31.0

DHT dht(DHTPIN, DHTTYPE);
bool led_status = false;


void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RELAY_PIN_1, OUTPUT);
  pinMode(RELAY_PIN_2, OUTPUT);
  delay(1000);
  digitalWrite(RELAY_PIN_1, LOW);
  digitalWrite(RELAY_PIN_2, HIGH);
  delay(500);
  digitalWrite(RELAY_PIN_1, LOW);
  digitalWrite(RELAY_PIN_2, LOW);
  delay(500);
  digitalWrite(RELAY_PIN_1, HIGH);
  digitalWrite(RELAY_PIN_2, HIGH);
  delay(500);
  digitalWrite(RELAY_PIN_1, HIGH);
  digitalWrite(RELAY_PIN_2, LOW);
  delay(500);
  
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  digitalWrite(RELAY_PIN_1, LOW);
  digitalWrite(RELAY_PIN_2, HIGH);
  delay(500);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  // 讀取溫度數據
  float temperature = dht.readTemperature();
  // 檢查是否成功讀取數據
  if (!isnan(temperature)) {
    // 根據溫度範圍控制繼電器
    if (temperature < lowest) {
      digitalWrite(RELAY_PIN_1, LOW);
      digitalWrite(RELAY_PIN_2, LOW);
    } else if (temperature >= lowest && temperature < medium) {
      digitalWrite(RELAY_PIN_1, LOW);
      digitalWrite(RELAY_PIN_2, HIGH);
    } else if (temperature >= medium && temperature < highest) {
      digitalWrite(RELAY_PIN_1, HIGH);
      digitalWrite(RELAY_PIN_2, LOW);
    } else if (temperature >= highest) {
      digitalWrite(RELAY_PIN_1, HIGH);
      digitalWrite(RELAY_PIN_2, HIGH);
    }
  }
  digitalWrite(LED_BUILTIN, LOW);
}
