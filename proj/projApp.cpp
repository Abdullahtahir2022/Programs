/***************************************************************
 * Name:      projApp.cpp
 * Purpose:   Code for Application Class
 * Author:    abdullah ()
 * Created:   2019-12-14
 * Copyright: abdullah ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "projApp.h"
#include "projMain.h"

IMPLEMENT_APP(projApp);

bool projApp::OnInit()
{
    
    projDialog* dlg = new projDialog(0L);
    dlg->SetIcon(wxICON(aaaa)); // To Set App Icon
    dlg->Show();
    return true;
}
