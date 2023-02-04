// ignore_for_file: library_prefixes, file_names

import 'package:flutter/material.dart';
import 'package:vrouter/vrouter.dart';

// Other
import 'package:project_time/pages/base.dart';
import 'package:project_time/Themes.dart' as ptTheme;

class ErrorPage extends StatelessWidget 
{
    const ErrorPage({Key? key}) : super(key: key);

    @override
    Widget build(BuildContext context) 
    {
        return Center(
            child: Column(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                    const Text(
                        "404", 
                        style: TextStyle(
                            color: ptTheme.kAccentColor,
                            fontSize: 200
                        )
                    ),
                    const Padding(padding: EdgeInsets.all(10)),
                    const Text(
                        "Page not found",
                        style: TextStyle(
                            color: ptTheme.kAccentColor,
                            fontSize: 30
                        )
                    ),
                    const Padding(padding: EdgeInsets.all(10)),
                    ElevatedButton(
                        onPressed: () => context.vRouter.to("/"),
                        style: ElevatedButton.styleFrom(
                            backgroundColor: ptTheme.kAccentColor,
                        ),
                        child: const Text(
                            "Go Home",
                            style: TextStyle(
                                fontSize: 30
                            )
                        )
                    )
                ]
            )
        );
    }
}