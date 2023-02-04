// ignore_for_file: file_names

import 'package:flutter/material.dart';
import 'package:bitsdojo_window/bitsdojo_window.dart';

class ControlPanel extends StatelessWidget 
{
    const ControlPanel({Key? key}) : super(key: key);
    
    @override
    Widget build(BuildContext context) 
    {
        return Expanded(
            child: Container(
                color: Colors.transparent,
                child: Column(
                    children: [
                        WindowTitleBarBox(
                            child: Row(
                                children: [Expanded(child: MoveWindow()), const WindowButtons()],
                            ),
                        )
                    ]
                )
            )
        );
    }
}

final buttonColors = WindowButtonColors(
    iconNormal: const Color(0xFF805306),
    mouseOver: const Color(0xFFF6A00C),
    mouseDown: const Color(0xFF805306),
    iconMouseOver: const Color(0xFF805306),
    iconMouseDown: const Color(0xFFFFD500)
);

final closeButtonColors = WindowButtonColors(
    mouseOver: const Color(0xFFD32F2F),
    mouseDown: const Color(0xFFB71C1C),
    iconNormal: const Color(0xFF805306),
    iconMouseOver: Colors.white
);

class WindowButtons extends StatefulWidget 
{
    const WindowButtons({Key? key}) : super(key: key);

    @override
    WindowButtonsState createState() => WindowButtonsState();
}

class WindowButtonsState extends State<WindowButtons> 
{
    void maximizeOrRestore() 
    {
        setState(() {
            appWindow.maximizeOrRestore();
        });
    }

    @override
    Widget build(BuildContext context) 
    {
        return Row(
            children: [
                MinimizeWindowButton(colors: buttonColors),
                appWindow.isMaximized
                    ? RestoreWindowButton(
                        colors: buttonColors,
                        onPressed: maximizeOrRestore,
                    )
                    : MaximizeWindowButton(
                        colors: buttonColors,
                        onPressed: maximizeOrRestore,
                    ),
                CloseWindowButton(colors: closeButtonColors),
            ],
        );
    }
}