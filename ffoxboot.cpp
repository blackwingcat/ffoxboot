// ffoxboot.cpp : アプリケーション用のエントリ ポイントの定義
//

#include "stdafx.h"
#include <windows.h>
#include <shellapi.h>
bool __fastcall FileExistsW(wchar_t *path){
  WIN32_FIND_DATAW fd;
  HANDLE hSearch;
  bool res=false;
  hSearch=::FindFirstFileW(path,&fd);
  if(hSearch!=INVALID_HANDLE_VALUE){
      FindClose(hSearch);
	res=true;
  }
  return res;
}
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow )
{
 	// TODO: この位置にコードを記述してください。
    wchar_t fn[640];
    ExpandEnvironmentStringsW(L"%SystemDrive%\\Program Files (x86)\\Mozilla Firefox\\firefox.exe",fn,640);
    if(!FileExistsW(fn))
        ExpandEnvironmentStringsW(L"%SystemDrive%\\Program Files\\Mozilla Firefox\\firefox.exe",fn,640);
    HINSTANCE x=ShellExecuteW(NULL,L"open",fn
		,NULL,NULL,SW_SHOW);
	return 0;
}



