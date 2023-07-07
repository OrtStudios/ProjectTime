// ignore_for_file: library_prefixes

import "package:flutter/material.dart";
import 'package:flutter_acrylic/flutter_acrylic.dart';

// Util
import 'package:project_time/Core.logger.dart';
import 'package:project_time/main.router.dart';

// Data
import 'package:project_time/main.theme.dart' as ptTheme;

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
                    routerDelegate: ptRouter.routerDelegate,
                    routeInformationParser: ptRouter.routeInformationParser,
                    routeInformationProvider: ptRouter.routeInformationProvider
                )
            )
        );
    }
}