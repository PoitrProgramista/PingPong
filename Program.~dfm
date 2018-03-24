object mainWindow: TmainWindow
  Left = 329
  Top = 70
  BorderStyle = bsSingle
  Caption = 'Ping Pong'
  ClientHeight = 807
  ClientWidth = 1518
  Color = clBtnFace
  UseDockManager = True
  DockSite = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object background: TShape
    Left = 0
    Top = 0
    Width = 1518
    Height = 807
    Align = alClient
    Brush.Color = clMedGray
  end
  object information: TLabel
    Left = 120
    Top = 152
    Width = 1201
    Height = 37
    Alignment = taCenter
    AutoSize = False
    Caption = 'Zagrajmy w Ping Ponga!'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    Transparent = True
  end
  object score: TLabel
    Left = 624
    Top = 256
    Width = 201
    Height = 49
    Alignment = taCenter
    AutoSize = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    Transparent = True
    Visible = False
  end
  object numberOfHits: TLabel
    Left = 624
    Top = 328
    Width = 201
    Height = 49
    Alignment = taCenter
    AutoSize = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    Transparent = True
    Visible = False
  end
  object player1: TShape
    Left = 56
    Top = 240
    Width = 32
    Height = 256
    Brush.Color = clHighlight
    Pen.Width = 3
  end
  object startGame: TButton
    Left = 544
    Top = 592
    Width = 361
    Height = 113
    Cursor = crHandPoint
    Caption = 'Nowa gra'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = startGameClick
  end
  object nextRound: TButton
    Left = 544
    Top = 456
    Width = 361
    Height = 113
    Cursor = crHandPoint
    Caption = 'Nast'#281'pna runda'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    Visible = False
  end
  object player1Vertical: TTimer
    Interval = 10
    OnTimer = player1VerticalTimer
    Left = 48
    Top = 48
  end
  object player1Horizontal: TTimer
    Interval = 10
    OnTimer = player1HorizontalTimer
    Left = 80
    Top = 48
  end
end
