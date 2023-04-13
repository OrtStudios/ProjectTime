// ignore_for_file: file_names, library_prefixes, non_constant_identifier_names, constant_identifier_names, must_be_immutable

import 'package:flutter/material.dart';
import 'package:go_router/go_router.dart';

// Utils
import 'package:project_time/utils/pageIndex.dart';

// Data
import 'package:project_time/main.theme.dart' as ptTheme;
import 'package:project_time/main.config.dart' as ptConfig;

class Sidebar extends StatelessWidget 
{
    final List<NavigationRailDestination> SidebarDestinations = const [
        NavigationRailDestination(
            icon: Icon(Icons.house_outlined),
            selectedIcon: Icon(Icons.house),
            label: Text('Home'),
        ),
        NavigationRailDestination(
            icon: Icon(Icons.library_books_outlined),
            selectedIcon: Icon(Icons.library_books),
            label: Text('Projects Library'),
        ),
        NavigationRailDestination(
            icon: Icon(Icons.settings_outlined),
            selectedIcon: Icon(Icons.settings),
            label: Text('Settings'),
        ),
    ];

    final Widget page;
    const Sidebar({required this.page, Key? key}) : super(key: key);

    @override
    Widget build(BuildContext context) 
    {
        void changeDestination(int value) 
        {
            switch (value) 
            {
                case 0:
                    context.go("/");
                    break;
                case 1:
                    context.go("/projectsLibrary");
                    break;
                case 2:
                    context.go("/settings");
                    break;
            }
        }

        return Container(
            height: ptConfig.windowHeight + 2,
            width: ptConfig.sidebarWidth,
            color: Colors.transparent,
            child: NavigationRail(
                backgroundColor: Colors.transparent,
                destinations: const [
                    NavigationRailDestination(
                        icon: Icon(Icons.house_outlined),
                        selectedIcon: Icon(Icons.house),
                        label: Text('Home'),
                    ),
                    NavigationRailDestination(
                        icon: Icon(Icons.library_books_outlined),
                        selectedIcon: Icon(Icons.library_books),
                        label: Text('Projects Library')
                    ),
                    NavigationRailDestination(
                        icon: Icon(Icons.settings_outlined),
                        selectedIcon: Icon(Icons.settings),
                        label: Text('Settings'),
                    ),
                ],
                selectedIndex:  GetPageIndex(page),
                onDestinationSelected: changeDestination,
                useIndicator: true,
            )
        );
    }
}