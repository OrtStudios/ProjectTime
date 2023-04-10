// ignore_for_file: file_names, library_prefixes, curly_braces_in_flow_control_structures
import 'package:flutter/material.dart';

// Widgets
import 'package:project_time/widgets/base.dart';
import 'package:project_time/widgets/Sidebar.dart';
import 'package:project_time/widgets/Home/AddProjectButton.dart';
import 'package:project_time/widgets/Home/SearchBar.dart';

// Other
import 'package:project_time/main.theme.dart' as ptTheme;
import 'package:project_time/main.config.dart' as ptConfig;

class HomePage extends StatefulWidget 
{
    const HomePage({Key? key}) : super(key: key);

    @override
    State<HomePage> createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> 
{
    @override
    Widget build(BuildContext context) 
    {
        return BaseWidget(
            child: Row(
                children: [
                    Sidebar(page: widget),
                    const Padding(padding: EdgeInsets.all(20)),
                    Column(
                        crossAxisAlignment: CrossAxisAlignment.baseline,
                        textBaseline: TextBaseline.alphabetic,
                        children: [
                            Container(
                                padding: const EdgeInsets.only(top: 10),
                                width: ptConfig.windowWidth - 320,
                                child: Row(
                                    mainAxisAlignment: MainAxisAlignment.center,
                                    children: const [
                                        SearchBar(),
                                        Padding(padding: EdgeInsets.all(10)),
                                        AddProjectButton()
                                    ]
                                )
                            ),
                            const Padding(padding: EdgeInsets.all(20)),
                            Column( 
                                // TODO: #3 Implement Graphs
                                //     - get data from database [C++]
                                //     - organize data [C++]
                                //     - write data to file [C++]
                                //     - create graphs [Flutter]
                                //     - add graphs to this page [Flutter]
                                children: [
                                    Row(
                                        children: [
                                            ClipRRect(
                                                borderRadius: const BorderRadius.all(Radius.circular(10)),
                                                clipBehavior: Clip.antiAliasWithSaveLayer,
                                                child: Container(
                                                    color: ptTheme.kPrimaryColor,
                                                    padding: const EdgeInsets.fromLTRB(30, 5, 30, 200),
                                                    child: const Text(
                                                        "Unimplemented Graph#1", 
                                                        style: TextStyle(
                                                            color: ptTheme.kSecondaryColor,
                                                            fontWeight: FontWeight.normal,
                                                            decoration: TextDecoration.none,
                                                            fontSize: 15
                                                        )
                                                    )
                                                )
                                            ),
                                            const Padding(padding: EdgeInsets.all(15)),
                                            Container(
                                                color: ptTheme.kPrimaryColor,
                                                padding: const EdgeInsets.fromLTRB(30, 5, 30, 200),
                                                child: const Text(
                                                    "Unimplemented Graph#2",
                                                    style: TextStyle(
                                                        color: ptTheme.kSecondaryColor,
                                                        fontWeight: FontWeight.normal,
                                                        decoration: TextDecoration.none,
                                                        fontSize: 15,
                                                    )
                                                )
                                            ),
                                            const Padding(padding: EdgeInsets.all(15)),
                                            Container(
                                                color: ptTheme.kPrimaryColor,
                                                padding: const EdgeInsets.fromLTRB(30, 5, 30, 200),
                                                child: const Text(
                                                    "Unimplemented Graph#3",
                                                    style: TextStyle(
                                                        color: ptTheme.kSecondaryColor,
                                                        fontWeight: FontWeight.normal,
                                                        decoration: TextDecoration.none,
                                                        fontSize: 15,
                                                    ),
                                                )
                                            )
                                        ]
                                    ),
                                    const Padding(padding: EdgeInsets.all(15)),
                                    Row(
                                        children: [
                                            Container(
                                                color: ptTheme.kPrimaryColor,
                                                padding: const EdgeInsets.fromLTRB(30, 5, 30, 200),
                                                child: const Text(
                                                    "Unimplemented Graph#4",
                                                    style: TextStyle(
                                                        color: ptTheme.kSecondaryColor,
                                                        fontWeight: FontWeight.normal,
                                                        decoration: TextDecoration.none,
                                                        fontSize: 15,
                                                    ),
                                                )
                                            ),
                                            const Padding(padding: EdgeInsets.all(15)),
                                            Container(
                                                color: ptTheme.kPrimaryColor,
                                                padding: const EdgeInsets.fromLTRB(30, 5, 30, 200),
                                                child: const Text(
                                                    "Unimplemented Graph#5",
                                                    style: TextStyle(
                                                        color: ptTheme.kSecondaryColor,
                                                        fontWeight: FontWeight.normal,
                                                        decoration: TextDecoration.none,
                                                        fontSize: 15,
                                                    ),
                                                )
                                            ),
                                            const Padding(padding: EdgeInsets.all(15)),
                                            Container(
                                                color: ptTheme.kPrimaryColor,
                                                padding: const EdgeInsets.fromLTRB(30, 5, 30, 200),
                                                child: const Text(
                                                    "Unimplemented Graph#6",
                                                    style: TextStyle(
                                                        color: ptTheme.kSecondaryColor,
                                                        fontWeight: FontWeight.normal,
                                                        decoration: TextDecoration.none,
                                                        fontSize: 15,
                                                    )
                                                )
                                            )
                                        ]
                                    )
                                ]
                            )
                        ]
                    )
                ]
            )
        );
        // End of Build Method //
    }
}