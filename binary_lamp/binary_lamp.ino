// 定数
int ONBUTTON = 8;
int OFFBUTTON = 7;
int LEDS[] = {13, 12, 11, 10, 9};
int LEDS_LENGTH = 5;

// 状態
int old_onval = 0;
int old_offval = 0;
int state = 0;

void setup() {
  pinMode(ONBUTTON,INPUT);
  pinMode(OFFBUTTON,INPUT);
  for (i = 0; i < LEDS_LENGTH; ++i) {
    pinMode(LEDS[i],OUTPUT);
  }
}

void loop() {
  // onボタンが押されたときの処理(ボタンがONになった瞬間だけ反応)
  int onval = digitalRead(ONBUTTON);
  if((onval == HIGH)&&(old_onval == LOW)){
    state = state + 1;
  }
  // 以前の状態を保持
  old_onval = onval;

  // offボタンを押されたときの処理(ボタンがONになった瞬間だけ反応)
  int offval = digitalRead(OFFBUTTON);
  if((offval == HIGH)&&(old_offval == LOW)){
    state = state - 1;
  }
  // 以前の状態を保持
  old_offval = offval;

  // stateをbitに変換して、点灯させる
  int loopstate = state;
  for (i = 0; i < LEDS_LENGTH; ++i) {
    digitalWrite(LEDS[(LEDS_LENGTH - 1) - i], loopstate % 2 ? HIGH : LOW);
    loopstate = loopstate << 1; // bitをshiftする
  }
}
