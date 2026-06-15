#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET    -1 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);



#define VBUS_OUT    13
#define GND_OUT     12
#define CC1_OUT     14
#define D_minus_OUT 27
#define D_plus_OUT  26
#define CC2_OUT     25

#define VBUS_IN     33
#define GND_IN      32
#define CC1_IN      19
#define D_minus_IN  18
#define D_plus_IN   4   
#define CC2_IN      5   


static const unsigned char PROGMEM logo_bmp[] = { 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x7f, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
	0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 
	0x00, 0x1f, 0x80, 0x00, 0x00, 0x01, 0xf8, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 
	0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 
	0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 
	0x00, 0xf0, 0x1f, 0xff, 0xff, 0xf8, 0x0f, 0x00, 0x00, 0xf0, 0x3f, 0xff, 0xff, 0xfc, 0x0f, 0x00, 
	0x00, 0xf0, 0x3f, 0xff, 0xff, 0xfc, 0x0f, 0x00, 0x00, 0xf0, 0x1f, 0xff, 0xff, 0xf8, 0x0f, 0x00, 
	0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 
	0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x00, 
	0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x1f, 0x80, 0x00, 0x00, 0x01, 0xf8, 0x00, 
	0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 
	0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xfe, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

uint8_t outs[] = {
  VBUS_OUT, 
  GND_OUT, 
  CC1_OUT, 
  D_minus_OUT, 
  D_plus_OUT, 
  CC2_OUT};
uint8_t ins[]  = {
  VBUS_IN, 
  GND_IN, 
  CC1_IN, 
  D_minus_IN, 
  D_plus_IN, 
  CC2_IN};
String pinNames[] = {
  "VBUS", 
  "GND", 
  "CC1", 
  "D_MINUS", 
  "D_PLUS", 
  "CC2"};

uint32_t successCounts[] = {0, 0, 0, 0, 0, 0};
bool latchFaults[] = {false, false, false, false, false, false};
uint32_t totalSamples = 0;
unsigned long lastDisconnectTime = 0;
int twistStep = 0;
bool sideA[6], sideB[6];
unsigned long promptTime = 0;

String test(int mode);
bool isCableConnected();
void goToSleep();
void updateDisplay(int mode, String json);


void showSplash() {
  for (int i = 0; i <= 100; i += 2) {
    display.clearDisplay(); 
    display.drawBitmap(32, 0, logo_bmp, 64, 64, SSD1306_WHITE);
    display.drawRect(24, 48, 80, 8, WHITE);
    int barWidth = map(i, 0, 100, 0, 76);
    display.fillRect(26, 50, barWidth, 4, WHITE);
    display.setTextSize(1);
    display.setCursor(108, 48);
    display.display();
    delay(15);
  }
  delay(300);
}

void setup() {
  Wire.begin(21, 22); 
  Serial.begin(115200);
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 failed"));
  }
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);

  for (uint8_t pin : outs) pinMode(pin, OUTPUT);
  for (uint8_t pin : ins)  pinMode(pin, INPUT_PULLDOWN);

  delay(200);

  showSplash();
  Serial.println("CableProbe Multi-Mode Wakeup.");

  if (!isCableConnected()) {
    goToSleep();
  }
}

void loop() {
  int sequence[] = {9, 3, 4, 6, 7, 8}; 
  
  for (int m : sequence) {
    unsigned long modeStartTime = millis();
    
    // Zeige jeden Modus für 10 Sekunden
    while (millis() - modeStartTime < 10000) {
      if (!isCableConnected()) goToSleep();
      
      String result = test(m);
      updateDisplay(m, result);
      delay(100); 
    }
  }
  
}

bool isCableConnected() {
  digitalWrite(VBUS_OUT, HIGH);
  delay(5);
  bool connected = (digitalRead(VBUS_IN) == HIGH);
  digitalWrite(VBUS_OUT, LOW);
  return connected;
}

void goToSleep() {
  display.clearDisplay();
  display.setCursor(20, 25);
  display.setTextSize(2);
  display.println("NO CABLE");
  display.setTextSize(1);
  display.setCursor(25, 45);
  display.println("Sleeping...");
  display.display();
  delay(3000);
  
  display.ssd1306_command(SSD1306_DISPLAYOFF);
  
  esp_sleep_enable_ext0_wakeup((gpio_num_t)VBUS_IN, 1); 
  esp_deep_sleep_start();
}



