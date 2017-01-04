#ifndef MY_CONFIG_H
#define MY_CONFIG_H

// 2016.7.28, 2.1.1.4(r3825)ベース
// 2016.7.29, 2.2.0.1(r4011)ベース

/* --------------------------------------------------------------------------
対応、修正したいこと.

~~#1. 2015.6.1 → [fix] 2015.6.1~~
 検索時、選択している文字列があった場合に正規表現にチェックが入っていたら
 正規表現で使用する記号を自動的にクォートする.
 PHPの preg_quote みたいなもの.

#2. 2015.6.2
 検索文字列がある行番号の色を変更したい.

#3. 2015.6.5
 bug?, 単語を削除する際、一瞬選択状態になる

#4. 2015.6.5 → [pre fix] 2015.8.4
 bug, カーソル移動したときに移動前の状態が一瞬残る
 \view\CEditView_Scroll.cpp:void CEditView::ScrollDraw() があやしい?
 ScrollWindowEx() で行われる更新をなんとかすればいい?

~~#5. 2015.6.5 → [fix] 2015.8.24~~
 Grep対象のフォルダの複数指定.

#6. 2015.6.8
 最近使ったファイルの整理. 存在しないファイルの項目を排除.

#7. 2015.6.9 → [pending]
 デフォルトの正規表現ライブラリを使用する.
 → re2 http://naoyat.hatenablog.jp/entry/2012/01/12/220812  
 → SRELL http://www.akenotsuki.com/misc/srell/  

#8. 2015.6.9
 ウィンドウ一覧, DELでウィンドウを閉じる.
 \window\CTabWnd.cpp : CTabWnd::TabListMenu : TrackPopupMenu()
 → すでにパッチあり [patchunicode:#1072] ウィンドウ一覧ダイアログ 

~~#9. 2015.6.10 → [fix] 2015.6.10~~
 ステータスバーにタイプ名を表示.
 \window\CMainStatusBar.cpp : CMainStatusBar::CreateStatusBar()
 \apiwrap\CommonControl.h : ApiWrap::StatusBar_SetParts
 \window\CEditWnd.cpp : CEditWnd::OnSize2 : nStArr カラムサイズ

#10. 2015.6.11
 iniをレジストリにする.

#11. 2015.6.30
 コメント内の検索文字列はコメント色の影響を受ける.

#12. 2015.7.2
 開いているタブのファイル名をコピー.

#13. 2015.7.30
 bug 2.2.0.1, タブを切り替えた時にGDIオブジェクトが3?増える
 bug 2.2.0.1, タブの切り替えをしているとフォントがおかしくなる？フォント生成に失敗しているよう VS2015
 bug 2.2.0.1, ときどき画面の文字がすべて消えることがある、掲示板でも同様の報告あり
              http://sakura-editor.sourceforge.net/cgi-bin/cyclamen/cyclamen.cgi?log=data&tree=r8042
              たぶん、ハンドル操作 (NULLだったらとか)の処理によるデグレードではないか?
 → 今のところ問題なし 20160801

#14. 2015.8.4
 タスクバーアイコンのちらつき
 \window\CTabWnd.cpp:CTabWnd::ShowHideWindow()
 SendMessageTimeout() と TabWnd_ActivateFrameWindow() の関係

#15. 2015.8.19
 TCHAR を std::basic_string<TCHAR> に置き換える  
 定義を typedef std::basic_string<TCHAR> _tstring; とする  

#16. 2015.8.25
 タブを切り替えた際、タブがクリックした位置とは別の位置にスクロールするのを直したい
 LRESULT CTabWnd::OnTabLButtonUp( WPARAM wParam, LPARAM lParam )
 void CTabWnd::ShowHideWindow( HWND hwnd, BOOL bDisp )
 void CTabWnd::AdjustWindowPlacement( void )
 void CTabWnd::LayoutTab( void )
 2001年12月: TM SOFT(http://tm-soft.seesaa.net/archives/20011218-1.html)
 TabCtrl_GetItemRect()

~~#17. 2015.11.23 → [fix] 2016.8.4~~
 置換のとき、置換後ボックスに置換前のテキストを入れる  

#18. 2016.12.13 → 
 各ダイアログボックスの位置をデスクトップの中央ではなく  
 呼び出し元ウィンドウの中央、または左上に配置する  

-------------------------------------------------------------------------- */

