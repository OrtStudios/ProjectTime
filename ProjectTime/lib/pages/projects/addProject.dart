// ignore_for_file: file_names, library_prefixes, curly_braces_in_flow_control_structures
import "package:flutter/material.dart";

// Widgets
import 'package:project_time/widgets/base.dart';
import 'package:project_time/pages/projects/addProject.form.dart';

// Other
import 'package:project_time/main.theme.dart' as ptTheme;
import 'package:project_time/main.config.dart' as ptConfig;

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
        return Material(
            child: BaseWidget(
                child: Row(
                    children: [
                        Container(
                            height: ptConfig.windowHeight,
                            color: ptTheme.kPrimaryColor,
                            child: const Text(
                                "Unimplemented", // TODO: Implement SideBar
                                style: TextStyle(
                                    color: ptTheme.kSecondaryLightColor,
                                    fontWeight: FontWeight.normal,
                                    decoration: TextDecoration.none,
                                    fontSize: 15
                                )
                            )
                        ),
                        Column(
                            children: [
                                const SizedBox(height: 10),
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
                                    width: ptConfig.windowWidth - 130,
                                    height: ptConfig.windowHeight - 52,
                                    child: Theme(
                                        data: ptTheme.mainTheme,
                                        child: const AddProjectForm()
                                    )
                                )
                            ]
                        )
                    ]
                )
            )
        );
    }
}