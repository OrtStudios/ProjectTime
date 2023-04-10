// ignore_for_file: library_prefixes, file_names
import 'package:flutter/material.dart';
import 'package:go_router/go_router.dart';
import 'package:project_time/widgets/Sidebar.dart';

// Other
import 'package:project_time/widgets/base.dart';
//import 'package:project_time/extensions/VRouter.dart';
import 'package:project_time/main.theme.dart' as ptTheme;

class ErrorPage extends StatelessWidget 
{
    const ErrorPage({Key? key}) : super(key: key);

    @override
    Widget build(BuildContext context) 
    {
        return Container( color: Colors.red,
          child: Center(
              child: Column(
                  mainAxisAlignment: MainAxisAlignment.center,
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
              )
          ),
        );
    }
}