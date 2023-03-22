// ignore_for_file: file_names, library_prefixes
import "package:flutter/material.dart";

// Widgets
import 'package:project_time/pages/base.dart';

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
        return BaseWidget(
            child: Container(),
        );
    }
}