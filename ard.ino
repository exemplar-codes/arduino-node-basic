void blink(int led = LED_BUILTIN, int time = 200)
{
  digitalWrite(led, HIGH);
  delay(time);
  digitalWrite(led, LOW);
  delay(time);
}

void blinkTogether(int *leds, int numberof, int time = 200)
{
  for (int i = 0; i < numberof; i++)
  {
    digitalWrite(leds[i], HIGH);
  }
  delay(time);

  for (int i = 0; i < numberof; i++)
  {
    digitalWrite(leds[i], LOW);
  }
  delay(time);
}

void blinkInOrder(int *leds, int numberof, int time = 200)
{
  for (int i = 0; i < numberof; i++)
  {
    digitalWrite(leds[i], HIGH);
    delay(time);
    digitalWrite(leds[i], LOW);
    delay(time);
  }
}

void blinkAlternates(int *leds, int numberof, int time = 200)
{
  for (int i = 0; i < numberof; i++)
    digitalWrite(leds[i], i % 2 == 0 ? HIGH : LOW);
  delay(time);

  for (int i = 0; i < numberof; i++)
    digitalWrite(leds[i], i % 2 == 0 ? LOW : HIGH);
  delay(time);
}

bool isON = true;
int count = 0;

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Arduino ON");

  digitalWrite(LED_BUILTIN, isON ? HIGH : LOW);
  digitalWrite(2, isON ? HIGH : LOW);digitalWrite(LED_BUILTIN, isON ? HIGH : LOW);
  digitalWrite(7, isON ? HIGH : LOW);
}

// the loop function runs over and over again forever
void loop()
{
  //  blink(LED_BUILTIN);

  // int leds[] = {2, LED_BUILTIN, 7};

  // blinkAlternates(leds, 3, 200);
  // printf("%i", count);
  // Serial.println(count++);
  // delay(500);
  // blinkInOrder(leds, 3, 200);
  // blinkTogether(leds, 3, 200);

  if (Serial.available())
  {
    String input = Serial.readString();
    if (input.length())
    {
      Serial.print("Received input (from UNO): ");
      Serial.println(input);
      isON = !isON;
      digitalWrite(LED_BUILTIN, isON ? HIGH : LOW);
      digitalWrite(2, isON ? HIGH : LOW);
      digitalWrite(7, isON ? HIGH : LOW);
    }
  }
}
