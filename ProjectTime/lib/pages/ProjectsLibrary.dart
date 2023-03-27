// ignore_for_file: file_names

import 'package:flutter/material.dart';

// Widgets
import 'package:project_time/widgets/base.dart';

// Other
import 'package:project_time/extensions/VRouter.dart';
import 'package:project_time/main.theme.dart' as ptTheme;
import 'package:project_time/main.config.dart' as ptCongig;

class ProjectsLibrary extends StatefulWidget 
{
    const ProjectsLibrary({Key? key}) : super(key: key);

    @override
    State<ProjectsLibrary> createState() => _ProjectsLibraryState();
}

class _ProjectsLibraryState extends State<ProjectsLibrary> 
{
    @override
    Widget build(BuildContext context) 
    {
        return BaseWidget(
            child: Center(
                child: Column(
                    mainAxisAlignment: MainAxisAlignment.center,
                    children: [
                        const Text(
                            "ProjectsLibrary", 
                            style: TextStyle(
                                color: ptTheme.kAccentColor,
                                fontSize: 120,
                                fontStyle: FontStyle.normal,
                                fontWeight: FontWeight.normal,
                                decoration: TextDecoration.none,
                            )
                        ),
                        const Padding(padding: EdgeInsets.all(10)),
                        const Text(
                            "Page not built",
                            style: TextStyle(
                                color: ptTheme.kAccentColor,
                                decoration: TextDecoration.none,
                                fontSize: 30
                            )
                        ),
                        const Padding(padding: EdgeInsets.all(10)),
                        ElevatedButton(
                            onPressed: () => widget.goto(context, "/"),
                            style: ElevatedButton.styleFrom(
                                backgroundColor: ptTheme.kAccentColor,
                            ),
                            child: const Text(
                                "Go Home",
                                style: TextStyle(
                                    decoration: TextDecoration.none,
                                    color: ptTheme.kPrimaryColor,
                                    fontSize: 30
                                )
                            )
                        )
                    ]
                )
            )
        );
    }
}