// ignore_for_file: library_prefixes, file_names
import 'package:flutter/material.dart';
import 'package:go_router/go_router.dart';

// Data
import 'package:project_time/main.theme.dart' as ptTheme;
import 'package:project_time/main.config.dart' as ptConfig;
import 'package:project_time/widgets/base.dart';

class ErrorPage extends StatefulWidget 
{
    const ErrorPage({Key? key}) : super(key: key);

    @override
    State<ErrorPage> createState() => _ErrorPageState();
}

class _ErrorPageState extends State<ErrorPage> 
{
    @override
    Widget build(BuildContext context) 
    {
        return BaseWidget(
            page: const ErrorPage(),
            child: SizedBox(
                width: ptConfig.windowWidth - (ptConfig.sidebarWidth + 50),
                child: Column(
                    mainAxisAlignment: MainAxisAlignment.center,
                    crossAxisAlignment: CrossAxisAlignment.center,
                    children: [
                        const Text(
                            "404", 
                            style: TextStyle(
                                color: ptTheme.kAccentColor,
                                fontSize: 200,
                                fontStyle: FontStyle.normal,
                                fontWeight: FontWeight.normal,
                                decoration: TextDecoration.none,
                            )
                        ),
                        const Padding(padding: EdgeInsets.all(10)),
                        const Text(
                            "Page not found",
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
                ),
            ),
        );
    }
}