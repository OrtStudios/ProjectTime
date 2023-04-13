// ignore_for_file: file_names, library_prefixes, curly_braces_in_flow_control_structures
import "package:flutter/material.dart";

// Widgets
import 'package:project_time/pages/projects/addProject.form.dart';

// Data
import 'package:project_time/main.theme.dart' as ptTheme;
import 'package:project_time/main.config.dart' as ptConfig;
import 'package:project_time/widgets/base.dart';

class AddProjectPage extends StatefulWidget
{
    const AddProjectPage({super.key});

    @override
    State<AddProjectPage> createState() => _AddProjectPageState();
}

class _AddProjectPageState extends State<AddProjectPage> 
{
    @override
    Widget build(BuildContext context) 
    {
        return BaseWidget(
            page: const AddProjectPage(),
            child: SizedBox(
                height: ptConfig.windowHeight - 55,
                child: Material(
                    child: Column(
                        children: [
                            const Text(
                                "New Project",
                                style: TextStyle(
                                    color: ptTheme.kAccentColor,
                                    fontWeight: FontWeight.w700,
                                    fontSize: 30,
                                    //fontFamily: 
                                )
                            ),
                            SizedBox(
                                width: ptConfig.windowWidth - (ptConfig.sidebarWidth + 50),
                                height: ptConfig.windowHeight - 98,
                                child: Theme(
                                    data: ptTheme.mainTheme,
                                    child: const AddProjectForm()
                                )
                            )
                        ]
                    )
                ),
            ),
        );
    }
}