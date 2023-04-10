// ignore_for_file: file_names, library_prefixes, curly_braces_in_flow_control_structures

import 'package:flutter/material.dart';
import 'package:go_router/go_router.dart';
import 'package:font_awesome_flutter/font_awesome_flutter.dart';

// Other
import 'package:project_time/main.theme.dart' as ptTheme;
//import 'package:project_time/extensions/VRouter.dart';

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
            onPressed: () => context.goNamed("addProject"),//widget.gotoNamed(context, "addProject"),
            onHover: (isHovering) => setState(() => addProjectButtonColor = isHovering 
                ? ptTheme.kSecondaryColor 
                : ptTheme.kSecondaryTransparentColor
            ),
            child: Container(
                padding: const EdgeInsets.all(7),
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
                child: const FaIcon(
                    FontAwesomeIcons.plus,
                    color: Colors.white,
                    size: 27
                )
            ),
        );
    }
}