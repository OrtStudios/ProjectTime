// ignore_for_file: file_names, library_prefixes
import 'package:flutter/material.dart';
import "dart:math" as math;

// Widgets
import 'package:flutter_gui_test/widgets/shortcuts.dart';

// Other
import 'package:flutter_gui_test/Themes.dart' as ptTheme;
import 'package:flutter_gui_test/config.dart' as ptConfig;

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
        return Scaffold(
            backgroundColor: ptTheme.kBackgroundColor,
            body: ShortCuts(
                child: Stack(
                    children: [
                        Image.asset(
                            ptTheme.kBackgroundImage,
                            height: ptConfig.windowHeight,
                            width: ptConfig.windowWidth,
                            fit: BoxFit.cover,
                        ),
                        Row(
                            children: [
                                Container(
                                    color: ptTheme.kPrimaryColor,
                                    child: const Text("Unimplemented SideBar"),
                                ),
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
                                                children: [
                                                    Container(
                                                        color: ptTheme.kPrimaryColor,
                                                        padding: const EdgeInsets.fromLTRB(100, 5, 100, 20),
                                                        child: const Text("Unimplemented SearchBar")
                                                    ),
                                                    const Padding(padding: EdgeInsets.all(10)),
                                                    Container(
                                                        color: ptTheme.kPrimaryColor,
                                                        child: const Text("Plus")
                                                    )
                                                ]
                                            )
                                        ),
                                        const Padding(padding: EdgeInsets.all(20)),
                                        Column(
                                            children: [
                                                Row(
                                                    children: [
                                                        ClipRRect(
                                                            borderRadius: const BorderRadius.all(Radius.circular(10)),
                                                            clipBehavior: Clip.antiAliasWithSaveLayer,
                                                            child: Container(
                                                                color: ptTheme.kPrimaryColor,
                                                                padding: const EdgeInsets.fromLTRB(30, 5, 30, 200),
                                                                child: const Text("Unimplemented Graph#1")
                                                            ),
                                                        ),
                                                        const Padding(padding: EdgeInsets.all(15)),
                                                        Container(
                                                            color: ptTheme.kPrimaryColor,
                                                            padding: const EdgeInsets.fromLTRB(30, 5, 30, 200),
                                                            child: const Text("Unimplemented Graph#2")
                                                        ),
                                                        const Padding(padding: EdgeInsets.all(15)),
                                                        Container(
                                                            color: ptTheme.kPrimaryColor,
                                                            padding: const EdgeInsets.fromLTRB(30, 5, 30, 200),
                                                            child: const Text("Unimplemented Graph#3")
                                                        )
                                                    ]
                                                ),
                                                const Padding(padding: EdgeInsets.all(15)),
                                                Row(
                                                    children: [
                                                        Container(
                                                            color: ptTheme.kPrimaryColor,
                                                            padding: const EdgeInsets.fromLTRB(30, 5, 30, 200),
                                                            child: const Text("Unimplemented Graph#4")
                                                        ),
                                                        const Padding(padding: EdgeInsets.all(15)),
                                                        Container(
                                                            color: ptTheme.kPrimaryColor,
                                                            padding: const EdgeInsets.fromLTRB(30, 5, 30, 200),
                                                            child: const Text("Unimplemented Graph#5")
                                                        ),
                                                        const Padding(padding: EdgeInsets.all(15)),
                                                        Container(
                                                            color: ptTheme.kPrimaryColor,
                                                            padding: const EdgeInsets.fromLTRB(30, 5, 30, 200),
                                                            child: const Text("Unimplemented Graph#6")
                                                        )
                                                    ]
                                                )
                                            ]
                                        )
                                    ]
                                )
                            ]
                        )
                    ]
                ),
            )
        );
    }
}