//-------------------------------------------------------------------------
// デバッグ用
//-------------------------------------------------------------------------

// デバッグ出力 2015.3.24  
#define REI_OUTPUT_DEBUG_STRING 0


//-------------------------------------------------------------------------
// 履歴
//-------------------------------------------------------------------------

// 最大数を変更 [REG] 2013.10.2, 2016.12.13  
// (SearchKeyMax:16)
// (ReplaceKeyMax:16)
// (GrepFileMax:8)
// (GrepFolderMax:16)
// \sakura_core\config\maxdata.h
#define REI_CHG_MAXDATA 1


//-------------------------------------------------------------------------
// ファイル
//-------------------------------------------------------------------------

// 開かれているファイルを自己管理する前提で多重オープンの許可 2013.6.19  
//  - Shiftを押しながらファイルドロップで多重オープン  
#define REI_MULTIPLE_OPEN_FILES 1


//-------------------------------------------------------------------------
// 行番号
//-------------------------------------------------------------------------

// 行番号表示の変更 [REG] 2012.9.6, 2015.6.9  
// (LineNrMod:0)
// 最上部行・最終行・10行おきに数値、1・5行おきに指定文字（Borland IDE like）  
//   101  
//     ･  
//     ･  
//     ･  
//     -  
//     ･  
//     ･  
//     ･  
//     ･  
//   110  
#define REI_MOD_LINE_NR 1
  #define REI_MOD_LINE_NR_1 L' '//'･' // 1行おきに表示する文字 (LineNrModChar1: )
  #define REI_MOD_LINE_NR_5 L'-' // 5行おきに表示する文字 (LineNrModChar5:-)
  // 10行おきに強調表示 [REG]  
  // (LineNrMod10Bold:0)
  #define REI_MOD_LINE_NR_10_BOLD 0

// 行番号のフォントサイズを変更する [REG]
//  - 0: 無効
//  (LineNrFontSize:900)
//   https://support.microsoft.com/ja-jp/kb/74299
//   http://d.hatena.ne.jp/itoasuka/20100104/1262585983
#define REI_MOD_LINE_NR_FONT_SIZE_FIX 1100


//-------------------------------------------------------------------------
// キャレット
//-------------------------------------------------------------------------

// キャレットの変更 2012.10.11  
#define REI_MOD_CARET 1
  // 0: 変更なし
  // 1-10: キャレットサイズ
  // 11: 1バイトコードの時は1px、2バイトコードの時は2px (Mozillaっぽく) [REG]  
  // 12: 半角入力の時は1px、全角入力の時は2px 2015.8.26  
  // (CaretType:2)
  #define REI_MOD_CARET_TYPE 2
  // キャレット位置を左にずらす (文字と重ならないように, SublimeTextっぽく) [REG] 2015.8.6  
  // 描画の関係上、左端の時はずらさずに表示  
  // IMEの表示位置もずらす  
  // 現状、重なった文字と Xorしてしまっているため見にくい  
  // (CaretShiftLeft:1)
  #define REI_MOD_CARET_SHIFT_LEFT 1

// カーソル移動リピート時の幅を 1 に変更 (default:2) [REG] 2015.8.5  
// (CursorRepeatWidth:1)
#define REI_MOD_LR_CURSOR_REPEAT_WIDTH 1

// 行を中央ぞろえにする 2014.3.26 - 2015.7.24  
//  - デフォルトでは行は上揃えになっているので行間は下に付加される  
//  - キャレットを行間含む高さにする  
#define REI_LINE_CENTERING 1


//-------------------------------------------------------------------------
// 編集
//-------------------------------------------------------------------------

// 水平スクロールの変更 [REG]  
// (HorisontalScrollMargin:1)
// (HorizontalScrollSize:16)
//  - スクロール開始マージンを 1 に変更。画面の端でスクロール開始 2014.5.7  
//  - スクロール幅を 16 に設定。一度に大きく移動することで見やすくする (動きはメモ帳参照) 2015.9.2  
#define REI_MOD_HORIZONTAL_SCR 16


