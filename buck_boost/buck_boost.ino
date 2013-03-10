#define VOUT 4.0
#define ADC_COUNT (int) (VOUT/5.0*1023.0/5.0)

int duty = 0;
float pgain = 1;
int count = 0;
void setup() {
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(0);
  /*if (count % 0xFFF == 0) {
    Serial.println(val);
    Serial.println(ADC_COUNT);
    Serial.println(duty);
    Serial.println(count);
    Serial.println();
  };*/
  duty += (ADC_COUNT - val) * pgain;
  if (duty < 0)
    duty = 0;
  if (duty > 1023)
    duty = 1023;
  analogWrite(3, duty); 
  count++;
}
