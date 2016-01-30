String Input = "";
String Amp = "";
String Output = "";
int Length = 0;

/*
 * Goal: Store users input in input, and then say
 * Amp = Input; -
 * After we run that, we can make modofacations to Amp,
 * and after we do that, say
 * Output = Amp;
 * Serial.println(Output);
 */

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (true) {
    if (Serial) {
      break;
    }
  }
  while (true) {
    if (Serial.available() > 0) {
      Input = Serial.readString();
      Amp = Input;
      Amp.trim();
      char UsersInput[120];
      memset(UsersInput, 0, sizeof(UsersInput));
      Amp.toCharArray(UsersInput, 120);
      Length = Amp.length();
      for (int i = Length - 1; i >= 1; i--) {
        // So the character we want to process is UsersInput[i]
        UsersInput[i + i] = UsersInput[i];
        UsersInput[i + i - 1] = '-';
        Serial.print(UsersInput[i + i]);

        Serial.print(UsersInput[i + i - 1]);
      }
      Serial.println(UsersInput[0]);
      Output = String(UsersInput);
      char OutputVal[120];
      memset(OutputVal, 0, sizeof(OutputVal));
      Output.toCharArray(OutputVal, 120);
      Length = Output.length();
      for (int i = 0; i < Length; i++) {
        if (i < Length - 1) {
          if (OutputVal[i] != '-') {
            Serial.print(OutputVal[i], BIN);
          } else if (OutputVal[i] == '-') {
            Serial.print(OutputVal[i]);
          }
        } else if (i == Length - 1) {
          if (OutputVal[i] != '-') {
            Serial.println(OutputVal[i], BIN);
          }
        }
      }
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
