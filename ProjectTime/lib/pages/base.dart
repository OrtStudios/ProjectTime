// ignore_for_file: library_prefixes

import 'package:flutter/material.dart';
import 'package:bitsdojo_window/bitsdojo_window.dart';

// Widgets
import 'package:project_time/widgets/shortcuts.dart';
import 'package:project_time/widgets/controlBar.dart';

// Other
import 'package:project_time/Themes.dart' as ptTheme;
import 'package:project_time/config.dart' as ptConfig;

class BaseWidget extends StatefulWidget 
{
    final Widget child;
    const BaseWidget({Key? key, required this.child}) : super(key: key);

    @override
    State<BaseWidget> createState() => _BaseWidgetState();
}

class _BaseWidgetState extends State<BaseWidget> 
{
    @override
    Widget build(BuildContext context) 
    {
        return Scaffold(
            backgroundColor: ptTheme.kBackgroundColor,
            body: ShortCuts(
                child: Stack(
                    children: [
                        Image.asset(
                            ptTheme.kBackgroundImage,
                            height: ptConfig.windowHeight,
                            width: ptConfig.windowWidth,
                            fit: BoxFit.cover,
                        ),
                        WindowBorder(
                            color: Colors.transparent,
                            width: 1,
                            child: Row(
                                children: const [
                                    ControlPanel()
                                ]
                            )
                        ),
                        widget.child
                    ]
                )
            )
        );
    }
}
