#pragma once

// テトリス専用パッド処理
namespace Pad
{
	// パッドの入力状態取得
	void update();

	// 押し下げ判定
	bool isPress(int button, int padNo = 0);
	// トリガー判定
	bool isTrigger(int button, int padNo = 0);

	// ログ記録開始、終了
	void startRecordLog();
	void endRecordLog();

	// ログ再生開始、終了
	void startPlayLog();
	void endPlayLog();
}

