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
        TTimer *player1Vertical;
        TTimer *player1Horizontal;
        void __fastcall player1VerticalTimer(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall startGameClick(TObject *Sender);
        void __fastcall player1HorizontalTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TmainWindow(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TmainWindow *mainWindow;
//---------------------------------------------------------------------------
#endif
