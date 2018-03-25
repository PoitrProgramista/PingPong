object mainWindow: TmainWindow
  Left = 246
  Top = 104
  Align = alClient
  BorderStyle = bsSingle
  Caption = 'Ping Pong'
  ClientHeight = 807
  ClientWidth = 1518
  Color = clBtnFace
  UseDockManager = True
  DefaultMonitor = dmMainForm
  DockSite = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
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
    Left = 320
    Top = 176
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
    Top = 368
    Width = 32
    Height = 256
    Brush.Color = clHighlight
    Pen.Width = 3
  end
  object ball: TShape
    Left = 160
    Top = 472
    Width = 49
    Height = 49
    Brush.Color = clMaroon
    Pen.Width = 3
    Shape = stEllipse
  end
  object startGame: TButton
    Left = 736
    Top = 464
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
    Left = 736
    Top = 320
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
  object player1Movement: TTimer
    Interval = 1
    OnTimer = player1MovementTimer
    Left = 48
    Top = 48
  end
end
