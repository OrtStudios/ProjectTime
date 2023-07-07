// ignore_for_file: library_prefixes

import 'package:flutter/material.dart';
import 'package:window_manager/window_manager.dart';
import 'package:bitsdojo_window/bitsdojo_window.dart';
import 'package:flutter_acrylic/flutter_acrylic.dart';

// Widgets
import 'package:project_time/main.widget.dart';

// Data
import 'package:project_time/main.config.dart' as ptConfig;

Future<void> main() async
{
    WidgetsFlutterBinding.ensureInitialized();
    windowManager.ensureInitialized();

    await Window.initialize();

    runApp(const ProjectTime());

    windowManager.waitUntilReadyToShow().then(
        (_) async 
        {
        // await windowManager.setTitleBarStyle(TitleBarStyle.hidden);
            await windowManager.setAsFrameless();
            await windowManager.setHasShadow(false);
            windowManager.show();
        }
    );

    doWhenWindowReady(() 
        {
            appWindow
                ..size = ptConfig.winSize
                ..title = "Project Time"
                ..minSize = ptConfig.winSize
                ..maxSize = ptConfig.winSize
                ..alignment = Alignment.center
                ..show();
        }
    );
}