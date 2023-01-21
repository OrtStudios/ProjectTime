// ignore_for_file: library_prefixes

import 'package:flutter/material.dart';
import "package:vrouter/vrouter.dart";
import 'package:bitsdojo_window/bitsdojo_window.dart';
import 'package:flutter_acrylic/flutter_acrylic.dart';
import 'package:window_manager/window_manager.dart';

// Pages
import 'package:project_time/pages/homePage.dart';
import 'package:project_time/pages/ProjectsLibrary.dart';

// Widgets
import 'package:project_time/widgets/controlBar.dart';

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
        return MaterialApp(
            debugShowCheckedModeBanner: false,
            title: "Project Time",
            color: Colors.transparent,
            theme: ptTheme.mainTheme,
            home: ClipRRect(
                borderRadius: BorderRadius.circular(25),
                child: Stack(
                    alignment: Alignment.center,
                    children: [
                        VRouter(
                            debugShowCheckedModeBanner: false,
                            darkTheme: ThemeData.dark(useMaterial3: true),
                            initialUrl: "/",
                            title: "Project Time",
                            routes: [
                                // Side Bar Buttons
                                VWidget(
                                    path: "/",
                                    name: "home",
                                    widget: const HomePage()
                                ),
                                VWidget(
                                    path: "/projectsLibrary",
                                    name: "library",
                                    widget:  const ProjectsLibrary()
                                ),
                                VWidget(
                                    path: "/calender",
                                    name: "calender",
                                    widget: const Text("calender")
                                ),
                                VWidget(
                                    path: "/account",
                                    name: "account",
                                    widget: const Text("account")
                                ),

                                // Control Panel
                                VWidget(
                                    path: "/Settings",
                                    name: "settings",
                                    widget: const Text("Settings")
                                ),

                                // Other
                                VWidget(
                                    path: "/newProject",
                                    name: "new",
                                    widget: const Text("New Project")
                                ),
                            ]
                        ),
                        WindowBorder(
                            color: Colors.transparent,
                            width: 1,
                            child: Row(
                                children: const [
                                    ControlPanel()
                                ]
                            )
                        )
                    ]
                )
            )
        );
    }
}