//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Program.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TmainWindow *mainWindow;

TPoint previousCursorPosition;

int calculatePlayerVelocity()
{
        int velocity;

       TPoint cursorPosition = Mouse->CursorPos;
       velocity = cursorPosition.y - previousCursorPosition.y;
       previousCursorPosition = cursorPosition;

       return velocity;

 }

//---------------------------------------------------------------------------
__fastcall TmainWindow::TmainWindow(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TmainWindow::player1VerticalTimer(TObject *Sender)
{

        int playerVerticalPosition = player1->Top + player1->Height/2;
        TPoint mousePosition = mainWindow->ScreenToClient(Mouse->CursorPos);
        if(playerVerticalPosition != mousePosition.y)
        {
                if(playerVerticalPosition > mousePosition.y  && player1->Top >= background->Top + 5)
                {
                    player1->Top -= abs(playerVerticalPosition-mousePosition.y)/10;
                }
                else if(playerVerticalPosition < mousePosition.y  && player1->Top + player1->Height <= background->Top + background->Height - 5)
                {
                     player1->Top += abs(playerVerticalPosition-mousePosition.y)/10;
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TmainWindow::FormCreate(TObject *Sender)
{
        player1Vertical->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TmainWindow::startGameClick(TObject *Sender)
{
        player1Vertical->Enabled =true;
        startGame->Visible =false;
        mainWindow->Cursor = crNone;
        previousCursorPosition = Mouse->CursorPos;

}
//---------------------------------------------------------------------------

void __fastcall TmainWindow::player1HorizontalTimer(TObject *Sender)
{
      int playerHorizontalPosition = player1->Left + player1->Width/2;
        TPoint mousePosition = mainWindow->ScreenToClient(Mouse->CursorPos);
        if(playerHorizontalPosition != mousePosition.x)
        {
                if(playerHorizontalPosition > mousePosition.x  && player1->Left >= background->Left + 56)
                {
                    player1->Left -= abs(playerHorizontalPosition-mousePosition.x)/10;
                }
                else if(playerHorizontalPosition < mousePosition.x  && player1->Left + player1->Width <= background->Left + 100)
                {
                     player1->Left += abs(playerHorizontalPosition-mousePosition.x)/10;
                }
        }
}
//---------------------------------------------------------------------------


