#define LedPin 13
#define OutPin 1
#define InPin 0

#define Equip1Pin 3
#define Equip2Pin 5
#define Equip3Pin 6
#define Equip4Pin 9

boolean ep1, ep2, ep3, ep4, ls;

void setup() 
{ 
  Serial.begin(38400);
  pinMode(OutPin, OUTPUT);
  pinMode(InPin, INPUT);
  pinMode(LedPin, OUTPUT);
  pinMode(Equip1Pin, OUTPUT);
  pinMode(Equip2Pin, OUTPUT);
  pinMode(Equip3Pin, OUTPUT);
  pinMode(Equip4Pin, OUTPUT);
  ep1 = false;
  ep2 = false;
  ep3 = false;
  ep4 = false;
  ls = false;
}

void loop() 
{
  
  if (Serial.available() > 0)
  {
    char command = Serial.read();
    Serial.print(command);
    flat(command);
    OP();
    delay(200);
  }
} 

void OP()
{
  CT(Equip1Pin, ep1);
  CT(Equip2Pin, ep2);
  CT(Equip3Pin, ep3);
  CT(Equip4Pin, ep4);
  CT(LedPin, ls);
  delay(200);
}

void CT(int EpNum, boolean Op)
{
  if (Op == true) {
    digitalWrite(EpNum, HIGH);
  } else {
    digitalWrite(EpNum, LOW);
  }
}

void flat(char command)
{
  switch (command) {
      case 'A': { ep1 = true; break; }
      case 'B': { ep2 = true; break; }
      case 'C': { ep3 = true; break; }
      case 'D': { ep4 = true; break; }
      case 'a': { ep1 = false; break; }
      case 'b': { ep2 = false; break; }
      case 'c': { ep3 = false; break; }
      case 'd': { ep4 = false; break; }
      default: { break; }
    }
}
/*
    if (ls == '0') {
      CT(LedPin, true);
    } else if(ls == '1') {
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
    */
