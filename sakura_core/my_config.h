#ifndef MY_CONFIG_H
#define MY_CONFIG_H

// 2016.7.28, 2.1.1.4(r3825)�x�[�X
// 2016.7.29, 2.2.0.1(r4011)�x�[�X

/* --------------------------------------------------------------------------
�Ή��A�C������������.

~~#1. 2015.6.1 �� [fix] 2015.6.1~~
 �������A�I�����Ă��镶���񂪂������ꍇ�ɐ��K�\���Ƀ`�F�b�N�������Ă�����
 ���K�\���Ŏg�p����L���������I�ɃN�H�[�g����.
 PHP�� preg_quote �݂����Ȃ���.

#2. 2015.6.2
 ���������񂪂���s�ԍ��̐F��ύX������.

#3. 2015.6.5
 bug?, �P����폜����ہA��u�I����ԂɂȂ�

#4. 2015.6.5 �� [pre fix] 2015.8.4
 bug, �J�[�\���ړ������Ƃ��Ɉړ��O�̏�Ԃ���u�c��
 \view\CEditView_Scroll.cpp:void CEditView::ScrollDraw() �����₵��?
 ScrollWindowEx() �ōs����X�V���Ȃ�Ƃ�����΂���?

~~#5. 2015.6.5 �� [fix] 2015.8.24~~
 Grep�Ώۂ̃t�H���_�̕����w��.

#6. 2015.6.8
 �ŋߎg�����t�@�C���̐���. ���݂��Ȃ��t�@�C���̍��ڂ�r��.

#7. 2015.6.9 �� [pending]
 �f�t�H���g�̐��K�\�����C�u�������g�p����.
 �� re2 http://naoyat.hatenablog.jp/entry/2012/01/12/220812  
 �� SRELL http://www.akenotsuki.com/misc/srell/  

#8. 2015.6.9
 �E�B���h�E�ꗗ, DEL�ŃE�B���h�E�����.
 \window\CTabWnd.cpp : CTabWnd::TabListMenu : TrackPopupMenu()
 �� ���łɃp�b�`���� [patchunicode:#1072] �E�B���h�E�ꗗ�_�C�A���O 

~~#9. 2015.6.10 �� [fix] 2015.6.10~~
 �X�e�[�^�X�o�[�Ƀ^�C�v����\��.
 \window\CMainStatusBar.cpp : CMainStatusBar::CreateStatusBar()
 \apiwrap\CommonControl.h : ApiWrap::StatusBar_SetParts
 \window\CEditWnd.cpp : CEditWnd::OnSize2 : nStArr �J�����T�C�Y

#10. 2015.6.11
 ini�����W�X�g���ɂ���.

#11. 2015.6.30
 �R�����g���̌���������̓R�����g�F�̉e�����󂯂�.

#12. 2015.7.2
 �J���Ă���^�u�̃t�@�C�������R�s�[.

#13. 2015.7.30
 bug 2.2.0.1, �^�u��؂�ւ�������GDI�I�u�W�F�N�g��3?������
 bug 2.2.0.1, �^�u�̐؂�ւ������Ă���ƃt�H���g�����������Ȃ�H�t�H���g�����Ɏ��s���Ă���悤 VS2015
 bug 2.2.0.1, �Ƃ��ǂ���ʂ̕��������ׂď����邱�Ƃ�����A�f���ł����l�̕񍐂���
              http://sakura-editor.sourceforge.net/cgi-bin/cyclamen/cyclamen.cgi?log=data&tree=r8042
              ���Ԃ�A�n���h������ (NULL��������Ƃ�)�̏����ɂ��f�O���[�h�ł͂Ȃ���?
 �� ���̂Ƃ�����Ȃ� 20160801

#14. 2015.8.4
 �^�X�N�o�[�A�C�R���̂����
 \window\CTabWnd.cpp:CTabWnd::ShowHideWindow()
 SendMessageTimeout() �� TabWnd_ActivateFrameWindow() �̊֌W

#15. 2015.8.19
 TCHAR �� std::basic_string<TCHAR> �ɒu��������  
 ��`�� typedef std::basic_string<TCHAR> _tstring; �Ƃ���  

#16. 2015.8.25
 �^�u��؂�ւ����ہA�^�u���N���b�N�����ʒu�Ƃ͕ʂ̈ʒu�ɃX�N���[������̂𒼂�����
 LRESULT CTabWnd::OnTabLButtonUp( WPARAM wParam, LPARAM lParam )
 void CTabWnd::ShowHideWindow( HWND hwnd, BOOL bDisp )
 void CTabWnd::AdjustWindowPlacement( void )
 void CTabWnd::LayoutTab( void )
 2001�N12��: TM SOFT(http://tm-soft.seesaa.net/archives/20011218-1.html)
 TabCtrl_GetItemRect()

~~#17. 2015.11.23 �� [fix] 2016.8.4~~
 �u���̂Ƃ��A�u����{�b�N�X�ɒu���O�̃e�L�X�g������  

#18. 2016.12.13 �� 
 �e�_�C�A���O�{�b�N�X�̈ʒu���f�X�N�g�b�v�̒����ł͂Ȃ�  
 �Ăяo�����E�B���h�E�̒����A�܂��͍���ɔz�u����  

-------------------------------------------------------------------------- */