void updateDisplay(int mode, String json) {

  digitalWrite(VBUS_OUT, HIGH);
  delayMicroseconds(50);
  bool shortToGnd = (digitalRead(GND_IN) == HIGH);
  digitalWrite(VBUS_OUT, LOW);

  if(shortToGnd) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(10, 10);
    display.println("!!! DANGER !!!");
    display.setTextSize(1);
    display.setCursor(10, 35);
    display.println("SHORT CIRCUIT:");
    display.setCursor(10, 45);
    display.println("VBUS <-> GND");
    display.display();
    return;
  }


  display.clearDisplay();
  display.setTextSize(1);
  
  display.setCursor(0, 0);
  display.print("MODE "); display.print(mode);
  if ((millis() / 500) % 2) display.fillRect(120, 0, 3, 3, WHITE);
  display.drawLine(0, 9, 128, 9, WHITE);

  if (mode == 9 || mode == 3) {
    display.setTextSize(2);
    display.setCursor(0, 20);
    if (json.indexOf("PD_FULL") > 0 || json.indexOf("fast_charge:OK") > 0) display.println("SUPER VOOC");
    else if (json.indexOf("USB2") > 0) display.println("USB 2.0");
    else if (json.indexOf("POWER") > 0) display.println("CHARGE ONLY");
    else display.println("NO CABLE");
    display.setTextSize(1);
    display.setCursor(0, 50);
    display.print(json.indexOf("DATA:OK") > 0 ? "[DATA] " : "");
    display.print(json.indexOf("PWR:OK") > 0 ? "[PWR]" : "");
  }

  else if (mode == 4 || mode == 7) {
    for (int i = 0; i < 6; i++) {
      int y = 14 + (i * 8);
      display.setCursor(0, y);
      display.print(pinNames[i]);
      
      if (mode == 4) {
        int barWidth = map(successCounts[i] * 100 / (totalSamples > 0 ? totalSamples : 1), 0, 100, 0, 80);
        display.drawRect(45, y, 80, 5, WHITE);
        display.fillRect(45, y, barWidth, 5, WHITE);
      } else {
        display.setCursor(50, y);
        display.print(latchFaults[i] ? "!!! FAILED !!!" : "LOCKED OK");
      }
    }
  }

  else if (mode == 1 || mode == 2) {
    for (int i = 0; i < 6; i++) {
      int yLeft = 14 + (i * 8);
      display.setCursor(0, yLeft);
      display.print(pinNames[i]);
      
      digitalWrite(outs[i], HIGH);
      delayMicroseconds(50);
      bool connected = (digitalRead(ins[i]) == HIGH);
      digitalWrite(outs[i], LOW);

      if (connected) {
        display.drawLine(40, yLeft + 3, 110, yLeft + 3, WHITE);
        display.fillCircle(115, yLeft + 3, 2, WHITE);           
      } else {
        display.setCursor(110, yLeft);
        display.print("X"); 
      }
    }
  }

  else if (mode == 6) {
    for (int i = 0; i < 6; i++) {
      int y = 14 + (i * 8);
      int raw = analogRead(ins[i]);
      int graphVal = map(raw, 0, 4095, 0, 80);
      display.setCursor(0, y);
      display.print(pinNames[i][0]);
      display.fillRect(15, y + 2, graphVal, 3, WHITE);
      display.setCursor(100, y);
      display.print(raw / 1000.0, 1); display.print("V");
    }
  }

  else if (mode == 8) {
    display.setTextSize(2);
    display.setCursor(10, 25);
    if (json.indexOf("CLEAN") > 0) {
      display.println("SHIELD: OK");
      display.drawCircle(64, 45, 10, WHITE);
    } else {
      display.println("NOISE!!");
      display.fillTriangle(64, 40, 54, 60, 74, 60, WHITE);
    }
  }

  else if (mode == 5) {
    display.setTextSize(1);
    if (twistStep == 0) {
      display.setCursor(20, 20); 
      display.println("STEP 1:");
      display.setTextSize(2); 
      display.setCursor(20, 35); 
      display.println("PLUG IN");
    } 
    else if (twistStep == 1) {
      display.setTextSize(2); 
      display.setCursor(15, 30); 
      display.println("UNPLUG!");
      display.drawRect(10, 25, 108, 25, WHITE);
    } 
    else if (twistStep == 2) {
      display.setCursor(20, 20); 
      display.println("STEP 2:");
      display.setTextSize(2); 
      display.setCursor(20, 35); 
      display.println("FLIP & IN");
    } 
    else if (twistStep == 3) {
      bool sym = (json.indexOf("SYMMETRIC") > 0);
      display.setCursor(0, 15); 
      display.setTextSize(2);
      display.println(sym ? "PERFECT" : "BAD TWIST");
      display.setTextSize(1);
      display.setCursor(0, 40);
      display.println(sym ? "Symmetric connection" : "Check CC/Data pins!");
    }
  }


  display.display();
}


