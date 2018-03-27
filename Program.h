//---------------------------------------------------------------------------

#ifndef ProgramH
#define ProgramH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TmainWindow : public TForm
{
__published:	// IDE-managed Components
        TShape *background;
        TLabel *information;
        TButton *startGame;
        TButton *nextRound;
        TLabel *score;
        TLabel *numberOfHits;
        TShape *player1;
        TTimer *player1Movement;
        TTimer *ballMovement;
        TShape *player2;
        TImage *ball;
        TButton *practice;
        TTimer *player2Movement;
        void __fastcall player1MovementTimer(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall startGameClick(TObject *Sender);
        void __fastcall ballMovementTimer(TObject *Sender);
        void __fastcall practiceClick(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall player2MovementTimer(TObject *Sender);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall nextRoundClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TmainWindow(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TmainWindow *mainWindow;
//---------------------------------------------------------------------------
#endif
