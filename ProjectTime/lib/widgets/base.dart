// ignore_for_file: library_prefixes

import 'package:flutter/material.dart';
import 'package:bitsdojo_window/bitsdojo_window.dart';
import 'package:project_time/widgets/Sidebar.dart';

// Widgets
import 'package:project_time/widgets/shortcuts.dart';
import 'package:project_time/widgets/controlBar.dart';

// Other
import 'package:project_time/main.theme.dart' as ptTheme;
import 'package:project_time/main.config.dart' as ptConfig;

class BaseWidget extends StatefulWidget 
{
    final Widget child;
    final Widget page;
    const BaseWidget({Key? key, required this.page, required this.child}) : super(key: key);

    @override
    State<BaseWidget> createState() => _BaseWidgetState();
}

class _BaseWidgetState extends State<BaseWidget> 
{
    final double _roundingRadius = 40;

    @override
    Widget build(BuildContext context) 
    {
        final BorderRadius borderRadius = BorderRadius.only(
            topLeft: Radius.circular(_roundingRadius),
            bottomLeft: Radius.circular(_roundingRadius)
        );
        
        return ShortCuts(
            child: Stack(
                children: [
                    Image.asset(
                        ptTheme.kBackgroundImage,
                        height: ptConfig.windowHeight,
                        width: ptConfig.windowWidth,
                        fit: BoxFit.cover,
                    ),
                    Container(
                        color: ptTheme.kSecondaryTransparentColor,
                        child: Stack(
                            children: [
                                Positioned(
                                    left: ptConfig.sidebarWidth,
                                    child: ClipRRect(
                                        borderRadius: borderRadius, 
                                        child: Image.asset(
                                            ptTheme.kBackgroundImage,
                                            height: ptConfig.windowHeight,
                                            width: ptConfig.windowWidth,
                                            fit: BoxFit.cover,
                                        ),
                                    ),
                                ),
                            ],
                        ),
                    ),
                    WindowBorder(
                        color: Colors.transparent,
                        width: 1,
                        child: const Row(
                            children: [
                                ControlPanel()
                            ]
                        )
                    ),
                    Row(
                        children: [
                            Sidebar(page: widget.page),
                            const SizedBox(width: 20),
                            widget.child
                        ],
                    ),
                ]
            )
        );
    }
}
