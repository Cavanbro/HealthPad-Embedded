#include <Adafruit_NeoPixel.h>

#define LED_PIN 23         // Pin connected to the NeoPixel ring
#define LED_COUNT 24       // Number of LEDs in the ring
#define HALL_SENSOR_PIN 15 // GPIO pin connected to the Hall sensor

Adafruit_NeoPixel ring(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// Constants
const unsigned long MILLIS_PER_DAY = 24UL * 60 * 60 * 1000;          // 86,400,000 ms
const unsigned long PILL_TIME_MS = 19UL * 60 * 60 * 1000;            // 7:00 PM = 68,400,000 ms
const unsigned long SCRIPT_START_TIME_MS = (19UL * 60 + 50) * 60 * 1000; // 7:50 PM = 71,400,000 ms

// State
unsigned long bootMillis;
unsigned long todayStartMillis;
bool pillTakenToday = false;

void setup() {
    Serial.begin(115200);
    pinMode(HALL_SENSOR_PIN, INPUT_PULLUP);

    ring.begin();
    ring.setBrightness(30);
    ring.show();

    bootMillis = millis();
    todayStartMillis = bootMillis - SCRIPT_START_TIME_MS; // Treat millis() as 7:50 PM
}

void loop() {
    int hallState = digitalRead(HALL_SENSOR_PIN);
    unsigned long now = millis();
    unsigned long dayMillis = now - todayStartMillis;

    // Reset new simulated day if needed
    if (dayMillis >= MILLIS_PER_DAY) {
        todayStartMillis += MILLIS_PER_DAY;
        pillTakenToday = false;
        Serial.println("🔁 New Day Started");
    }

    // Magnet removed = pill being taken
    if (hallState == HIGH) {
        if (!pillTakenToday && dayMillis >= PILL_TIME_MS) {
            pillTakenToday = true;
            Serial.println("✅ Pill Taken");
        }
        setRingColor(255, 165, 0); // Orange - Taking pill
    }

    // Past pill time, but pill hasn't been taken
    else if (dayMillis >= PILL_TIME_MS && !pillTakenToday) {
        setRingColor(255, 0, 0); // Red - Pill due
        Serial.println("⚠️  Pill Due - Not Yet Taken");
    }

    // Idle state (before pill time or already taken)
    else if (hallState == LOW) {
        // Fixing light is too bright issue by lowering brightness 
        ring.setBrightness(10);
        setRingColor(0, 0, 255); // Blue - Idle
    }

    delay(100);
}

// Helper function to set NeoPixel color
void setRingColor(int r, int g, int b) {
    for (int i = 0; i < LED_COUNT; i++) {
        ring.setPixelColor(i, ring.Color(r, g, b));
    }
    ring.show();
}
