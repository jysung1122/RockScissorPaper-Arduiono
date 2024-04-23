// C++ code
//
const int ledPins[] = {9, 10, 11};
const int switchPin = 8; // 스위치 핀 번호

void setup()
{
  for(int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT); // 모든 LED 핀을 출력으로 설정
  }
  pinMode(switchPin, INPUT);
  
  // 랜덤 시드 설정
  randomSeed(analogRead(0));

  Serial.begin(9600);
}

void loop()
{
  // 스위치가 ON 인가?
  int sw = digitalRead(switchPin); // 1, 0
  
  // 포텐셔미터 읽기
  int vol = analogRead(A0); // 0 ~ 1023
  vol = map(vol, 0, 1023, 50, 200); // map(value, fromLow, fromHigh, toLow, toHigh)
  
  if(sw == HIGH) {
    for(int i = 0; i < 3; i++) {
      digitalWrite(ledPins[i], HIGH);
      delay(400);
      digitalWrite(ledPins[i], LOW);
    }

    for(int i = 0; i < 3; i++) {
      digitalWrite(ledPins[i], HIGH);
      delay(600);
      digitalWrite(ledPins[i], LOW);
    }

    // 모든 LED를 끔
    for(int i = 0; i < 3; i++) {
      digitalWrite(ledPins[i], LOW);
    }

    delay(500);

    // 랜덤으로 하나의 LED를 켬
    int randomLed = random(0, 3); // 0, 1, 2 중 하나를 랜덤으로 선택
    digitalWrite(ledPins[randomLed], HIGH);
    
    switch(randomLed)
    {
      case 0: for(int i = 0; i < 30; i++) Serial.println(); Serial.println("가위"); break;
      case 1: for(int i = 0; i < 30; i++) Serial.println(); Serial.println("바위"); break;
      case 2: for(int i = 0; i < 30; i++) Serial.println(); Serial.println("보"); break;
    }

    delay(1500);

    // 다시 모든 LED를 끔
    for(int i = 0; i < 3; i++) {
      digitalWrite(ledPins[i], LOW);
    }
  }
  else
  {
    // 스위치가 눌리지 않았을 때의 기본 동작
    digitalWrite(ledPins[0], HIGH);
    delay(vol);
    digitalWrite(ledPins[0], LOW);

    digitalWrite(ledPins[1], HIGH);
    delay(vol);
    digitalWrite(ledPins[1], LOW);

    digitalWrite(ledPins[2], HIGH);
    delay(vol);
    digitalWrite(ledPins[2], LOW);
  }
}

