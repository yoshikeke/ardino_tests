 const int LED = 13;
 const int BUTTON = 7;

int val = 0;
int old_val = 0;
int state = 0;

 void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
  pinMode(BUTTON,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(BUTTON);
  if((val == HIGH)&&(old_val == LOW)){
    state = 1 - state;
  }
  old_val = val;
  if(state == 1){
    digitalWrite(LED,HIGH);
  }else{
    digitalWrite(LED,LOW);
  }
  
}
