/***************************************************************
 * Name:      abMain.h
 * Purpose:   Defines Application Frame
 * Author:    abdullah ()
 * Created:   2019-12-14
 * Copyright: abdullah ()
 * License:
 **************************************************************/

#ifndef ABMAIN_H
#define ABMAIN_H

//(*Headers(abFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class abFrame: public wxFrame
{
    public:

        abFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~abFrame();

    private:

        //(*Handlers(abFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(abFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(abFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ABMAIN_H
