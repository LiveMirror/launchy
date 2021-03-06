/*
Launchy: Application Launcher
Copyright (C) 2005  Josh Karlin

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#include "StdAfx.h"
#include "ExeLauncher.h"
#include <shellapi.h>
#include "FileRecord.h"

ExeLauncher::ExeLauncher(void)
{
}

ExeLauncher::~ExeLauncher(void)
{
}

void ExeLauncher::Run(FileRecordPtr file, CString  args)
{
//	HINSTANCE res =	ShellExecuteEx(NULL, _T("open"),file.fullPath, _T(""), _T(""), SW_SHOW);
//	CString str;
//	str.Format(_T("%d"),(int) res);
//	AfxMessageBox(str);

	CString exec = file->fullPath;
	if (exec.Find(_T(".directory")) != -1) {
		exec = exec.Left(exec.Find(_T(".directory")));
	}



	SHELLEXECUTEINFO ShExecInfo;

	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = NULL;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = exec;
	if (args != L"") {
		ShExecInfo.lpParameters = args;
	} else {
		ShExecInfo.lpParameters = NULL;
	}
	ShExecInfo.lpDirectory = file->GetDirectory();
	ShExecInfo.nShow = SW_NORMAL;
	ShExecInfo.hInstApp = NULL;

	BOOL ret = ShellExecuteEx(&ShExecInfo);

	
}

void ExeLauncher::Run(CString path)
{
	SHELLEXECUTEINFO ShExecInfo;

	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = NULL;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = path;
	ShExecInfo.lpParameters = NULL;
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_NORMAL;
	ShExecInfo.hInstApp = NULL;

	BOOL ret = ShellExecuteEx(&ShExecInfo);

	
}
