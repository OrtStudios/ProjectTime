// ignore_for_file: file_names, library_prefixes

import 'package:flutter/material.dart';
import 'package:go_router/go_router.dart';

// Widgets
import 'package:project_time/widgets/base.dart';

// Other
import 'package:project_time/main.theme.dart' as ptTheme;

class ProjectsLibraryPage extends StatefulWidget 
{
    const ProjectsLibraryPage({Key? key}) : super(key: key);

    @override
    State<ProjectsLibraryPage> createState() => _ProjectsLibraryPageState();
}

class _ProjectsLibraryPageState extends State<ProjectsLibraryPage> 
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
                            onPressed: () => context.go("/"),
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