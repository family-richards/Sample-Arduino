void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
String  input = "";
int i;

if (Serial.available() > 0)
{
  input = Serial.readString();
}

if (input.length() > 0)
{
  for (i = 0; i < input.length(); i++)
  {
    char character = input[i];
    Serial.print("Character at ");
    Serial.print(i);
    Serial.print(" is <");
    Serial.print(character);
    Serial.println(">");
  }
}

delay(100);
}
