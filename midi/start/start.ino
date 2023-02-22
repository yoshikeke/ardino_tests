byte noteOn[] = {0x90, 0x60, 0x7f};
byte noteOff[] = {0x90, 0x60, 0x00};

void setup(){
  Serial.begin(31250);
}

void loop(){
  Serial.write(noteOn, sizeof(noteOn));
  delay(1000);
  Serial.write(noteOff, sizeof(noteOn));
  delay(1000);
}
