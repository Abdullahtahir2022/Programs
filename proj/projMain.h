/***************************************************************
 * Name:      projMain.h
 * Purpose:   Defines Application Frame
 * Author:    abdullah ()
 * Created:   2019-12-14
 * Copyright: abdullah ()
 * License:
 **************************************************************/

#ifndef PROJMAIN_H
#define PROJMAIN_H



#include "projApp.h"



#include "GUIDialog.h"

class projDialog: public GUIDialog
{
    public:
        projDialog(wxDialog *dlg);
        ~projDialog();
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
};
#endif // PROJMAIN_H