//-------------------------------------------------------------------------
// �f�o�b�O�p
//-------------------------------------------------------------------------

// �f�o�b�O�o�� 2015.3.24  
#define REI_OUTPUT_DEBUG_STRING 0


//-------------------------------------------------------------------------
// ����
//-------------------------------------------------------------------------

// �ő吔��ύX [REG] 2013.10.2, 2016.12.13  
// (SearchKeyMax:16)
// (ReplaceKeyMax:16)
// (GrepFileMax:8)
// (GrepFolderMax:16)
// \sakura_core\config\maxdata.h
#define REI_CHG_MAXDATA 1


//-------------------------------------------------------------------------
// �t�@�C��
//-------------------------------------------------------------------------

// �J����Ă���t�@�C�������ȊǗ�����O��ő��d�I�[�v���̋��� 2013.6.19  
//  - Shift�������Ȃ���t�@�C���h���b�v�ő��d�I�[�v��  
#define REI_MULTIPLE_OPEN_FILES 1


//-------------------------------------------------------------------------
// �s�ԍ�
//-------------------------------------------------------------------------

// �s�ԍ��\���̕ύX [REG] 2012.9.6, 2015.6.9  
// (LineNrMod:0)
// �ŏ㕔�s�E�ŏI�s�E10�s�����ɐ��l�A1�E5�s�����Ɏw�蕶���iBorland IDE like�j  
//   101  
//     �  
//     �  
//     �  
//     -  
//     �  
//     �  
//     �  
//     �  
//   110  
#define REI_MOD_LINE_NR 1
  #define REI_MOD_LINE_NR_1 L' '//'�' // 1�s�����ɕ\�����镶�� (LineNrModChar1: )
  #define REI_MOD_LINE_NR_5 L'-' // 5�s�����ɕ\�����镶�� (LineNrModChar5:-)
  // 10�s�����ɋ����\�� [REG]  
  // (LineNrMod10Bold:0)
  #define REI_MOD_LINE_NR_10_BOLD 0

// �s�ԍ��̃t�H���g�T�C�Y��ύX���� [REG]
//  - 0: ����
//  (LineNrFontSize:900)
//   https://support.microsoft.com/ja-jp/kb/74299
//   http://d.hatena.ne.jp/itoasuka/20100104/1262585983
#define REI_MOD_LINE_NR_FONT_SIZE_FIX 1100


//-------------------------------------------------------------------------
// �L�����b�g
//-------------------------------------------------------------------------

// �L�����b�g�̕ύX 2012.10.11  
#define REI_MOD_CARET 1
  // 0: �ύX�Ȃ�
  // 1-10: �L�����b�g�T�C�Y
  // 11: 1�o�C�g�R�[�h�̎���1px�A2�o�C�g�R�[�h�̎���2px (Mozilla���ۂ�) [REG]  
  // 12: ���p���͂̎���1px�A�S�p���͂̎���2px 2015.8.26  
  // (CaretType:2)
  #define REI_MOD_CARET_TYPE 2
  // �L�����b�g�ʒu�����ɂ��炷 (�����Əd�Ȃ�Ȃ��悤��, SublimeText���ۂ�) [REG] 2015.8.6  
  // �`��̊֌W��A���[�̎��͂��炳���ɕ\��  
  // IME�̕\���ʒu�����炷  
  // ����A�d�Ȃ��������� Xor���Ă��܂��Ă��邽�ߌ��ɂ���  
  // (CaretShiftLeft:1)
  #define REI_MOD_CARET_SHIFT_LEFT 1

