// ignore_for_file: library_prefixes

import 'package:flutter/material.dart';

// Other
import "package:project_time/main.theme.dart" as ptTheme;

class AddProjectFormGeneralPage extends StatelessWidget 
{
    const AddProjectFormGeneralPage({super.key});

    @override
    Widget build(BuildContext context)
    {
        return Column(
            mainAxisAlignment: MainAxisAlignment.start,
            textDirection: TextDirection.ltr,
            children: [
                //>> Name <<\\
                Row(
                    children: [
                        const Text(
                            "Name:          ",
                            style: TextStyle(
                                fontSize: 20,
                                fontWeight: FontWeight.w500,
                                //fontFamily: //TODO
                                color: ptTheme.kSecondaryLightColor
                            )
                        ),
                        SizedBox(
                            width: 500,
                            child: TextFormField(
                                maxLines: 1,
                                maxLength: 30,
                                cursorColor: ptTheme.kAccentColor,
                                decoration: const InputDecoration(
                                    hintText: "Project name",
                                    counterText: ""
                                ),
                            ),
                        )
                    ]
                ),
                const SizedBox(height: 20),

                //>> Description <<\\
                Row(
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                        const Text(
                            "Description: ",
                            style: TextStyle(
                                fontSize: 20,
                                fontWeight: FontWeight.w500,
                                //fontFamily: //TODO
                                color: ptTheme.kSecondaryLightColor
                            )
                        ),
                        Container(
                            width: 500,
                            color: ptTheme.kSecondaryTransparentColor,
                            child: TextFormField(
                                maxLines: 3,
                                maxLength: 500,
                                cursorColor: ptTheme.kAccentColor,
                                decoration: const InputDecoration(
                                    hintText: "Project description",
                                    counterText: ""
                                ),
                            ),
                        )
                    ]
                ),
                const SizedBox(height: 20),

                //>> Version <<\\
                Row(
                    children: [
                        const Text(
                            "Version:       ",
                            style: TextStyle(
                                fontSize: 20,
                                fontWeight: FontWeight.w500,
                                //fontFamily: //TODO
                                color: ptTheme.kSecondaryLightColor
                            )
                        ),
                        SizedBox(
                            width: 100,
                            child: TextFormField(
                                maxLines: 1,
                                maxLength: 9,
                                cursorColor: ptTheme.kAccentColor,
                                decoration: const InputDecoration(
                                    hintText: "Version",
                                    counterText: ""
                                ),
                            ),
                        )
                    ]
                ),
                const SizedBox(height: 20),

                
            ]
        );
    }
}