//-------------------------------------------------------------------------
// 表示
//-------------------------------------------------------------------------

// 半角空白文字に "･" を描画 (SublimeTextっぽく) 2013.6.2  
//  - REI_MOD_SP_COLOR=3のときは背景を塗りつぶしで描画 2016.8.19
#define REI_MOD_HAN_SPACE 1

// 全角空白文字...
#define REI_MOD_ZEN_SPACE 0

// タブ文字（矢印）の鏃(>)は表示しない (SublimeTextっぽく) 2015.5.25  
//  - REI_MOD_SP_COLOR=3のときは背景を塗りつぶしで描画、「長い矢印」のみ対応 2016.8.19
//  - 「短い矢印」廃止 2016.8.19
#define REI_MOD_TAB 1

// カーソル行アンダーラインは左端から 2015.1.30  
#define REI_CUR_UL_FROM_LEFT_END 1

// フォントを「ＭＳ Ｐゴシック」から変更 2015.6.2  
//  - sakura_rc.rc は数が多いので置換で対応することにした  
#define REI_CHANGE_UI_FONT 1
  #if REI_CHANGE_UI_FONT
    //#define REI_FONT "Meiryo UI"
    //#define REI_FONT_AND_SIZE REI_FONT ", 9"
    //#define REI_CHG_FONT 9, REI_FONT
    #define REI_FONT "MS UI Gothic"
    #define REI_FONT_AND_SIZE REI_FONT ", 10"
    #define REI_CHG_FONT 10, REI_FONT
  #else
    #define REI_FONT "ＭＳ Ｐゴシック"
    #define REI_FONT_AND_SIZE REI_FONT ", 9"
    #define REI_CHG_FONT 9, REI_FONT
  #endif

// アウトライン解析ダイアログの変更 2016.12.14  
//  - フォントをメインフォントにする
//  - ドッキング時にウィンドウカラーをテキストに合わせない
// (DockColorSync:0)
#define REI_MOD_OUTLINEDLG 1

// 選択領域の色を変更 2015.6.5  
#define REI_MOD_SELAREA 1
  // 選択領域 テキストのブレンド率 [REG] 2015.6.5  
  // (SelectAreaTextBlendPer:0)
  //  - 通常、テキスト選択時に選択色がブレンドされる率  
  #define REI_MOD_SELAREA_TEXT_BLEND_PER 0 /* % */
  
  // 選択領域 背景のブレンド率 [REG] 2015.6.5  
  // (SelectAreaBackBlendPer:50)
  //  - 通常、テキスト選択時に選択色がブレンドされる率  
  //  - テキストカラーがマゼンタだったらそのままの色を返す  
  //  - テキストカラーのＲ成分が100以下だったらブレント率として扱う  
  #define REI_MOD_SELAREA_BACK_BLEND_PER 50 /* % */

// 空白TAB,改行のカラーを変更 2015.6.5  
//  - 0: 無効  
//  - 1: 現在のテキスト色をブレントする 2015.6.5  
//  - 2: 現在のテキスト色の半分 (空白TABのカラー設定は無視されます) 2015.6.8  
//  - 3: 現在のテキスト色と現在の背景色をブレンドする (空白TABのカラー設定は無視されます) 2015.6.8  
//       対象は空白TABなどで、コントロールコードには適用されません  
#define REI_MOD_SP_COLOR 3
  // 空白TAB 現在のカラーのブレンド率 [REG] 2015.6.5  
  // (WhiteSpaceBlendPer:30)
  #define REI_MOD_SP_BLEND_PER 30 /* % */
//						     
						     

// カラー設定の変更 2016.6.25  
//  - 上記、カラー設定を変更している個所以外の変更  
#define REI_MOD_COLOR_STRATEGY 1

// コメント行の修正 2016.12.27
//  - 改行以降もカラーを有効にする [REG]
// (CommentColorWholeLine:1)
#define REI_MOD_COMMENT 1

// シングルクォートとダブルクォートのカラー設定を統合する 2016.7.13  
//  - ダブルクォーテーションの処理に統合  
#define REI_MOD_UNIFY_QUOTE 1