// �J�[�\���ړ����s�[�g���̕��� 1 �ɕύX (default:2) [REG] 2015.8.5  
// (CursorRepeatWidth:1)
#define REI_MOD_LR_CURSOR_REPEAT_WIDTH 1

// �s�𒆉����낦�ɂ��� 2014.3.26 - 2015.7.24  
//  - �f�t�H���g�ł͍s�͏㑵���ɂȂ��Ă���̂ōs�Ԃ͉��ɕt�������  
//  - �L�����b�g���s�Ԋ܂ލ����ɂ���  
#define REI_LINE_CENTERING 1


//-------------------------------------------------------------------------
// �ҏW
//-------------------------------------------------------------------------

// �����X�N���[���̕ύX [REG]  
// (HorisontalScrollMargin:1)
// (HorizontalScrollSize:16)
//  - �X�N���[���J�n�}�[�W���� 1 �ɕύX�B��ʂ̒[�ŃX�N���[���J�n 2014.5.7  
//  - �X�N���[������ 16 �ɐݒ�B��x�ɑ傫���ړ����邱�ƂŌ��₷������ (�����̓������Q��) 2015.9.2  
#define REI_MOD_HORIZONTAL_SCR 16


//-------------------------------------------------------------------------
// �\��
//-------------------------------------------------------------------------

// ���p�󔒕����� "�" ��`�� (SublimeText���ۂ�) 2013.6.2  
//  - REI_MOD_SP_COLOR=3�̂Ƃ��͔w�i��h��Ԃ��ŕ`�� 2016.8.19
#define REI_MOD_HAN_SPACE 1

// �S�p�󔒕���...
#define REI_MOD_ZEN_SPACE 0

// �^�u�����i���j���V(>)�͕\�����Ȃ� (SublimeText���ۂ�) 2015.5.25  
//  - REI_MOD_SP_COLOR=3�̂Ƃ��͔w�i��h��Ԃ��ŕ`��A�u�������v�̂ݑΉ� 2016.8.19
//  - �u�Z�����v�p�~ 2016.8.19
#define REI_MOD_TAB 1

// �J�[�\���s�A���_�[���C���͍��[���� 2015.1.30  
#define REI_CUR_UL_FROM_LEFT_END 1

// �t�H���g���u�l�r �o�S�V�b�N�v����ύX 2015.6.2  
//  - sakura_rc.rc �͐��������̂Œu���őΉ����邱�Ƃɂ���  
#define REI_CHANGE_UI_FONT 1
  #if REI_CHANGE_UI_FONT
    //#define REI_FONT "Meiryo UI"
    //#define REI_FONT_AND_SIZE REI_FONT ", 9"
    //#define REI_CHG_FONT 9, REI_FONT
    #define REI_FONT "MS UI Gothic"
    #define REI_FONT_AND_SIZE REI_FONT ", 10"
    #define REI_CHG_FONT 10, REI_FONT
  #else
    #define REI_FONT "�l�r �o�S�V�b�N"
    #define REI_FONT_AND_SIZE REI_FONT ", 9"
    #define REI_CHG_FONT 9, REI_FONT
  #endif

// �A�E�g���C����̓_�C�A���O�̕ύX 2016.12.14  
//  - �t�H���g�����C���t�H���g�ɂ���
//  - �h�b�L���O���ɃE�B���h�E�J���[���e�L�X�g�ɍ��킹�Ȃ�
// (DockColorSync:0)
#define REI_MOD_OUTLINEDLG 1

