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
  for (int i = 0; i < LEDS_LENGTH; ++i) {
    pinMode(LEDS[i],OUTPUT);
  }
}

void loop() {
  // onボタンが押されたときの処理(ボタンがONになった瞬間だけ反応)
  int onval = digitalRead(ONBUTTON);
  if((onval == HIGH)&&(old_onval == LOW)){
    ++state;
  }
  // 以前の状態を保持
  old_onval = onval;

  // offボタンを押されたときの処理(ボタンがONになった瞬間だけ反応)
  int offval = digitalRead(OFFBUTTON);
  if((offval == HIGH)&&(old_offval == LOW)){
    --state;
  }
  // 以前の状態を保持
  old_offval = offval;

  
 
  int loopstate = state;
  for(int i = 0;i<5;i++){
    if(loopstate%2 == 1){
      digitalWrite(LEDS[i],HIGH);
    }else{
      digitalWrite(LEDS[i],LOW);
    }
    loopstate = loopstate >> 1;
  }
}