// 折り返し記号表示時に折り返し位置の線を引かない [REG] 2016.6.25  
// (NoWrapLine:1)
#define REI_MOD_WRAP_LINE 1

// ステータスバーを変更 2015.6.10  
//  - タイプ名を表示  
//  - タブサイズを表示  
//  - RECの色を赤にする  
//  - 「○ 行 ○ 桁」→「(○, ○)」に変更、左端に表示  
#define REI_MOD_STATUSBAR 1

// 対括弧検索モード [REG] 2016.12.21
// (SearchBracketMode:2)
#define REI_MOD_SEARCH_BRACKET_MODE 2

//-------------------------------------------------------------------------
// 機能
//-------------------------------------------------------------------------

// 正規表現検索の際、検索文字列の正規表現記号をクォートする [REG] 2015.6.1  
// (RegexpAutoQuote:1)
#define REI_MOD_SEARCH_KEY_REGEXP_AUTO_QUOTE 1

// Grep変更 2015.8.24  
//  - Grepするフォルダの指定を UI的に増やす
//    →カンマで区切るより分かれていた方が扱いやすいし、履歴管理もしやすい.
//  - 指定フォルダをすべてチェックをはずすと「現在編集中のファイルから検索」とする
//  - 「現在編集中のファイルから検索」をチェックした時の状態を保持しないようにする
//    →本来の「現在編集中のファイルから検索」を使用すると、
//      影響を受ける他のチェックボックスの状態が変更したまま戻らないのが嫌だから.
//  - ファイル(フィルタ)指定はフォルダのあとに置く (フォルダのほうが変更する機会が多いため)  
//  - 検索中のダイアログを中央に置かない（リアルタイム時に見づらい）
#define REI_MOD_GREP 1

// 置換変更 [REG] 2016.8.4  
// (ReplaceTextToText:1)
//  - 置換後文字列に置換前文字列を設定する  
#define REI_MOD_REPLACE 1

// フォルダ選択ダイアログを変更 [REG] 2015.8.25  
// (SelectDirIFileOperation:1)
//  - CLSID_FileOpenDialogを使用する  
//    使用するには Vista以降にする必要がある  
//      WINVER=0x0500;_WIN32_WINNT=0x0500;_WIN32_IE=0x0501  
//                          ↓  
//      WINVER=0x0601;_WIN32_WINNT=0x0601;_WIN32_IE=0x0800  
// [http://eternalwindows.jp/installer/originalinstall/originalinstall02.html]
// [https://msdn.microsoft.com/ja-jp/library/windows/desktop/ff485843(v=vs.85).aspx  ]
#define REI_MOD_SELECTDIR 1

// ダイレクトタグジャンプ一覧を変更 2015.8.27  
//  - 表示するカラムの選別と並び替え  
#define REI_MOD_DIRECTTAGJUMP 1

// 外部コマンド実行ダイアログを変更 2016.12.20  
//  - ウィンドウの位置が決まった位置にでるようにする
#define REI_MOD_EXECDLG 1

//-------------------------------------------------------------------------
// 修正
//-------------------------------------------------------------------------

// 数値色付け u ul ll 1. 0.f の形に対応 2015.1.26 - 2015.6.1  
#define REI_FIX_NUMERIC_SUFFIX_COLOR 1

// 検索マーク切り替えの際に検索ダイアログの「正規表現」が外れるのを回避 2015.6.1  
#define REI_FIX_SEARCH_KEEP_REGEXP 1

// インクリメンタルサーチの際に検索ダイアログの「正規表現」にチェックがついたままなのを回避 2016.12.14
#define REI_FIX_ISEARCH_KEEP_REGEXP 1

// ウェイトカーソルを変更 2015.7.9  
//  - 一部、正しい位置に修正  
//  - 文字列削除時に表示しない（アンドゥのときなど）  
#define REI_FIX_WAITCUESOR 1

// ルーラー非表示時は「ルーラーとテキストの隙間」を無視する 2016.12.28
#define REI_FIX_RULER_HIDE_IGNORE_BOTTOM_SPACE 1

// 行番号縦線を行番号の色で描画に変更 2016.12.21
#define REI_FIX_LINE_TERM_TYPE 1

