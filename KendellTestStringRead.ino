String InString;

void setup() {
Serial.begin(9600);
}

void loop() {
while (Serial.available() > 0) {
for (int i = 0; i < 50; i++) {
    InString = Serial.readString();
    }
  }
  Serial.print("What you typed is this: ");
  Serial.println(InString);
}
