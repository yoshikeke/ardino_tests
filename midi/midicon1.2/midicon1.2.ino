#include <MIDI.h> //MIDIライブラリ使用のためのヘッダファイル読み込み

// MIDIメッセージ送受信の方法についての簡単なチュートリアル
// チャンネル4にメッセージが入ってきたら、1秒間ArduinoのLEDが点灯し、その間ノートが再生される。
int var8 = 0;
int old_var8 = 0;
int var7 = 0;
int old_var7 = 0;
MIDI_CREATE_DEFAULT_INSTANCE(); // MIDIクラスのインスタンスとして"MIDI"を生成する。

#define LED 13              // Arduino Uno用のLEDピンの設定

void setup()
{
    pinMode(LED, OUTPUT);
    pinMode(8,INPUT);
    pinMode(7,INPUT);
    MIDI.begin(4);          // MIDIインスタンスの初期化、その際チャンネル4のみをlisten
}

void loop()
{
      var8 = digitalRead(8);
      if((var8 == HIGH)&&(old_var8 == LOW)){
        digitalWrite(LED,HIGH);
        MIDI.sendNoteOn(48,127,1);
      }
      if(var8 == LOW){
        MIDI.sendNoteOff(48,0,1);   // ノートオフ
        digitalWrite(LED,LOW);
      }
      old_var8 = var8;

      var7 = digitalRead(7);
      if((var7 == HIGH)&&(old_var7 == LOW)){
        digitalWrite(LED,HIGH);
        MIDI.sendNoteOn(50,127,1);
      }
      if(var7 == LOW){
        MIDI.sendNoteOff(50,0,1);   // ノートオフ
        digitalWrite(LED,LOW);
      }
      old_var7 = var7;
      delay(10);
      
        // ノートオン(pitch 42, velo 127 on channel 1)
      
  
}