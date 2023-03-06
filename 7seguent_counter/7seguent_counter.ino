int LEDS[] = {13, 12, 11, 10, 9, 6, 5};
int LEDS_LENGTH = 7;
int ONBUTTON = 8;
int OFFBUTTON = 7;

int old_onval = 0;
int old_offval = 0;
int state = 0;

int seg[][7] = {{1,1,1,1,1,1,0},{1,1,0,0,0,0,0},{0,1,1,0,1,1,1},{0,0,1,1,1,1,1},{1,0,0,1,1,0,1},{1,0,1,1,0,1,1},{1,1,1,1,0,0,1},{0,0,0,1,1,1,0},{1,1,1,1,1,1,1},{1,0,1,1,1,1,1}};
int seg0[] = {1,1,1,1,1,1,0};

void setup() {
  // put your setup code here, to run once:
  pinMode(ONBUTTON,INPUT);
  pinMode(OFFBUTTON,INPUT);
  for (int i = 0; i < LEDS_LENGTH; ++i) {
    pinMode(LEDS[i],OUTPUT);
  }
}

void lampswitch(int var){  
  for(int i = 0;i < LEDS_LENGTH;++i){
    digitalWrite(LEDS[i],seg[var][i]);
    
  }
}
void loop() {
  
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
  // put your main code here, to run repeatedly:
  lampswitch(state);
}
