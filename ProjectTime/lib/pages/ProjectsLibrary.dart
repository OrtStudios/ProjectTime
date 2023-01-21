// ignore_for_file: file_names

import 'package:flutter/material.dart';

// Widgets
import 'package:project_time/widgets/shortcuts.dart';

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
        return const ShortCuts(child: Text("projectsLibrary"));
    }
}