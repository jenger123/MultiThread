object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 509
  ClientWidth = 741
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object Label1: TLabel
    Left = 232
    Top = 477
    Width = 34
    Height = 15
    Caption = 'Label1'
    Visible = False
  end
  object Label2: TLabel
    Left = 559
    Top = 72
    Width = 130
    Height = 15
    Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1090#1080#1087#1099' '#1092#1072#1081#1083#1086#1074
  end
  object Label3: TLabel
    Left = 544
    Top = 187
    Width = 149
    Height = 15
    Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1083#1086#1075#1080#1095#1077#1089#1082#1080#1081' '#1090#1086#1084' '
  end
  object ProgressBar1: TProgressBar
    Left = 8
    Top = 422
    Width = 497
    Height = 49
    TabOrder = 0
    Visible = False
  end
  object Button1: TButton
    Left = 638
    Top = 408
    Width = 75
    Height = 25
    Caption = #1053#1072#1081#1090#1080' '#1092#1072#1081#1083#1099
    TabOrder = 1
    OnClick = Button1Click
  end
  object CheckListBox1: TCheckListBox
    Left = 536
    Top = 104
    Width = 177
    Height = 57
    ItemHeight = 15
    Items.Strings = (
      'jpg/jpeg'
      'bmp'
      'png')
    TabOrder = 2
  end
  object VirtualStringTree1: TVirtualStringTree
    Left = 48
    Top = 24
    Width = 425
    Height = 392
    AccessibleName = 'type of file'
    Colors.BorderColor = 15987699
    Colors.DisabledColor = clGray
    Colors.DropMarkColor = 15385233
    Colors.DropTargetColor = 15385233
    Colors.DropTargetBorderColor = 15385233
    Colors.FocusedSelectionColor = 15385233
    Colors.FocusedSelectionBorderColor = 15385233
    Colors.GridLineColor = 15987699
    Colors.HeaderHotColor = clBlack
    Colors.HotColor = clBlack
    Colors.SelectionRectangleBlendColor = 15385233
    Colors.SelectionRectangleBorderColor = 15385233
    Colors.SelectionTextColor = clBlack
    Colors.TreeLineColor = 9471874
    Colors.UnfocusedColor = clGray
    Colors.UnfocusedSelectionColor = clWhite
    Colors.UnfocusedSelectionBorderColor = clWhite
    Header.AutoSizeIndex = 0
    Header.Height = 18
    Header.Options = [hoColumnResize, hoDrag, hoShowSortGlyphs, hoVisible]
    TabOrder = 3
    OnGetText = VirtualStringTree1GetText
    Touch.InteractiveGestures = [igPan, igPressAndTap]
    Touch.InteractiveGestureOptions = [igoPanSingleFingerHorizontal, igoPanSingleFingerVertical, igoPanInertia, igoPanGutter, igoParentPassthrough]
    Columns = <
      item
        Position = 0
        Text = 'id'
        Width = 79
      end
      item
        Position = 1
        Text = 'number cluster'
        Width = 134
      end
      item
        Position = 2
        Text = 'type of file'
        Width = 142
      end>
  end
  object Button2: TButton
    Left = 511
    Top = 408
    Width = 108
    Height = 25
    Caption = #1055#1088#1077#1088#1074#1072#1090#1100' '#1095#1090#1077#1085#1080#1077
    TabOrder = 4
    OnClick = Button2Click
  end
  object ComboBox1: TComboBox
    Left = 544
    Top = 208
    Width = 145
    Height = 23
    TabOrder = 5
    Text = 'ComboBox1'
    OnSelect = ComboBox1Select
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 688
    Top = 464
  end
end
