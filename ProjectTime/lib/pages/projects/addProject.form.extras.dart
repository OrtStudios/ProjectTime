// ignore_for_file: library_prefixes

import 'package:flutter/material.dart';

// Other
import "package:project_time/main.theme.dart" as ptTheme;

class AddProjectFormExtrasPage extends StatelessWidget 
{
    const AddProjectFormExtrasPage({super.key});

    @override
    Widget build(BuildContext context)
    {
        return Column(
            mainAxisAlignment: MainAxisAlignment.start,
            textDirection: TextDirection.ltr,
            children: [
                //>> Name <<\\
                const Text(
                    "Extra Information About The Project",
                    style: TextStyle(
                        fontSize: 20,
                        fontWeight: FontWeight.w500,
                        //fontFamily: //TODO
                        color: ptTheme.kSecondaryLightColor
                    )
                ),
                Container(
                    width: 700,
                    color: ptTheme.kSecondaryTransparentColor,
                    child: TextFormField(
                        maxLines: 10,
                        maxLength: 2055,
                        cursorColor: ptTheme.kAccentColor,
                        decoration: const InputDecoration(
                            hintText: "Extra information",
                            counterText: ""
                        ),
                    ),
                ),
                const SizedBox(height: 20),
            ]
        );
    }
}