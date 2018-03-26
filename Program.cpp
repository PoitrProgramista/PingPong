//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Program.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TmainWindow *mainWindow;

const int VELOCITY_CAP = 200;
TPoint previousCursorPosition;
int ballVerticalVelocity;
int ballHorizontalVelocity;
bool isColliding = false;
bool isCollidingBack = false;

int sign(int x)
{
        if(x!=0)
                return x/abs(x);
        else
                return 0;
}

int calculateHorizontalPlayerVelocity()
{

        int horizontalVelocity;

       TPoint cursorPosition = Mouse->CursorPos;
       horizontalVelocity = cursorPosition.x - previousCursorPosition.x;

       if(abs(horizontalVelocity) >VELOCITY_CAP)
                horizontalVelocity = sign(horizontalVelocity) * VELOCITY_CAP;

       return horizontalVelocity;
 }

 int calculateVerticalPlayerVelocity()
{
        int verticalVelocity;

       TPoint cursorPosition = Mouse->CursorPos;
       verticalVelocity = cursorPosition.y - previousCursorPosition.y;

       if(abs(verticalVelocity) > VELOCITY_CAP)
                verticalVelocity = sign(verticalVelocity) * VELOCITY_CAP;

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
               player1->Top += verticalVelocity/4;

        int horizontalVelocity = calculateHorizontalPlayerVelocity();
        if(horizontalVelocity > 0 && player1->Left <= background->Left+300 || horizontalVelocity < 0 && player1->Left >= background->Left+50)
                player1->Left += horizontalVelocity/8;

        Mouse->CursorPos = ClientToScreen(TPoint(background->Left+background->Width/2 ,background->Top + background->Height/2));
        previousCursorPosition = Mouse->CursorPos;

}
//---------------------------------------------------------------------------

void __fastcall TmainWindow::FormCreate(TObject *Sender)
{
        player1Movement->Enabled=false;
        ballMovement->Enabled = false;
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
        ballVerticalVelocity = 0;
        ballHorizontalVelocity = 0;
        ball->Visible = true;
        previousCursorPosition = Mouse->CursorPos;
        player1Movement->Enabled =true;
         ballMovement->Enabled = true;
}
//---------------------------------------------------------------------------




void __fastcall TmainWindow::ballMovementTimer(TObject *Sender)
{
       float horizontalFrictionMultipler;
       float verticalFrictionMultipler;

       if(abs(ballHorizontalVelocity) > 100 )
                horizontalFrictionMultipler = 0.9f ;
       else
                horizontalFrictionMultipler = 1.0f ;

       if(abs(ballVerticalVelocity) > 100 )
                verticalFrictionMultipler = 0.9f ;
       else
                verticalFrictionMultipler = 1.0f ;


        if(ball->Left <= background->Left+5)
                {
                        player1Movement->Enabled=false;
                        ballMovement->Enabled = false;
                        player1->Visible = false;
                        ball->Visible = false;
                        information->Caption = "as";
                        information->Visible = true;
                }

        if(ball->Left <= player1->Left+player1->Width && ball->Left > player1->Left
                &&  ball->Top <= player1->Top + player1->Height && ball->Top+ball->Height >= player1->Top)
        {
                  int verticalVelocity = calculateVerticalPlayerVelocity();
                  int horizontalVelocity = calculateHorizontalPlayerVelocity();

                  ballVerticalVelocity  += verticalVelocity;
                  ballHorizontalVelocity = (abs(ballHorizontalVelocity) +horizontalVelocity);
        }

        if(ball->Top <= background->Top +5 || ball->Top+ball->Height >= background->Height - 5)
                {
                      if(isColliding == false)
                      {
                         ballVerticalVelocity  = -ballVerticalVelocity * verticalFrictionMultipler;
                         ballHorizontalVelocity = ballHorizontalVelocity * horizontalFrictionMultipler;
                      }
                         isColliding = true;
                }
        else
            isColliding = false;


        if(ball->Left+ball->Width >= background->Width)
        {
             if(isCollidingBack == false)
                      {
                         ballVerticalVelocity  = ballVerticalVelocity * verticalFrictionMultipler;
                         ballHorizontalVelocity = -ballHorizontalVelocity * horizontalFrictionMultipler;
                      }
                         isCollidingBack = true;
        }
        else      
                isCollidingBack = false;

        const int BALL_VELOCITY_CAP = 600;

        if(ballHorizontalVelocity > BALL_VELOCITY_CAP)
                ballHorizontalVelocity = BALL_VELOCITY_CAP;

          if(ballVerticalVelocity > BALL_VELOCITY_CAP)
                ballVerticalVelocity = BALL_VELOCITY_CAP;

        ball->Left += ballHorizontalVelocity/20;
        ball->Top  += ballVerticalVelocity/20;
}
//---------------------------------------------------------------------------

void __fastcall TmainWindow::Player2MovementTimer(TObject *Sender)
{
        ;        
}
//---------------------------------------------------------------------------

