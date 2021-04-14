
/**
 * MHRiseのamiibo福引を無限に引き続けるスケッチ
 *
 * 初期条件は以下の通り
 * 0.時刻設定が自動になっていないこと
 * 1.雑貨屋の前で話しかけるボタンが表示されていること
 * 2.nfc読み込み機能のついたコントローラが接続されていること
 * 3.nfcリーダの上にamiiboが正しく設置されていること
 */
#include <NintendoSwitchControlLibrary.h>

// マイコンのセット時に1度だけ行われる処理
void setup(){
    // コントローラとして認識させるための処理。利用条件下において影響のない十字キー右を採用。削除不可。
    pushHat(Hat::RIGHT, 500, 5);
    // 話しかける
    pushButton(Button::A, 1000);
    // カーソル移動
    pushHat(Hat::DOWN, 100, 4);
}

// 福引実行
void execLottery() {
  // amiibo読み込み
  pushButton(Button::A, 5000);
  // 回して受け取る
  pushButton(Button::A, 50, 11);
}

// 時計変更
void timeFlyer() {
    // ホーム画面 > 設定
    pushButton(Button::HOME, 1000);
    pushHat(Hat::DOWN, 25);
    pushHat(Hat::RIGHT, 25, 5);
    pushButton(Button::A, 100);
    // 設定 > 本体 > 日付と時刻
    holdHat(Hat::DOWN, 2000);
    pushHat(Hat::RIGHT, 25);
    pushHat(Hat::DOWN, 25, 4);
    pushButton(Button::A, 200);
    // 日付と時刻 > 現在の日付と時刻
    pushHat(Hat::DOWN, 25, 2);
    pushButton(Button::A, 500);
    pushHat(Hat::RIGHT, 25);
    pushHat(Hat::UP, 25);
    pushHat(Hat::RIGHT, 25);
    pushHat(Hat::UP, 25);
    pushHat(Hat::RIGHT, 25, 3);
    pushButton(Button::A, 50);
    // ホーム画面 > ゲーム画面
    pushButton(Button::HOME, 1000);
    pushButton(Button::A, 500);
}

// 自動セーブ誘発
void execSaving() {
    // 会話から離脱する
    pushButton(Button::B, 3000);
    // 話しかける
    pushButton(Button::A, 1000);
    // カーソル移動
    pushHat(Hat::DOWN, 100, 4);
}

// ここに記述した内容がループされ続ける
void loop() {
  // 福引実行
  execLottery();

  // 時計変更
  timeFlyer();

  // オートセーブはお好みで。必要であればコメントアウト解除。
  //execSaving();
}
