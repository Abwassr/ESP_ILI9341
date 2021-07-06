#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

#define TFT_CS 15  // TFT CS  pin is connected to NodeMCU pin D2
#define TFT_RST -1 // TFT RST pin is connected to NodeMCU pin D3
#define TFT_DC 2   // TFT DC  pin is connected to NodeMCU pin D4
#define TFT_MOSI 5 // TFT DC  pin is connected to NodeMCU pin D4
#define TFT_MISO 0 // TFT DC  pin is connected to NodeMCU pin D4
#define TFT_SCK 4  // TFT DC  pin is connected to NodeMCU pin D4
// initialize ILI9341 TFT library with hardware SPI module
// SCK (CLK) ---> NodeMCU pin D5 (GPIO14)
// MOSI(DIN) ---> NodeMCU pin D7 (GPIO13)

Adafruit_ILI9341 tft = Adafruit_ILI9341(15, 2);

// TODO Try with SPIClass

unsigned long testFillScreen()
{
  unsigned long start = micros();
  tft.fillScreen(ILI9341_BLACK);
  delay(1000);
  tft.fillScreen(ILI9341_RED);
  delay(1000);
  tft.fillScreen(ILI9341_GREEN);
  delay(1000);
  tft.fillScreen(ILI9341_BLUE);
  delay(1000);
  tft.fillScreen(ILI9341_BLACK);
  delay(1000);
  return micros() - start;
}

void setup()
{
  Serial.begin(9600);
  Serial.println("ILI9341 Test!");
  delay(100);
  tft.begin();
  delay(1000);
  tft.fillScreen(ILI9341_RED);
  // read diagnostics (optional but can help debug problems)
  uint8_t x = tft.readcommand8(ILI9341_RDMODE);
  Serial.print("Display Power Mode: 0x");
  Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDMADCTL);
  Serial.print("MADCTL Mode: 0x");
  Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDPIXFMT);
  Serial.print("Pixel Format: 0x");
  Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDIMGFMT);
  Serial.print("Image Format: 0x");
  Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDSELFDIAG);
  Serial.print("Self Diagnostic: 0x");
  Serial.println(x, HEX);

  Serial.println(F("Benchmark                Time (microseconds)"));

  Serial.print(F("Screen fill              "));
  Serial.println(testFillScreen());
  delay(500);
  Serial.println(F("Done!"));
}

void loop(void)
{
}