// �I��̈�̐F��ύX 2015.6.5  
#define REI_MOD_SELAREA 1
  // �I��̈� �e�L�X�g�̃u�����h�� [REG] 2015.6.5  
  // (SelectAreaTextBlendPer:0)
  //  - �ʏ�A�e�L�X�g�I�����ɑI��F���u�����h����闦  
  #define REI_MOD_SELAREA_TEXT_BLEND_PER 0 /* % */
  
  // �I��̈� �w�i�̃u�����h�� [REG] 2015.6.5  
  // (SelectAreaBackBlendPer:50)
  //  - �ʏ�A�e�L�X�g�I�����ɑI��F���u�����h����闦  
  //  - �e�L�X�g�J���[���}�[���^�������炻�̂܂܂̐F��Ԃ�  
  //  - �e�L�X�g�J���[�̂q������100�ȉ���������u�����g���Ƃ��Ĉ���  
  #define REI_MOD_SELAREA_BACK_BLEND_PER 50 /* % */

// ��TAB,���s�̃J���[��ύX 2015.6.5  
//  - 0: ����  
//  - 1: ���݂̃e�L�X�g�F���u�����g���� 2015.6.5  
//  - 2: ���݂̃e�L�X�g�F�̔��� (��TAB�̃J���[�ݒ�͖�������܂�) 2015.6.8  
//  - 3: ���݂̃e�L�X�g�F�ƌ��݂̔w�i�F���u�����h���� (��TAB�̃J���[�ݒ�͖�������܂�) 2015.6.8  
//       �Ώۂ͋�TAB�ȂǂŁA�R���g���[���R�[�h�ɂ͓K�p����܂���  
#define REI_MOD_SP_COLOR 3
  // ��TAB ���݂̃J���[�̃u�����h�� [REG] 2015.6.5  
  // (WhiteSpaceBlendPer:30)
  #define REI_MOD_SP_BLEND_PER 30 /* % */
//						     
						     

// �J���[�ݒ�̕ύX 2016.6.25  
//  - ��L�A�J���[�ݒ��ύX���Ă�����ȊO�̕ύX  
#define REI_MOD_COLOR_STRATEGY 1

// �R�����g�s�̏C�� 2016.12.27
//  - ���s�ȍ~���J���[��L���ɂ��� [REG]
// (CommentColorWholeLine:1)
#define REI_MOD_COMMENT 1

// �V���O���N�H�[�g�ƃ_�u���N�H�[�g�̃J���[�ݒ�𓝍����� 2016.7.13  
//  - �_�u���N�H�[�e�[�V�����̏����ɓ���  
#define REI_MOD_UNIFY_QUOTE 1

// �܂�Ԃ��L���\�����ɐ܂�Ԃ��ʒu�̐��������Ȃ� [REG] 2016.6.25  
// (NoWrapLine:1)
#define REI_MOD_WRAP_LINE 1

// �X�e�[�^�X�o�[��ύX 2015.6.10  
//  - �^�C�v����\��  
//  - �^�u�T�C�Y��\��  
//  - REC�̐F��Ԃɂ���  
//  - �u�� �s �� ���v���u(��, ��)�v�ɕύX�A���[�ɕ\��  
#define REI_MOD_STATUSBAR 1

// �Ί��ʌ������[�h [REG] 2016.12.21
// (SearchBracketMode:2)
#define REI_MOD_SEARCH_BRACKET_MODE 2

//-------------------------------------------------------------------------
// �@�\
//-------------------------------------------------------------------------

// ���K�\�������̍ہA����������̐��K�\���L�����N�H�[�g���� [REG] 2015.6.1  
// (RegexpAutoQuote:1)
#define REI_MOD_SEARCH_KEY_REGEXP_AUTO_QUOTE 1

// Grep�ύX 2015.8.24  
//  - Grep����t�H���_�̎w��� UI�I�ɑ��₷
//    ���J���}�ŋ�؂��蕪����Ă������������₷�����A�����Ǘ������₷��.
//  - �w��t�H���_�����ׂă`�F�b�N���͂����Ɓu���ݕҏW���̃t�@�C�����猟���v�Ƃ���
//  - �u���ݕҏW���̃t�@�C�����猟���v���`�F�b�N�������̏�Ԃ�ێ����Ȃ��悤�ɂ���
//    ���{���́u���ݕҏW���̃t�@�C�����猟���v���g�p����ƁA
//      �e�����󂯂鑼�̃`�F�b�N�{�b�N�X�̏�Ԃ��ύX�����܂ܖ߂�Ȃ��̂���������.
//  - �t�@�C��(�t�B���^)�w��̓t�H���_�̂��Ƃɒu�� (�t�H���_�̂ق����ύX����@���������)  
//  - �������̃_�C�A���O�𒆉��ɒu���Ȃ��i���A���^�C�����Ɍ��Â炢�j
#define REI_MOD_GREP 1

