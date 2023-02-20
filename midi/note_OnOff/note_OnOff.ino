#include <MIDI.h> //MIDIライブラリ使用のためのヘッダファイル読み込み

// MIDIメッセージ送受信の方法についての簡単なチュートリアル
// チャンネル4にメッセージが入ってきたら、1秒間ArduinoのLEDが点灯し、その間ノートが再生される。

MIDI_CREATE_DEFAULT_INSTANCE(); // MIDIクラスのインスタンスとして"MIDI"を生成する。

#define LED 13              // Arduino Uno用のLEDピンの設定

void setup()
{
    pinMode(LED, OUTPUT);
    MIDI.begin(4);          // MIDIインスタンスの初期化、その際チャンネル4のみをlisten
}

void loop()
{
   
    digitalWrite(LED,HIGH);
    MIDI.sendNoteOn(42,127,1);  // ノートオン(pitch 42, velo 127 on channel 1)
    delay(1000);                // 1秒待機
    MIDI.sendNoteOff(42,0,1);   // ノートオフ
    digitalWrite(LED,LOW);

}