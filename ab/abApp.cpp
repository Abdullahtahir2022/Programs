/***************************************************************
 * Name:      abApp.cpp
 * Purpose:   Code for Application Class
 * Author:    abdullah ()
 * Created:   2019-12-14
 * Copyright: abdullah ()
 * License:
 **************************************************************/

#include "abApp.h"

//(*AppHeaders
#include "abMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(abApp);

bool abApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	abFrame* Frame = new abFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
