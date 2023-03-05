// ignore_for_file: library_prefixes, file_names

import 'package:flutter/material.dart';

// Other
import 'package:project_time/Themes.dart' as ptTheme;
import 'package:project_time/config.dart' as ptConfig;

class SearchBar extends StatefulWidget 
{
    const SearchBar({super.key});

    @override
    State<SearchBar> createState() => _SearchBarState();
}

class _SearchBarState extends State<SearchBar> 
{
    @override
    Widget build(BuildContext context) 
    {
        return Material(
            color: Colors.transparent,
            child: Container(
                width: 550,
                decoration: const BoxDecoration(
                    border: Border.fromBorderSide(
                        BorderSide(
                            color: ptTheme.kSecondaryColor,
                            width: 3,
                        )
                    ),
                    borderRadius: BorderRadius.all(Radius.circular(30))
                ),
                child: TextField(
                    decoration: InputDecoration(
                        border: OutlineInputBorder(
                            borderRadius: BorderRadius.circular(20),
                            borderSide: BorderSide.none,
                        ),
                        filled: true,
                        fillColor: ptTheme.kSecondaryTransparentColor,
                        hintText: "Search",
                        hintStyle: const TextStyle(
                            color: ptTheme.kAccentTransparentColor,
                            fontWeight: FontWeight.normal,
                            decoration: TextDecoration.none,
                            fontSize: 20,
                        ),
                    ),
                    style: const TextStyle(
                        color: ptTheme.kAccentColor,
                        fontWeight: FontWeight.normal,
                        decoration: TextDecoration.none,
                        fontSize: 20,
                    )
                )
            )
        );
    }
}