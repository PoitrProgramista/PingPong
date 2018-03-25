//---------------------------------------------------------------------------

#ifndef ProgramH
#define ProgramH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
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
        TShape *ball;
        void __fastcall player1MovementTimer(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall startGameClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TmainWindow(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TmainWindow *mainWindow;
//---------------------------------------------------------------------------
#endif
