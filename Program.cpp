//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Program.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TmainWindow *mainWindow;

TPoint previousCursorPosition;

int calculateHorizontalPlayerVelocity()
{
        int horizontalVelocity;

       TPoint cursorPosition = Mouse->CursorPos;
       horizontalVelocity = cursorPosition.x - previousCursorPosition.x;

       return horizontalVelocity;

 }

 int calculateVerticalPlayerVelocity()
{
        int verticalVelocity;

       TPoint cursorPosition = Mouse->CursorPos;
       verticalVelocity = cursorPosition.y - previousCursorPosition.y;

       return verticalVelocity;

 }

//---------------------------------------------------------------------------
__fastcall TmainWindow::TmainWindow(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TmainWindow::player1MovementTimer(TObject *Sender)
{

        int verticalVelocity = calculateVerticalPlayerVelocity();
        if(verticalVelocity < 0 && player1->Top >= background->Top + 5 || verticalVelocity > 0  && player1->Top + player1->Height <= background->Top + background->Height - 5)
               player1->Top += verticalVelocity/6;

        int horizontalVelocity = calculateHorizontalPlayerVelocity();
        if(horizontalVelocity > 0 && player1->Left <= background->Left+250 || horizontalVelocity < 0 && player1->Left >= background->Left+50)
                player1->Left += horizontalVelocity/8;

        Mouse->CursorPos = ClientToScreen(TPoint(background->Left+background->Width/2 ,background->Top + background->Height/2));
        previousCursorPosition = Mouse->CursorPos;

}
//---------------------------------------------------------------------------

void __fastcall TmainWindow::FormCreate(TObject *Sender)
{
        player1Movement->Enabled=false;
        player1->Visible = false;
        ball->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TmainWindow::startGameClick(TObject *Sender)
{
        startGame->Visible =false;
        information->Visible = false;
        mainWindow->Cursor = crNone;
        player1->Visible = true;
        ball->Visible = true;
        previousCursorPosition = Mouse->CursorPos;
        player1Movement->Enabled =true;
}

//---------------------------------------------------------------------------



