int onval = 0;
int old_onval = 0;
int offval = 0;
int old_offval = 0;
int ONBUTTON = 8;
int OFFBUTTON = 7;
int LED16 = 9;
int LED8 = 10;
int LED4 = 11;
int LED2 = 12;
int LED1 = 13;
int binary[] = {0,0,0,0,0};
int division = 0;
int base = 0;
int state = 0;
int loopstate;
void setup() {
  
  pinMode(ONBUTTON,INPUT);
  pinMode(OFFBUTTON,INPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(LED8,OUTPUT);
  pinMode(LED16,OUTPUT);
}

void loop() {
  onval = digitalRead(ONBUTTON);
  offval = digitalRead(OFFBUTTON);
  if((onval == HIGH)&&(old_onval == LOW)){
    // digitalWrite(LED16,HIGH);
    state = state + 1;
  }
  if((offval == HIGH)&&(old_offval == LOW)){
    // digitalWrite(LED16,LOW);
    state = state - 1;
  }
  // if((onval == HIGH)&&(old_onval == LOW)){
  //   state =state +1;
  // }
  // if((offval == HIGH)&&(old_offval == LOW)){
  //   state =state - 1;
  // }
  
  loopstate = state;
  binary[4] = loopstate % 2;
  if(binary[4]){
    loopstate = loopstate - 1;
  }
  loopstate = loopstate / 2;
  binary[3] = loopstate % 2;
  if(binary[3]){
    loopstate = loopstate - 1;
  }
  loopstate = loopstate / 2;
  binary[2] = loopstate % 2;
  if(binary[2]){
    loopstate = loopstate - 1;
  }
  loopstate = loopstate / 2;
  binary[1] = loopstate % 2;
  if(binary[1]){
    loopstate = loopstate - 1;
  }
  loopstate = loopstate / 2;
  binary[0] = loopstate % 2;
  if(binary[0]){
    loopstate = loopstate - 1;
  }
  loopstate = loopstate / 2;
 
  if(binary[4]){
    digitalWrite(LED1,HIGH);
  }else{
    digitalWrite(LED1,LOW);
  }
  if(binary[3]){
    digitalWrite(LED2,HIGH);
  }else{
    digitalWrite(LED2,LOW);
  }
  if(binary[2]){
    digitalWrite(LED4,HIGH);
  }else{
    digitalWrite(LED4,LOW);
  }
  if(binary[1]){
    digitalWrite(LED8,HIGH);
  }else{
    digitalWrite(LED8,LOW);
  }
  
  if(binary[0]){
    digitalWrite(LED16,HIGH);
  }else{
    digitalWrite(LED16,LOW);
  }
  old_onval = onval;
  old_offval = offval;
}
