#include <MIDI.h> //MIDIライブラリ使用のためのヘッダファイル読み込み

// MIDIメッセージ送受信の方法についての簡単なチュートリアル
// チャンネル4にメッセージが入ってきたら、1秒間ArduinoのLEDが点灯し、その間ノートが再生される。
int var = 0;
MIDI_CREATE_DEFAULT_INSTANCE(); // MIDIクラスのインスタンスとして"MIDI"を生成する。

#define LED 13              // Arduino Uno用のLEDピンの設定

void setup()
{
    pinMode(LED, OUTPUT);
    pinMode(7,INPUT);
    MIDI.begin(4);          // MIDIインスタンスの初期化、その際チャンネル4のみをlisten
}

void loop()
{
      var = digitalRead(7);
      if(var == HIGH){
        digitalWrite(LED,HIGH);
        MIDI.sendNoteOn(42,127,1);
      }else{
        MIDI.sendNoteOff(42,0,1);   // ノートオフ
        digitalWrite(LED,LOW);
      }
      
        // ノートオン(pitch 42, velo 127 on channel 1)
      
  
}