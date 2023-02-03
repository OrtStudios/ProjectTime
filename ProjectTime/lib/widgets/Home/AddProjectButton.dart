// ignore_for_file: file_names, library_prefixes, curly_braces_in_flow_control_structures

import 'package:flutter/material.dart';

// Other
import 'package:project_time/Themes.dart' as ptTheme;

class AddProjectButton extends StatefulWidget 
{
    const AddProjectButton({Key? key}) : super(key: key);

    @override
    State<AddProjectButton> createState() => _AddProjectButtonState();
}

class _AddProjectButtonState extends State<AddProjectButton> 
{
    Color addProjectButtonColor = ptTheme.kSecondaryTransparentColor;

    @override
    Widget build(BuildContext context) 
    {
        // This code creates a button that can be pressed to add a new project.
        // It is a circular button that is outlined in the secondary color of the theme.
        // When the button is hovered over or focused, the background of the button
        // becomes the secondary color of the theme. When the button is clicked,
        // the background of the button becomes the secondary color of the theme.
        // The button contains an "add" icon that is white and 27 pixels high.

        return TextButton(
            onPressed: () {print("Add Project Button Pressed");},
            style: ButtonStyle(
                overlayColor: MaterialStateProperty.resolveWith<Color>(
                    (Set<MaterialState> states) 
                    {
                        if (states.contains(MaterialState.hovered) &&
                            states.contains(MaterialState.focused))
                            return ptTheme.kSecondaryColor;
                        else
                            return ptTheme.kSecondaryTransparentColor;
                    }
                )
            ),
            child: Container(
                padding: const EdgeInsets.all(3),
                decoration: BoxDecoration(
                    shape: BoxShape.circle,
                    border: const Border.fromBorderSide(
                        BorderSide(
                            color: ptTheme.kSecondaryColor,
                            width: 3
                        )
                    ),
                    color: addProjectButtonColor
                ),
                child: const Icon(
                    Icons.add,
                    color: Colors.white,
                    size: 27,
                )
            ),
        );
    }
}