// カーソル上下移動時に次の条件?のときに画面の更新が間に合わずに描画が崩れる 2015.8.4  
//  - キーリピートが早い  
//  - 裏で描画を頻繁に行うアプリが動いている  
// →UpdateWindow() を呼び出すことで一時対応  
#define REI_FIX_CALL_CURSOR_MOVE_UPDATEWINDOW 1

// カーソル移動時のちらつきを暫定で対処 2015.8.4  
//  - スクロールした時に ScrollWindowEx() と再描画の同期がとれていない?  
//  - MacTypeなどを使用すると描画の負荷が高くなり顕著になる。使わない場合は高速にやると再現する  
// →MoveCursor()に処理をまとめてしばらく様子見 2015.8.5  
#define REI_FIX_CURSOR_MOVE_FLICKER 1

// タブウィンドウの処理を修正 2015.8.28  
//  - しなくていい処理をちゃんとしないようにする  
//  - 1. はじめて切り替えたタブが左側にある場合にタブの位置が右にズレる問題 (対応中)  
//    2. Refresh()の処理が関係しているようだ  
//    3. どうやらすべてのウィンドウがタブコントロールを持っていてタブが変更されるたびに同期しているようだ  
//       2.の挙動が起こるのはそのせい  
//       それならばタブの位置を同期することはできないか？  
#define REI_FIX_TABWND 0


//
//#define USE_SSE2


#include <windows.h>

//------------------------------------------------------------------
//! レジストリキーの読み取り(DWORD)
//! @param[in] key_name
//! @param[in] defValue
//------------------------------------------------------------------
inline DWORD RegGetDword(LPCTSTR key_name, DWORD defValue) {
  HKEY hKey;
  DWORD dwType = REG_DWORD;  // REG_SZ;
  DWORD dwByte = 4;
  DWORD dwValue;
  LONG rc;

  rc = RegOpenKeyEx(HKEY_CURRENT_USER,        //親キー
                    L"Software\\sakura_rei",  //サブキー
                    0,                        //常にゼロ
                    KEY_ALL_ACCESS,           //セキュリティマスク
                    &hKey);                   //キーのハンドル
  if (rc != ERROR_SUCCESS) {
    return false;
  }
  rc = RegQueryValueEx(hKey,              //キーのハンドル
                       key_name,          //読み取るキーの名前
                       NULL,              //常に NULL
                       &dwType,           //データのタイプ
                       (BYTE *)&dwValue,  //受け取る領域
                       &dwByte);          //領域のバイト数(受け取ったバイト数)
  RegCloseKey(hKey);
  if (rc != ERROR_SUCCESS) {
    return defValue;
  } else {
    return dwValue;
  }
}

//------------------------------------------------------------------
//! レジストリキーの読み取り(SZ)
//! @param[in] key_name
//! @param[in] defValue
//------------------------------------------------------------------
inline bool RegGetString(LPCTSTR key_name, char *out) {
  HKEY hKey;
  DWORD dwType;
  DWORD dwByte;
  LONG rc;

  rc = RegOpenKeyEx(HKEY_CURRENT_USER,        //親キー
                    L"Software\\sakura_rei",  //サブキー
                    0,                        //常にゼロ
                    KEY_ALL_ACCESS,           //セキュリティマスク
                    &hKey);                   //キーのハンドル
  if (rc != ERROR_SUCCESS) {
    return false;
  }
  rc = RegQueryValueEx(hKey,                  //キーのハンドル
                       key_name,              //読み取るキーの名前
                       NULL,                  //常に NULL
                       &dwType,               //データのタイプ
                       NULL,                  //受け取る領域
                       &dwByte);              //領域のバイト数(受け取ったバイト数)
  rc = RegQueryValueEx(hKey,                  //キーのハンドル
                       key_name,              //読み取るキーの名前
                       NULL,                  //常に NULL
                       &dwType,               //データのタイプ
                       (LPBYTE)(LPCTSTR)out,  //受け取る領域
                       &dwByte);              //領域のバイト数(受け取ったバイト数)
  RegCloseKey(hKey);
  if (rc != ERROR_SUCCESS) {
    return false;
  } else {
    return true;
  }
}

#endif  /* MY_CONFIG_H */