// �u���ύX [REG] 2016.8.4  
// (ReplaceTextToText:1)
//  - �u���㕶����ɒu���O�������ݒ肷��  
#define REI_MOD_REPLACE 1

// �t�H���_�I���_�C�A���O��ύX [REG] 2015.8.25  
// (SelectDirIFileOperation:1)
//  - CLSID_FileOpenDialog���g�p����  
//    �g�p����ɂ� Vista�ȍ~�ɂ���K�v������  
//      WINVER=0x0500;_WIN32_WINNT=0x0500;_WIN32_IE=0x0501  
//                          ��  
//      WINVER=0x0601;_WIN32_WINNT=0x0601;_WIN32_IE=0x0800  
// [http://eternalwindows.jp/installer/originalinstall/originalinstall02.html]
// [https://msdn.microsoft.com/ja-jp/library/windows/desktop/ff485843(v=vs.85).aspx  ]
#define REI_MOD_SELECTDIR 1

// �_�C���N�g�^�O�W�����v�ꗗ��ύX 2015.8.27  
//  - �\������J�����̑I�ʂƕ��ёւ�  
#define REI_MOD_DIRECTTAGJUMP 1

// �O���R�}���h���s�_�C�A���O��ύX 2016.12.20  
//  - �E�B���h�E�̈ʒu�����܂����ʒu�ɂł�悤�ɂ���
#define REI_MOD_EXECDLG 1

//-------------------------------------------------------------------------
// �C��
//-------------------------------------------------------------------------

// ���l�F�t�� u ul ll 1. 0.f �̌`�ɑΉ� 2015.1.26 - 2015.6.1  
#define REI_FIX_NUMERIC_SUFFIX_COLOR 1

// �����}�[�N�؂�ւ��̍ۂɌ����_�C�A���O�́u���K�\���v���O���̂���� 2015.6.1  
#define REI_FIX_SEARCH_KEEP_REGEXP 1

// �C���N�������^���T�[�`�̍ۂɌ����_�C�A���O�́u���K�\���v�Ƀ`�F�b�N�������܂܂Ȃ̂���� 2016.12.14
#define REI_FIX_ISEARCH_KEEP_REGEXP 1

// �E�F�C�g�J�[�\����ύX 2015.7.9  
//  - �ꕔ�A�������ʒu�ɏC��  
//  - ������폜���ɕ\�����Ȃ��i�A���h�D�̂Ƃ��Ȃǁj  
#define REI_FIX_WAITCUESOR 1

// ���[���[��\�����́u���[���[�ƃe�L�X�g�̌��ԁv�𖳎����� 2016.12.28
#define REI_FIX_RULER_HIDE_IGNORE_BOTTOM_SPACE 1

// �s�ԍ��c�����s�ԍ��̐F�ŕ`��ɕύX 2016.12.21
#define REI_FIX_LINE_TERM_TYPE 1

// �J�[�\���㉺�ړ����Ɏ��̏���?�̂Ƃ��ɉ�ʂ̍X�V���Ԃɍ��킸�ɕ`�悪����� 2015.8.4  
//  - �L�[���s�[�g������  
//  - ���ŕ`���p�ɂɍs���A�v���������Ă���  
// ��UpdateWindow() ���Ăяo�����Ƃňꎞ�Ή�  
#define REI_FIX_CALL_CURSOR_MOVE_UPDATEWINDOW 1

// �J�[�\���ړ����̂�������b��őΏ� 2015.8.4  
//  - �X�N���[���������� ScrollWindowEx() �ƍĕ`��̓������Ƃ�Ă��Ȃ�?  
//  - MacType�Ȃǂ��g�p����ƕ`��̕��ׂ������Ȃ茰���ɂȂ�B�g��Ȃ��ꍇ�͍����ɂ��ƍČ�����  
// ��MoveCursor()�ɏ������܂Ƃ߂Ă��΂炭�l�q�� 2015.8.5  
#define REI_FIX_CURSOR_MOVE_FLICKER 1

