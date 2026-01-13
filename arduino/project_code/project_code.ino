#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

// ==== Pinos do TFT (iguais ao teu código funcional) ====
#define LCD_MOSI 23
#define LCD_SCLK 18
#define LCD_CS   15
#define LCD_DC   2
#define LCD_RST  4
#define LCD_BLK  32

// ==== Piezo ====
#define PIEZO_PIN 34

Adafruit_ST7789 lcd = Adafruit_ST7789(LCD_CS, LCD_DC, LCD_RST);

void setup() {
  Serial.begin(115200);
  delay(500);

  // Backlight
  pinMode(LCD_BLK, OUTPUT);
  digitalWrite(LCD_BLK, HIGH);

  // Inicializar TFT
  lcd.init(135, 240);
  lcd.setRotation(1);
  lcd.fillScreen(ST77XX_BLACK);

  // Texto inicial
  lcd.setTextSize(2);
  lcd.setTextColor(ST77XX_WHITE);
  lcd.setCursor(0, 0);
  lcd.println("Teste Piezo");
}

void loop() {
  int valor = analogRead(PIEZO_PIN);

  // Limpa apenas a zona do valor
  lcd.fillRect(0, 40, 240, 40, ST77XX_BLACK);
  lcd.setCursor(0, 40);
  lcd.setTextSize(2);
  lcd.setTextColor(ST77XX_GREEN);

  lcd.print("Valor: ");
  lcd.println(valor);

  // Serial (debug)
  Serial.println(valor);

  delay(100);
}
