// Combined Serial Control Tasks (LED, Fan, Buzzer)

String command = "";
int ledState = LOW;
int fanState = LOW;
int buzzerState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT); // LED
  pinMode(6, OUTPUT); // Fan
  pinMode(7, OUTPUT); // Buzzer
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.readStringUntil('\n');
    command.trim();
    command.toLowerCase();

    if (command == "ledon") {
      digitalWrite(5, HIGH);
      ledState = HIGH;
    }
    else if (command == "ledoff") {
      digitalWrite(5, LOW);
      ledState = LOW;
    }
    else if (command == "fanon") {
      digitalWrite(6, HIGH);
      fanState = HIGH;
    }
    else if (command == "fanoff") {
      digitalWrite(6, LOW);
      fanState = LOW;
    }
    else if (command == "buzzeron") {
      digitalWrite(7, HIGH);
      buzzerState = HIGH;
    }
    else if (command == "buzzeroff") {
      digitalWrite(7, LOW);
      buzzerState = LOW;
    }
    else {
      Serial.println("Invalid Command");
    }

    // Print current status of all devices
    Serial.print("Status → LED: ");
    Serial.print(ledState == HIGH ? "ON" : "OFF");
    Serial.print(", FAN: ");
    Serial.print(fanState == HIGH ? "ON" : "OFF");
    Serial.print(", BUZZER: ");
    Serial.println(buzzerState == HIGH ? "ON" : "OFF");
  }
}