// �^�u�E�B���h�E�̏������C�� 2015.8.28  
//  - ���Ȃ��Ă��������������Ƃ��Ȃ��悤�ɂ���  
//  - 1. �͂��߂Đ؂�ւ����^�u�������ɂ���ꍇ�Ƀ^�u�̈ʒu���E�ɃY������ (�Ή���)  
//    2. Refresh()�̏������֌W���Ă���悤��  
//    3. �ǂ���炷�ׂẴE�B���h�E���^�u�R���g���[���������Ă��ă^�u���ύX����邽�тɓ������Ă���悤��  
//       2.�̋������N����̂͂��̂���  
//       ����Ȃ�΃^�u�̈ʒu�𓯊����邱�Ƃ͂ł��Ȃ����H  
#define REI_FIX_TABWND 0


//
//#define USE_SSE2


#include <windows.h>

//------------------------------------------------------------------
//! ���W�X�g���L�[�̓ǂݎ��(DWORD)
//! @param[in] key_name
//! @param[in] defValue
//------------------------------------------------------------------
inline DWORD RegGetDword(LPCTSTR key_name, DWORD defValue) {
  HKEY hKey;
  DWORD dwType = REG_DWORD;  // REG_SZ;
  DWORD dwByte = 4;
  DWORD dwValue;
  LONG rc;

  rc = RegOpenKeyEx(HKEY_CURRENT_USER,        //�e�L�[
                    L"Software\\sakura_rei",  //�T�u�L�[
                    0,                        //��Ƀ[��
                    KEY_ALL_ACCESS,           //�Z�L�����e�B�}�X�N
                    &hKey);                   //�L�[�̃n���h��
  if (rc != ERROR_SUCCESS) {
    return false;
  }
  rc = RegQueryValueEx(hKey,              //�L�[�̃n���h��
                       key_name,          //�ǂݎ��L�[�̖��O
                       NULL,              //��� NULL
                       &dwType,           //�f�[�^�̃^�C�v
                       (BYTE *)&dwValue,  //�󂯎��̈�
                       &dwByte);          //�̈�̃o�C�g��(�󂯎�����o�C�g��)
  RegCloseKey(hKey);
  if (rc != ERROR_SUCCESS) {
    return defValue;
  } else {
    return dwValue;
  }
}

//------------------------------------------------------------------
//! ���W�X�g���L�[�̓ǂݎ��(SZ)
//! @param[in] key_name
//! @param[in] defValue
//------------------------------------------------------------------
inline bool RegGetString(LPCTSTR key_name, char *out) {
  HKEY hKey;
  DWORD dwType;
  DWORD dwByte;
  LONG rc;

  rc = RegOpenKeyEx(HKEY_CURRENT_USER,        //�e�L�[
                    L"Software\\sakura_rei",  //�T�u�L�[
                    0,                        //��Ƀ[��
                    KEY_ALL_ACCESS,           //�Z�L�����e�B�}�X�N
                    &hKey);                   //�L�[�̃n���h��
  if (rc != ERROR_SUCCESS) {
    return false;
  }
  rc = RegQueryValueEx(hKey,                  //�L�[�̃n���h��
                       key_name,              //�ǂݎ��L�[�̖��O
                       NULL,                  //��� NULL
                       &dwType,               //�f�[�^�̃^�C�v
                       NULL,                  //�󂯎��̈�
                       &dwByte);              //�̈�̃o�C�g��(�󂯎�����o�C�g��)
  rc = RegQueryValueEx(hKey,                  //�L�[�̃n���h��
                       key_name,              //�ǂݎ��L�[�̖��O
                       NULL,                  //��� NULL
                       &dwType,               //�f�[�^�̃^�C�v
                       (LPBYTE)(LPCTSTR)out,  //�󂯎��̈�
                       &dwByte);              //�̈�̃o�C�g��(�󂯎�����o�C�g��)
  RegCloseKey(hKey);
  if (rc != ERROR_SUCCESS) {
    return false;
  } else {
    return true;
  }
}

#endif  /* MY_CONFIG_H */