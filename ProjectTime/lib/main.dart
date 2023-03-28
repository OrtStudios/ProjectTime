// ignore_for_file: library_prefixes

import 'package:vrouter/vrouter.dart';
import 'package:flutter/material.dart';
import 'package:window_manager/window_manager.dart';
import 'package:bitsdojo_window/bitsdojo_window.dart';
import 'package:flutter_acrylic/flutter_acrylic.dart';

// Pages
import 'package:project_time/pages/404.dart';
import 'package:project_time/pages/homePage.dart';
import 'package:project_time/pages/ProjectsLibrary.dart';
import 'package:project_time/pages/projects/addProject.dart';

// Other
import 'package:project_time/Core.logger.dart';
import 'package:project_time/main.config.dart' as ptConfig;
import 'package:project_time/main.theme.dart' as ptTheme;

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
        Core.setLogLevel(LogLevel.DEBUG);

        return MaterialApp(
            debugShowCheckedModeBanner: false,
            title: "Project Time",
            color: Colors.transparent,
            theme: ptTheme.mainTheme,
            home: ClipRRect(
                borderRadius: BorderRadius.circular(25),
                child: VRouter(
                    debugShowCheckedModeBanner: false,
                    title: "Project Time",
                    color: Colors.transparent,
                    darkTheme: ThemeData.dark(useMaterial3: true),
                    initialUrl: "/",
                    transitionDuration: const Duration(milliseconds: 0),
                    routes: [
                        VWidget(
                            path: "/",
                            widget: const HomePage(),
                        ),
                        VWidget(
                            path: "/projectsLibrary",
                            widget: const ProjectsLibrary(),
                        ),
                        VWidget(
                            path: "/projects/addProject",
                            name: "addProject",
                            widget: const AddProjectPage(),
                        ),
                        VWidget(
                            path: "/projects/:projectID",
                            widget: const ErrorPage(),
                        ),
                        VWidget(
                            path: "/calender",
                            widget: const ErrorPage(),
                        ),
                        VWidget(
                            path: "/account",
                            widget: const ErrorPage(),
                        ),
                        VWidget(
                            path: "/settings",
                            widget: const ErrorPage(),
                        ),
                        VWidget(
                            path: "/about",
                            widget: const ErrorPage(),
                        ),
                        VWidget(
                            path: "/404",
                            widget: const ErrorPage(),
                        )
                    ]
                )
            )
        );
    }
}