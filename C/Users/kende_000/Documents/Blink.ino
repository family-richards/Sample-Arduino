int LEDPinNum = 13;
int LEDP = LEDPinNum;
void setup() {
pinMode(LEDP, OUTPUT);
}

void loop() {
digatalWrite(LEDP, HIGH);
delay(1000);
digatalWrite(LEDP, LOW);
delay(1000);
}

