#define OutPin 1
#define InPin 0
#define LedPin 13
#define Equip1Pin 5
#define Equip1Pin_ 6
#define Equip1PinS 4                                    
#define Equip2Pin 9
#define Equip2Pin_ 10
#define Equip2PinS 8

boolean ep1, _ep1, ep1s, ep2, _ep2, ep2s, ls;

void setup() 
{ 
  Serial.begin(38400);
  pinMode(OutPin, OUTPUT);
  pinMode(InPin, INPUT);
  pinMode(Equip1Pin, OUTPUT);
  pinMode(Equip1Pin_, OUTPUT);
  pinMode(Equip1PinS, OUTPUT);
  pinMode(Equip2Pin, OUTPUT);
  pinMode(Equip2Pin_, OUTPUT);
  pinMode(Equip2PinS, OUTPUT);
  ep1 = _ep1 = ep1s = false;
  ep2 = _ep2 = ep2s = false;
  ls = false;
  OP();
}

void loop() 
{
  
  if (Serial.available() > 0)
  {
    char command = Serial.read();
    //Serial.print(command);
    Serial.write(command);  // return the recog result msg
    flat(command);
    OP();
    delay(300);
  }
}

/*
* Reflash
*/
void OP()
{
  CT(Equip1Pin, ep1);
  CT(Equip1Pin_, _ep1);
  CT(Equip1PinS, ep1s);
  CT(Equip2Pin, ep2);
  CT(Equip2Pin_, _ep2);
  CT(Equip2PinS, ep2s);
  CT(LedPin, ls);
}

/*
* Set
*/
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
      case 'a': { ep1 = false; break; }
      case 'b': { ep2 = false; break; }
      case '0': { ls = false; ep1s = false; ep2s = false; break; }
      case '1': { ls = true; ep1s = true; ep2s = true; break; }
      case '2': { flash(); break; }
      case 't': { crazy(); break; }
      default: { break; }
    }
}

void crazy()
{
  for (int i=0; i < 10; i++) {
    digitalWrite(Equip1Pin, HIGH);
    digitalWrite(Equip2Pin, LOW);
    delay(200);
    digitalWrite(Equip1Pin, LOW);
    digitalWrite(Equip2Pin, HIGH);
    delay(200);
  }
}

void flash()
{
  for (int i=0; i < 5; i++) {
    digitalWrite(LedPin, LOW);
    delay(100);
    digitalWrite(LedPin, HIGH);
    delay(100);
  }
}