String test(int mode) {
  String output = "{";
  size_t count = 6;
  bool anyConnection = false;
  bool hasData = false, hasCC = false, hasVBUS = false;

  for (int i = 0; i < count; i++) {
    digitalWrite(outs[i], HIGH); delayMicroseconds(50);
    if (digitalRead(ins[i]) == HIGH) anyConnection = true;
    digitalWrite(outs[i], LOW);
  }


  for (int i = 0; i < count; i++) {
    for (int k = 0; k < count; k++) { pinMode(ins[k], OUTPUT); digitalWrite(ins[k], LOW); }
    delay(2);
    for (int k = 0; k < count; k++) { pinMode(ins[k], INPUT_PULLDOWN); }

    digitalWrite(outs[i], HIGH); delay(10);
    bool selfConnected = (digitalRead(ins[i]) == HIGH);

    if (selfConnected) {
      if (pinNames[i] == "VBUS") hasVBUS = true;
      if (pinNames[i] == "CC1" || pinNames[i] == "CC2") hasCC = true;
      if (pinNames[i] == "D_MINUS" || pinNames[i] == "D_PLUS") hasData = true;
    }

    if (mode == 1 || mode == 2) {
      output += "\"" + pinNames[i] + "\": ";
      if (mode == 1) output += (selfConnected ? "true" : "false");
      else {
        output += "[";
        bool first = true;
        for (int j = 0; j < count; j++) {
          if (digitalRead(ins[j]) == HIGH) {
            if (!first) output += ",";
            output += pinNames[j];
            first = false;
          }
        }
        output += "]";
      }
      if (i < count - 1) output += ", ";
    }

    if (mode == 4 && anyConnection) {
      if (selfConnected) successCounts[i]++;
      if (i == count - 1) totalSamples++;
    }

    if (mode == 7 && anyConnection) {
      if (!selfConnected) latchFaults[i] = true;
    }
    digitalWrite(outs[i], LOW);
  }

  if (mode == 3) {
    output += "PWR:" + String(hasVBUS?"OK":"NO") + ", CC:" + String(hasCC?"OK":"NO") + ", DATA:" + String(hasData?"OK":"NO");
  }
  if (mode == 4) {
    for (int i = 0; i < count; i++) {
      float pct = (totalSamples > 0) ? (successCounts[i] * 100.0 / totalSamples) : 0;
      output += pinNames[i] + ":" + String(pct, 0) + "% ";
    }
  }


  if (mode == 5) { 
    if (twistStep == 0 && anyConnection) { 
      for(int i=0; i<6; i++) { 
        digitalWrite(outs[i], HIGH); 
        delay(5); 
        sideA[i] = (digitalRead(ins[i]) == HIGH); 
        digitalWrite(outs[i], LOW); 
        } 
        twistStep=1; 
      }
    else if (twistStep == 1 && !anyConnection) twistStep = 2;
    else if (twistStep == 2 && anyConnection) { 
      for(int i=0; i<6; i++) { 
        digitalWrite(outs[i], HIGH); 
        delay(5); 
        sideB[i] = (digitalRead(ins[i]) == HIGH); 
        digitalWrite(outs[i], LOW); 
          } 
        twistStep=3; 
        promptTime = millis(); 
        }
    else if (twistStep == 3) { 
      bool sym = true; 
      for(int i=0; i<6; i++) if(sideA[i]!=sideB[i]) sym=false;
      output += "\"final\": \"" + String(sym ? "SYMMETRIC" : "ASYMMETRIC") + "\"";
      if(millis() - promptTime > 5000) twistStep=0;
    }
  }

  
  if (mode == 6) {
    for(int i=0; i<count; i++) { 
      digitalWrite(outs[i], HIGH); delay(10); 
      output += pinNames[i] + ":" + String(analogRead(ins[i])); 
      digitalWrite(outs[i], LOW); if(i<count-1) output+=",";
    }
  }
  if (mode == 7) {
    for(int i=0; i<count; i++) { output += pinNames[i] + ":" + (latchFaults[i]?"FAIL":"OK") + " "; }
    if (!anyConnection) for(int i=0; i<6; i++) latchFaults[i] = false;
  }
  if (mode == 8) {
    bool noise = false;
    for(int i=0; i<count; i++) { digitalWrite(outs[i], HIGH); for(int j=0; j<count; j++) if(i!=j && digitalRead(ins[j])==HIGH) noise=true; digitalWrite(outs[i], LOW); }
    output += "Shielding:" + String(noise ? "BAD" : "OK");
  }
  if (mode == 9) {
    if (!anyConnection) output += "ID:NONE";
    else if (hasVBUS && hasCC && hasData) output += "ID:PD_FULL";
    else if (hasVBUS && hasData) output += "ID:USB2_DATA";
    else if (hasVBUS) output += "ID:POWER_ONLY";
    else output += "ID:ERROR";
  }

  output += "}";
  return output;
}
