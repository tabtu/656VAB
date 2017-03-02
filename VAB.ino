#define LedPin 13
#define OutPin 1
#define InPin 0

#define Equip1Pin 3
#define Equip2Pin 5
#define Equip3Pin 6
#define Equip4Pin 9

char lightstate;

void setup() 
{ 
  Serial.begin(9600);
  pinMode(OutPin, OUTPUT);
  pinMode(InPin, INPUT);
  pinMode(LedPin, OUTPUT);
  pinMode(Equip1Pin, OUTPUT);
  pinMode(Equip2Pin, OUTPUT);
  pinMode(Equip3Pin, OUTPUT);
  pinMode(Equip4Pin, OUTPUT);
  lightstate = '0';
}

void loop() 
{
  flat();
} 

void CT(int EpNum, boolean Op)
{
  if (Op == true) {
    digitalWrite(EpNum, HIGH);
  } else {
    digitalWrite(EpNum, LOW);
  }
  delay(300);
}

void flat()
{
  if (Serial.available() > 0)
  {
    lightstate = Serial.read();
    Serial.print(lightstate);
    if (lightstate == '0') {
      CT(LedPin, true);
    } else if(lightstate == '1') {
      CT(LedPin, false);
    } else {
      for (int i=0; i < 7; i++)
      {
        //digitalWrite(LightPin, LOW);
        digitalWrite(LedPin, LOW);
        delay(200);
        //digitalWrite(LightPin, HIGH);
        digitalWrite(LedPin, HIGH);
        delay(200);
      }
    }
  }
}
