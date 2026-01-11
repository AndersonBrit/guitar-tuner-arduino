#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define PIEZO_PIN 34

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Wire.begin(21, 22); // pinos do TFT integrado
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while(true); // trava aqui se TFT falhar
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Teste Piezo");
  display.display();
}

void loop() {
  int valor = analogRead(PIEZO_PIN); // lê piezo

  // Mostra valor no TFT
  display.setCursor(0,30);
  display.fillRect(0,30,128,34,BLACK); // limpa área anterior
  display.print("Valor: ");
  display.println(valor);
  display.display();

  // Mostra também no Serial (opcional)
  Serial.println(valor);

  delay(100); // atualiza a cada 100ms
}
