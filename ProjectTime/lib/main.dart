// ignore_for_file: library_prefixes

import 'package:flutter/material.dart';
import 'package:go_router/go_router.dart';
import 'package:window_manager/window_manager.dart';
import 'package:bitsdojo_window/bitsdojo_window.dart';
import 'package:flutter_acrylic/flutter_acrylic.dart';

// Pages
import 'package:project_time/pages/404.dart';
import 'package:project_time/pages/homePage.dart';
import 'package:project_time/pages/ProjectsLibrary.dart';
import 'package:project_time/pages/projects/addProject.dart';

// Util
import 'package:project_time/Core.logger.dart';
import 'package:project_time/utils/routerTransition.dart';

// Data
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
                child: Router(
                    routerDelegate: _router.routerDelegate,
                    routeInformationParser: _router.routeInformationParser,
                    routeInformationProvider: _router.routeInformationProvider
                )
            )
        );
    }

    final _router = GoRouter(
        routes: [
            GoRoute(
                path: '/',
                name: "home",
                pageBuilder: (context, state) => ptRouterPageBuilder(
                    context, state, const HomePage()
                )
            ),
            GoRoute(
                path: '/projectsLibrary',
                name: "projectsLibrary",
                pageBuilder: (context, state) => ptRouterPageBuilder(
                    context, state, const ProjectsLibraryPage()
                )
            ),
            GoRoute(
                path: '/projects/addProject',
                name: "addProject",
                pageBuilder: (context, state) => ptRouterPageBuilder(
                    context, state, const AddProjectPage()
                )
            ),
            GoRoute(
                path: '/projects/:projectID',
                name: "project",
                pageBuilder: (context, state) => ptRouterPageBuilder(
                    context, state, const ErrorPage()
                )
            ),
            GoRoute(
                path: '/calender',
                name: "calender",
                pageBuilder: (context, state) => ptRouterPageBuilder(
                    context, state, const ErrorPage()
                )
            ),
            GoRoute(
                path: '/account',
                name: "account",
                pageBuilder: (context, state) => ptRouterPageBuilder(
                    context, state, const ErrorPage()
                )
            ),
            GoRoute(
                path: '/settings',
                name: "settings",
                pageBuilder: (context, state) => ptRouterPageBuilder(
                    context, state, const ErrorPage()
                )
            ),
            GoRoute(
                path: '/about',
                name: "about",
                pageBuilder: (context, state) => ptRouterPageBuilder(
                    context, state, const ErrorPage()
                )
            ),
            GoRoute(
                path: '/404',
                name: "404",
                pageBuilder: (context, state) => ptRouterPageBuilder(
                    context, state, const ErrorPage()
                )
            )
        ],
    );
}