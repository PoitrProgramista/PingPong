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
bool isCollidingPlayer1 = false;
bool isCollidingPlayer2 = false;
bool isPractice;
int player2HorizontalVelocity;
int player2VerticalVelocity;
int player1Score;
int player2Score;
int hitCount;

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

        //vertical bounds
        int verticalVelocity = calculateVerticalPlayerVelocity();
        if(verticalVelocity < 0 && player1->Top >= background->Top + 5 || verticalVelocity > 0  && player1->Top + player1->Height <= background->Top + background->Height - 5)
               player1->Top += verticalVelocity/3;
        //horizontal bounds
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
        player2->Visible = false;
        ball->Visible = false;
        player1Score = 0;
        player2Score = 0;
        hitCount = 0;
        AnsiString message =  "Witaj w grze Ping Pong!\n\nLewy gracz steruje za pomoca myszki";
        message += "\nPredkosc poruszania myszki wplywa na predkosc paletki oraz na predkosc odbitej pilki.";
        message +="\nDrugi gracz steruje strzalkami na klawiaturze.";
        message +="\n\nPo kazdym odbiciu od sciany pilka troche zwalnia, ale nigdy do zatrzymania.";
        message +="\nPredkosc paletki dodaje sie do predkosci pilki.";
        ShowMessage(message);
}
//---------------------------------------------------------------------------

