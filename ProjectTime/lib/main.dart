// ignore_for_file: library_prefixes

import 'package:flutter/material.dart';
import 'package:go_router/go_router.dart';
import 'package:bitsdojo_window/bitsdojo_window.dart';
import 'package:flutter_acrylic/flutter_acrylic.dart';
import 'package:window_manager/window_manager.dart';

// Pages
import 'package:project_time/pages/homePage.dart';
import 'package:project_time/pages/ProjectsLibrary.dart';

// Other
import 'package:project_time/config.dart' as ptConfig;
import 'package:project_time/Themes.dart' as ptTheme;

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

class ProjectTime extends StatefulWidget 
{
    const ProjectTime({Key? key}) : super(key: key);

    @override
    State<ProjectTime> createState() => _ProjectTimeState();
}

class _ProjectTimeState extends State<ProjectTime> 
{
    @override
    void initState() 
    {
        super.initState();

        Window.setEffect(
            effect: WindowEffect.transparent
        );
    }

    @override
    Widget build(BuildContext context) 
    {
        return ClipRRect(
            borderRadius: BorderRadius.circular(25),
            child: MaterialApp.router(
                debugShowCheckedModeBanner: false,
                title: "Project Time",
                color: Colors.transparent,
                theme: ptTheme.mainTheme,
                routeInformationParser: _router.routeInformationParser,
                routerDelegate: _router.routerDelegate,
                routeInformationProvider: _router.routeInformationProvider
            )
        );
    }

    final GoRouter _router = GoRouter(
        initialLocation: "/",
        routes: [
            GoRoute(
                path: "/",
                builder: (context, state) => const HomePage()
            ),
            GoRoute(
                path: "/projectsLibrary",
                builder: (context, state) => const ProjectsLibrary()
            ),
            GoRoute(
                path: "/calender",
                builder: (context, state) => const Text("calender")
            ),
            GoRoute(
                path: "/account",
                builder: (context, state) => const Text("account")
            ),

            // Control Panel
            GoRoute(
                path: "/Settings",
                builder: (context, state) => const Text("Settings")
            ),

            // Other
            GoRoute(
                path: "/newProject",
                builder: (context, state) => const Text("New Project")
            ),
        ],
        errorBuilder: (context, state) => const Text("Error")
    );
}