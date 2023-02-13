// ignore_for_file: library_prefixes, file_names

import 'package:flutter/material.dart';

// Other
import 'package:project_time/Themes.dart' as ptTheme;

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
        return Container(
            decoration: const BoxDecoration(
                border: Border.fromBorderSide(
                    BorderSide(
                        color: ptTheme.kSecondaryColor,
                        width: 3,
                    )
                ),
                borderRadius: BorderRadius.all(Radius.circular(30))
            ),
            padding: const EdgeInsets.fromLTRB(100, 6, 100, 20),
            child: const Text(
                "Unimplemented SearchBar",
                style: TextStyle(
                    color: ptTheme.kSecondaryColor,
                    fontWeight: FontWeight.normal,
                    decoration: TextDecoration.none,
                    fontSize: 20,
                ),
            )
        );
    }
}