void __fastcall TmainWindow::startGameClick(TObject *Sender)
{
        nextRound->Visible =false;
        player1Score = 0;
        player2Score = 0;
        hitCount = 0;
        isPractice = false;
        startGame->Visible =false;
        practice->Visible =false;
        information->Caption = "ESC aby wrocic";
        information->Top = 0;
        information->Left = 0;
        mainWindow->Cursor = crNone;
        player1->Top = background->Height/2-player1->Height/2;
        player1->Left = 24;
        player1->Visible = true;
        player2-> Top = background->Height/2-player2->Height/2;
        player2->Left = background->Width - 24 - player2->Width;
        player2->Visible = true;
        player2->Enabled = true;
        ballVerticalVelocity = 0;
        ballHorizontalVelocity = 0;
        player2HorizontalVelocity = 0;
        player2VerticalVelocity = 0;
        ball->Top = background->Height/2-ball->Height/2;
        ball->Left = 320;
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

        //player1 lose
        if(ball->Left <= background->Left+5)
                {
                        player2Score ++;
                        player1Movement->Enabled=false;
                        ballMovement->Enabled = false;
                        player1->Visible = false;
                        player2->Visible = false;
                        ball->Visible = false;
                        if(isPractice == true)
                                information->Caption = "Ilosc odbic: " + IntToStr(hitCount);
                        else
                                information->Caption = "Punkt dla gracza prawego>\nIlosc odbic: " + IntToStr(hitCount) + "\nWynik: " + IntToStr(player1Score) + ":" +IntToStr(player2Score);

                        information->Top = background->Height/4;
                        information->Left = background->Width/2-information->Width/2;
                        information->Visible = true;
                        
                        if(isPractice == true)
                        {
                                practice->Top = background->Height/2;
                                practice->Left = background->Width/2 - practice->Width/2;
                                practice->Caption = "Jeszcze raz";
                                practice->Visible = true;
                        }
                        else
                        {
                                startGame->Top = background->Height/2 + startGame->Height;
                                startGame->Left = background->Width/2 - practice->Width/2;
                                startGame->Caption = "Od nowa";
                                startGame->Visible = true;
                                nextRound->Top = background->Height/2;
                                nextRound->Left = background->Width/2 - practice->Width/2;
                                nextRound->Visible = true;
                        }
                        
                        mainWindow->Cursor = crArrow;
                }
                
        //collision with palyer1
        if(ball->Left <= player1->Left+player1->Width && ball->Left > player1->Left
                &&  ball->Top <= player1->Top + player1->Height && ball->Top+ball->Height >= player1->Top)
        {
                  int verticalVelocity = calculateVerticalPlayerVelocity();
                  int horizontalVelocity = calculateHorizontalPlayerVelocity();

                  ballVerticalVelocity  += verticalVelocity;
                  ballHorizontalVelocity = (abs(ballHorizontalVelocity) +horizontalVelocity);
                  if(isCollidingPlayer1 == false)
                        hitCount++;
                        
                  isCollidingPlayer1 =true;
        }
        else
                isCollidingPlayer1 = false;

        //collision with palyer2
        if(ball->Left + ball->Width >= player2->Left && ball->Left + ball->Width < player2->Left + player2->Width
                &&  ball->Top <= player2->Top + player2->Height && ball->Top+ball->Height >= player2->Top)
        {
                if(isCollidingPlayer2 == false)
                {
                  ballHorizontalVelocity = 5*player2HorizontalVelocity - ballHorizontalVelocity;
                  ballVerticalVelocity +=  5*player2VerticalVelocity;
                  hitCount++;

                }
                  isCollidingPlayer2 = true;
        }
        else
                isCollidingPlayer2 = false;


        //reflection from top  and bottom
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

        //reflection from back
        if(ball->Left+ball->Width >= background->Width)
        {
           if(isPractice == true)
                {
                         if(isCollidingBack == false)
                         {
                                ballVerticalVelocity  = ballVerticalVelocity * verticalFrictionMultipler;
                                ballHorizontalVelocity = -ballHorizontalVelocity * horizontalFrictionMultipler;
                         }
                         
                         isCollidingBack = true;
                }
                //player2 lose
                else
                {
                        player1Score ++;
                        player1Movement->Enabled=false;
                        ballMovement->Enabled = false;
                        player1->Visible = false;
                        player2->Visible = false;
                        ball->Visible = false;
                        information->Caption = "<Punkt dla gracza lewego\nIlosc odbic: " + IntToStr(hitCount)+ "\nWynik: " + IntToStr(player1Score) + ":" +IntToStr(player2Score);
                        information->Top = background->Height/4;
                        information->Left = background->Width/2-information->Width/2;
                        information->Visible = true;
                        startGame->Caption = "Od nowa";
                        startGame->Top = background->Height/2 + startGame->Height;
                        startGame->Left = background->Width/2 - practice->Width/2;
                        startGame->Visible = true;
                        nextRound->Top = background->Height/2;
                        nextRound->Left = background->Width/2 - practice->Width/2;
                        nextRound->Visible = true;
                        mainWindow->Cursor = crArrow;
                }
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



void __fastcall TmainWindow::practiceClick(TObject *Sender)
{
        nextRound->Visible =false;
        hitCount = 0;
        isPractice = true;
        startGame->Visible =false;
        practice->Visible =false;
        information->Caption = "ESC aby wrocic";
        information->Top = 0;
        information->Left = 0;
        mainWindow->Cursor = crNone;
        player1->Top = background->Height/2-player1->Height/2;
        player1->Left = 24;
        player1->Visible = true;
        player2->Left = background->Width + 50;
        ballVerticalVelocity = 0;
        ballHorizontalVelocity = 0;
        ball->Top = background->Height/2-ball->Height/2;
        ball->Left = 320;
        ball->Visible = true;
        previousCursorPosition = Mouse->CursorPos;
        player1Movement->Enabled =true;
        ballMovement->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TmainWindow::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_ESCAPE )
        {
                player1Movement->Enabled=false;
                ballMovement->Enabled = false;
                player1->Visible = false;
                player2->Visible = false;
                ball->Visible = false;
                startGame->Caption = "Nowa gra";
                startGame->Top = background->Height/2 + startGame->Height;
                startGame->Left = background->Width/2 - practice->Width/2;
                startGame->Visible =true;
                practice->Caption = "Trening";
                practice->Top = background->Height/2;
                practice->Left = background->Width/2 - practice->Width/2;
                practice->Visible =true;
                information->Caption = "Zagrajmy w Ping Ponga!";
                information->Top = background->Height/4;
                information->Left = background->Width/2-information->Width/2;
                information->Visible = true;
                nextRound->Visible =false;
                mainWindow->Cursor = crArrow;
        }

        if(isPractice == false && Key == VK_UP)
        {
           player2VerticalVelocity = -20 ;
        }

         if(isPractice == false && Key == VK_DOWN)
        {
           player2VerticalVelocity = 20 ;
        }

          if(isPractice == false && Key == VK_LEFT)
        {
           player2HorizontalVelocity = -10;
        }
          if(isPractice == false && Key == VK_RIGHT)
        {
           player2HorizontalVelocity = 10 ;
        }
}
//---------------------------------------------------------------------------


void __fastcall TmainWindow::player2MovementTimer(TObject *Sender)
{
        if(player2VerticalVelocity < 0 && player2->Top >= background->Top + 5 || player2VerticalVelocity > 0 && player2->Top + player2->Height <= background->Top + background->Height - 5)
                player2->Top += player2VerticalVelocity;

        if(player2HorizontalVelocity > 0 && player2->Left + player2->Width <= background->Width- 50 || player2HorizontalVelocity < 0 && player2->Left >= background->Width - 500)
                 player2->Left += player2HorizontalVelocity;
}
//---------------------------------------------------------------------------

void __fastcall TmainWindow::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
         if(isPractice == false && Key == VK_UP || Key == VK_DOWN)
        {
           player2VerticalVelocity = 0 ;
        }

          if(isPractice == false && Key == VK_LEFT || Key == VK_RIGHT)
        {
           player2HorizontalVelocity = 0 ;
        }

}
//---------------------------------------------------------------------------

void __fastcall TmainWindow::nextRoundClick(TObject *Sender)
{
        nextRound->Visible = false;
        hitCount = 0;
        isPractice = false;
        startGame->Visible =false;
        practice->Visible =false;
        information->Caption = "ESC aby wrocic";
        information->Top = 0;
        information->Left = 0;
        mainWindow->Cursor = crNone;
        player1->Top = background->Height/2-player1->Height/2;
        player1->Left = 24;
        player1->Visible = true;
        player2-> Top = background->Height/2-player2->Height/2;
        player2->Left = background->Width - 24 - player2->Width;
        player2->Visible = true;
        player2->Enabled = true;
        ballVerticalVelocity = 0;
        ballHorizontalVelocity = 0;
        player2HorizontalVelocity = 0;
        player2VerticalVelocity = 0;
        ball->Top = background->Height/2-ball->Height/2;
        ball->Left = 320;
        ball->Visible = true;
        previousCursorPosition = Mouse->CursorPos;
        player1Movement->Enabled =true;
        ballMovement->Enabled = true;

}
//---------------------------------------------------------------------------

